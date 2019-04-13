//
// Created by mrbueno on 29/03/19.
//
#ifndef _GEARMOTOR_H_
#define _GEARMOTOR_H_

#include <HID.h>
#include <TaskSchedulerDeclarations.h>
#include "GearMotorCallbacks.h"

#define LEFT_GEARMOTOR_PWD 5
#define LEFT_GEARMOTOR_AHEAD 6
#define LEFT_GEARMOTOR_REVERSE 7

#define RIGHT_GEARMOTOR_PWD 10
#define RIGHT_GEARMOTOR_AHEAD 8
#define RIGHT_GEARMOTOR_REVERSE 9

const unsigned long MIN_MOVE_TIME = 100;

Task stopLeftGearMotorTask(1000, TASK_IMMEDIATE, stopLeftGearMotor);
Task stopRightGearMotorTask(1000, TASK_IMMEDIATE, stopRightGearMotor);

boolean areInitializedGearMotors = false;

long currentSpeed = 0;

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
        currentSpeed = speed;
    }
}

void moveRightGearMotor(int speed) {
    stopRightGearMotorTask.disable();
    move(speed, RIGHT_GEARMOTOR_PWD, RIGHT_GEARMOTOR_AHEAD, RIGHT_GEARMOTOR_REVERSE);
    stopRightGearMotorTask.restartDelayed(MIN_MOVE_TIME);
}

void moveLeftGearMotor(int speed) {
    stopLeftGearMotorTask.disable();
    move(speed, LEFT_GEARMOTOR_PWD, LEFT_GEARMOTOR_AHEAD, LEFT_GEARMOTOR_REVERSE);
    stopLeftGearMotorTask.restartDelayed(MIN_MOVE_TIME);
}

void stop(int pwdPin, int aheadPin, int reversePin) {
    if (areInitializedGearMotors) {
        analogWrite(pwdPin, 0);
        digitalWrite(aheadPin, LOW);
        digitalWrite(reversePin, LOW);
    }
}

void stopLeftGearMotor() {
    stop(LEFT_GEARMOTOR_PWD, LEFT_GEARMOTOR_AHEAD, LEFT_GEARMOTOR_REVERSE);
    stopLeftGearMotorTask.disable();
}

void stopRightGearMotor() {
    stop(RIGHT_GEARMOTOR_PWD, RIGHT_GEARMOTOR_AHEAD, RIGHT_GEARMOTOR_REVERSE);
    stopRightGearMotorTask.disable();
}

#endif //_GEARMOTOR_H_

