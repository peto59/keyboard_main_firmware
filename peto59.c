#include "peto59.h"

//static i2c_status_t last_err = 0;
bool i2c_initialized = false;
bool right_connected = false;
bool left_connected = false;
uint8_t read;

void i2c_initialize(void){

    if(!i2c_initialized) {
        i2c_init();
        i2c_initialized = true;
        check_connection_right();
        check_connection_left();
    }
}

void check_connection_right(void) {
	    i2c_status_t status = i2c_read_register(SLAVE_I2C_ADDRESS_RIGHT, 0, &read, 1, 1000);
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
		i2c_status_t status = i2c_read_register(SLAVE_I2C_ADDRESS_LEFT, 0, &read, 1, 1000);
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

bool isI2C_initialized(void) {
    return i2c_initialized;
}

bool is_right_connected(void) {
    return right_connected;
}

bool is_left_connected(void) {
    return left_connected;
}
