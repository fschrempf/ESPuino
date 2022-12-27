
#include "settings.h"

#ifdef CONFIG_LANGUAGE_EN
	#include "Log.h"

	const char tryConnectMqttS[] PROGMEM = "Trying to connect to MQTT-broker";
	const char mqttOk[] PROGMEM = "MQTT-connection established.";
	const char sleepTimerEOP[] PROGMEM = "Sleep-timer: after last track of playlist.";
	const char sleepTimerEOT[] PROGMEM = "Sleep-timer: after end of current track.";
	const char sleepTimerStop[] PROGMEM = "Sleep-timer has been disabled.";
	const char sleepTimerEO5[] PROGMEM = "Sleep-timer: after five track or end of playlist - whatever is reached first";
	const char sleepTimerAlreadyStopped[] PROGMEM = "sleep-timer is already disabled.";
	const char sleepTimerSetTo[] PROGMEM = "sleep-timer adjusted to";
	const char allowButtons[] PROGMEM = "Unlocking all keys.";
	const char lockButtons[] PROGMEM = "Locking all keys.";
	const char noPlaylistNotAllowedMqtt[] PROGMEM = "Playmode cannot be adjusted to 'no playlist' via MQTT.";
	const char playmodeChangedMQtt[] PROGMEM = "Playlist adjusted via MQTT.";
	const char noPlaymodeChangeIfIdle[] PROGMEM = "Playlist cannot be adjusted while no playlist is active.";
	const char noValidTopic[] PROGMEM = "No valid MQTT-topic: %s";
	const char freePtr[] PROGMEM = "Releasing Pointer: %s (0x%04x)";
	const char freeMemory[] PROGMEM = "Free memory: %u";
	const char writeEntryToNvs[] PROGMEM = "Storing data to NVS";
	const char freeMemoryAfterFree[] PROGMEM = "Free memory after cleaning: %u";
	const char releaseMemoryOfOldPlaylist[] PROGMEM = "Releasing memory of old playlist.";
	const char dirOrFileDoesNotExist[] PROGMEM = "File of directory does not exist: %s";
	const char unableToAllocateMemForPlaylist[] PROGMEM = "Unable to allocate memory for playlist!";
	const char unableToAllocateMem[] PROGMEM = "Unable to allocate memory!";
	const char fileModeDetected[] PROGMEM = "File-mode detected.";
	const char nameOfFileFound[] PROGMEM = "File found: %s";
	const char reallocCalled[] PROGMEM = "Reallocated memory.";
	const char unableToAllocateMemForLinearPlaylist[] PROGMEM = "Unable to allocate memory for linear playlist!";
	const char numberOfValidFiles[] PROGMEM = "Number of valid files/webstreams: %u";
	const char newLoudnessReceivedQueue[] PROGMEM = "New volume received via queue: %u";
	const char newCntrlReceivedQueue[] PROGMEM = "Control-command received via queue: %u";
	const char newPlaylistReceived[] PROGMEM = "New playlist received with %d track(s)";
	const char repeatTrackDueToPlaymode[] PROGMEM = "Repeating track due to playmode configured.";
	const char repeatPlaylistDueToPlaymode[] PROGMEM = "Repeating playlist due to playmode configured.";
	const char cmndStop[] PROGMEM = "Command: stop";
	const char cmndPause[] PROGMEM = "Command: pause";
	const char cmndNextTrack[] PROGMEM = "Command: next track";
	const char cmndPrevTrack[] PROGMEM = "Command: previous track";
	const char cmndFirstTrack[] PROGMEM = "Command: first track of playlist";
	const char cmndLastTrack[] PROGMEM = "Command: last track of playlist";
	const char cmndDoesNotExist[] PROGMEM = "Command requested does not exist.";
	const char lastTrackAlreadyActive[] PROGMEM = "Already playing last track.";
	const char trackStartAudiobook[] PROGMEM = "Starting track in playmode from the very beginning.";
	const char trackStart[] PROGMEM = "Starting track from the very beginning.";
	const char trackChangeWebstream[] PROGMEM = "Playing from the very beginning is not possible while webradio-mode is active.";
	const char endOfPlaylistReached[] PROGMEM = "Reached end of playlist.";
	const char trackStartatPos[] PROGMEM = "Starting track at position %u";
	const char waitingForTaskQueues[] PROGMEM = "Task Queue for RFID does not exist yet, waiting...";
	const char rfidScannerReady[] PROGMEM = "RFID-tags can now be applied...";
	const char rfidTagDetected[] PROGMEM = "RFID-tag detected: %s";
	const char rfid15693TagDetected[] PROGMEM = "RFID-ta (ISO-15693) detected: ";
	const char rfidTagReceived[] PROGMEM = "RFID-tag received";
	const char dontAccepctSameRfid[] PROGMEM = "Reapplied same rfid-tag - rejected! (%s)";
	const char rfidTagUnknownInNvs[] PROGMEM = "RFID-tag is unkown to NVS.";
	const char goToSleepDueToIdle[] PROGMEM = "Going to deepsleep due to inactivity-timer...";
	const char goToSleepDueToTimer[] PROGMEM = "Going to deepsleep due to sleep timer...";
	const char goToSleepNow[] PROGMEM = "Going to deepsleep now!";
	const char maxLoudnessReached[] PROGMEM = "Already reached max volume!";
	const char minLoudnessReached[] PROGMEM = "Already reached min volume!";
	const char errorOccured[] PROGMEM = "Error occured!";
	const char noMp3FilesInDir[] PROGMEM = "Directory does not contain mp3-files.";
	const char modeSingleTrack[] PROGMEM = "Mode: Single track";
	const char modeSingleTrackLoop[] PROGMEM = "Mode: single track as infinite loop";
	const char modeSingleTrackRandom[] PROGMEM = "Mode: single track (random) of directory";
	const char modeSingleAudiobook[] PROGMEM = "Mode: audiobook";
	const char modeSingleAudiobookLoop[] PROGMEM = "Mode: audiobook as infinite loop";
	const char modeAllTrackAlphSorted[] PROGMEM = "Mode: all tracks (in alph. order) of directory '%s'";
	const char modeAllTrackRandom[] PROGMEM = "Mode: all tracks (in random. order) of directory";
	const char modeAllTrackAlphSortedLoop[] PROGMEM = "Mode: all tracks (in alph. order) of directory as infinite loop";
	const char modeAllTrackRandomLoop[] PROGMEM = "Mode: all tracks (in random order) of directory as infinite loop";
	const char modeWebstream[] PROGMEM = "Mode: webstream";
	const char modeWebstreamM3u[] PROGMEM = "Mode: Webstream (local .m3u-file)";
	const char webstreamNotAvailable[] PROGMEM = "Unable to access webstream as no wifi-connection is available!";
	const char modeDoesNotExist[] PROGMEM = "Playmode does not exist!";
	const char modeRepeatNone[] PROGMEM = "Repeatmode: no repeat";
	const char modeRepeatTrack[] PROGMEM = "Repeatmode: current track";
	const char modeRepeatPlaylist[] PROGMEM = "Repeatmode: whole playlist";
	const char modeRepeatTracknPlaylist[] PROGMEM = "Repeatmode: track and playlist";
	const char modificatorAllButtonsLocked[] PROGMEM = "Modificator: locking all keys via RFID-tag.";
	const char modificatorAllButtonsUnlocked[] PROGMEM = "Modificator: unlocking all keys via RFID-tag.";
	const char modificatorSleepd[] PROGMEM = "Modificator: sleep-Timer deactivated.";
	const char modificatorSleepTimer15[] PROGMEM = "Modificator: sleep-Timer enabled via RFID (15 minutes).";
	const char modificatorSleepTimer30[] PROGMEM = "Modificator: sleep-Timer enabled via RFID (30 minutes).";
	const char modificatorSleepTimer60[] PROGMEM = "Modificator: sleep-Timer enabled via RFID (60 minutes).";
	const char modificatorSleepTimer120[] PROGMEM = "Modificator: sleep-Timer enabled via RFID (2 hours).";
	const char ledsDimmedToNightmode[] PROGMEM = "Dimmed LEDs to nightmode.";
	const char ledsDimmedToInitialValue[] PROGMEM = "Dimmed LEDs to initial value.";
	const char modificatorNotallowedWhenIdle[] PROGMEM = "Modificator cannot be applied while playlist is inactive.";
	const char modificatorSleepAtEOT[] PROGMEM = "Modificator: adjusted sleep-timer to after end of current track.";
	const char modificatorSleepAtEOTd[] PROGMEM = "Modificator: disabled sleep-timer after end of current track.";
	const char modificatorSleepAtEOP[] PROGMEM = "Modificator: adjusted sleep-timer to after end of playlist.";
	const char modificatorSleepAtEOPd[] PROGMEM = "Modificator: disabled sleep-timer after end of playlist.";
	const char modificatorAllTrackAlphSortedLoop[] PROGMEM = "Modificator: adjusted to all tracks (in alph. order) as infinite loop.";
	const char modificatorAllTrackRandomLoop[] PROGMEM = "Modificator: adjusted to all tracks (in random order) as infinite loop.";
	const char modificatorCurTrackLoop[] PROGMEM = "Modificator: adjusted to current track as infinite loop.";
	const char modificatorCurAudiobookLoop[] PROGMEM = "Modificator: adjusted to current audiobook as infinite loop.";
	const char modificatorPlaylistLoopActive[] PROGMEM = "Modificator: adjusted to all tracks as infinite loop.";
	const char modificatorPlaylistLoopDeactive[] PROGMEM = "Modificator: disabled all tracks as infinite loop.";
	const char modificatorTrackActive[] PROGMEM = "Modificator: adjusted to current track as infinite loop.";
	const char modificatorTrackDeactive[] PROGMEM = "Modificator: disabled current track as infinite loop.";
	const char modificatorNotAllowed[] PROGMEM = "Unable to apply modificator.";
	const char modificatorLoopRev[] PROGMEM = "Modificator: infinite loop ended.";
	const char modificatorDoesNotExist[] PROGMEM = "This type of card-modificator does not exist %d!";
	const char errorOccuredNvs[] PROGMEM = "Error occured while reading from NVS!";
	const char statementsReceivedByServer[] PROGMEM = "Data received from server";
	const char savedSsidInNvs[] PROGMEM = "Storing SSID to NVS";
	const char savedWifiPwdInNvs[] PROGMEM = "Storing wifi-password to NVS";
	const char apReady[] PROGMEM = "Started wifi-access-point";
	const char httpReady[] PROGMEM = "Started HTTP-server.";
	const char unableToMountSd[] PROGMEM = "Unable to mount sd-card.";
	const char unableToCreateVolQ[] PROGMEM = "Unable to create volume-queue.";
	const char unableToCreateRfidQ[] PROGMEM = "Unable to create RFID-queue.";
	const char unableToCreateMgmtQ[] PROGMEM = "Unable to play-management-queue.";
	const char unableToCreatePlayQ[] PROGMEM = "Unable to create track-queue..";
	const char initialBrightnessfromNvs[] PROGMEM = "Restoring initial LED-brightness from NVS: %u";
	const char wroteInitialBrightnessToNvs[] PROGMEM = "Storing initial LED-brightness to NVS.";
	const char restoredInitialBrightnessForNmFromNvs[] PROGMEM = "Restored LED-brightness for nightmode from NVS: %u";
	const char wroteNmBrightnessToNvs[] PROGMEM = "Stored LED-brightness for nightmode to NVS.";
	const char wroteFtpUserToNvs[] PROGMEM = "Stored FTP-user to NVS.";
	const char restoredFtpUserFromNvs[] PROGMEM = "Restored FTP-user from NVS: %s";
	const char wroteFtpPwdToNvs[] PROGMEM = "Stored FTP-password to NVS.";
	const char restoredFtpPwdFromNvs[] PROGMEM = "Restored FTP-password from NVS: %s";
	const char restoredMaxInactivityFromNvs[] PROGMEM = "Restored maximum inactivity-time from NVS: %u minutes";
	const char wroteMaxInactivityToNvs[] PROGMEM = "Stored maximum inactivity-time to NVS.";
	const char restoredInitialLoudnessFromNvs[] PROGMEM = "Restored initial volume from NVS: %u";
	const char wroteInitialLoudnessToNvs[] PROGMEM = "Stored initial volume to NVS.";
	const char restoredMaxLoudnessForSpeakerFromNvs[] PROGMEM = "Restored maximum volume for speaker from NVS: %u";
	const char restoredMaxLoudnessForHeadphoneFromNvs[] PROGMEM = "Restored maximum volume for headphone from NVS: %u";
	const char wroteMaxLoudnessForSpeakerToNvs[] PROGMEM = "Wrote maximum volume for speaker to NVS.";
	const char wroteMaxLoudnessForHeadphoneToNvs[] PROGMEM = "Wrote maximum volume for headphone to NVS.";
	const char maxVolumeSet[] PROGMEM = "Maximum volume set to: %u";
	const char wroteMqttFlagToNvs[] PROGMEM = "Stored MQTT-flag to NVS.";
	const char restoredMqttActiveFromNvs[] PROGMEM = "Restored MQTT-flag (enabled) from NVS";
	const char restoredMqttDeactiveFromNvs[] PROGMEM = "Restored MQTT-flag (disabled) from NVS";
	const char wroteMqttClientIdToNvs[] PROGMEM = "Stored MQTT-clientid to NVS.";
	const char restoredMqttClientIdFromNvs[] PROGMEM = "Restored MQTT-clientid from NVS";
	const char wroteMqttServerToNvs[] PROGMEM = "Stored MQTT-server to NVS.";
	const char restoredMqttServerFromNvs[] PROGMEM = "Restored MQTT-Server from NVS";
	const char wroteMqttUserToNvs[] PROGMEM = "Stored MQTT-user to NVS.";
	const char restoredMqttUserFromNvs[] PROGMEM = "Restored MQTT-user from NVS";
	const char wroteMqttPwdToNvs[] PROGMEM = "Stored MQTT-password to NVS.";
	const char restoredMqttPwdFromNvs[] PROGMEM = "Restored MQTT-password from NVS";
	const char restoredMqttPortFromNvs[] PROGMEM = "Restored MQTT-port from NVS";
	const char mqttWithPwd[] PROGMEM = "Try to connect to MQTT-server with user und password";
	const char mqttWithoutPwd[] PROGMEM = "Try to connect to MQTT-server without user und password";
	const char ssidNotFoundInNvs[] PROGMEM = "Unable to find SSID to NVS.";
	const char wifiPwdNotFoundInNvs[] PROGMEM = "Unable to find wifi-password to NVS.";
	const char wifiStaticIpConfigNotFoundInNvs[] PROGMEM = "Unable to find wifi-ip-configuration to NVS.";
	const char wifiHostnameNotSet[] PROGMEM = "Unable to find hostname-configuration to NVS.";
	const char mqttConnFailed[] PROGMEM = "Unable to establish mqtt-connection, trying again...";
	const char restoredHostnameFromNvs[] PROGMEM = "Restored hostname from NVS: %s";
	const char currentVoltageMsg[] PROGMEM = "Current battery-voltage: %.2f V";
	const char currentChargeMsg[] PROGMEM = "Current battery charge: %.2f %%";
	const char batteryCurrentMsg[] PROGMEM = "Power usage (Battery): %.2f mA";
	const char batteryTempMsg[] PROGMEM = "Battery temperature: %.2f °C";
	const char batteryCyclesMsg[] PROGMEM = "Seen battery cycles: %.2f";
	const char batteryLowMsg[] PROGMEM = "Battery charge low";
	const char batteryCriticalMsg[] PROGMEM = "Battery charge critical. Will go to deepsleep...";
	const char sdBootFailedDeepsleep[] PROGMEM = "Failed to boot due to SD. Will go to deepsleep...";
	const char wifiEnabledAfterRestart[] PROGMEM = "WiFi will be enabled.";
	const char wifiDisabledAfterRestart[] PROGMEM = "WiFi will be disabled .";
	const char voltageIndicatorLowFromNVS[] PROGMEM = "Restored lower voltage-level for Neopixel-display from NVS: %.2fV";
	const char voltageIndicatorHighFromNVS[] PROGMEM = "Restored upper voltage-level for Neopixel-display from NVS: %.2fV";
	const char batteryCheckIntervalFromNVS[] PROGMEM = "Restored interval of battery-measurement or Neopixel-display from NVS: %u minutes";
	const char warningLowVoltageFromNVS[] PROGMEM = "Restored low battery-voltage-level for warning via Neopixel from NVS: %.2fV";
	const char warningCriticalVoltageFromNVS[] PROGMEM = "Restored critical battery-voltage-level for warning via Neopixel from NVS: %.2fV";
	const char batteryLowFromNVS[] PROGMEM = "Restored low battery level from NVS: %.2f %%";
	const char batteryCriticalFromNVS[] PROGMEM = "Restored critical battery level from NVS: %.2f %%";
	const char unableToRestoreLastRfidFromNVS[] PROGMEM = "Unable to restore last RFID from NVS";
	const char restoredLastRfidFromNVS[] PROGMEM = "Restored last RFID from NVS: %s";
	const char failedOpenFileForWrite[] PROGMEM = "Failed to open file for writing";
	const char fileWritten[] PROGMEM = "File written";
	const char writeFailed[] PROGMEM = "Write failed";
	const char writingFile[] PROGMEM = "Writing file: %s";
	const char failedToOpenFileForAppending[] PROGMEM = "Failed to open file for appending";
	const char listingDirectory[] PROGMEM = "Listing directory";
	const char failedToOpenDirectory[] PROGMEM = "Failed to open directory";
	const char notADirectory[] PROGMEM = "Not a directory";
	const char sdMountedMmc1BitMode[] PROGMEM = "SD card mounted in SPI-mode configured...";
	const char sdMountedSpiMode[] PROGMEM = "Mounting SD card in SPI-mode...";
	const char backupRecoveryWebsite[] PROGMEM = "<p>Backup-file is being applied...<br />Back to <a href=\"javascript:history.back()\">last page</a>.</p>";
	const char restartWebsite[] PROGMEM = "<p>ESPuino is being restarted...<br />Back to <a href=\"javascript:history.back()\">last page</a>.</p>";
	const char shutdownWebsite[] PROGMEM = "<p>Der ESPuino is being shutdown...</p>";
	const char mqttMsgReceived[] PROGMEM = "MQTT-message received";
	const char trackPausedAtPos[] PROGMEM = "Track paused at position: %u (%u)";
	const char freeHeapWithoutFtp[] PROGMEM = "Free heap before FTP-allocation: %u";
	const char freeHeapWithFtp[] PROGMEM = "Free heap after FTP-allocation: %u";
	const char freeHeapAfterSetup[] PROGMEM = "Free heap after setup";
	const char ftpServerStarted[] PROGMEM = "FTP-Server started";
	const char tryStaticIpConfig[] PROGMEM = "Performing IP-configuration...";
	const char staticIPConfigFailed[] PROGMEM = "IP-configuration failed";
	const char wakeUpRfidNoIso14443[] PROGMEM = "Wakeup caused by low power card-detection. RF-field changed but no ISO-14443 card on reader was found. So I'll return back to sleep now...";
	const char lowPowerCardSuccess[] PROGMEM = "Switch to low power card-detection: success";
	const char rememberLastVolume[] PROGMEM = "Restored volume used before last shutdown. This overwrites the initial volume configured via webgui.";
	const char unableToStartFtpServer[] PROGMEM = "FTP-server cannot be started. This is because FTP-service is already active or because WiFi is unavailable.";
	const char unableToTellIpAddress[] PROGMEM = "IP-address can't be announced as there's no WiFi-connection available.";
	const char newPlayModeStereo[] PROGMEM = "New mode: stereo";
	const char newPlayModeMono[] PROGMEM = "New mode: mono";
	const char portExpanderFound[] PROGMEM = "Port-expander found";
	const char portExpanderNotFound[] PROGMEM = "Unable to detect port-expander";
	const char portExpanderInterruptEnabled[] PROGMEM = "Enabled interrupt-handling for port-expander";
	const char warningRefactoring[] PROGMEM = "!!!!IMPORTANT!!!! Please review https://forum.espuino.de/t/wechsel-zum-refactoring-branch-was-ist-zu-beachten/510 !!!!IMPORTANT!!!!";
	const char playlistGenModeUncached[] PROGMEM = "Playlist-generation: uncached";
	const char playlistGenModeCached[] PROGMEM = "Playlist-generation: cached";
	const char playlistCacheFoundBut0[] PROGMEM = "Playlist-cache-file found but 0 bytes";
	const char bootLoopDetected[] PROGMEM = "Bootloop detected! Last RFID won't be restored.";
	const char noBootLoopDetected[] PROGMEM = "No bootloop detected. Great :-)";
	const char importCountNokNvs[] PROGMEM = "Number of invalid import-entries: %u";
	const char errorReadingTmpfile[] PROGMEM = "Error occured while reading from import-tmpfile";
	const char errorWritingTmpfile[] PROGMEM = "Error occured while writing to import-tmpfile";
	const char eraseRfidNvsWeb[] PROGMEM = "<p>NVS-RFID-assignments are being deleted...<br />Back to <a href=\"javascript:history.back()\">last page</a>.</p>";
	const char eraseRfidNvs[] PROGMEM = "NVS-RFID-assignments are being deleted...";
	const char erasePlaylistCachefile[] PROGMEM = "Playlist-cachefile deleted: %s";
	const char fwStart[] PROGMEM = "Starting firmware-update via OTA...";
	const char fwEnd[] PROGMEM = "Firmware-update finished";
	const char otaNotSupported[] PROGMEM = "Firmware-update isn't supported by this ESPuino!";
	const char otaNotSupportedWebsite[] PROGMEM = "<p>FFirmware-update isn't supported by this ESPuino!<br />Back to <a href=\"javascript:history.back()\">last page</a>.</p>";
	const char noPlaylist[] PROGMEM = "No active playlist.";
	const char rfidTagRemoved[] PROGMEM = "RFID-tag removed";
	const char rfidTagReapplied[] PROGMEM = "RFID-tag reapplied";
	const char ftpEnableTooLate[] PROGMEM = "FTP can only be enabled within the first 30s after ESPuino-start. Child-protection :-)";
	const char syncingViaNtp[] PROGMEM = "Getting current time via NTP...";
	const char sdInfo[] PROGMEM = "SD card size / free space: %llu MB / %llu MB";
	const char paOn[] PROGMEM = "Loudspeaker on";
	const char paOff[] PROGMEM = "Loudspeaker off";
	const char hpOn[] PROGMEM = "Headphones on";
	const char hpOff[] PROGMEM = "Headphones off";
	const char webTxCanceled[] PROGMEM = "Webtransfer canceled due to inactivity-timer.";
	const char cantConnectToWifi[] PROGMEM = "Can't connect to wifi. Trying again...";
	const char tryToPickRandomDir[] PROGMEM = "Try to pick randon subdirectory out of: %s";
	const char pickedRandomDir[] PROGMEM = "Randomly picked subdirectory: %s";
	const char wrongWakeUpGpio[] PROGMEM = "GPIO choosen as wakeup-pin isn't of type RTC and that reason for can't wake up ESP32! (GPIO: %u)";
	const char currentlyPlaying[] PROGMEM = "'%s' is being played (%d of %d)";
	const char secondsJumpForward[] PROGMEM = "Jumped %d seconds forwards";
	const char secondsJumpBackward[] PROGMEM = "Jumped %d seconds backward";
	const char wroteLastTrackToNvs[] PROGMEM = "Write '%s' to NVS for RFID-Card-ID %s with playmode %d and last track %u";
	const char wifiConnectionInProgress[] PROGMEM = "Try to connect to WiFi with SSID '%s'...";
	const char wifiCurrentIp[] PROGMEM = "Current IP: %s";
	const char jsonErrorMsg[] PROGMEM = "deserializeJson() failed: %s";
#endif
