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
#define IR_RECEIVE_PIN 4 // GPIO4 voor de IR-Ontvanger

IRrecv irrecv(IR_RECEIVE_PIN);
decode_results results;
painlessMesh mesh;
ToFSensor sensor;

enum State
{
    WaitForIRandToF,
    WaitForSend,
    Idle
};

State state = WaitForIRandToF;

// Flags
crt::Flag flagPersonDetected;
crt::Flag IRscannedFlag;
crt::Flag flagFinished;
crt::Flag flagInfoSent;

// Variables
int irID = 0;
std::string measuringFinished;

// Function prototypes
void personDetected();
void irScanned();
void infoSent();
void Finished();
void receivedCallback(uint32_t from, String &msg);

// Implementations
void personDetected()
{
    flagPersonDetected.set();
}

void irScanned()
{
    if (irID != 0)
    {
        IRscannedFlag.set();
    }
}

void infoSent()
{
    flagInfoSent.set();
}

void Finished()
{
    flagFinished.set();
}

void receivedCallback(uint32_t from, String &msg)
{
    if (msg == "FINISHED")
    {
        measuringFinished = msg.c_str(); // Store the received message
    }
}

void setup()
{
    // Serial begin
    Serial.begin(115200);

    // Start IR
    irrecv.enableIRIn();
    Serial.println("IR ontvanger gereed op GPIO4...");

    // Start de ToF sensor
    sensor.begin();

    // Checken wat de mode is ter controle van of de ToF werkt
    sensor.requestMode();
    sensor.printMode();

    // Start de Mesh
    mesh.init(MESH_PREFIX, MESH_PASSWORD, MESH_PORT);
    mesh.onReceive(receivedCallback);

    // Start het programma, finished moet geset zijn voor de switch cases om te werken
    Finished();
}

void main()
{
    for (;;)
    {
        switch (state)
        {
        case WaitForIRandToF:
            crt::Task::wait(flagFinished);

            // Check de ToF en IR sensor
            sensor.requestBytes();
            sensor.shiftBytes();
            uint16_t dist = sensor.getDistance();

            if (dist > 149 && dist < 251 && irrecv.decode(&results))
            {
                irID = results.value;
                Serial.printf("IR-signaal ontvangen: %d\n", irID);
                irrecv.resume(); // Prepare for the next IR signal
                irScanned();
                personDetected();
                state = WaitForSend;
            }
            break;

        case WaitForSend:
            crt::Task::wait(flagPersonDetected, IRscannedFlag);

            // Stuur TRIGGER en IR ID via mesh
            mesh.update();
            mesh.sendBroadcast("TRIGGER");
            mesh.sendBroadcast(String(irID));
            Serial.printf("TRIGGER en ID %d verzonden via mesh\n", irID);
            mesh.update();

            // Reset IR ID en set de vlag
            irID = 0;
            infoSent();
            state = Idle;
            break;

        case Idle:
            crt::Task::wait(flagInfoSent);

            int counter = 45; // Timeout van 45 seconden

            while (counter >= 1)
            {
                this_thread::sleep_for(std::chrono::seconds(1));
                counter--;

                // Update mesh en check op ontvangen berichten
                mesh.update();

                if (measuringFinished == "FINISHED")
                {
                    Serial.println("Meting voltooid.");
                    Finished();
                    measuringFinished.clear();
                    state = Idle;
                    break;
                }

                if (counter <= 0)
                {
                    Serial.println("Timeout bereikt.");
                    Finished();
                    counter = 45;
                    state = Idle;
                    break;
                }
            }
        }
    }
}
