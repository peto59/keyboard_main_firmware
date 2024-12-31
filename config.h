#pragma once

//#include "config_common.h"
//#define DESCRIPTION three way split test on RP2040

#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET // Activates the double-tap behavior
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_TIMEOUT 200U // Timeout window in ms in which the double tap can occur.
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_LED GP25 // Specify a optional status led by GPIO number which blinks when entering the bootloader

#define BOOTMAGIC_ROW 1
#define BOOTMAGIC_COLUMN 4

#define DEBOUNCE 30

#define MATRIX_ROWS 10
#define MATRIX_COLS 19

#define MAIN_ROWS 10
#define MAIN_COLS 11
#define LEFT_ROWS 6
#define LEFT_COLS 4
#define RIGHT_ROWS 5
#define RIGHT_COLS 4

#define SLAVE_I2C_ADDRESS_RIGHT (0x76 << 1)
#define SLAVE_I2C_ADDRESS_LEFT (0x77 << 1)

#undef USE_I2C
#define USE_I2C TRUE
#undef I2C_DRIVER
#define I2C_DRIVER I2CD0
#undef I2C1_SCL_PIN
#define I2C1_SCL_PIN GP5
//#define I2C2_SCL_PAL_MODE 3
#undef I2C1_SDA_PIN
#define I2C1_SDA_PIN GP4
//#define I2C2_SDA_PAL_MODE 3

#undef F_SCL
#define F_SCL 1000000

#ifdef CONSOLE_ENABLE
#define DEBUG_MATRIX_SCAN_RATE
#endif
