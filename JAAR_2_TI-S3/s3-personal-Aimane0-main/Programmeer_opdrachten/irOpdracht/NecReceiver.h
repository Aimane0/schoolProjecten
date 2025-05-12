#ifndef NEC_RECEIVER_H
#define NEC_RECEIVER_H

#include <Arduino.h>
#include <crt_CleanRTOS.h>
#include "SignalPauseDetector.h"
#include "MessageReceiver.h"

namespace crt
{
    class NecReceiver : public Task
    {
    private:
        // Channels aanmaken voor de interface functies
        Queue<int, 20> signalChannel;
        Queue<int, 20> pauseChannel;

        // Voor het detecteren van signalen en pauzes
        int T_LEADSIGNAL_MIN_US = 7000;
        int T_LEADSIGNAL_MAX_US = 11000;
        int T_LEADPAUSE_MIN_US = 3000;
        int T_LEADPAUSE_MAX_US = 6000;
        int T_BITPAUSE_MIN_US = 200;
        int T_BITPAUSE_MAX_US = 2000;
        int T_BITPAUSE_THRESHOLD_ZERO_ONE = 1100;

        MessageReceiver messageReceiver;

        // De states voor de code
        enum NecReceiverState
        {
            WAITING_FOR_LEAD_SIGNAL,
            WAITING_FOR_LEAD_PAUSE,
            WAITING_FOR_BIT_PAUSE
        };

        NecReceiverState state = WAITING_FOR_LEAD_SIGNAL;

    public:
        // Aangemaakte variabelen, de states zullen rouleren in variabel state
        // De uint variabelen zijn voor de extractMessage functie
        uint64_t m = 0;
        uint n = 0;
        uint64_t msg;
        uint nofBytes = 0;

        NecReceiver(const char *name, unsigned int priority, unsigned int stackSize, unsigned int core)
            : Task(name, priority, stackSize, core), signalChannel(this, false), pauseChannel(this, false) {}

        int t_signalUs = 0;
        int t_pauseUs = 0;

        // Volgorde van bits omkeren, zodat de MSB naar links gaat, waar de MSB normaal hoort te zitten
        void extractMessage(uint64_t &msg, uint &nofBytes, uint64_t m, uint n)
        {
            msg = 0;
            uint64_t mloc = m;
            for (int i = 0; i < n; i++)
            {
                msg <<= 1;
                msg |= (mloc & 1);
                mloc = mloc >> 1;
            }
            nofBytes = n / 8;
        }

        // Interface functie
        void SignalDetected(int t_signalUs)
        {
            if (t_signalUs > T_LEADSIGNAL_MIN_US)
            {
                signalChannel.clear();
                pauseChannel.clear();
            }
            signalChannel.write(t_signalUs);
        }

        // Interface functie
        void PauseDetected(int t_pauseUs)
        {
            pauseChannel.write(t_pauseUs);
        }

        void main()
        {
            for (;;)
            {
                switch (state)
                {
                case WAITING_FOR_LEAD_SIGNAL:
                    signalChannel.read(t_signalUs);
                    if (t_signalUs > T_LEADSIGNAL_MIN_US && t_signalUs < T_LEADSIGNAL_MAX_US)
                    {
                        state = WAITING_FOR_LEAD_PAUSE;
                    }
                    break;

                case WAITING_FOR_LEAD_PAUSE:
                    pauseChannel.read(t_pauseUs);
                    if ((t_pauseUs > T_LEADPAUSE_MIN_US) && (t_pauseUs < T_LEADPAUSE_MAX_US))
                    {
                        m = 0;
                        n = 0;
                        state = WAITING_FOR_BIT_PAUSE;
                    }
                    else
                    {
                        state = WAITING_FOR_LEAD_SIGNAL;
                    }
                    break;

                case WAITING_FOR_BIT_PAUSE:
                    pauseChannel.read(t_pauseUs);
                    if ((t_pauseUs > T_BITPAUSE_MIN_US) && (t_pauseUs < T_BITPAUSE_MAX_US))
                    {
                        m <<= 1;
                        if (t_pauseUs > T_BITPAUSE_THRESHOLD_ZERO_ONE)
                        {
                            m |= 1;
                        }
                        n++;
                        state = WAITING_FOR_BIT_PAUSE;
                    }
                    else
                    {
                        extractMessage(msg, nofBytes, m, n);
                        messageReceiver.messageReceived(msg, nofBytes);
                        state = WAITING_FOR_LEAD_SIGNAL;
                    }
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