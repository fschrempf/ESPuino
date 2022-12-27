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
	//######################### INFOS ####################################
	// This is the general configfile for ESPuino-configuration.

	//################## HARDWARE-PLATFORM ###############################
	/* Make sure to also edit the configfile, that is specific for your platform.
	If in doubts (your develboard is not listed) use HAL 1
	1: Wemos Lolin32                        => settings-lolin32.h
	2: ESP32-A1S Audiokit                   => settings-espa1s.h
	3: Wemos Lolin D32                      => settings-lolin_D32.h
	4: Wemos Lolin D32 pro                  => settings-lolin_D32_pro.h
	5: Lilygo T8 (V1.7)                     => settings-ttgo_t8.h
	6: ESPuino complete                     => settings-complete.h
	7: Lolin D32 pro SDMMC Port-Expander    => settings-lolin_d32_pro_sdmmc_pe.h
	8: AZDelivery ESP32 NodeMCU             => settings-azdelivery_sdmmc.h
	9: Lolin D32 SDMMC Port-Expander        => settings-lolin_d32_sdmmc_pe.h
	10: RASPIAUDIO Muse Proto               => settings-muse_proto.h
	99: custom                              => settings-custom.h
	more to come...
	*/
	#ifndef HAL             // Will be set by platformio.ini. If using Arduino-IDE you have to set HAL according your needs!
		#define HAL 1       // HAL 1 = LoLin32, 2 = ESP32-A1S-AudioKit, 3 = Lolin D32, 4 = Lolin D32 pro; ... 99 = custom
	#endif


	//########################## MODULES #################################
	#define SHUTDOWN_IF_SD_BOOT_FAILS       // Will put ESP to deepsleep if boot fails due to SD. Really recommend this if there's in battery-mode no other way to restart ESP! Interval adjustable via deepsleepTimeAfterBootFails.
	#define MEASURE_BATTERY_VOLTAGE         // Enables battery-measurement via GPIO (ADC) and voltage-divider
	//#define MEASURE_BATTERY_MAX17055      // Enables battery-measurement via external fuel gauge (MAX17055)
	//#define SHUTDOWN_ON_BAT_CRITICAL      // Whether to turn off on critical battery-level (only used if MEASURE_BATTERY_XXX is active)
	//#define PLAY_LAST_RFID_AFTER_REBOOT   // When restarting ESPuino, the last RFID that was active before, is recalled and played
	#define USEROTARY_ENABLE                // If rotary-encoder is used (don't forget to review WAKEUP_BUTTON if you disable this feature!)
	#define BLUETOOTH_ENABLE                // If enabled and bluetooth-mode is active, you can stream to your ESPuino via bluetooth (a2dp-sink).
	//#define IR_CONTROL_ENABLE             // Enables remote control (https://forum.espuino.de/t/neues-feature-fernsteuerung-per-infrarot-fernbedienung/265)
	//#define PAUSE_WHEN_RFID_REMOVED       // Playback starts when card is applied and pauses automatically, when card is removed (https://forum.espuino.de/t/neues-feature-pausieren-wenn-rfid-karte-entfernt-wurde/541)
	//#define PAUSE_ON_MIN_VOLUME           // When playback is active and volume is changed to zero, playback is paused automatically. Playback is continued if volume reaches 1. (https://forum.espuino.de/t/neues-feature-pausieren-wenn-rfid-karte-entfernt-wurde/541)
	//#define DONT_ACCEPT_SAME_RFID_TWICE   // RFID-reader doesn't accept the same RFID-tag twice in a row (unless it's a modification-card or RFID-tag is unknown in NVS). Flag will be ignored silently if PAUSE_WHEN_RFID_REMOVED is active. (https://forum.espuino.de/t/neues-feature-dont-accept-same-rfid-twice/1247)
	//#define HALLEFFECT_SENSOR_ENABLE      // Support for hallsensor. For fine-tuning please adjust HallEffectSensor.h Please note: only user-support provided (https://forum.espuino.de/t/magnetische-hockey-tags/1449/35)

	//################## set PAUSE_WHEN_RFID_REMOVED behaviour #############################
	#ifdef PAUSE_WHEN_RFID_REMOVED
		#define ACCEPT_SAME_RFID_AFTER_TRACK_END           // Accepts same RFID after playback has ended (https://forum.espuino.de/t/neues-feature-pausieren-wenn-rfid-karte-entfernt-wurde/541/2)
	#endif

	//################## select SD card mode #############################
	#define SD_MMC_1BIT_MODE              // run SD card in SD-MMC 1Bit mode (using GPIOs 15 + 14 + 2 is mandatory!)
	//#define SINGLE_SPI_ENABLE             // If only one SPI-instance should be used instead of two (not yet working!)


	//################## select RFID reader ##############################
	#define RFID_READER_TYPE_MFRC522_SPI    // use MFRC522 via SPI
	//#define RFID_READER_TYPE_MFRC522_I2C  // use MFRC522 via I2C
	//#define RFID_READER_TYPE_PN5180       // use PN5180 via SPI

	#ifdef RFID_READER_TYPE_MFRC522_I2C
		#define MFRC522_ADDR 0x28           // default I2C-address of MFRC522
	#endif

	#ifdef RFID_READER_TYPE_PN5180
		//#define PN5180_ENABLE_LPCD        // Wakes up ESPuino if RFID-tag was applied while deepsleep is active. Only ISO-14443-tags are supported for wakeup!
	#endif

	#if defined(RFID_READER_TYPE_MFRC522_I2C) || defined(RFID_READER_TYPE_MFRC522_SPI)
		constexpr uint8_t rfidGain = 0x07 << 4;      // Sensitivity of RC522. For possible values see reference: https://forum.espuino.de/uploads/default/original/1X/9de5f8d35cbc123c1378cad1beceb3f51035cec0.png
	#endif


	//############# Port-expander-configuration ######################
	#ifdef CONFIG_PORT_EXPANDER
		constexpr uint8_t expanderI2cAddress = 0x20;  // I2C-address of PCA9555 (0x20 is true if PCA's pins A0+A1+A2 are pulled to GND)
	#endif

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
	#define INCLUDE_ROTARY_IN_CONTROLS_LOCK			// If set the rotary encoder is locked if controls are locked

	// RFID-RC522
	#define RFID_SCAN_INTERVAL 100                      // Interval-time in ms (how often is RFID read?)

	// Automatic restart
	#ifdef SHUTDOWN_IF_SD_BOOT_FAILS
		constexpr uint32_t deepsleepTimeAfterBootFails = 20;      // Automatic restart takes place if boot was not successful after this period (in seconds)
	#endif

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

	#if defined(MEASURE_BATTERY_VOLTAGE) || defined(MEASURE_BATTERY_MAX17055)
		#define BATTERY_MEASURE_ENABLE                 // Don't change. Set automatically if any method of battery monitoring is selected.
		constexpr uint8_t s_batteryCheckInterval = 10; // How often battery is measured (in minutes) (can be changed via GUI!)
	#endif

	#ifdef MEASURE_BATTERY_VOLTAGE
		// (optional) Default-voltages for battery-monitoring via Neopixel; can be changed later via WebGUI
		constexpr float s_warningLowVoltage = 3.4;                      // If battery-voltage is <= this value, a cyclic warning will be indicated by Neopixel (can be changed via GUI!)
		constexpr float s_warningCriticalVoltage = 3.1;                 // If battery-voltage is <= this value, assume battery near-empty. Set to 0V to disable.
		constexpr float s_voltageIndicatorLow = 3.0;                    // Lower range for Neopixel-voltage-indication (0 leds) (can be changed via GUI!)
		constexpr float s_voltageIndicatorHigh = 4.2;                   // Upper range for Neopixel-voltage-indication (all leds) (can be changed via GUI!)
	#endif

	#ifdef MEASURE_BATTERY_MAX17055
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
	#if defined(RFID_READER_TYPE_MFRC522_I2C) || defined(CONFIG_PORT_EXPANDER) || defined(MEASURE_BATTERY_MAX17055)
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
	#if (HAL == 1)
		#include "settings-lolin32.h"                       // Contains all user-relevant settings for Wemos Lolin32
	#elif (HAL == 2)
		#include "settings-espa1s.h"                        // Contains all user-relevant settings for ESP32-A1S Audiokit
	#elif (HAL == 3)
		#include "settings-lolin_d32.h"                     // Contains all user-relevant settings for Wemos Lolin D32
	#elif (HAL == 4)
		#include "settings-lolin_d32_pro.h"                 // Contains all user-relevant settings for Wemos Lolin D32 pro
	#elif (HAL == 5)
		#include "settings-ttgo_t8.h"                       // Contains all user-relevant settings for Lilygo TTGO T8 1.7
	#elif (HAL == 6)
		#include "settings-complete.h"                      // Contains all user-relevant settings for ESPuino complete
	#elif (HAL == 7)
		#include "settings-lolin_d32_pro_sdmmc_pe.h"        // Pre-configured settings for ESPuino Lolin D32 pro with SDMMC + port-expander (https://forum.espuino.de/t/espuino-minid32pro-lolin-d32-pro-mit-sd-mmc-und-port-expander-smd/866)
	#elif (HAL == 8)
		#include "settings-azdelivery_sdmmc.h"              // Pre-configured settings for AZ Delivery ESP32 NodeMCU / Devkit C (https://forum.espuino.de/t/az-delivery-esp32-nodemcu-devkit-c-mit-sd-mmc-und-pn5180-als-rfid-leser/634)
	#elif (HAL == 9)
		#include "settings-lolin_d32_sdmmc_pe.h"            // Pre-configured settings for Lolin D32 (non-pro) with SDMMC + port-expander (https://forum.espuino.de/t/espuino-minid32-pro-lolin-d32-pro-mit-sd-mmc-und-port-expander-smd/866)
	#elif (HAL == 10)
		#include "settings-muse_proto.h"                     // Pre-configured settings for Raspiaudio ESPMuse Proto Board with I2C RFID Reader (https://raspiaudio.com/produit/muse-proto)
	#elif (HAL == 99)
		#include "settings-custom.h"                        // Contains all user-relevant settings custom-board
	#endif

	//#define ENABLE_ESPUINO_DEBUG                            // Needs modification of platformio.ini (https://forum.espuino.de/t/rfid-mit-oder-ohne-task/353/21); better don't enable unless you know what you're doing :-)
	#endif //settings_override
#endif
