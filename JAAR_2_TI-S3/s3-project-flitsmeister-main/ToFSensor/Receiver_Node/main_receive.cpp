#include "painlessMesh.h"
#include "CleanRTOS.h"
#include "ToFSensor.hpp"
#include <Arduino.h>
#include <IRrecv.h>
#include <IRutils.h>
#include <chrono>
#include <string>

// Network details
#define MESH_PREFIX "Flitsmaisters"
#define MESH_PASSWORD "SneakyPassword"
#define MESH_PORT 5555

#define UART_TX 16
#define UART_RX 17

painlessMesh mesh;
ToFSensor sensor;

// IR Receiver
#define IR_RECEIVE_PIN 4
IRrecv irrecv(IR_RECEIVE_PIN);
decode_results results;

// Timing and calculations
unsigned long receivedTriggerTime = 0;
unsigned long receiverTriggerTime = 0;
const float distanceMeters = 10.0;

// States for the state machine
enum State
{
    Idle,
    WaitForIRandToF,
    SendingToPi
};
State state = Idle;

// rtos::flags
crt::Flag flagPersonDetected;
crt::Flag IRscannedFlag;
crt::Flag startInfoFlag;
crt::Flag flagFinished;

// Shared variables
std::string irID = "";
float speedKmH = 0.0;

// Callback function for receiving mesh messages
void receivedCallback(uint32_t from, String &msg)
{
    if (msg == "TRIGGER")
    {
        receivedTriggerTime = millis();
        Serial.printf("Received TRIGGER message at: %lu ms\n", receivedTriggerTime);
    }
}

// Functions to set flags
void personDetected()
{
    flagPersonDetected.set();
}

void irScanned()
{
    if (!irID.empty())
    {
        IRscannedFlag.set();
    }
}

void infoFlag()
{
    startInfoFlag.set();
}

void Finished()
{
    flagFinished.set();
}

void setup()
{
    Serial.begin(115200);
    Serial1.begin(115200, SERIAL_8N1, UART_TX, UART_RX);

    // Initialize sensor
    sensor.begin();

    // Initialize IR receiver
    irrecv.enableIRIn();
    Serial.println("IR receiver ready...");

    // Initialize mesh network
    mesh.init(MESH_PREFIX, MESH_PASSWORD, MESH_PORT);
    mesh.onReceive(&receivedCallback);

    // Set the initial finished flag
    Finished();
}

void main()
{
    for (;;)
    {
        switch (state)
        {
        case Idle:
            // Wait for the finished flag
            wait(flagFinished);

            // Check if IR has been scanned
            if (irrecv.decode(&results))
            {
                if (results.value != 0xFFFFFFFFFFFFFFFF)
                {
                    irID = String(results.value, HEX).c_str();
                    Serial.printf("IR signal received: %s\n", irID.c_str());
                    irScanned(); // Set IR scanned flag
                }
                irrecv.resume();
            }

            // Transition to the next state if IR is scanned
            if (IRscannedFlag.is_set())
            {
                infoFlag();
                state = WaitForIRandToF;
            }
            break;

        case WaitForIRandToF:
            wait(startInfoFlag);
            startInfoFlag.clear();

            int counter = 45;
            while (counter > 0)
            {
                mesh.update();

                this_thread::sleep_for(std::chrono::seconds(1));
                counter--;

                // Check ToF sensor
                sensor.requestBytes();
                sensor.shiftBytes();
                uint16_t distance = sensor.getDistance();

                if (distance > 150 && distance < 250)
                {
                    receiverTriggerTime = millis();
                    Serial.printf("Local trigger detected at: %lu ms\n", receiverTriggerTime);

                    if (receivedTriggerTime > 0)
                    {
                        unsigned long deltaTimeMs = receiverTriggerTime - receivedTriggerTime;
                        speedKmH = (distanceMeters / (deltaTimeMs / 1000.0)) * 3.6;
                        Serial.printf("Calculated speed: %.2f km/h\n", speedKmH);

                        personDetected(); // Set person detected flag
                        state = SendingToPi;
                        break;
                    }
                }

                delay(1000); // 1-second delay for the loop
                counter--;
            }

            if (counter <= 0)
            {
                Finished(); // Reset state if no trigger is detected
                counter = 45;
                state = Idle;
            }
            break;

        case SendingToPi:
            wait(flagPersonDetected);
            flagPersonDetected.clear();

            // Send the calculated speed to Raspberry Pi via UART
            Serial1.printf("ID:%s SPEED:%.2f\n", irID.c_str(), speedKmH);
            Serial.printf("Sent via UART: ID:%s SPEED:%.2f\n", irID.c_str(), speedKmH);

            // Broadcast the result to the mesh network
            mesh.sendBroadcast("FINISHED");
            mesh.update();

            // Reset variables and transition to Idle
            Finished();
            state = Idle;
            break;

        default:
            state = Idle;
            break;
        }
    }
}
