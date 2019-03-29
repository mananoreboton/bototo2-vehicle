//
// Created by mrbueno on 29/03/19.
//

#include <HID.h>
#include "GearMotor.h"


GearMotor::GearMotor(uint8_t _pwdPin, uint8_t _aheadPin, uint8_t _reversePin) {
    pwdPin = _pwdPin;
    aheadPin = _aheadPin;
    reversePin = _reversePin;
    stopLeftWheelsTask = Task(1000, TASK_ONCE, &GearMotor::stop);
}

void GearMotor::init() {
    pinMode(pwdPin, OUTPUT);
    pinMode(aheadPin, OUTPUT);
    pinMode(reversePin, OUTPUT);
    isInit = true;
}

void GearMotor::move(int speed) {

    if (isInit) {
        stopLeftWheelsTask.disable();
        analogWrite(pwdPin, 100);
        if (speed > 0) {
            digitalWrite(aheadPin, HIGH);
            digitalWrite(reversePin, LOW);
        } else if (speed < 0) {
            digitalWrite(aheadPin, LOW);
            digitalWrite(reversePin, HIGH);
        }
    }
    //delay(1000);
    //stopLeftWheels();

    //stopLeftWheelsTask.enableDelayed(1000);
    stopLeftWheelsTask.restartDelayed(MIN_MOVE_TIME);
}

void GearMotor::stop() {
    if (isInit) {
        analogWrite(pwdPin, 0);
        digitalWrite(aheadPin, LOW);
        digitalWrite(reversePin, LOW);
        stopLeftWheelsTask.disable();
    }
}

