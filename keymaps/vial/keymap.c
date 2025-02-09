// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include <stdint.h>
#include <quantum.h>
#include "enums.h"
#include "print.h"
#include "debug.h"
#define ____ KC_TRNS

const uint32_t PROGMEM unicode_map[] = {
    [A_ACUTE_UPPER] = 0x00C1,  // Á
    [A_ACUTE_LOWER] = 0x00E1,  // á
    [A_DIAERESIS_UPPER] = 0x00C4,  // Ä
    [A_DIAERESIS_LOWER] = 0x00E4,  // ä
    [E_ACUTE_UPPER] = 0x00C9,  // É
    [E_ACUTE_LOWER] = 0x00E9,  // é
    [I_ACUTE_UPPER] = 0x00CD,  // Í
    [I_ACUTE_LOWER] = 0x00ED,  // í
    [O_ACUTE_UPPER] = 0x00D3,  // Ó
    [O_ACUTE_LOWER] = 0x00F3,  // ó
    [O_CIRCUMFLEX_UPPER] = 0x00D4,  // Ô
    [O_CIRCUMFLEX_LOWER] = 0x00F4,  // ô
    [U_ACUTE_UPPER] = 0x00DA,  // Ú
    [U_ACUTE_LOWER] = 0x00FA,  // ú
    [Y_ACUTE_UPPER] = 0x00DD,  // Ý
    [Y_ACUTE_LOWER] = 0x00FD,  // ý

    [C_CARON_UPPER] = 0x010C,  // Č
    [C_CARON_LOWER] = 0x010D,  // č
    [D_CARON_UPPER] = 0x010D,  // Ď
    [D_CARON_LOWER] = 0x010F,  // ď
    [L_ACUTE_UPPER] = 0x0139,  // Ĺ
    [L_ACUTE_LOWER] = 0x013A,  // ĺ
    [L_CARON_UPPER] = 0x013D,  // Ľ
    [L_CARON_LOWER] = 0x013E,  // ľ
    [N_CARON_UPPER] = 0x0147,  // Ň
    [N_CARON_LOWER] = 0x0148,  // ň
    [R_ACUTE_UPPER] = 0x0154,  // Ŕ
    [R_ACUTE_LOWER] = 0x0155,  // ŕ
    [S_CARON_UPPER] = 0x0160,  // Š
    [S_CARON_LOWER] = 0x0161,  // š
    [T_CARON_UPPER] = 0x0164,  // Ť
    [T_CARON_LOWER] = 0x0165,  // ť
    [Z_CARON_UPPER] = 0x017D,  // Ž
    [Z_CARON_LOWER] = 0x017E,  // ž
};



bool dead_key_pressed_acute = false;
bool dead_key_pressed_caron = false;
bool shift_pressed = false;
uint_fast8_t bootloader_jump_state = 0;
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    shift_pressed = get_mods() & MOD_MASK_SHIFT;
    // #ifdef CONSOLE_ENABLE
    // printf("%i\n", record->tap.count);
    // #endif
    if (matrix_get_row(6) & (1 << 11)){ // fn key
        if(record->event.pressed){
            bootloader_jump_state = 1;
        } else {
            bootloader_jump_state = 0;
        }
        return true;
    } else if (matrix_get_row(6) & (1 << 4)){ // Lctrl key
        if(record->event.pressed && bootloader_jump_state == 1){
            bootloader_jump_state = 2;
        } else {
            bootloader_jump_state = 0;
        }
        return true;
    } else if (matrix_get_row(BOOTMAGIC_ROW) & (1 << BOOTMAGIC_COLUMN)) { //esc key
        if(record->event.pressed && bootloader_jump_state == 2){
            bootloader_jump();
        } else {
            bootloader_jump_state = 0;
        }
        return true;
    }
    switch (keycode) {
        case TD(0):
            if (record->event.pressed) {
                if(dead_key_pressed_acute || dead_key_pressed_caron){
                    dead_key_pressed_acute = false;
                    dead_key_pressed_caron = false;
                } else if (shift_pressed){
                    dead_key_pressed_caron = true;
                } else {
                    dead_key_pressed_acute = true;
                }
            }
            return true;
        case KC_A:
            if (record->event.pressed && dead_key_pressed_acute) {
                if (shift_pressed){
                    register_unicodemap(A_ACUTE_UPPER);
                } else {
                    register_unicodemap(A_ACUTE_LOWER);
                }
                dead_key_pressed_acute = false;
                return false;
            } else if (record->event.pressed && dead_key_pressed_caron) {
                if (shift_pressed){
                    register_unicodemap(A_DIAERESIS_UPPER);
                } else {
                    register_unicodemap(A_DIAERESIS_LOWER);
                }
                dead_key_pressed_caron = false;
                return false;
            }
            return true; // Let QMK send the press/release events

        case KC_E:
            if (record->event.pressed && dead_key_pressed_acute) {
                if (shift_pressed){
                    register_unicodemap(E_ACUTE_UPPER);
                } else {
                    register_unicodemap(E_ACUTE_LOWER);
                }
                dead_key_pressed_acute = false;
                return false;
            } else if (record->event.pressed && dead_key_pressed_caron) {
                dead_key_pressed_caron = false;
                tap_code16(S(KC_EQL));
            }
            return true; // Let QMK send the press/release events
        case KC_I:
            if (record->event.pressed && dead_key_pressed_acute) {
                if (shift_pressed){
                    register_unicodemap(I_ACUTE_UPPER);
                } else {
                    register_unicodemap(I_ACUTE_LOWER);
                }
                dead_key_pressed_acute = false;
                return false;
            } else if (record->event.pressed && dead_key_pressed_caron) {
                dead_key_pressed_caron = false;
                tap_code16(S(KC_EQL));
            }
            return true; // Let QMK send the press/release events
        case KC_O:
            if (record->event.pressed && dead_key_pressed_acute) {
                if (shift_pressed){
                    register_unicodemap(O_ACUTE_UPPER);
                } else {
                    register_unicodemap(O_ACUTE_LOWER);
                }
                dead_key_pressed_acute = false;
                return false;
            } else if (record->event.pressed && dead_key_pressed_caron) {
                if (shift_pressed){
                    register_unicodemap(O_CIRCUMFLEX_UPPER);
                } else {
                    register_unicodemap(O_CIRCUMFLEX_LOWER);
                }
                dead_key_pressed_caron = false;
                return false;
            }
            return true; // Let QMK send the press/release events
        case KC_U:
            if (record->event.pressed && dead_key_pressed_acute) {
                if (shift_pressed){
                    register_unicodemap(U_ACUTE_UPPER);
                } else {
                    register_unicodemap(U_ACUTE_LOWER);
                }
                dead_key_pressed_acute = false;
                return false;
            } else if (record->event.pressed && dead_key_pressed_caron) {
                dead_key_pressed_caron = false;
                tap_code16(S(KC_EQL));
            }
            return true; // Let QMK send the press/release events
        case KC_Y:
            if (record->event.pressed && dead_key_pressed_acute) {
                if (shift_pressed){
                    register_unicodemap(Y_ACUTE_UPPER);
                } else {
                    register_unicodemap(Y_ACUTE_LOWER);
                }
                dead_key_pressed_acute = false;
                return false;
            } else if (record->event.pressed && dead_key_pressed_caron) {
                dead_key_pressed_caron = false;
                tap_code16(S(KC_EQL));
            }
            return true; // Let QMK send the press/release events



        case KC_C:
            if (record->event.pressed && dead_key_pressed_acute) {
                dead_key_pressed_acute = false;
                del_mods(MOD_MASK_SHIFT);
                tap_code(KC_EQL);
                if (shift_pressed){
                    register_mods(MOD_MASK_SHIFT);
                }
            } else if (record->event.pressed && dead_key_pressed_caron) {
                if (shift_pressed){
                    register_unicodemap(C_CARON_UPPER);
                } else {
                    register_unicodemap(C_CARON_LOWER);
                }
                dead_key_pressed_caron = false;
                return false;
            }
            return true; // Let QMK send the press/release events

        case KC_D:
            if (record->event.pressed && dead_key_pressed_acute) {
                dead_key_pressed_acute = false;
                del_mods(MOD_MASK_SHIFT);
                tap_code(KC_EQL);
                if (shift_pressed){
                    register_mods(MOD_MASK_SHIFT);
                }
            } else if (record->event.pressed && dead_key_pressed_caron) {
                if (shift_pressed){
                    register_unicodemap(D_CARON_UPPER);
                } else {
                    register_unicodemap(D_CARON_LOWER);
                }
                dead_key_pressed_caron = false;
                return false;
            }
            return true; // Let QMK send the press/release events

        case KC_L:
            if (record->event.pressed && dead_key_pressed_acute) {
                if (shift_pressed){
                    register_unicodemap(L_ACUTE_UPPER);
                } else {
                    register_unicodemap(L_ACUTE_LOWER);
                }
                dead_key_pressed_acute = false;
                return false;
            } else if (record->event.pressed && dead_key_pressed_caron) {
                if (shift_pressed){
                    register_unicodemap(L_CARON_UPPER);
                } else {
                    register_unicodemap(L_CARON_LOWER);
                }
                dead_key_pressed_caron = false;
                return false;
            }
            return true; // Let QMK send the press/release events

        case KC_N:
            if (record->event.pressed && dead_key_pressed_acute) {
                dead_key_pressed_acute = false;
                del_mods(MOD_MASK_SHIFT);
                tap_code(KC_EQL);
                if (shift_pressed){
                    register_mods(MOD_MASK_SHIFT);
                }
            } else if (record->event.pressed && dead_key_pressed_caron) {
                if (shift_pressed){
                    register_unicodemap(N_CARON_UPPER);
                } else {
                    register_unicodemap(N_CARON_LOWER);
                }
                dead_key_pressed_caron = false;
                return false;
            }
            return true; // Let QMK send the press/release events

        case KC_R:
            if (record->event.pressed && dead_key_pressed_acute) {
                if (shift_pressed){
                    register_unicodemap(R_ACUTE_UPPER);
                } else {
                    register_unicodemap(R_ACUTE_LOWER);
                }
                dead_key_pressed_acute = false;
                return false;
            } else if (record->event.pressed && dead_key_pressed_caron) {
                dead_key_pressed_caron = false;
                tap_code16(S(KC_EQL));
            }
            return true; // Let QMK send the press/release events

        case KC_S:
            if (record->event.pressed && dead_key_pressed_acute) {
                dead_key_pressed_acute = false;
                del_mods(MOD_MASK_SHIFT);
                tap_code(KC_EQL);
                if (shift_pressed){
                    register_mods(MOD_MASK_SHIFT);
                }
            } else if (record->event.pressed && dead_key_pressed_caron) {
                if (shift_pressed){
                    register_unicodemap(S_CARON_UPPER);
                } else {
                    register_unicodemap(S_CARON_LOWER);
                }
                dead_key_pressed_caron = false;
                return false;
            }
            return true; // Let QMK send the press/release events

        case KC_T:
            if (record->event.pressed && dead_key_pressed_acute) {
                dead_key_pressed_acute = false;
                del_mods(MOD_MASK_SHIFT);
                tap_code(KC_EQL);
                if (shift_pressed){
                    register_mods(MOD_MASK_SHIFT);
                }
            } else if (record->event.pressed && dead_key_pressed_caron) {
                if (shift_pressed){
                    register_unicodemap(T_CARON_UPPER);
                } else {
                    register_unicodemap(T_CARON_LOWER);
                }
                dead_key_pressed_caron = false;
                return false;
            }
            return true; // Let QMK send the press/release events

        case KC_Z:
            if (record->event.pressed && dead_key_pressed_acute) {
                dead_key_pressed_acute = false;
                del_mods(MOD_MASK_SHIFT);
                tap_code(KC_EQL);
                if (shift_pressed){
                    register_mods(MOD_MASK_SHIFT);
                }
            } else if (record->event.pressed && dead_key_pressed_caron) {
                if (shift_pressed){
                    register_unicodemap(Z_CARON_UPPER);
                } else {
                    register_unicodemap(Z_CARON_LOWER);
                }
                dead_key_pressed_caron = false;
                return false;
            }
            return true; // Let QMK send the press/release events

        case KC_LSFT:
        case KC_RSFT:
            if (!record->event.pressed){
                del_mods(MOD_MASK_SHIFT);
            }
            return true;
        default:
            if(dead_key_pressed_acute || dead_key_pressed_caron){
                dead_key_pressed_acute = false;
                dead_key_pressed_caron = false;
                tap_code(KC_EQL);
            }
            return true; // Process all other keycodes normally
    }
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * ┌───┬───┬───┬───┐
     * │ 7 │ 8 │ 9 │ / │
     * ├───┼───┼───┼───┤
     * │ 4 │ 5 │ 6 │ * │
     * ├───┼───┼───┼───┤
     * │ 1 │ 2 │ 3 │ - │
     * ├───┼───┼───┼───┤
     * │ 0 │ . │Ent│ + │
     * └───┴───┴───┴───┘
     */

    [_BASE] = LAYOUT(\
    KC_NO,                                         KC_F13, KC_F14, KC_F15, KC_F16, KC_F17, KC_F18, KC_F19, KC_F20, KC_F21, KC_F22, KC_F23, KC_F24,                                                                      \
                                     KC_ESCAPE,    KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12,        KC_PSCR, KC_SCRL, KC_PAUS,                                             \
    PB_1, PB_2, PB_3, PB_4,          KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, TD(0), KC_BSPC,                KC_INS, KC_HOME, KC_PAGE_UP,       KC_NUM, KC_PSLS, KC_PAST, KC_PMNS,  \
    PB_5, PB_6, PB_7, PB_8,          KC_TAB,  KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_ENT,              KC_DEL, KC_END, KC_PGDN,           KC_KP_7, KC_KP_8, KC_KP_9, KC_PPLS, \
    PB_9, PB_10, PB_11, PB_12,       KC_CAPS,   KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_BSLS,                                                    KC_KP_4, KC_KP_5, KC_KP_6,          \
    PB_13, PB_14, PB_15, PB_16,      KC_LSFT,    KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_INT1, KC_RSFT,                    KC_UP,                    KC_KP_1, KC_KP_2, KC_KP_3,          \
    PB_17, PB_18, PB_19, PB_20,      KC_LCTL, KC_LGUI, KC_LALT,       KC_SPC,         KC_SPC,        KC_RALT, KC_APP, MO(_FN), KC_RCTL,          KC_LEFT, KC_DOWN, KC_RGHT,         KC_KP_0, KC_PDOT,       KC_PENT     \
    ),

    [_COLEMAK] = LAYOUT(\
    ____,                                     ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____,                                                                          \
                                 ____,        ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____,              ____, ____, ____,                                           \
    ____, ____, ____, ____,      ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____,               ____, ____, ____,                ____, ____, ____, ____,    \
    ____, ____, ____, ____,      ____,  KC_Q, KC_W, KC_F, KC_P, KC_G, KC_J, KC_L, KC_U, KC_Y, ____, ____, ____, ____,              ____, ____, ____,                ____, ____, ____, ____,    \
    ____, ____, ____, ____,      ____,   KC_A, KC_R, KC_S, KC_T, KC_D, KC_H, KC_N, KC_E, KC_I, KC_O, ____, ____,                                                    ____, ____, ____,          \
    ____, ____, ____, ____,      ____,    KC_Z, KC_X, KC_C, KC_V, KC_B, KC_K, KC_M, ____, ____, ____, ____, ____,                        ____,                      ____, ____, ____,          \
    ____, ____, ____, ____,      ____, ____, ____,       ____,         ____,        ____, ____, ____, ____,                        ____, ____, ____,                ____, ____,       ____     \
    ),

    [_FN] = LAYOUT(\
    ____,                                     ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____,                                                                                              \
                                 EE_CLR,  KC_MSEL, KC_VOLD, KC_VOLU, KC_MUTE, KC_MSTP, KC_MPRV, KC_MPLY, KC_MNXT, KC_BRID, KC_BRIU, KC_MAIL, KC_CALC,          ____, ____, ____,                                  \
    ____, ____, ____, ____,      ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____,                                            ____, ____, ____,       ____, ____, ____, ____,    \
    ____, ____, ____, ____,      ____,  ____, ____, ____, ____, ____, ____, ____, ____, UC_PREV, UC_NEXT, ____, ____, TG(_COLEMAK),                             ____, ____, ____,       ____, ____, ____, ____,    \
    ____, ____, ____, ____,      ____,   ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____,                                                                        ____, ____, ____,          \
    ____, ____, ____, ____,      ____,    ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____,                                                     ____,             ____, ____, ____,          \
    ____, ____, ____, ____,      ____, ____, ____,       ____,         ____,        ____, ____, ____, ____,                                                     ____, ____, ____,       ____, ____,       ____     \
    ),
};

#define TAP_TAPPING_TERM 200
void install_tap_dance_entries(void) {
        vial_tap_dance_entry_t td0 = { KC_NO,
                                       KC_EQL,
                                       KC_EQL,
                                       KC_NO,
                                       TAP_TAPPING_TERM };
        // vial_tap_dance_entry_t td1 = { KC_SLSH, // / [ ? ]
        //                                KC_LBRC,
        //                                LSFT(KC_SLSH),
        //                                KC_RBRC,
        //                                TAP_TAPPING_TERM };
        dynamic_keymap_set_tap_dance(0, &td0); // the first value corresponds to the TD(i) slot
        //dynamic_keymap_set_tap_dance(1, &td1);
}

void keyboard_pre_init_user(void) {
}

void keyboard_post_init_user(void) {
  // Customise these values to desired behaviour
#ifdef CONSOLE_ENABLE
  debug_enable=true;
  debug_matrix=true;
  debug_keyboard=true;
#endif
  user_config_t user_config;
  user_config.raw = eeconfig_read_user();
  if (!user_config.config_written) {
#ifdef TAP_DANCE_ENABLE
    install_tap_dance_entries();
#endif
    user_config.config_written = 1;
    eeconfig_update_user(user_config.raw);
  }
}

void eeconfig_init_user(void) {  // EEPROM is getting reset!
    user_config_t user_config;
    user_config.raw = 0;
    user_config.config_written = false;
    eeconfig_update_user(user_config.raw);
}

/*
[INTL] = LAYOUT(\
    ____,                                     ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____,                                                                          \
                                 ____,        ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____,              ____, ____, ____,                                           \
    ____, ____, ____, ____,      ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____,               ____, ____, ____,                ____, ____, ____, ____,    \
    ____, ____, ____, ____,      ____,  ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____,              ____, ____, ____,                ____, ____, ____, ____,    \
    ____, ____, ____, ____,      ____,   ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____,                                                    ____, ____, ____,          \
    ____, ____, ____, ____,      ____,    ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____,                        ____,                      ____, ____, ____,          \
    ____, ____, ____, ____,      ____, ____, ____,       ____,         ____,        ____, ____, ____, ____,                        ____, ____, ____,                ____, ____,       ____     \
    )
*/
