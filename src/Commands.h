//
// Created by mrbueno on 29/03/19.
//

#ifndef ARDUINOTESTBT_COMMANDS_H
#define ARDUINOTESTBT_COMMANDS_H

#include <CmdMessenger.h>
#include "GearMotor.h"
#include "Debugger.h"

// This is the list of recognized commands. These can be commands that can either be sent or received.
// In order to receive, attach a callback function to these events
enum {
    LEFT_GEARMOTOR_COMMAND,
    RIGHT_GEARMOTOR_COMMAND,
    ACK_COMMAND,
};

CmdMessenger cmdMessenger = CmdMessenger(Serial);

void setCmdMessenger(CmdMessenger _cmdMessenger) {
    CmdMessenger cmdMessenger = _cmdMessenger;
}

// Called when a received command has no attached function
void OnUnknownCommand() {
    cmdMessenger.sendCmd(ACK_COMMAND, "OnUnknownCommand");
    debug("OnUnknownCommand");
}

void OnLeftWheelCommand() {

    const int16_t speed = cmdMessenger.readInt16Arg();

    if (!cmdMessenger.isArgOk()) {
        debug("Wrong args");
        return;
    }
    cmdMessenger.sendCmd(ACK_COMMAND, "OnLeftWheelCommand");
    moveLeftGearMotor(speed);
    debug("OnLeftWheelCommand", speed);
}

void OnRightWheelCommand() {

    const int16_t speed = cmdMessenger.readInt16Arg();

    if (!cmdMessenger.isArgOk()) {
        debug("Wrong args");
        return;
    }
    cmdMessenger.sendCmd(ACK_COMMAND, "OnRightWheelCommand");
    moveRightGearMotor(speed);
    debug("OnRightWheelCommand", speed);
}


// Callbacks define on which received commands we take action
void attachCommandCallbacks() {
    // Attach callback methods
    cmdMessenger.attach(OnUnknownCommand);
    cmdMessenger.attach(LEFT_GEARMOTOR_COMMAND, OnLeftWheelCommand);
    cmdMessenger.attach(RIGHT_GEARMOTOR_COMMAND, OnRightWheelCommand);
    debug("attachCommandCallbacks");
}


#endif //ARDUINOTESTBT_COMMANDS_H
