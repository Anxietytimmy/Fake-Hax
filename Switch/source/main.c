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
    // print A int text
    printf("`7MMXXYMM   db      7MMF   YMM  7MMXXXYMM     7MMF    7MMF      db      YMM     MP  \n");
    printf("  MM    `7 ;MM:      MM   .M'    MM    `7      MM      MM      ;MM:      VMb.  ,P   \n"); 
    printf("  MM   d  ,V^MM.     MM .d       MM   d        MM      MM     ,V^MM.      `MM.M'    \n"); 
    printf("  MM""MM ,M  `MM     MMMMM.      MMmmMM        MMmmmmmmMM    ,M  `MM        MMb     \n");
    printf("  MM   Y AbmmmqMA    MM  VMA     MM   Y  mmmmm MM      MM    AbmmmqMA     ,M'`Mb.   \n");
    printf("  MM    A'     VML   MM   `MM.   MM     ,M     MM      MM   A'     VML   ,P   `MM.  \n");
    printf(".JMML..AMA.   .AMMA.JMML.   MMb.JMMmmmmMMM   .JMML.  .JMML.AMA.   .AMMA.MM:.  .:MMa.\n");
    
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
