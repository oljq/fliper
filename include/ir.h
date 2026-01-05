#ifndef IR_H
#define IR_H

#include <Arduino.h>
#include <IRremoteESP8266.h>
#include <IRrecv.h>
#include <IRsend.h>
#include <IRutils.h>
#include <LittleFS.h>

class Ir {
private:
    IRsend irsend;
    IRrecv irrecv;
    decode_results results;

public:
    int numberOfLines;
    Ir(uint8_t recvPin, uint8_t sendPin);
    void begin();

    long read();
    void save(unsigned long value);

    void send(uint32_t code);
};

#endif
