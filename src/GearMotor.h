//
// Created by mrbueno on 29/03/19.
//
#ifndef _GEARMOTOR_H_
#define _GEARMOTOR_H_

#include <HID.h>

#define LEFT_GEARMOTOR_PWD 5
#define LEFT_GEARMOTOR_AHEAD 6
#define LEFT_GEARMOTOR_REVERSE 7

#define RIGHT_GEARMOTOR_PWD 10
#define RIGHT_GEARMOTOR_AHEAD 8
#define RIGHT_GEARMOTOR_REVERSE 9

boolean areInitializedGearMotors = false;

void initGearMotors() {
    pinMode(LEFT_GEARMOTOR_PWD, OUTPUT);
    pinMode(LEFT_GEARMOTOR_AHEAD, OUTPUT);
    pinMode(LEFT_GEARMOTOR_REVERSE, OUTPUT);
    pinMode(RIGHT_GEARMOTOR_PWD, OUTPUT);
    pinMode(RIGHT_GEARMOTOR_AHEAD, OUTPUT);
    pinMode(RIGHT_GEARMOTOR_REVERSE, OUTPUT);
    areInitializedGearMotors = true;
}

void move(int speed, int pwdPin, int aheadPin, int reversePin) {
    if (areInitializedGearMotors) {
        if (speed == 0) {
            digitalWrite(aheadPin, LOW);
            digitalWrite(reversePin, LOW);
        } else if (speed > 0) {
            digitalWrite(aheadPin, HIGH);
            digitalWrite(reversePin, LOW);

        } else if (speed < 0) {
            speed *= -1;
            digitalWrite(aheadPin, LOW);
            digitalWrite(reversePin, HIGH);
        }
        analogWrite(pwdPin, speed);
    }
}

void moveRightGearMotor(int speed) {
    move(speed, RIGHT_GEARMOTOR_PWD, RIGHT_GEARMOTOR_AHEAD, RIGHT_GEARMOTOR_REVERSE);
}

void moveLeftGearMotor(int speed) {
    move(speed, LEFT_GEARMOTOR_PWD, LEFT_GEARMOTOR_AHEAD, LEFT_GEARMOTOR_REVERSE);
}

#endif //_GEARMOTOR_H_

