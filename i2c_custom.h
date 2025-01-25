#pragma once


#include <i2c_master.h>
#include <stdint.h>
#include <stdbool.h>
#include "config.h"
#include "print.h"
#include "debug.h"
#include QMK_KEYBOARD_H

void i2c_initialize(void);

bool isI2C_initialized(void);
bool is_right_connected(void);
bool is_left_connected(void);

bool i2c_read_row_right(uint8_t row_index, uint8_t* buffer);
bool i2c_read_row_left(uint8_t row_index, uint8_t* buffer);
