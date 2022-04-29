// Include the nessecary libs 
#include <switch.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include <unistd.h>

// Main program entrypoint
int main(int argc, char* argv[])
{
    // This example uses a text console, as a simple way to output text to the screen.
    consoleInit(NULL);

    // Configure our supported input layout: a single player with standard controller styles
    padConfigureInput(1, HidNpadStyleSet_NpadStandard);

    // Initialize the default gamepad (which reads handheld mode inputs as well as the first connected controller)
    PadState pad;
    padInitializeDefault(&pad);
    // Print out ASCI art                       
    // I have no clue why it spits out garbage ¯\_(ツ)_/¯
    // It prints but the letters get out of order very quickly
    // Might have something to do with the slanted letters but other than that I dunno 
    // Gonna comment this out for now, just going to use regular text
    // printf("    _________    __ __ ______     __  _____   _  __      _   ___  __\n");
    // printf("   / ____/   |  / //_// ____/    / / / /   | | |/ /     / | / / |/ /\n"); 
    // printf("  / /_  / /| | / ,<  / __/______/ /_/ / /| | |   /_____/  |/ /|   / \n"); 
    // printf(" / __/ / ___ |/ /| |/ /__/_____/ __  / ___ |/   /_____/ /|  //   |  \n");
    // printf("/_/   /_/  |_/_/ |_/_____/    /_/ /_/_/  |_/_/|_|    /_/ |_//_/|_|  \n");
    printf("Fake-Hax-NX\n");
    printf("Press A to continue\n");
    printf("As of now, this app is very POC, so if you want to try it out now, its probably just gonna print out random things with button presses.\n");
    if (kDown & HidNpadButton_A);
        printf("Uploading payload, please wait");
    // Main loop
    while (appletMainLoop())
    {
        // Scan the gamepad. This should be done once for each frame
        padUpdate(&pad);

        // padGetButtonsDown returns the set of buttons that have been
        // newly pressed in this frame compared to the previous one
        u64 kDown = padGetButtonsDown(&pad);


        if (kDown & HidNpadButton_Plus)
            break; // break in order to return to hbmenu

        // Update the console, sending a new frame to the display
        consoleUpdate(NULL);
    }

    // Deinitialize and clean up resources used by the console (important!)
    consoleExit(NULL);
    return 0;
}
