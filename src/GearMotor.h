//
// Created by mrbueno on 29/03/19.
//

#ifndef ARDUINOTESTBT_GEARMOTOR_H
#define ARDUINOTESTBT_GEARMOTOR_H


#include <TaskScheduler.h>

class GearMotor {

//#define WHEEL1_PWD 5
//#define WHEEL1_AHEAD     6
//#define WHEEL1_REVERSE 7
//
//#define WHEEL2_PWD 10
//#define WHEEL2_AHEAD 8
//#define WHEEL2_REVERSE 9

const unsigned long MIN_MOVE_TIME = 100;

    uint8_t pwdPin;
    uint8_t aheadPin;
    uint8_t reversePin;

    bool isInit = false;

public:
    GearMotor(uint8_t pwdPin, uint8_t aheadPin, uint8_t reversePin);

    Task stopLeftWheelsTask;

    void init();
    void move(int speed);
    void stop();
};


#endif //ARDUINOTESTBT_GEARMOTOR_H
