#include <crt_CleanRTOS.h>
#include <crt_Mutex.h>

#include <crt_Timer.h>
#include <crt_Queue.h>
#include <crt_FreeRTOS.h>
#include "SignalPauseDetector.h"
#include "NecReceiver.h"
#include "MessageReceiver.h"
#include <Arduino.h>

namespace crt
{
    void setup()
    {
        Serial.begin(115200);
        NecReceiver necReceiver("NecReceiver", 1, 5000, 1);
        SignalPauseDetector signalPauseDetector("SignalPauseDetector", 1, 5000, 1, 8, necReceiver);
        ESP_LOGI("Setup has been started", "Starting up IR_Ino!");
        vTaskDelay(5);
    }

    void loop()
    {
        vTaskDelay(1);
    }
}

void setup() {
    crt::setup();
}

void loop() {
    crt::loop();
}
