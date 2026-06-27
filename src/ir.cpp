/*
#include "ir.h"


Ir::Ir(uint8_t recvPin, uint8_t sendPin): irrecv(recvPin), irsend(sendPin)             
{
    
}

void Ir::begin(){
    irrecv.enableIRIn();
    irsend.begin();

    File file = LittleFS.open("/ir_codes.txt", FILE_READ);
    
    if(!file){
        Serial.println("IR codes file not found!");
        return;
    }

    numberOfLines=0;

    while(true){
        String line = file.readStringUntil('\n');
        line.trim(); 
        if(line.length() > 0) numberOfLines++; 
        if(file.available() == 0) break; 
    }

    file.close();
}

long Ir::read() {
    if (irrecv.decode(&results)) {
        long value = results.value; 
        irrecv.resume();           
        return value;
    }
    return -1;
}

void Ir::save(unsigned long value){
    bool exists = false;
    File fileread=LittleFS.open("/ir_codes.txt", FILE_READ);

    if(fileread){

        while(fileread.available()){
            String line = fileread.readStringUntil('\n');
            line.trim(); // uklanja \r\n
                if(line == String(value)){
                    exists = true;
                    break;
                }
        }

        fileread.close();
    }

    if(!exists){
        File file = LittleFS.open("/ir_codes.txt", FILE_APPEND);
        if(!file){
            Serial.println("Failed to open file for appending");
            return;
        }
        file.println(value);
        file.close();
    }

}

void Ir::send(uint32_t code){
    irsend.sendNEC(code, 32);
    Serial.println("Poslato");
}

*/