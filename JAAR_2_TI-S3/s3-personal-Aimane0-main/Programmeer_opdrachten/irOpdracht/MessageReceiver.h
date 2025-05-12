#ifndef MESSAGE_RECEIVER_H
#define MESSAGE_RECEIVER_H

#include <Arduino.h>

class MessageReceiver
{
    public:
    uint64_t printMsg;
    void messageReceived(uint64_t msg, unsigned int nofBytes)
    {
        for (uint i = 0; i < nofBytes; i++)
        {
            printMsg = msg;
        } for (uint j = 0; j < nofBytes; j++){
            Serial.print(printMsg, HEX);
            Serial.print(" ");
        }
    }
};

#endif