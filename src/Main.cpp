
#include <CmdMessenger.h>
#include <SoftwareSerial.h>
#include <stdlib.h>

SoftwareSerial Bluetooth(2, 3);

// Attach a new CmdMessenger object to the default Bluetooth port
CmdMessenger cmdMessenger = CmdMessenger(Bluetooth);

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
        Serial.println(msg);
    }
}

void debug(const char *msg, int16_t value) {
    if (enableDebug) {
        char buffer[64] = "";
        sprintf (buffer, "%s with %d", msg, value);
        Serial.println(buffer);
    }
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
    debug("OnLeftWheelCommand", speed);
}

void OnRightWheelCommand() {

    const int16_t speed = cmdMessenger.readInt16Arg();

    if (!cmdMessenger.isArgOk()) {
        debug("Wrong args");
        return;
    }
    cmdMessenger.sendCmd(ACK, "OnRightWheelCommand");
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
    Serial.begin(9600);

    // Listen on serial connection for messages from the PC
    Bluetooth.setTimeout(100);
    Bluetooth.begin(9600);

    // Adds newline to every command
    // Do not send LFCR from the other party
    cmdMessenger.printLfCr();

    // Attach my application's user-defined callback methods
    attachCommandCallbacks();

    // Send the status to the PC that says the Arduino has booted
    // Note that this is a good debug function: it will let you also know
    // if your program had a bug and the arduino restarted
    cmdMessenger.sendCmd(ACK, "Vehicle has started!");

    debug("Setup end");
}

// Loop function
void loop() {
    // Process incoming serial data, and perform callbacks
    cmdMessenger.feedinSerialData();
}
