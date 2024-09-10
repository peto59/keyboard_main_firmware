#pragma once

#include <i2c_master.h>
#include <stdint.h>
#include <stdbool.h>

void i2c_initialize(void);
bool isI2C_initialized(void);

void i2c_select_row(uint8_t row_index);
void i2c_select_row_on(uint8_t addr, uint8_t row_index);
