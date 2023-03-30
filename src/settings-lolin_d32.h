#ifndef __ESPUINO_SETTINGS_LOLIN_D32_H__
#define __ESPUINO_SETTINGS_LOLIN_D32_H__
    #include "Arduino.h"

    //######################### INFOS ####################################
    /* This is a develboard-specific config-file for *Wemos Lolin D32*. Specific doesn't mean it's only working with this board.
    Lolin D32 is the successor of Lolin32 and the "little brother" of Wemos Lolin D32 pro.
    PCB: https://github.com/biologist79/ESPuino/tree/master/PCBs/Wemos%20Lolin%20D32
    Infos: https://www.wemos.cc/en/latest/d32/d32.html
    Schematics: https://www.wemos.cc/en/latest/_static/files/sch_d32_v1.0.0.pdf
    Caveats: GPIO35 (battery monitoring) can't be changed, it's built in
    Status:
        tested with 2x SPI: RC522 & SD (by biologist79)
    */


    //################## GPIO-configuration ##############################
    // Please note: GPIOs 34, 35, 36, 39 are input-only and don't have pullup-resistors.
    // So if connecting a button to these, make sure to add a 10k-pullup-resistor for each button.
    // Further infos: https://randomnerdtutorials.com/esp32-pinout-reference-gpios/

    // (optinal) Headphone-detection
    #ifdef CONFIG_HEADPHONE_ADJUST
        //#define DETECT_HP_ON_HIGH                       // Per default headphones are supposed to be connected if HT_DETECT is LOW. DETECT_HP_ON_HIGH will change this behaviour to HIGH.
        #define HP_DETECT                   22          // GPIO that detects, if there's a plug in the headphone jack or not
    #endif

    // (optional) Monitoring of battery-voltage via ADC
    #ifdef CONFIG_MEASURE_BATTERY_VOLTAGE
        #define VOLTAGE_READ_PIN            35          // Cannot be changed, it's built in
        constexpr float referenceVoltage = 3.30;                  // Voltage between 3.3V and GND-pin at the develboard in battery-mode (disconnect USB!)
        constexpr float offsetVoltage = 0.2;                      // If voltage measured by ESP isn't 100% accurate, you can add an correction-value here
    #endif

    #ifdef CONFIG_MEASURE_BATTERY_VOLTAGE
        constexpr uint16_t rdiv1 = 100;                           // Cannot be changed, it's built in
        constexpr uint16_t rdiv2 = 100;                           // Cannot be changed, it's built in
    #endif

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
