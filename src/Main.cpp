
#include <TaskScheduler.h>
#include "Commands.h"
#include "Debugger.h"
#include "Ultrasonic.h"

Scheduler scheduler;

void setup() {

    // Init sensors
    setupUltrasonic();
    initGearMotors();

    // Init Scheduler
    scheduler.init();
    scheduler.addTask(measureDistanceTask);
    //scheduler.addTask(stopLeftGearMotorTask);
    //scheduler.addTask(stopRightGearMotorTask);
    measureDistanceTask.enable();

    // Init Bluetooth
    Serial.begin(9600);

    // Init commands
    cmdMessenger.printLfCr();
    attachCommandCallbacks();
    cmdMessenger.sendCmd(ACK_COMMAND, "Vehicle has started!");

    debug("Setup end");
}

void loop() {
    scheduler.execute();
    // Process incoming //Serial data, and perform callbacks
    cmdMessenger.feedinSerialData();
}
