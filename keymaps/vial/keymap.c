// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#define ____ KC_TRNS

enum layers {
    _BASE,
    _FN,
    _INTL,
};

enum unicode_names {
    A_ACUTE_LOWER,
    A_ACUTE_UPPER,
    A_DIAERESIS_LOWER,
    A_DIAERESIS_UPPER,
    E_ACUTE_LOWER,
    E_ACUTE_UPPER,
    I_ACUTE_LOWER,
    I_ACUTE_UPPER,
    O_ACUTE_LOWER,
    O_ACUTE_UPPER,
    O_CIRCUMFLEX_LOWER,
    O_CIRCUMFLEX_UPPER,
    U_ACUTE_LOWER,
    U_ACUTE_UPPER,
    Y_ACUTE_LOWER,
    Y_ACUTE_UPPER,

    C_CARON_UPPER,
    C_CARON_LOWER,
    D_CARON_UPPER,
    D_CARON_LOWER,
    L_ACUTE_LOWER,
    L_ACUTE_UPPER,
    L_CARON_LOWER,
    L_CARON_UPPER,
    N_CARON_UPPER,
    N_CARON_LOWER,
    R_ACUTE_LOWER,
    R_ACUTE_UPPER,
    S_CARON_UPPER,
    S_CARON_LOWER,
    T_CARON_UPPER,
    T_CARON_LOWER,
    Z_CARON_UPPER,
    Z_CARON_LOWER,
};

const uint32_t PROGMEM unicode_map[] = {
    [A_ACUTE_LOWER] = 0x00E1,  // á
    [A_ACUTE_UPPER] = 0x00C1,  // Á
    [A_DIAERESIS_LOWER] = 0x00E4,  // ä
    [A_DIAERESIS_UPPER] = 0x00C4,  // Ä
    [E_ACUTE_LOWER] = 0x00E9,  // é
    [E_ACUTE_UPPER] = 0x00C9,  // É
    [I_ACUTE_LOWER] = 0x00ED,  // í
    [I_ACUTE_UPPER] = 0x00CD,  // Í
    [O_ACUTE_LOWER] = 0x00F3,  // ó
    [O_ACUTE_UPPER] = 0x00D3,  // Ó
    [O_CIRCUMFLEX_LOWER] = 0x00F4,  // ô
    [O_CIRCUMFLEX_UPPER] = 0x00D4,  // Ô
    [U_ACUTE_LOWER] = 0x00FA,  // ú
    [U_ACUTE_UPPER] = 0x00DA,  // Ú
    [Y_ACUTE_LOWER] = 0x00FD,  // ý
    [Y_ACUTE_UPPER] = 0x00DD,  // Ý

    [L_ACUTE_LOWER] = 0x013A,  // ĺ
    [L_ACUTE_UPPER] = 0x0139,  // Ĺ
    [L_CARON_LOWER] = 0x013E,  // ľ
    [L_CARON_UPPER] = 0x013D,  // Ľ

    [R_ACUTE_LOWER] = 0x0155,  // ŕ
    [R_ACUTE_UPPER] = 0x0154,  // Ŕ
};

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
    KC_NO, KC_NO, KC_NO, KC_NO,      KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, TD(0), KC_BSPC,                KC_INS, KC_HOME, KC_PAGE_UP,       KC_NUM, KC_PSLS, KC_PAST, KC_PMNS,  \
    KC_NO, KC_NO, KC_NO, KC_NO,      KC_TAB,  KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_ENT,              KC_DEL, KC_END, KC_PGDN,           KC_KP_7, KC_KP_8, KC_KP_9, KC_PPLS, \
    KC_NO, KC_NO, KC_NO, KC_NO,      KC_CAPS,   KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_BSLS,                                                    KC_KP_4, KC_KP_5, KC_KP_6,          \
    KC_NO, KC_NO, KC_NO, KC_NO,      KC_LSFT,    KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_INT1, KC_RSFT,                    KC_UP,                    KC_KP_1, KC_KP_2, KC_KP_3,          \
    KC_NO, KC_NO, KC_NO, KC_NO,      KC_LCTL, KC_LGUI, KC_LALT,       KC_SPC,         KC_SPC,        KC_RALT, KC_APP, MO(_FN), KC_RCTL,          KC_LEFT, KC_DOWN, KC_RGHT,         KC_KP_0, KC_PDOT,       KC_PENT     \
    ),

    [_FN] = LAYOUT(\
    ____,                                     ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____,                                                                                              \
                                 QK_BOOT,     KC_MSEL, KC_VOLD, KC_VOLU, KC_MUTE, KC_MSTP, KC_MPRV, KC_MPLY, KC_MNXT, KC_BRID, KC_BRIU, KC_MAIL, KC_CALC,       ____, ____, ____,                                  \
    ____, ____, ____, ____,      ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____,                                            ____, ____, ____,       ____, ____, ____, ____,    \
    ____, ____, ____, ____,      ____,  ____, ____, ____, ____, ____, ____, ____, ____, UC_PREV, UC_NEXT, ____, ____, ____,                                     ____, ____, ____,       ____, ____, ____, ____,    \
    ____, ____, ____, ____,      ____,   ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____,                                                                        ____, ____, ____,          \
    ____, ____, ____, ____,      ____,    ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____,                                                     ____,             ____, ____, ____,          \
    ____, ____, ____, ____,      ____, ____, ____,       ____,         ____,        ____, ____, ____, ____,                                                     ____, ____, ____,       ____, ____,       ____     \
    ),

    [_INTL] = LAYOUT(\
    ____,                                     ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____,                                                                          \
                                 ____,        ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____,              ____, ____, ____,                                           \
    ____, ____, ____, ____,      ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, KC_EQL, ____,               ____, ____, ____,                ____, ____, ____, ____,    \
    ____, ____, ____, ____,      ____,  ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____,              ____, ____, ____,                ____, ____, ____, ____,    \
    ____, ____, ____, ____,      ____,   UP(A_ACUTE_LOWER, A_ACUTE_UPPER), ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____,                                                    ____, ____, ____,          \
    ____, ____, ____, ____,      ____,    ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____,                        ____,                      ____, ____, ____,          \
    ____, ____, ____, ____,      ____, ____, ____,       ____,         ____,        ____, ____, ____, ____,                        ____, ____, ____,                ____, ____,       ____     \
    )
};

#define TAP_TAPPING_TERM 200
void install_tap_dance_entries(void) {
    vial_tap_dance_entry_t td0 = { OSL(2), // Change layers
        KC_EQL,
        KC_NO,
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
#ifdef TAP_DANCE_ENABLE
  install_tap_dance_entries();
#endif
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
