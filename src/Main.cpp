// *** SentandReceive ***

// This example expands the previous Receive example. The Arduino will now send back a status.
// It adds a demonstration of how to:
// - Handle received commands that do not have a function attached
// - Send a command with a parameter to the PC

#include <CmdMessenger.h>  // CmdMessenger
#include <SoftwareSerial.h>

// Blinking led variables
bool ledState                   = 0;   // Current state of Led
const int kBlinkLed             = 8;  // Pin of internal Led

SoftwareSerial Bluetooth(2,3);

// Attach a new CmdMessenger object to the default Bluetooth port
CmdMessenger cmdMessenger = CmdMessenger(Bluetooth);

// This is the list of recognized commands. These can be commands that can either be sent or received.
// In order to receive, attach a callback function to these events
enum
{
    kSetLed              , // Command to request led to be set in specific state
    kStatus              , // Command to report status
};

// Called when a received command has no attached function
void OnUnknownCommand()
{
    cmdMessenger.sendCmd(kStatus,"Command without attached callback");
}

// Callback function that sets led on or off
void OnSetLed()
{
    // Read led state argument, interpret string as boolean
    ledState = cmdMessenger.readBoolArg();
    // Set led
    digitalWrite(kBlinkLed, ledState?HIGH:LOW);
    // Send back status that describes the led state
    cmdMessenger.sendCmd(kStatus,(int)ledState);
}

// Callbacks define on which received commands we take action
void attachCommandCallbacks()
{
    // Attach callback methods
    cmdMessenger.attach(OnUnknownCommand);
    cmdMessenger.attach(kSetLed, OnSetLed);
}



// Setup function
void setup()
{
    // Listen on serial connection for messages from the PC
    Bluetooth.begin(9600);

    // Adds newline to every command
    // Do not send LFCR from the other party
    cmdMessenger.printLfCr();

    // Attach my application's user-defined callback methods
    attachCommandCallbacks();

    // Send the status to the PC that says the Arduino has booted
    // Note that this is a good debug function: it will let you also know
    // if your program had a bug and the arduino restarted
    cmdMessenger.sendCmd(kStatus,"Arduino has started!");

    // set pin for blink LED
    pinMode(kBlinkLed, OUTPUT);
}

// Loop function
void loop()
{
    // Process incoming serial data, and perform callbacks
    cmdMessenger.feedinSerialData();
}


