#pragma once

#include <i2c_master.h>
#include <stdint.h>
#include <stdbool.h>
#include "config.h"
#include "print.h"
#include "debug.h"

void i2c_initialize(void);

void check_connection_right(void);
void check_connection_left(void);

bool isI2C_initialized(void);
bool is_right_connected(void);
bool is_left_connected(void);

void i2c_select_row(uint8_t row_index);
void i2c_select_row_on(uint8_t addr, uint8_t row_index);
