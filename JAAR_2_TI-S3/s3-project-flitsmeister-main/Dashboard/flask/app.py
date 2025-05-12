from flask import Flask, request, jsonify
from pymongo import MongoClient
from flask_cors import CORS

app = Flask(__name__)
CORS(app)  # Enable CORS for all routes (allows all origins)

# Connect to MongoDB
client = MongoClient('mongodb://flitsmaister:flitsmaister@100.69.176.84:27017/')
db = client['flitsmaister_speeddetector']
leaderboardCollection = db['SpeedAndTimes']
identificationCollection = db['Identification']
usersUICollection = db['usersUI']

@app.route('/leaderboard', methods=['GET'])
def getLeaderboard():
    try:
        leaderboardData = list(leaderboardCollection.find({}, {'_id': 0}))
        leaderboardData.sort(key=lambda x: x['speed_kmh'], reverse=True)
        return jsonify(leaderboardData)
    except Exception as e:
        return jsonify({'error': str(e)}), 500

@app.route('/speeds', methods=['GET'])
def getSpeeds():
    try:
        speedData = list(leaderboardCollection.find({}, {'_id': 0}))
        speedData.sort(key=lambda x: x['timestamp'], reverse=True)
        return jsonify(speedData)
    except Exception as e:
        return jsonify({'error': str(e)}), 500


@app.route('/store-data', methods=['POST'])
def storeData():
    data = request.json
    if data:
        identificationCollection.replace_one({"_id": "identification_data"}, data, upsert=True)
        return jsonify({"message": "Data saved successfully"}, data), 201
    return jsonify({"error": "No data provided"}), 400

@app.route('/get-identification', methods=['GET'])
def getIdentificationData():
    try:
        document = identificationCollection.find_one({"_id": "identification_data"}, {'_id': 0})
        if document:
            return jsonify({"message": "Data retrieved successfully", "data": document}), 200
        else:
            return jsonify({"message": "No identification data found"}), 404
    except Exception as e:
        return jsonify({'error': str(e)}), 500
    
@app.route('/login', methods=['POST'])
def login():
    try:
        # Vraagt JSON data op!
        dataLogin = request.json
        username = dataLogin.get('username')
        password = dataLogin.get('password')

        # Controleert of zowel een username als wachtwoord 
        if not username or not password:
            return jsonify({"error": "Username and password are required"}), 400
        
        user = usersUICollection.find_one({"username":username})

        if user and user['password'] == password:
            return jsonify({"message": "Login succesful"}), 200
        else:
            return jsonify({"error": "Invalid username or password"}), 401
    except Exception as e:
        return jsonify({'error': str(e)}), 500

if __name__ == '__main__':
    app.run(host="0.0.0.0", debug=True, port=5000, ssl_context='adhoc')
