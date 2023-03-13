#ifndef __ESPUINO_SETTINGS_H__
    	#define __ESPUINO_SETTINGS_H__
        #include "Arduino.h"
        #include "values.h"
	#if __has_include("../config.h")
		#include "../config.h"
	#endif
#if __has_include("settings-override.h")
    	#include "settings-override.h"
#else

	//################## BUTTON-Layout ##################################
	/* German documentation: https://forum.espuino.de/t/das-dynamische-button-layout/224
	Please note the following numbers as you need to know them in order to define actions for buttons.
	Even if you don't use all of them, their numbers won't change
		0: NEXT_BUTTON
		1: PREVIOUS_BUTTON
		2: PAUSEPLAY_BUTTON
		3: ROTARYENCODER_BUTTON
		4: BUTTON_4
		5: BUTTON_5

	Don't forget to enable/configure those buttons you want to use in your develboard-specific config (e.g. settings-custom.h)

	Single-buttons [can be long or short] (examples):
		BUTTON_0_SHORT => Button 0 (NEXT_BUTTON) pressed shortly
		BUTTON_3_SHORT => Button 3 (ROTARYENCODER_BUTTON) pressed shortly
		BUTTON_4_LONG => Button 4 (BUTTON_4) pressed long

	Multi-buttons [short only] (examples):
		BUTTON_MULTI_01 => Buttons 0+1 (NEXT_BUTTON + PREVIOUS_BUTTON) pressed in parallel
		BUTTON_MULTI_12 => Buttons 1+2 (PREV_BUTTON + PAUSEPLAY_BUTTON) pressed in parallel

	Actions:
		To all of those buttons, an action can be assigned freely.
		Please have a look at values.h to look up actions available (>=100 can be used)
		If you don't want to assign an action or you don't use a given button: CMD_NOTHING has to be set
	*/
	// *****BUTTON*****        *****ACTION*****
	#define BUTTON_0_SHORT    CMD_NEXTTRACK
	#define BUTTON_1_SHORT    CMD_PREVTRACK
	#define BUTTON_2_SHORT    CMD_PLAYPAUSE
	#define BUTTON_3_SHORT    CMD_MEASUREBATTERY
	#define BUTTON_4_SHORT    CMD_SEEK_BACKWARDS
	#define BUTTON_5_SHORT    CMD_SEEK_FORWARDS

	#define BUTTON_0_LONG     CMD_LASTTRACK
	#define BUTTON_1_LONG     CMD_FIRSTTRACK
	#define BUTTON_2_LONG     CMD_PLAYPAUSE
	#define BUTTON_3_LONG     CMD_SLEEPMODE
	#define BUTTON_4_LONG     CMD_VOLUMEUP
	#define BUTTON_5_LONG     CMD_VOLUMEDOWN

	#define BUTTON_MULTI_01   CMD_NOTHING   //CMD_TOGGLE_WIFI_STATUS (disabled now to prevent children from unwanted WiFi-disable)
	#define BUTTON_MULTI_02   CMD_ENABLE_FTP_SERVER
	#define BUTTON_MULTI_03   CMD_NOTHING
	#define BUTTON_MULTI_04   CMD_NOTHING
	#define BUTTON_MULTI_05   CMD_NOTHING
	#define BUTTON_MULTI_12   CMD_TELL_IP_ADDRESS
	#define BUTTON_MULTI_13   CMD_NOTHING
	#define BUTTON_MULTI_14   CMD_NOTHING
	#define BUTTON_MULTI_15   CMD_NOTHING
	#define BUTTON_MULTI_23   CMD_NOTHING
	#define BUTTON_MULTI_24   CMD_NOTHING
	#define BUTTON_MULTI_25   CMD_NOTHING
	#define BUTTON_MULTI_34   CMD_NOTHING
	#define BUTTON_MULTI_35   CMD_NOTHING
	#define BUTTON_MULTI_45   CMD_NOTHING

	//#################### Various settings ##############################

	// Serial-logging-configuration
	#define SERIAL_LOGLEVEL LOGLEVEL_DEBUG              // Current loglevel for serial console

	// Buttons (better leave unchanged if in doubts :-))
	constexpr uint8_t buttonDebounceInterval = 50;                // Interval in ms to software-debounce buttons
	constexpr uint16_t intervalToLongPress = 700;                 // Interval in ms to distinguish between short and long press of buttons

	//#define CONTROLS_LOCKED_BY_DEFAULT			// If set the controls are locked at boot

	// FTP
	// Nothing to be configured here...
	// Default user/password is esp32/esp32 but can be changed via webgui

	// ESPuino will create a WiFi if joing existing WiFi was not possible. Name and password can be configured here.
	constexpr const char accessPointNetworkSSID[] PROGMEM = "ESPuino";     // Access-point's SSID
	constexpr const char accessPointNetworkPassword[] PROGMEM = "";        // Access-point's Password, at least 8 characters! Set to an empty string to spawn an open WiFi.

	// Bluetooth
	constexpr const char nameBluetoothSinkDevice[] PROGMEM = "ESPuino";        // Name of your ESPuino as Bluetooth-device
	constexpr const char nameBluetoothSourceDevice[] PROGMEM = "My POGS Wireless Headphone"; // Name of Bluetooth-device to connect to (BT-Headset name) (https://forum.espuino.de/t/neues-feature-bluetooth-kopfhoerer/1293/)

	// Where to store the backup-file for NVS-records
	constexpr const char backupFile[] PROGMEM = "/backup.txt"; // File is written every time a (new) RFID-assignment via GUI is done
	// Filename that is used for caching playlists
	// Arduino 1.0.6 uses ANSI / Arduino >=2.0.5 UTF-8 encoding. Use different filenames to avoid incompabilities
	#if ESP_ARDUINO_VERSION_MAJOR >= 2
		constexpr const char playlistCacheFile[] PROGMEM = "playlistcache2.csv"; 
	#else
		constexpr const char playlistCacheFile[] PROGMEM = "playlistcache.csv";  
	#endif

	#if defined(CONFIG_MEASURE_BATTERY_VOLTAGE) || defined(CONFIG_MEASURE_BATTERY_MAX17055)
		#define BATTERY_MEASURE_ENABLE                 // Don't change. Set automatically if any method of battery monitoring is selected.
		constexpr uint8_t s_batteryCheckInterval = 10; // How often battery is measured (in minutes) (can be changed via GUI!)
	#endif

	#ifdef CONFIG_MEASURE_BATTERY_VOLTAGE
		// (optional) Default-voltages for battery-monitoring via Neopixel; can be changed later via WebGUI
		constexpr float s_warningLowVoltage = 3.4;                      // If battery-voltage is <= this value, a cyclic warning will be indicated by Neopixel (can be changed via GUI!)
		constexpr float s_warningCriticalVoltage = 3.1;                 // If battery-voltage is <= this value, assume battery near-empty. Set to 0V to disable.
		constexpr float s_voltageIndicatorLow = 3.0;                    // Lower range for Neopixel-voltage-indication (0 leds) (can be changed via GUI!)
		constexpr float s_voltageIndicatorHigh = 4.2;                   // Upper range for Neopixel-voltage-indication (all leds) (can be changed via GUI!)
	#endif

	#ifdef CONFIG_MEASURE_BATTERY_MAX17055
		constexpr float s_batteryLow = 15.0;            // low percentage
		constexpr float s_batteryCritical = 5.0;        // critical percentage

		constexpr uint16_t s_batteryCapacity = 6000;    // design cap of battery (mAh)
		constexpr uint16_t s_emptyVoltage = 300;        // empty voltage in 10mV
		constexpr uint16_t s_recoveryVoltage = 360;     // recovery voltage in 10mV
		constexpr uint8_t  s_batteryChemistry = 0x60;   // 0 = Li-Ion, 0x20 = NCR, 0x60 = LiFePO4
		constexpr float s_resistSensor = 0.01;          // current sense resistor, currently non-default values might lead to problems
		constexpr bool s_vCharge = false;                   // true if charge voltage is greater than 4.275V
	#endif

	// enable I2C if necessary
	#if defined(CONFIG_RFID_READER_MFRC522_I2C) || defined(CONFIG_PORT_EXPANDER) || defined(CONFIG_MEASURE_BATTERY_MAX17055)
		#define I2C_2_ENABLE
	#endif

	// (optinal) Headphone-detection (leave unchanged if in doubts...)
	#ifdef CONFIG_HEADPHONE_ADJUST
		constexpr uint16_t headphoneLastDetectionDebounce = 1000; // Debounce-interval in ms when plugging in headphone
	#endif

	// Seekmode-configuration
	constexpr uint8_t jumpOffset = 30;                            // Offset in seconds to jump for commands CMD_SEEK_FORWARDS / CMD_SEEK_BACKWARDS

	// (optional) Topics for MQTT
	#ifdef MQTT_ENABLE
		constexpr uint16_t mqttRetryInterval = 60;                // Try to reconnect to MQTT-server every (n) seconds if connection is broken
		constexpr uint8_t mqttMaxRetriesPerInterval = 1;          // Number of retries per time-interval (mqttRetryInterval). mqttRetryInterval 60 / mqttMaxRetriesPerInterval 1 => once every 60s
		#define DEVICE_HOSTNAME "ESP32-ESPuino"         // Name that is used for MQTT
		constexpr const char topicSleepCmnd[] PROGMEM = "Cmnd/ESPuino/Sleep";
		constexpr const char topicSleepState[] PROGMEM = "State/ESPuino/Sleep";
		constexpr const char topicRfidCmnd[] PROGMEM = "Cmnd/ESPuino/Rfid";
		constexpr const char topicRfidState[] PROGMEM = "State/ESPuino/Rfid";
		constexpr const char topicTrackState[] PROGMEM = "State/ESPuino/Track";
		constexpr const char topicTrackControlCmnd[] PROGMEM = "Cmnd/ESPuino/TrackControl";
		constexpr const char topicCoverChangedState[] PROGMEM = "State/ESPuino/CoverChanged";
		constexpr const char topicLoudnessCmnd[] PROGMEM = "Cmnd/ESPuino/Loudness";
		constexpr const char topicLoudnessState[] PROGMEM = "State/ESPuino/Loudness";
		constexpr const char topicSleepTimerCmnd[] PROGMEM = "Cmnd/ESPuino/SleepTimer";
		constexpr const char topicSleepTimerState[] PROGMEM = "State/ESPuino/SleepTimer";
		constexpr const char topicState[] PROGMEM = "State/ESPuino/State";
		constexpr const char topicCurrentIPv4IP[] PROGMEM = "State/ESPuino/IPv4";
		constexpr const char topicLockControlsCmnd[] PROGMEM ="Cmnd/ESPuino/LockControls";
		constexpr const char topicLockControlsState[] PROGMEM ="State/ESPuino/LockControls";
		constexpr const char topicPlaymodeState[] PROGMEM = "State/ESPuino/Playmode";
		constexpr const char topicRepeatModeCmnd[] PROGMEM = "Cmnd/ESPuino/RepeatMode";
		constexpr const char topicRepeatModeState[] PROGMEM = "State/ESPuino/RepeatMode";
		constexpr const char topicLedBrightnessCmnd[] PROGMEM = "Cmnd/ESPuino/LedBrightness";
		constexpr const char topicLedBrightnessState[] PROGMEM = "State/ESPuino/LedBrightness";
		constexpr const char topicWiFiRssiState[] PROGMEM = "State/ESPuino/WifiRssi";
		constexpr const char topicSRevisionState[] PROGMEM = "State/ESPuino/SoftwareRevision";
		#ifdef BATTERY_MEASURE_ENABLE
		constexpr const char topicBatteryVoltage[] PROGMEM = "State/ESPuino/Voltage";
		constexpr const char topicBatterySOC[] PROGMEM     = "State/ESPuino/Battery";
		#endif
	#endif

	// !!! MAKE SURE TO EDIT PLATFORM SPECIFIC settings-****.h !!!
	#ifdef CONFIG_BOARD_LOLIN32
		#include "settings-lolin32.h"                       // Contains all user-relevant settings for Wemos Lolin32
	#elif CONFIG_BOARD_AUDIO_KIT
		#include "settings-espa1s.h"                        // Contains all user-relevant settings for ESP32-A1S Audiokit
	#elif CONFIG_BOARD_LOLIN_D32
		#include "settings-lolin_d32.h"                     // Contains all user-relevant settings for Wemos Lolin D32
	#elif CONFIG_BOARD_LOLIN_D32_PRO
		#include "settings-lolin_d32_pro.h"                 // Contains all user-relevant settings for Wemos Lolin D32 pro
	#elif CONFIG_BOARD_TTGO_T8
		#include "settings-ttgo_t8.h"                       // Contains all user-relevant settings for Lilygo TTGO T8 1.7
	#elif CONFIG_BOARD_COMPLETE
		#include "settings-complete.h"                      // Contains all user-relevant settings for ESPuino complete
	#elif CONFIG_BOARD_NODEMCU_DEVKIT
		#include "settings-azdelivery_sdmmc.h"              // Pre-configured settings for AZ Delivery ESP32 NodeMCU / Devkit C (https://forum.espuino.de/t/az-delivery-esp32-nodemcu-devkit-c-mit-sd-mmc-und-pn5180-als-rfid-leser/634)
	#elif CONFIG_BOARD_MUSE_PROTO
		#include "settings-muse_proto.h"                     // Pre-configured settings for Raspiaudio ESPMuse Proto Board with I2C RFID Reader (https://raspiaudio.com/produit/muse-proto)
	#endif

	//#define ENABLE_ESPUINO_DEBUG                            // Needs modification of platformio.ini (https://forum.espuino.de/t/rfid-mit-oder-ohne-task/353/21); better don't enable unless you know what you're doing :-)
	#endif //settings_override
#endif
