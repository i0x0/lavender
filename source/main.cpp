/**
*  @file    main.cpp
 *  @author  i0x0
 *  @date    2024-06-30
 *  @version 0.0.1
 *
 *  This is the main file for cpp_test.
 *  Original example file by WerWolv.
 */

#include <switch.h>     //The nxlib header file. It includes the functions which allow you to talk to the switch software/hardware
#include <stdio.h>      //Used for printf
#include <borealis.hpp>
#include <iostream>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <sys/errno.h>
#include <unistd.h>
#include "Bitcoin.h"
#include "PSBT.h"

using namespace std;

char mnemonic[] = "flight canvas heart purse potato mixed offer tooth maple blue kitten salute almost staff physical remain coral clump midnight rotate innocent shield inch ski";

//The main entry point
int main(int argc, char **argv) {

    consoleInit(nullptr);
    // Sets up the network sockets for nxlink
    printf("point 1.5\n");
    printf("\x1b[16;20point 2\n");

    socketInitializeDefault();

    // Sets up printf to be passed to our nxlink server on the computer
     nxlinkStdio();

    // Setup the console


    padConfigureInput(1, HidNpadStyleSet_NpadStandard);

    // Initialize the default gamepad (which reads handheld mode inputs as well as the first connected controller)
    PadState pad;
    padInitializeDefault(&pad);

//    printf("Hello World!\n");
    printf("\x1b[16;20tthe start of something terrible!\n");
    HDPrivateKey hd(mnemonic, "");
    printf(string(hd).c_str());
    // Our main loop. As long as the program shouldn't close, keep executing our code
    while (appletMainLoop()) {
        padUpdate(&pad);

        // padGetButtonsDown returns the set of buttons that have been
        // newly pressed in this frame compared to the previous one
        u64 kDown = padGetButtonsDown(&pad);

        if (kDown & HidNpadButton_Plus)
            break; // break in order to return to hbmenu

        // Your code goes here

        // Update the console, sending a new frame to the display
        consoleUpdate(NULL);
    }

    //Clean up after we're done and close our sockets.
//    socketExit();
    //Terminate SUCCESSFULLY
    consoleExit(nullptr);
    return 0;
}
