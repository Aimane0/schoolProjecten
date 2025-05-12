//This main.cpp needs the libraries: painlessmesh, cleanrtos, asynctcp, arduino-esp to work

#include "painlessMesh.h"
#include "CleanRTOS.h"

//network details
#define MESH_PREFIX     "Flitsmaisters"
#define MESH_PASSWORD   "SneakyPassword"
#define MESH_PORT       5555

painlessMesh mesh;

// Message queue
QueueHandle_t messageQueue;

// Task prototypes (defined later)
void taskSendMessage(void *parameter);
void taskMeshUpdate(void *parameter);
void taskProcessReceivedMessages(void *parameter);

void receivedCallback(uint32_t from, String &msg) {
    // Send received messages to processing task via queue:
    String receivedMsg = String(from) + ": " + msg;
    xQueueSend(messageQueue, receivedMsg.c_str(), 0);
}

void newConnectionCallback(uint32_t nodeId) {
    Serial.printf("New Connection, nodeId = %u\n", nodeId);
}

void changedConnectionCallback() {
    Serial.printf("Changed connections\n");
}

void nodeTimeAdjustedCallback(int32_t offset) {
    Serial.printf("Adjusted time %u. Offset = %d\n", mesh.getNodeTime(), offset);
}

void setup() {
    Serial.begin(115200);

    // Mesh init
    mesh.setDebugMsgTypes(ERROR | STARTUP);
    mesh.init(MESH_PREFIX, MESH_PASSWORD, MESH_PORT);
    mesh.onReceive(&receivedCallback);
    mesh.onNewConnection(&newConnectionCallback);
    mesh.onChangedConnections(&changedConnectionCallback);
    mesh.onNodeTimeAdjusted(&nodeTimeAdjustedCallback);

    // Initializes message queue (10 Msgs and max 128 chars):
    messageQueue = xQueueCreate(10, sizeof(char) * 128);

    // CleanRTOS tasks
    xTaskCreate(taskSendMessage, "SendMessage", 4096, NULL, 1, NULL);
    xTaskCreate(taskMeshUpdate, "MeshUpdate", 4096, NULL, 1, NULL);
    xTaskCreate(taskProcessReceivedMessages, "ProcessMessages", 4096, NULL, 1, NULL);
}

void loop() {
    // No loop logic as CleanRTOS handles tasks
    vTaskDelay(portMAX_DELAY); // Prevent watchdog resets
}

// Task to send broadcast messages
void taskSendMessage(void *parameter) {
    while (true) {
        String msg = "Hi from node 1 with ID: ";
        msg += mesh.getNodeId();
        mesh.sendBroadcast(msg);
        Serial.printf("Broadcasted message: %s\n", msg.c_str());

        // interval between messages (2 seconds)
        vTaskDelay(pdMS_TO_TICKS(2000));
    }
}

// taskMeshUpdate updates the mesh network
void taskMeshUpdate(void *parameter) {
    while (true) {
        mesh.update();
        vTaskDelay(pdMS_TO_TICKS(10)); // Update mesh at 100 Hz
    }
}

// taskProcessReceivedMessages processes received messages
void taskProcessReceivedMessages(void *parameter) {
    char receivedMsg[128];
    while (true) {
        if (xQueueReceive(messageQueue, receivedMsg, portMAX_DELAY) == pdTRUE) {
            Serial.printf("Received message: %s\n", receivedMsg);
        }
    }
}
