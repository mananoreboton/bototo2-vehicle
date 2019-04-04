
#include <TaskScheduler.h>
#include "Commands.h"
#include "Debugger.h"

//SoftwareSerial Bluetooth(2, 3);   º

// Attach a new CmdMessenger object to the default Bluetooth port

// Setup function
void setup() {
    //scheduler.addTask(stopLeftGearMotorTask);
    //scheduler.addTask(stopRightGearMotorTask);
    //Serial.begin(9600);

    // Listen on //Serial connection for messages from the PC
    //Serial.setTimeout(100);
    Serial.begin(9600);

    // Adds newline to every command
    // Do not send LFCR from the other party
    cmdMessenger.printLfCr();

    // Attach my application's user-defined callback methods
    attachCommandCallbacks();

    initGearMotors();

    // Send the status to the PC that says the Arduino has booted
    // Note that this is a good debug function: it will let you also know
    // if your program had a bug and the arduino restarted
    cmdMessenger.sendCmd(ACK_COMMAND, "Vehicle has started!");

    debug("Setup end");
}

// Loop function
void loop() {
    // Process incoming //Serial data, and perform callbacks
    cmdMessenger.feedinSerialData();
}
