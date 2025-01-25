#include "i2c_custom.h"
#include "config.h"

bool i2c_initialized = false;
bool right_connected = false;
bool left_connected = false;
uint8_t read;
deferred_token my_token;

i2c_status_t i2c_read_row(uint8_t addr, uint8_t row_index, uint8_t* buffer){
    return i2c_read_register(addr, row_index, buffer, 1, 1000);
}

void check_connection_right(void) {
	    i2c_status_t status = i2c_read_row(SLAVE_I2C_ADDRESS_RIGHT, 0, &read);
		if(status == I2C_STATUS_SUCCESS){
            right_connected = true;
		}
		else {
            right_connected = false;
#ifdef CONSOLE_ENABLE
			dprint("i2c error right\n");
#endif
		}
}

void check_connection_left(void) {
		i2c_status_t status = i2c_read_row(SLAVE_I2C_ADDRESS_LEFT, 0, &read);
		if(status == I2C_STATUS_SUCCESS){
            left_connected = true;
		}
		else {
            left_connected = false;
#ifdef CONSOLE_ENABLE
			dprint("i2c error left\n");
#endif
		}
}

void check_connections(void){
#ifdef CONSOLE_ENABLE
    dprint("Checking for availability of I2C slaves\n");
#endif
    check_connection_right();
    check_connection_left();
}

uint32_t timer_callback(uint32_t trigger_time, void *cb_arg) {
    check_connections();
    return I2C_RECHECK_PERIOD;
}

void i2c_initialize(void){

    if(!i2c_initialized) {
        i2c_init();
        i2c_initialized = true;
        check_connections();
        my_token = defer_exec(I2C_RECHECK_PERIOD, timer_callback, NULL);
    }
}

bool i2c_read_row_right(uint8_t row_index, uint8_t* buffer){
    if(i2c_read_row(SLAVE_I2C_ADDRESS_RIGHT, row_index, buffer) != I2C_STATUS_SUCCESS){
        right_connected = false;
#ifdef CONSOLE_ENABLE
        dprint("i2c error right\n");
#endif
        return false;
    }
    return true;
}

bool i2c_read_row_left(uint8_t row_index, uint8_t* buffer){
    if(i2c_read_row(SLAVE_I2C_ADDRESS_LEFT, row_index, buffer) != I2C_STATUS_SUCCESS){
        left_connected = false;
#ifdef CONSOLE_ENABLE
        dprint("i2c error left\n");
#endif
        return false;
    }
    return true;
}

bool isI2C_initialized(void) {
    return i2c_initialized;
}

bool is_right_connected(void) {
    return right_connected;
}

bool is_left_connected(void) {
    return left_connected;
}
