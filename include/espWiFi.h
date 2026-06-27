#ifndef ESPWIFI_H
#define ESPWIFI_H

#include <WiFi.h>
#include <WebServer.h>
#include <vector>


class EspWiFi {

public:
    std::vector<String> ispis;
    EspWiFi();
    void begin();
    std::vector<String> scanNetwork();

};


#endif