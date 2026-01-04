#include "ir.h"


Ir::Ir(uint8_t recvPin, uint8_t sendPin): irrecv(recvPin), irsend(sendPin)             
{
    
}

void Ir::begin(){
    irrecv.enableIRIn();
    irsend.begin();

    File file = LittleFS.open("/ir_codes.txt", FILE_READ);
    file.seek(0);
    
    while(file.available()){
        file.readStringUntil('\n');
        Ir::numberOfLines++;
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
    File file=LittleFS.open("/ir_codes.txt", FILE_APPEND);

    if(!file){
        Serial.println("Failed to open file");
        return;
    }
    file.println(value); 
    file.close();

}

void Ir::send(uint32_t code){
    irsend.sendNEC(code, 32);
    Serial.println("Poslato");
}
