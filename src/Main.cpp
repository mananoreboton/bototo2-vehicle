
#include <CmdMessenger.h>
#include <TaskScheduler.h>
#include "Main.h"

//SoftwareSerial Bluetooth(2, 3);   º

// Attach a new CmdMessenger object to the default Bluetooth port
CmdMessenger cmdMessenger = CmdMessenger(Serial);

Scheduler scheduler;

#define WHEEL1_PWD 5
#define WHEEL1_AHEAD     6
#define WHEEL1_REVERSE 7

#define WHEEL2_PWD 10
#define WHEEL2_AHEAD 8
#define WHEEL2_REVERSE 9

// This is the list of recognized commands. These can be commands that can either be sent or received.
// In order to receive, attach a callback function to these events
enum {
    LEFT_WHEEL,
    RIGHT_WHEEL,
    ACK,
};

bool enableDebug = true;

void debug(const char *msg) {
    if (enableDebug) {
        //Serial.println(msg);
    }
}

void debug(const char *msg, int16_t value) {
    if (enableDebug) {
        char buffer[64] = "";
        sprintf(buffer, "%s with %d", msg, value);
        //Serial.println(buffer);
    }
}

void initWheels() {
    pinMode(WHEEL1_PWD, OUTPUT);
    pinMode(WHEEL1_AHEAD, OUTPUT);
    pinMode(WHEEL1_REVERSE, OUTPUT);
    pinMode(WHEEL2_PWD, OUTPUT);
    pinMode(WHEEL2_AHEAD, OUTPUT);
    pinMode(WHEEL2_REVERSE, OUTPUT);
}

Task stopLeftWheelsTask(1000, TASK_ONCE, &stopLeftWheels);
Task stopRightWheelsTask(1000, TASK_ONCE, &stopRightWheels);

unsigned long MIN_MOVE_TIME = 100;

void stopLeftWheels() {
    analogWrite(WHEEL1_PWD, 0);
    digitalWrite(WHEEL1_AHEAD, LOW);
    digitalWrite(WHEEL1_REVERSE, LOW);
    stopLeftWheelsTask.disable();
}

void stopRightWheels() {
    analogWrite(WHEEL2_PWD, 0);
    digitalWrite(WHEEL2_AHEAD, LOW);
    digitalWrite(WHEEL2_REVERSE, LOW);
    stopRightWheelsTask.disable();
}

void moveLeftWheel(int speed) {
    stopLeftWheelsTask.disable();
    analogWrite(WHEEL1_PWD, 100);
    if (speed > 0) {
        digitalWrite(WHEEL1_AHEAD, HIGH);
        digitalWrite(WHEEL1_REVERSE, LOW);
    } else if (speed < 0) {
        digitalWrite(WHEEL1_AHEAD, LOW);
        digitalWrite(WHEEL1_REVERSE, HIGH);
    }
    //delay(1000);
    //stopLeftWheels();

    //stopLeftWheelsTask.enableDelayed(1000);
    stopLeftWheelsTask.restartDelayed(MIN_MOVE_TIME);
}

void moveRightWheel(int speed) {
    stopRightWheelsTask.disable();
    analogWrite(WHEEL2_PWD, 100);
    if (speed > 0) {
        digitalWrite(WHEEL2_AHEAD, HIGH);
        digitalWrite(WHEEL2_REVERSE, LOW);
    } else if (speed < 0) {
        digitalWrite(WHEEL2_AHEAD, LOW);
        digitalWrite(WHEEL2_REVERSE, HIGH);
    }
    //delay(1000);
    //stopRightWheels();
    //stopRightWheelsTask.enableDelayed(1000);
    stopRightWheelsTask.restartDelayed(MIN_MOVE_TIME);
}

// Called when a received command has no attached function
void OnUnknownCommand() {
    cmdMessenger.sendCmd(ACK, "OnUnknownCommand");
    debug("OnUnknownCommand");
}

void OnLeftWheelCommand() {

    const int16_t speed = cmdMessenger.readInt16Arg();

    if (!cmdMessenger.isArgOk()) {
        debug("Wrong args");
        return;
    }
    cmdMessenger.sendCmd(ACK, "OnLeftWheelCommand");
    moveLeftWheel(speed);
    debug("OnLeftWheelCommand", speed);
}

void OnRightWheelCommand() {

    const int16_t speed = cmdMessenger.readInt16Arg();

    if (!cmdMessenger.isArgOk()) {
        debug("Wrong args");
        return;
    }
    cmdMessenger.sendCmd(ACK, "OnRightWheelCommand");
    moveRightWheel(speed);
    debug("OnRightWheelCommand", speed);
}

// Callbacks define on which received commands we take action
void attachCommandCallbacks() {
    // Attach callback methods
    cmdMessenger.attach(OnUnknownCommand);
    cmdMessenger.attach(LEFT_WHEEL, OnLeftWheelCommand);
    cmdMessenger.attach(RIGHT_WHEEL, OnRightWheelCommand);
    debug("attachCommandCallbacks");

}


// Setup function
void setup() {
    scheduler.init();
    scheduler.addTask(stopLeftWheelsTask);
    scheduler.addTask(stopRightWheelsTask);
    //Serial.begin(9600);

    // Listen on //Serial connection for messages from the PC
    //Serial.setTimeout(100);
    Serial.begin(9600);

    // Adds newline to every command
    // Do not send LFCR from the other party
    cmdMessenger.printLfCr();

    // Attach my application's user-defined callback methods
    attachCommandCallbacks();

    initWheels();

    // Send the status to the PC that says the Arduino has booted
    // Note that this is a good debug function: it will let you also know
    // if your program had a bug and the arduino restarted
    cmdMessenger.sendCmd(ACK, "Vehicle has started!");

    debug("Setup end");
}

// Loop function
void loop() {
    scheduler.execute();
    // Process incoming //Serial data, and perform callbacks
    cmdMessenger.feedinSerialData();
}
