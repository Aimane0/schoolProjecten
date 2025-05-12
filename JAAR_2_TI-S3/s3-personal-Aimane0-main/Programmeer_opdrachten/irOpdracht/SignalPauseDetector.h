#ifndef SIGNAL_PAUSE_DETECTOR_H
#define SIGNAL_PAUSE_DETECTOR_H

#include <Arduino.h>
#include <crt_CleanRTOS.h>
#include <crt_Timer.h>
#include <crt_Queue.h>
#include "NecReceiver.h"

namespace crt
{
    class SignalPauseDetector : public Task
    {
    private:
        int tsop_pin;
        NecReceiver& necReceiver;
        const int T_MAX_PAUSE_US = 6000;
        Timer timer;

        // States van de code
        enum SignalPauseDetectorState
        {
            WAITING_FOR_PAUSE,
            WAITING_FOR_SIGNAL
        };

    SignalPauseDetectorState signalState = WAITING_FOR_PAUSE;

        public :
        SignalPauseDetector(const char* name, unsigned int priority, unsigned int stackSize, unsigned int core, int tsop_pin, NecReceiver& necReceiver) 
        : Task(name, priority, stackSize, core), tsop_pin(tsop_pin), necReceiver(necReceiver), timer(this){}

        void main()
        {
            while (true)
            {
                switch (signalState)
                {
                case WAITING_FOR_PAUSE:
                    timer.sleep_us(100);
                    if (digitalRead(tsop_pin) == HIGH)
                    {
                        necReceiver.t_signalUs += 100;
                        signalState = WAITING_FOR_PAUSE;
                    }
                    else
                    {
                        necReceiver.SignalDetected(necReceiver.t_signalUs);
                        necReceiver.t_pauseUs = 0;
                        signalState = WAITING_FOR_SIGNAL;
                    }
                    break;

                case WAITING_FOR_SIGNAL:
                    timer.sleep_us(100);
                    if (digitalRead(tsop_pin) == LOW)
                    {
                        necReceiver.t_pauseUs += 100;
                        if (necReceiver.t_pauseUs > T_MAX_PAUSE_US)
                        {
                            necReceiver.PauseDetected(necReceiver.t_pauseUs);
                            necReceiver.t_pauseUs = 0;
                            signalState = WAITING_FOR_SIGNAL;
                        }
                        else
                        {
                            signalState = WAITING_FOR_SIGNAL;
                        }
                    }
                    else
                    {
                        necReceiver.t_signalUs = 0;
                        signalState = WAITING_FOR_PAUSE;
                    }
                    break;
                }
            }
        }
        void start()
        {
            Task::start();
        }
    };
}

#endif