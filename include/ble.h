#ifndef BLE_H
#define BLE_H

#include<Arduino.h>
#include<BLEDevice.h>
#include<BLEUtils.h>
#include<BLEScan.h>


class Ble{
public: 
    std::vector<String> ispis;
    void begin();
    std::vector<String> scan(int seconds);


private:
    BLEScan* bleScan=nullptr;

};

#endif