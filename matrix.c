#include "i2c_custom.h"
#include "debounce.h"
#include <quantum.h>
#include <info_config.h>
#include QMK_KEYBOARD_H

#define MIN_MACRO(A, B) \
((A) < (B) ? (A) : (B))

#define MAX_MACRO(A, B) \
((A) > (B) ? (A) : (B))


__attribute__((weak)) void matrix_init_kb(void) { matrix_init_user(); }
__attribute__((weak)) void matrix_scan_kb(void) { matrix_scan_user(); }
__attribute__((weak)) void matrix_init_user(void) {}
__attribute__((weak)) void matrix_scan_user(void) {}
__attribute__((weak)) void matrix_init_quantum(void) { matrix_init_kb(); }
__attribute__((weak)) void matrix_scan_quantum(void) { matrix_scan_kb(); }

uint_fast8_t col_pins [MAIN_COLS] = {GP2, GP3, GP6, GP7, GP8, GP9, GP10, GP11, GP12, GP13, GP14};
uint_fast8_t row_pins [MAIN_ROWS] = {GP15, GP16, GP17, GP18, GP19, GP20, GP21, GP22, GP26, GP27};

bool changed;

//#define MY_GPIO_PORT GPIOA
//#define MY_PINS (PAL_PORT_BIT(15) | PAL_PORT_BIT(16) | PAL_PORT_BIT(17) | PAL_PORT_BIT(18) | PAL_PORT_BIT(19) | PAL_PORT_BIT(20) | PAL_PORT_BIT(21) | PAL_PORT_BIT(22) | PAL_PORT_BIT(26) | PAL_PORT_BIT(27))
//#define MY_VALUES (PAL_PORT_BIT(2) | PAL_PORT_BIT(3) | PAL_PORT_BIT(6) | PAL_PORT_BIT(7) | PAL_PORT_BIT(8) | PAL_PORT_BIT(9) | PAL_PORT_BIT(10) | PAL_PORT_BIT(11) | PAL_PORT_BIT(12) | PAL_PORT_BIT(13) | PAL_PORT_BIT(14))

static matrix_row_t raw_matrix[MATRIX_ROWS];  // raw values
static matrix_row_t matrix[MATRIX_ROWS];      // debounced values

inline uint8_t matrix_rows(void) { return MATRIX_ROWS; }
inline uint8_t matrix_cols(void) { return MATRIX_COLS; }


matrix_row_t matrix_get_row(uint8_t row) {
    // TODO: return the requested row data
    return matrix[row];
}

void matrix_print(void) {
#ifdef CONSOLE_ENABLE
	for (uint_fast8_t r = 0; r < MATRIX_ROWS; r++) {
        dprintf("matrix row %u : %lu\n", r, matrix[r]);
        //dprintf("%02u: ", r);
        /*for (uint_fast8_t c = MATRIX_COLS - 1; c >= 0; c++) {
		    dprintf("%lu ", matrix[r] & (1 << c));
        }
        dprintf("\n");*/
	}
#endif
}

void matrix_init(void) {
    i2c_initialize();
    for(uint8_t i = 0; i < MATRIX_ROWS; i++) {
        raw_matrix[i] = 0;
        matrix[i] = 0;
    }

	for (uint8_t i = 0; i < MAIN_ROWS; i++) {
        gpio_set_pin_input_low(row_pins[i]);
    }

    for (uint8_t i = 0; i < MAIN_COLS; i++) {
        gpio_set_pin_output(col_pins[i]);
    }

    // Unless hardware debouncing - Init the configured debounce routine
    debounce_init(MATRIX_ROWS);

    // This *must* be called for correct keyboard behavior
	matrix_init_kb();
    matrix_init_quantum();
}

uint8_t matrix_scan(void) {
    changed = false;

	uint_fast8_t r;
	for (r = 0; r < MATRIX_ROWS; r++) {
		raw_matrix[r] = 0;
	}
	for (uint_fast8_t c = 0; c < MAIN_COLS; c++) {
		gpio_write_pin_high(col_pins[c]);
		wait_us(MATRIX_IO_DELAY);
		for (r = 0; r < MAIN_ROWS; r++) {
			raw_matrix[r] |= (gpio_read_pin(row_pins[r]) << (c+RIGHT_COLS));
		}
		gpio_write_pin_low(col_pins[c]);
	}


	uint8_t read;

    if (is_right_connected()) {
        for (r = 0; r < RIGHT_ROWS; r++) {
            if (!i2c_read_row_right(r, &read)){
                break;
            }
            raw_matrix[r] |= read;
        }
    }

    if (is_left_connected()) {
        for (r = 0; r < LEFT_ROWS; r++) {
            if (!i2c_read_row_left(r, &read)){
                break;
            }
            raw_matrix[r] |= (read << (MAIN_COLS+RIGHT_COLS));
        }
    }

	for (r = 0; r < MATRIX_ROWS; r++) {
        if(raw_matrix[r] != matrix[r]) {
            //matrix[r] = raw_matrix[r];
            changed = true;
        }
    }

    changed = debounce(raw_matrix, matrix, MATRIX_ROWS, changed);

    matrix_scan_quantum();
	matrix_scan_kb();

    return changed;
}

    /*MULTIPLE PIN WRITE
    palSetPort(GPIOA, MY_VALUES);
    wait_us(50);
    for (r = 0; r < MAIN_ROWS; r++) {
        raw_matrix[r] |= (gpio_read_pin(row_pins[r]) << (c+RIGHT_COLS));
    }
    palClearPort(GPIOA, ~MY_VALUES);



    MULTIPLE PIN READ
    uint32_t tmp = palReadPort(GPIOA) & MY_PINS;
#ifdef CONSOLE_ENABLE
    dprintf("%u : %lu \n", c, tmp);
#endif
    */
