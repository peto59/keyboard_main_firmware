// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#define ____ KC_TRNS

enum layers {
    _BASE,
    _FN,
    _INTL,
};

typedef struct {
    uint16_t tap;
    uint16_t hold;
    uint16_t held;
} tap_dance_tap_hold_t;

enum {
    TD_INTL_EQUAL,
};

tap_dance_action_t tap_dance_actions[] = {
    // Tap once for INTL dead key, twice for KC_EQUAL
    [TD_INTL_EQUAL] = ACTION_TAP_DANCE_DOUBLE(OSL(_INTL), KC_EQL),
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
    KC_NO, KC_NO, KC_NO, KC_NO,      KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, TD(TD_INTL_EQUAL), KC_BSPC,    KC_INS, KC_HOME, KC_PAGE_UP,       KC_NUM, KC_PSLS, KC_PAST, KC_PMNS,  \
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
    ____, ____, ____, ____,      ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____,               ____, ____, ____,                ____, ____, ____, ____,    \
    ____, ____, ____, ____,      ____,  ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____,              ____, ____, ____,                ____, ____, ____, ____,    \
    ____, ____, ____, ____,      ____,   ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____,                                                    ____, ____, ____,          \
    ____, ____, ____, ____,      ____,    ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____,                        ____,                      ____, ____, ____,          \
    ____, ____, ____, ____,      ____, ____, ____,       ____,         ____,        ____, ____, ____, ____,                        ____, ____, ____,                ____, ____,       ____     \
    )
};

void keyboard_pre_init_user(void) {
}

void keyboard_post_init_user(void) {
  // Customise these values to desired behaviour
#ifdef CONSOLE_ENABLE
  debug_enable=true;
  debug_matrix=true;
  debug_keyboard=true;
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
