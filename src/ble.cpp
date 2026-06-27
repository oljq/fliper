
#include "ble.h"

void Ble::begin(){
    BLEDevice::init("ESP32");

    bleScan=BLEDevice::getScan();
    bleScan->setActiveScan(true);
    bleScan->setInterval(100);
    bleScan->setWindow(80);
}

std::vector<String> Ble::scan(int seconds){
    if(!bleScan) return {};

    ispis.clear();

    BLEScanResults results = bleScan->start(seconds, true);

    Serial.println(results.getCount());

    for (int i = 0; i < results.getCount(); i++){
        BLEAdvertisedDevice device = results.getDevice(i);

        String line = device.haveName() ? device.getName().c_str() : "(no name)";

        line += " (";
        line += String(device.getRSSI());
        line += ")";

        ispis.push_back(line);
    }

    bleScan->clearResults();

    return ispis;
}
