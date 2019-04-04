//
// Created by mrbueno on 4/04/19.
//

#ifndef ARDUINOTESTBT_HC_SR04_SENSOR_H
#define ARDUINOTESTBT_HC_SR04_SENSOR_H

#include <TaskSchedulerDeclarations.h>
#include "HC_SR04.h"
#include "HC_SR04SensorCallback.h"
#include "GearMotor.h"
#include "Commands.h"

#define TRIG_PIN 3
#define ECHO_PIN 2
#define ECHO_INT 0

HC_SR04 distanceSensor(TRIG_PIN, ECHO_PIN, ECHO_INT);

Task measureObstacleDistanceTask(500, TASK_FOREVER, measureObstacleDistance);

void measureObstacleDistance() {
    if (goingForward) {
        distanceSensor.start();
        while(!distanceSensor.isFinished()) continue;
        //Serial.print(distanceSensor.getRange());
        //Serial.println("cm");
        const unsigned int range = distanceSensor.getRange();
        if(10 > range || range > 2000) {
            moveRightGearMotor(0);
            moveLeftGearMotor(0);
            cmdMessenger.sendCmd(ACK_COMMAND, range);
        }
    } else {
        cmdMessenger.sendCmd(ACK_COMMAND, "avoid measure");
    }
}

#endif //ARDUINOTESTBT_HC_SR04_SENSOR_H
