#include "espWiFi.h"
#include "../var/var.h" 

EspWiFi::EspWiFi(){}

void EspWiFi::begin(){
    WiFi.mode(WIFI_AP);
    WiFi.softAP(WIFI_SSID, WIFI_PASS);

}

std::vector<String> EspWiFi::scanNetwork(){
    ispis.clear();

    int n= WiFi.scanNetworks();
    if(n==0){
        ispis.push_back("Nema WiFi mreza");
    }

    for(int i=0; i<n;i++){
        String name = WiFi.SSID(i);
        name = name.substring(0,7);
        String info = name + "  " + String(WiFi.RSSI(i)) + "," + String(WiFi.encryptionType(i));
        ispis.push_back(info);
    }

    return ispis;
}