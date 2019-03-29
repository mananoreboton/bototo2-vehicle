//
// Created by mrbueno on 29/03/19.
//

#ifndef ARDUINOTESTBT_DEBUGGER_H
#define ARDUINOTESTBT_DEBUGGER_H

#include <HID.h>

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

#endif //ARDUINOTESTBT_DEBUGGER_H
