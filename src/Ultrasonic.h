//
// Created by mrbueno on 7/04/19.
//
#ifndef ARDUINOTESTBT_ULTRASONIC_H
#define ARDUINOTESTBT_ULTRASONIC_H

#include <EnableInterrupt.h>
#include <TaskSchedulerDeclarations.h>
#include "Commands.h"

// Pin 7 is useful on Arduino Uno, Leonardo, Mighty1284, ATtiny84...
#define TRIGGER 13
#define ECHO 12

unsigned long pulseStart = 0;

bool pulseBusy = false;

void ping();

Task measureDistanceTask(300, TASK_FOREVER, ping);

unsigned long measureDistance() {
    //PcintPort::detachInterrupt(ECHOPIN);
    return (micros() - pulseStart);
}

void interruptFunctionUltrasonic() {
    pulseBusy = false;
    //Serial.println("pong ");
    const unsigned long distance = measureDistance();
    if (700 < distance && distance < 1700) {
        if (currentSpeed > 120) {
            moveRightGearMotor(0);
            moveLeftGearMotor(0);
            //stopLeftGearMotorTask.restart();
            //stopRightGearMotorTask.restart();
            cmdMessenger.sendCmd(ACK_COMMAND, distance);
            cmdMessenger.sendCmd(ACK_COMMAND, currentSpeed);
        }
    } else {
        //cmdMessenger.sendCmd(ACK_COMMAND, currentSpeed);
    }
    //Serial.println(pingDistance);
}

void ping() {
    //_finished=false;
    //cmdMessenger.sendCmd(ACK_COMMAND, "ping");
    if (!pulseBusy) {
        pulseBusy = true;
        pulseStart = micros();
        digitalWrite(TRIGGER, HIGH);
        delayMicroseconds(10);
        digitalWrite(TRIGGER, LOW);
    }
}

void setupUltrasonic() {
    pinMode(TRIGGER, OUTPUT);
    digitalWrite(TRIGGER, LOW);
    pinMode(ECHO, INPUT);
    enableInterrupt(ECHO, interruptFunctionUltrasonic, HIGH);
}

#endif //ARDUINOTESTBT_ULTRASONIC_H
