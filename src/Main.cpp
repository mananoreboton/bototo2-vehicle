//
// Created by mrbueno on 16/03/19.
//

#include <Arduino.h>
#include <SoftwareSerial.h>
//#include "../lib/CmdMessenger/CmdMessenger.h"

SoftwareSerial Bluetooth(2,3);
const int led = 13;
char msg_buffer[7];

//CmdMessenger cmdMessenger = CmdMessenger(Bluetooth);

void setup() {
    Serial.begin(9600);
    Bluetooth.begin(9600);
    Bluetooth.setTimeout(10);

    Serial.println("setup");
    Bluetooth.println("setup");
}

void loop() {
    //si existe información pendiente
    //Bluetooth.println("loop");
    //Serial.println("loop");
    if (Bluetooth.available() > 0) {
        //leeemos la opcion
        size_t num_read = Serial.readBytesUntil('\n', msg_buffer, sizeof(msg_buffer)-1 );

        Serial.print(msg_buffer);
        Bluetooth.print(msg_buffer);
        //si la opcion esta entre '1' y '9'
        /*if (option >= '1' && option <= '9') {
            //restamos el valor '0' para obtener el numero enviado
            option -= '0';
            for (int i = 0; i < option; i++) {
                digitalWrite(led, HIGH);
                delay(100);
                digitalWrite(led, LOW);
                delay(200);
            }
        }*/
    }
}
