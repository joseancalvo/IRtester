#include <IRremote.h>
#include <EasyBuzzer.h>
#define PIN_DETECT 2 // Pin detección detector IR
#define PIN_STATUS 13 // Pin status detector IR


void setup() {
 pinMode(PIN_DETECT, INPUT); //Pin detección IR
 pinMode(PIN_STATUS, OUTPUT); //Pin status IR
 pinMode(12, INPUT); //Pin inicio Buzzer
 EasyBuzzer.setPin(5); //Pin del Buzzer
 Serial.begin(9600);
}

void loop() {
  EasyBuzzer.update(); //Inicio libreria Buzzer
  digitalWrite(PIN_STATUS, !digitalRead(PIN_DETECT)); //Detección IR

if(digitalRead(12) == HIGH){ //Si se detecta señal IR
  EasyBuzzer.singleBeep(2000, 100); //Suena el Buzzer
  EasyBuzzer.stopBeep();
  Serial.println("El buzzer esta sonando");


}


}
