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
    printf("  ______    _               _    _                   _   ___   __\n");
    printf(" |  ____|  | |             | |  | |                 | \ | \ \ / /\n"); 
    printf(" | |__ __ _| | _____ ______| |__| | __ ___  ________|  \| |\ V / \n"); 
    printf(" |  __/ _` | |/ / _ \______|  __  |/ _` \ \/ /______| . ` | > <  \n");
    printf(" | | | (_| |   <  __/      | |  | | (_| |>  <       | |\  |/ . \ \n");
    printf(" |_|  \__,_|_|\_\___|      |_|  |_|\__,_/_/\_\      |_| \_/_/ \_\\n");
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
