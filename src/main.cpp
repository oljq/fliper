#include "ekran.h"

Ekran e;
int selectedIndex=0;
int selectedIndex2=0;
const int taster1=18;
const int taster2=19;
const int taster3=23;
bool saveIR= false;
bool sendIR=false;
bool moveRight=false;
bool moveLeft=false;

void setup() {
  Serial.begin(9600);
  randomSeed(analogRead(A0));

  pinMode(taster1, INPUT_PULLUP);
  pinMode(taster2, INPUT_PULLUP);
  pinMode(taster3, INPUT_PULLUP);
  e.begin(); 

  if (!LittleFS.begin()) {
    Serial.println("LittleFS mount FAILED");
  } else {
    Serial.println("LittleFS mounted OK");
  }
}

void loop() {
  Serial.println("hello");
  if(e.firstScreen){
    e.pocetni();
    if(digitalRead(taster1)==LOW){
      delay(150);
      e.firstScreen=false;
      e.brisi();
    }
    
    
  }else{  
    selectedIndex %= e.ListMainMenu.size();
    
    if(digitalRead(taster1)==LOW){
      delay(150);
      Serial.println("Taster1");

      if (e.currentScreen == SCREEN_MAIN_MENU) selectedIndex++;
      else if(e.currentScreen == SCREEN_IR_RECEIVER)saveIR=true;
      else if(e.currentScreen == SCREEN_IR_EMISSION) selectedIndex2++;
      else if(e.currentScreen == SCREEN_GAME)moveRight=true;
  
    }

    if(digitalRead(taster2)==LOW){   
      delay(150);
      Serial.println("Taster2");
      if(e.currentScreen == SCREEN_MAIN_MENU){
      
        switch (selectedIndex % e.ListMainMenu.size()) {
          case 0: e.currentScreen = SCREEN_IR_RECEIVER; break;
          case 1: e.currentScreen = SCREEN_IR_EMISSION; break;
          case 2: e.currentScreen = SCREEN_GAME; break;
          case 3: e.firstScreen = true; break;
          
          
        }

      }
      else e.currentScreen=SCREEN_MAIN_MENU;

    }

    if(digitalRead(taster3)==LOW){
      delay(150);

      if(e.currentScreen == SCREEN_IR_EMISSION)sendIR=true;
      else if(e.currentScreen == SCREEN_GAME) moveLeft=true;

    }

    e.DrawMeni(e.currentScreen, selectedIndex, saveIR, selectedIndex2, sendIR, moveRight, moveLeft);
    saveIR=false;
    sendIR=false;
    moveRight=false;
    moveLeft=false;
    
  }

}



