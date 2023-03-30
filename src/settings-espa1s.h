#ifndef __ESPUINO_SETTINGS_ESPA1S_H__
#define __ESPUINO_SETTINGS_ESPA1S_H__
    #include "Arduino.h"

    //######################### INFOS ####################################
    /* This is a develboard-specific config-file for *AI Tinker ESP32-A1S-AudioKit*. It's highly customized and almost certainly
    not suitable for a different develboard.
    Has a lot of stuff already onboard but needs some soldering rework as there are not all GPIOs exposed.
    PCB: Not necessary.
    Infos: https://github.com/Ai-Thinker-Open/ESP32-A1S-AudioKit
           https://forum.espuino.de/t/esp32-audio-kit-esp32-a1s/106
    Status: tested by kkloesner with RC522-I2C
    */


    //################## GPIO-configuration ##############################
    // SD
    // Make sure to enable CONFIG_SD_MMC_1BIT_MODE! GPIOs 2, 14, 15 are used therefore. Make sure to not assign them elsewhere!

    // I2C (AC101)
    #define IIC_CLK                         32          // internal
    #define IIC_DATA                        33          // internal

    // (Optional) remote control via infrared
    #ifdef CONFIG_IR_CONTROL
        #define IRLED_PIN                   22              // GPIO where IR-receiver is connected (only tested with VS1838B)
        #define IR_DEBOUNCE                 200             // Interval in ms to wait at least for next signal (not used for actions volume up/down)

        // Actions available. Use your own remote control and have a look at the console for "Command=0x??". E.g. "Protocol=NEC Address=0x17F Command=0x68 Repeat gap=39750us"
        // Make sure to define a hex-code not more than once as this will lead to a compile-error
        // https://forum.espuino.de/t/neues-feature-fernsteuerung-per-infrarot-fernbedienung/265
        #define RC_PLAY                     0x68            // command for play
        #define RC_PAUSE                    0x67            // command for pause
        #define RC_NEXT                     0x6b            // command for next track of playlist
        #define RC_PREVIOUS                 0x6a            // command for previous track of playlist
        #define RC_FIRST                    0x6c            // command for first track of playlist
        #define RC_LAST                     0x6d            // command for last track of playlist
        #define RC_VOL_UP                   0x1a            // Command for volume up (one step)
        #define RC_VOL_DOWN                 0x1b            // Command for volume down (one step)
        #define RC_MUTE                     0x1c            // Command to mute ESPuino
        #define RC_SHUTDOWN                 0x2a            // Command for deepsleep
        #define RC_BLUETOOTH                0x72            // Command to enable/disable bluetooth
        #define RC_FTP                      0x65            // Command to enable FTP-server
    #endif
#endif
