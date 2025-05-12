# Use the official Node.js image as the base image
FROM node:16-alpine

# Set the working directory in the container
WORKDIR /app

# Copy the package.json and package-lock.json files to the container
COPY package.json package-lock.json ./

# Install dependencies
RUN npm install

# Copy the rest of the application code to the container
COPY . .

# Expose the port used by the React development server
EXPOSE 3000

# Set environment variables for development
ENV NODE_ENV=development

# Command to start the development server
CMD ["npm", "start"]
