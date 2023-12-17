#pragma once

/*
 * IS_ENABLED() helpers
 *
 * Derived from include/zephyr/sys/util_internal.h
 *
 * Copyright (c) 2011-2014, Wind River Systems, Inc.
 * Copyright (c) 2020, Nordic Semiconductor ASA
 */

#define IS_ENABLED(macro) _IS_ENABLED1(macro)

/* This is called from IS_ENABLED(), and sticks on a "_XXXX" prefix,
 * it will now be "_XXXX1" if config_macro is "1", or just "_XXXX" if it's
 * undefined.
 *   ENABLED:   Z_IS_ENABLED2(_XXXX1)
 *   DISABLED   Z_IS_ENABLED2(_XXXX)
 */
#define _IS_ENABLED1(config_macro) _IS_ENABLED2(_XXXX##config_macro)

/* Here's the core trick, we map "_XXXX1" to "_YYYY," (i.e. a string
 * with a trailing comma), so it has the effect of making this a
 * two-argument tuple to the preprocessor only in the case where the
 * value is defined to "1"
 *   ENABLED:    _YYYY,    <--- note comma!
 *   DISABLED:   _XXXX
 */
#define _XXXX1 _YYYY,

/* Then we append an extra argument to fool the gcc preprocessor into
 * accepting it as a varargs macro.
 *                         arg1   arg2  arg3
 *   ENABLED:   _IS_ENABLED3(_YYYY,    1,    0)
 *   DISABLED   _IS_ENABLED3(_XXXX 1,  0)
 */
#define _IS_ENABLED2(one_or_two_args) _IS_ENABLED3(one_or_two_args 1, 0)

/* And our second argument is thus now cooked to be 1 in the case
 * where the value is defined to 1, and 0 if not:
 */
#define _IS_ENABLED3(ignore_this, val, ...) val

/* End of IS_ENABLED() helpers */

// FilePathLength
#define MAX_FILEPATH_LENTGH 256

constexpr char stringDelimiter[] = "#"; // Character used to encapsulate data in linear NVS-strings (don't change)
constexpr char stringOuterDelimiter[] = "^"; // Character used to encapsulate encapsulated data along with RFID-ID in backup-file

inline bool isNumber(const char *str) {
	int i = 0;

	while (*(str + i) != '\0') {
		if (!isdigit(*(str + i++))) {
			return false;
		}
	}

	if (i > 0) {
		return true;
	} else {
		return false;
	}
}

// Checks if string starts with prefix
// Returns true if so
inline bool startsWith(const char *str, const char *pre) {
	if (strlen(pre) < 1) {
		return false;
	}

	return !strncmp(str, pre, strlen(pre));
}

// Checks if string ends with suffix
// Returns true if so
inline bool endsWith(const char *str, const char *suf) {
	const char *a = str + strlen(str);
	const char *b = suf + strlen(suf);

	while (a != str && b != suf) {
		if (*--a != *--b) {
			break;
		}
	}

	return b == suf && *a == *b;
}

inline void convertFilenameToAscii(String utf8String, char *asciiString) {
	// Arduino >= 2.0.5 filenames are already unicode, copy to result here without UTF-8 decoding
	strncpy(asciiString, (char *) utf8String.c_str(), utf8String.length() / sizeof(asciiString[0]));
	asciiString[utf8String.length()] = 0;
}

inline void convertAsciiToUtf8(String asciiString, char *utf8String) {

	int k = 0;

	for (int i = 0; i < asciiString.length() && k < MAX_FILEPATH_LENTGH - 2; i++) {

		switch (asciiString[i]) {
			case 0x8e:
				utf8String[k++] = 0xc3;
				utf8String[k++] = 0x84;
				break; // Ä
			case 0x84:
				utf8String[k++] = 0xc3;
				utf8String[k++] = 0xa4;
				break; // ä
			case 0x9a:
				utf8String[k++] = 0xc3;
				utf8String[k++] = 0x9c;
				break; // Ü
			case 0x81:
				utf8String[k++] = 0xc3;
				utf8String[k++] = 0xbc;
				break; // ü
			case 0x99:
				utf8String[k++] = 0xc3;
				utf8String[k++] = 0x96;
				break; // Ö
			case 0x94:
				utf8String[k++] = 0xc3;
				utf8String[k++] = 0xb6;
				break; // ö
			case 0xe1:
				utf8String[k++] = 0xc3;
				utf8String[k++] = 0x9f;
				break; // ß
			default:
				utf8String[k++] = asciiString[i];
		}
	}

	utf8String[k] = 0;
}

// Release previously allocated memory
inline void freeMultiCharArray(char **arr, const uint32_t cnt) {
	for (uint32_t i = 0; i < cnt; i++) {
		// Log_Printf(LOGLEVEL_DEBUG, freePtr, *(arr+i), arr);
		free(*(arr + i));
	}
	free(arr);
	*arr = NULL;
}
