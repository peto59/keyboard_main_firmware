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

    //kana
    [A_HIRA_LOWER] = 0x3041,   //ぁ
    [A_HIRA_UPPER] = 0x3042,   //あ
    [I_HIRA_LOWER] = 0x3043,   //ぃ
    [I_HIRA_UPPER] = 0x3044,   //い
    [U_HIRA_LOWER] = 0x3045,   //ぅ
    [U_HIRA_UPPER] = 0x3046,   //う
    [E_HIRA_LOWER] = 0x3047,   //ぇ
    [E_HIRA_UPPER] = 0x3048,   //え
    [O_HIRA_LOWER] = 0x3049,   //ぉ
    [O_HIRA_UPPER] = 0x304A,   //お
    [KA_HIRA_UPPER] = 0x304B,   //か
    [GA_HIRA_UPPER] = 0x304C,   //が
    [KI_HIRA_UPPER] = 0x304D,   //き
    [GI_HIRA_UPPER] = 0x304E,   //ぎ
    [KU_HIRA_UPPER] = 0x304F,   //く
    [GU_HIRA_UPPER] = 0x3050,   //ぐ
    [KE_HIRA_UPPER] = 0x3051,   //け
    [GE_HIRA_UPPER] = 0x3052,   //げ
    [KO_HIRA_UPPER] = 0x3053,   //こ
    [GO_HIRA_UPPER] = 0x3054,   //ご
    [SA_HIRA_UPPER] = 0x3055,   //さ
    [ZA_HIRA_UPPER] = 0x3056,   //ざ
    [SI_HIRA_UPPER] = 0x3057,   //し
    [ZI_HIRA_UPPER] = 0x3058,   //じ
    [SU_HIRA_UPPER] = 0x3059,   //す
    [ZU_HIRA_UPPER] = 0x305A,   //ず
    [SE_HIRA_UPPER] = 0x305B,   //せ
    [ZE_HIRA_UPPER] = 0x305C,   //ぜ
    [SO_HIRA_UPPER] = 0x305D,   //そ
    [ZO_HIRA_UPPER] = 0x305E,   //ぞ
    [TA_HIRA_UPPER] = 0x305F,   //た
    [DA_HIRA_UPPER] = 0x3060,   //だ
    [TI_HIRA_UPPER] = 0x3061,   //ち
    [DI_HIRA_UPPER] = 0x3062,   //ぢ
    [TU_HIRA_LOWER] = 0x3063,   //っ
    [TU_HIRA_UPPER] = 0x3064,   //つ
    [DU_HIRA_UPPER] = 0x3065,   //づ
    [TE_HIRA_UPPER] = 0x3066,   //て
    [DE_HIRA_UPPER] = 0x3067,   //で
    [TO_HIRA_UPPER] = 0x3068,   //と
    [DO_HIRA_UPPER] = 0x3069,   //ど
    [NA_HIRA_UPPER] = 0x306A,   //な
    [NI_HIRA_UPPER] = 0x306B,   //に
    [NU_HIRA_UPPER] = 0x306C,   //ぬ
    [NE_HIRA_UPPER] = 0x306D,   //ね
    [NO_HIRA_UPPER] = 0x306E,   //の
    [HA_HIRA_UPPER] = 0x306F,   //は
    [BA_HIRA_UPPER] = 0x3070,   //ば
    [PA_HIRA_UPPER] = 0x3071,   //ぱ
    [HI_HIRA_UPPER] = 0x3072,   //ひ
    [BI_HIRA_UPPER] = 0x3073,   //び
    [PI_HIRA_UPPER] = 0x3074,   //ぴ
    [HU_HIRA_UPPER] = 0x3075,   //ふ
    [BU_HIRA_UPPER] = 0x3076,   //ぶ
    [PU_HIRA_UPPER] = 0x3077,   //ぷ
    [HE_HIRA_UPPER] = 0x3078,   //へ
    [BE_HIRA_UPPER] = 0x3079,   //べ
    [PE_HIRA_UPPER] = 0x307A,   //ぺ
    [HO_HIRA_UPPER] = 0x307B,   //ほ
    [BO_HIRA_UPPER] = 0x307C,   //ぼ
    [PO_HIRA_UPPER] = 0x307D,   //ぽ
    [MA_HIRA_UPPER] = 0x307E,   //ま
    [MI_HIRA_UPPER] = 0x307F,   //み
    [MU_HIRA_UPPER] = 0x3080,   //む
    [ME_HIRA_UPPER] = 0x3081,   //め
    [MO_HIRA_UPPER] = 0x3082,   //も
    [YA_HIRA_LOWER] = 0x3083,   //ゃ
    [YA_HIRA_UPPER] = 0x3084,   //や
    [YU_HIRA_LOWER] = 0x3085,   //ゅ
    [YU_HIRA_UPPER] = 0x3086,   //ゆ
    [YO_HIRA_LOWER] = 0x3087,   //ょ
    [YO_HIRA_UPPER] = 0x3088,   //よ
    [RA_HIRA_UPPER] = 0x3089,   //ら
    [RI_HIRA_UPPER] = 0x308A,   //り
    [RU_HIRA_UPPER] = 0x308B,   //る
    [RE_HIRA_UPPER] = 0x308C,   //れ
    [RO_HIRA_UPPER] = 0x308D,   //ろ
    [WA_HIRA_LOWER] = 0x308E,   //ゎ
    [WA_HIRA_UPPER] = 0x308F,   //わ
    [WI_HIRA_UPPER] = 0x3090,   //ゐ
    [WE_HIRA_UPPER] = 0x3091,   //ゑ
    [WO_HIRA_UPPER] = 0x3092,   //を
    [N_HIRA_UPPER] = 0x3093,   //ん
    [A_KATA_LOWER] = 0x30A1,   //ァ
    [A_KATA_UPPER] = 0x30A2,   //ア
    [I_KATA_LOWER] = 0x30A3,   //ィ
    [I_KATA_UPPER] = 0x30A4,   //イ
    [U_KATA_LOWER] = 0x30A5,   //ゥ
    [U_KATA_UPPER] = 0x30A6,   //ウ
    [E_KATA_LOWER] = 0x30A7,   //ェ
    [E_KATA_UPPER] = 0x30A8,   //エ
    [O_KATA_LOWER] = 0x30A9,   //ォ
    [O_KATA_UPPER] = 0x30AA,   //オ
    [KA_KATA_UPPER] = 0x30AB,   //カ
    [GA_KATA_UPPER] = 0x30AC,   //ガ
    [KI_KATA_UPPER] = 0x30AD,   //キ
    [GI_KATA_UPPER] = 0x30AE,   //ギ
    [KU_KATA_UPPER] = 0x30AF,   //ク
    [GU_KATA_UPPER] = 0x30B0,   //グ
    [KE_KATA_UPPER] = 0x30B1,   //ケ
    [GE_KATA_UPPER] = 0x30B2,   //ゲ
    [KO_KATA_UPPER] = 0x30B3,   //コ
    [GO_KATA_UPPER] = 0x30B4,   //ゴ
    [SA_KATA_UPPER] = 0x30B5,   //サ
    [ZA_KATA_UPPER] = 0x30B6,   //ザ
    [SI_KATA_UPPER] = 0x30B7,   //シ
    [ZI_KATA_UPPER] = 0x30B8,   //ジ
    [SU_KATA_UPPER] = 0x30B9,   //ス
    [ZU_KATA_UPPER] = 0x30BA,   //ズ
    [SE_KATA_UPPER] = 0x30BB,   //セ
    [ZE_KATA_UPPER] = 0x30BC,   //ゼ
    [SO_KATA_UPPER] = 0x30BD,   //ソ
    [ZO_KATA_UPPER] = 0x30BE,   //ゾ
    [TA_KATA_UPPER] = 0x30BF,   //タ
    [DA_KATA_UPPER] = 0x30C0,   //ダ
    [TI_KATA_UPPER] = 0x30C1,   //チ
    [DI_KATA_UPPER] = 0x30C2,   //ヂ
    [TU_KATA_LOWER] = 0x30C3,   //ッ
    [TU_KATA_UPPER] = 0x30C4,   //ツ
    [DU_KATA_UPPER] = 0x30C5,   //ヅ
    [TE_KATA_UPPER] = 0x30C6,   //テ
    [DE_KATA_UPPER] = 0x30C7,   //デ
    [TO_KATA_UPPER] = 0x30C8,   //ト
    [DO_KATA_UPPER] = 0x30C9,   //ド
    [NA_KATA_UPPER] = 0x30CA,   //ナ
    [NI_KATA_UPPER] = 0x30CB,   //ニ
    [NU_KATA_UPPER] = 0x30CC,   //ヌ
    [NE_KATA_UPPER] = 0x30CD,   //ネ
    [NO_KATA_UPPER] = 0x30CE,   //ノ
    [HA_KATA_UPPER] = 0x30CF,   //ハ
    [BA_KATA_UPPER] = 0x30D0,   //バ
    [PA_KATA_UPPER] = 0x30D1,   //パ
    [HI_KATA_UPPER] = 0x30D2,   //ヒ
    [BI_KATA_UPPER] = 0x30D3,   //ビ
    [PI_KATA_UPPER] = 0x30D4,   //ピ
    [HU_KATA_UPPER] = 0x30D5,   //フ
    [BU_KATA_UPPER] = 0x30D6,   //ブ
    [PU_KATA_UPPER] = 0x30D7,   //プ
    [HE_KATA_UPPER] = 0x30D8,   //ヘ
    [BE_KATA_UPPER] = 0x30D9,   //ベ
    [PE_KATA_UPPER] = 0x30DA,   //ペ
    [HO_KATA_UPPER] = 0x30DB,   //ホ
    [BO_KATA_UPPER] = 0x30DC,   //ボ
    [PO_KATA_UPPER] = 0x30DD,   //ポ
    [MA_KATA_UPPER] = 0x30DE,   //マ
    [MI_KATA_UPPER] = 0x30DF,   //ミ
    [MU_KATA_UPPER] = 0x30E0,   //ム
    [ME_KATA_UPPER] = 0x30E1,   //メ
    [MO_KATA_UPPER] = 0x30E2,   //モ
    [YA_KATA_LOWER] = 0x30E3,   //ャ
    [YA_KATA_UPPER] = 0x30E4,   //ヤ
    [YU_KATA_LOWER] = 0x30E5,   //ュ
    [YU_KATA_UPPER] = 0x30E6,   //ユ
    [YO_KATA_LOWER] = 0x30E7,   //ョ
    [YO_KATA_UPPER] = 0x30E8,   //ヨ
    [RA_KATA_UPPER] = 0x30E9,   //ラ
    [RI_KATA_UPPER] = 0x30EA,   //リ
    [RU_KATA_UPPER] = 0x30EB,   //ル
    [RE_KATA_UPPER] = 0x30EC,   //レ
    [RO_KATA_UPPER] = 0x30ED,   //ロ
    [WA_KATA_LOWER] = 0x30EE,   //ヮ
    [WA_KATA_UPPER] = 0x30EF,   //ワ
    [WI_KATA_UPPER] = 0x30F0,   //ヰ
    [WE_KATA_UPPER] = 0x30F1,   //ヱ
    [WO_KATA_UPPER] = 0x30F2,   //ヲ
    [N_KATA_UPPER] = 0x30F3,   //ン
    [VU_KATA_UPPER] = 0x30F4,   //ヴ
    [KA_KATA_LOWER] = 0x30F5,   //ヵ
    [KE_KATA_LOWER] = 0x30F6,   //ヶ
};



bool dead_key_pressed_acute = false;
bool dead_key_pressed_caron = false;
bool shift_pressed = false;
bool ctrl_pressed = false;
bool kana_toggled = false;
uint_fast8_t bootloader_jump_state = 0;
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    shift_pressed = get_mods() & MOD_MASK_SHIFT;
    ctrl_pressed = get_mods() & MOD_MASK_CTRL;
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
        case TG_KANA:
            if (record->event.pressed) {
                kana_toggled = !kana_toggled;
            }
        case TD(0):
            if (record->event.pressed) {
                if (kana_toggled) {
                    if (shift_pressed) {
                        register_unicodemap(HE_KATA_UPPER);
                    } else {
                        register_unicodemap(HE_HIRA_UPPER);
                    }
                    return false;
                } else if (dead_key_pressed_acute || dead_key_pressed_caron){
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
            if (record->event.pressed) {
                if (kana_toggled) {
                    if (shift_pressed){
                        register_unicodemap(DI_KATA_UPPER);
                    } else {
                        register_unicodemap(DI_HIRA_UPPER);
                    }
                    return false;
                } else if (dead_key_pressed_acute) {
                    if (shift_pressed){
                        register_unicodemap(A_ACUTE_UPPER);
                    } else {
                        register_unicodemap(A_ACUTE_LOWER);
                    }
                    dead_key_pressed_acute = false;
                    return false;
                } else if (dead_key_pressed_caron) {
                    if (shift_pressed){
                        register_unicodemap(A_DIAERESIS_UPPER);
                    } else {
                        register_unicodemap(A_DIAERESIS_LOWER);
                    }
                    dead_key_pressed_caron = false;
                    return false;
                }
            }
            return true; // Let QMK send the press/release events

        case KC_E:
            if (record->event.pressed) {
                if (kana_toggled) {
                    if (shift_pressed){
                        if (ctrl_pressed) {
                            register_unicodemap(I_KATA_LOWER);
                        } else {
                            register_unicodemap(I_KATA_UPPER);
                        }
                    } else {
                        if (ctrl_pressed) {
                            register_unicodemap(I_HIRA_LOWER);
                        } else {
                            register_unicodemap(I_HIRA_UPPER);
                        }
                    }
                    return false;
                } else if (dead_key_pressed_acute) {
                    if (shift_pressed){
                        register_unicodemap(E_ACUTE_UPPER);
                    } else {
                        register_unicodemap(E_ACUTE_LOWER);
                    }
                    dead_key_pressed_acute = false;
                    return false;
                } else if (dead_key_pressed_caron) {
                    dead_key_pressed_caron = false;
                    tap_code16(S(KC_EQL));
                }
            }
            return true; // Let QMK send the press/release events
        case KC_I:
            if (record->event.pressed) {
                if (kana_toggled) {
                    if (shift_pressed){
                        register_unicodemap(NI_KATA_UPPER);
                    } else {
                        register_unicodemap(NI_HIRA_UPPER);
                    }
                    return false;
                } else if (dead_key_pressed_acute) {
                    if (shift_pressed){
                        register_unicodemap(I_ACUTE_UPPER);
                    } else {
                        register_unicodemap(I_ACUTE_LOWER);
                    }
                    dead_key_pressed_acute = false;
                    return false;
                } else if (dead_key_pressed_caron) {
                    dead_key_pressed_caron = false;
                    tap_code16(S(KC_EQL));
                }
            }
            return true; // Let QMK send the press/release events
        case KC_O:
            if (record->event.pressed) {
                if (kana_toggled) {
                    if (shift_pressed){
                        register_unicodemap(RA_KATA_UPPER);
                    } else {
                        register_unicodemap(RA_HIRA_UPPER);
                    }
                    return false;
                } else if (dead_key_pressed_acute) {
                    if (shift_pressed){
                        register_unicodemap(O_ACUTE_UPPER);
                    } else {
                        register_unicodemap(O_ACUTE_LOWER);
                    }
                    dead_key_pressed_acute = false;
                    return false;
                } else if (dead_key_pressed_caron) {
                    if (shift_pressed){
                        register_unicodemap(O_CIRCUMFLEX_UPPER);
                    } else {
                        register_unicodemap(O_CIRCUMFLEX_LOWER);
                    }
                    dead_key_pressed_caron = false;
                    return false;
                }
            }
            return true; // Let QMK send the press/release events
        case KC_U:
            if (record->event.pressed) {
                if (kana_toggled) {
                    if (shift_pressed){
                        register_unicodemap(NA_KATA_UPPER);
                    } else {
                        register_unicodemap(NA_HIRA_UPPER);
                    }
                    return false;
                } else if (dead_key_pressed_acute) {
                    if (shift_pressed){
                        register_unicodemap(U_ACUTE_UPPER);
                    } else {
                        register_unicodemap(U_ACUTE_LOWER);
                    }
                    dead_key_pressed_acute = false;
                    return false;
                } else if (dead_key_pressed_caron) {
                    dead_key_pressed_caron = false;
                    tap_code16(S(KC_EQL));
                }
            }
            return true; // Let QMK send the press/release events
        case KC_Y:
            if (record->event.pressed) {
                if (kana_toggled) {
                    if (shift_pressed){
                        register_unicodemap(N_KATA_UPPER);
                    } else {
                        register_unicodemap(N_HIRA_UPPER);
                    }
                    return false;
                } else if (dead_key_pressed_acute) {
                    if (shift_pressed){
                        register_unicodemap(Y_ACUTE_UPPER);
                    } else {
                        register_unicodemap(Y_ACUTE_LOWER);
                    }
                    dead_key_pressed_acute = false;
                    return false;
                } else if (dead_key_pressed_caron) {
                    dead_key_pressed_caron = false;
                    tap_code16(S(KC_EQL));
                }
            }
            return true; // Let QMK send the press/release events



        case KC_C:
            if (record->event.pressed) {
                if (kana_toggled) {
                    if (shift_pressed){
                        register_unicodemap(SO_KATA_UPPER);
                    } else {
                        register_unicodemap(SO_HIRA_UPPER);
                    }
                    return false;
                } else if (dead_key_pressed_acute) {
                    dead_key_pressed_acute = false;
                    del_mods(MOD_MASK_SHIFT);
                    tap_code(KC_EQL);
                    if (shift_pressed){
                        register_mods(MOD_MASK_SHIFT);
                    }
                } else if (dead_key_pressed_caron) {
                    if (shift_pressed){
                        register_unicodemap(C_CARON_UPPER);
                    } else {
                        register_unicodemap(C_CARON_LOWER);
                    }
                    dead_key_pressed_caron = false;
                    return false;
                }
            }
            return true; // Let QMK send the press/release events

        case KC_D:
            if (record->event.pressed) {
                if (kana_toggled) {
                    if (shift_pressed){
                        register_unicodemap(SI_KATA_UPPER);
                    } else {
                        register_unicodemap(SI_HIRA_UPPER);
                    }
                    return false;
                } else if (dead_key_pressed_acute) {
                    dead_key_pressed_acute = false;
                    del_mods(MOD_MASK_SHIFT);
                    tap_code(KC_EQL);
                    if (shift_pressed){
                        register_mods(MOD_MASK_SHIFT);
                    }
                } else if (dead_key_pressed_caron) {
                    if (shift_pressed){
                        register_unicodemap(D_CARON_UPPER);
                    } else {
                        register_unicodemap(D_CARON_LOWER);
                    }
                    dead_key_pressed_caron = false;
                    return false;
                }
            }
            return true; // Let QMK send the press/release events

        case KC_L:
            if (record->event.pressed) {
                if (kana_toggled) {
                    if (shift_pressed){
                        register_unicodemap(RI_KATA_UPPER);
                    } else {
                        register_unicodemap(RI_HIRA_UPPER);
                    }
                    return false;
                } else if (dead_key_pressed_acute) {
                    if (shift_pressed){
                        register_unicodemap(L_ACUTE_UPPER);
                    } else {
                        register_unicodemap(L_ACUTE_LOWER);
                    }
                    dead_key_pressed_acute = false;
                    return false;
                } else if (dead_key_pressed_caron) {
                    if (shift_pressed){
                        register_unicodemap(L_CARON_UPPER);
                    } else {
                        register_unicodemap(L_CARON_LOWER);
                    }
                    dead_key_pressed_caron = false;
                    return false;
                }
            }
            return true; // Let QMK send the press/release events

        case KC_N:
            if (record->event.pressed) {
                if (kana_toggled) {
                    if (shift_pressed){
                        register_unicodemap(MI_KATA_UPPER);
                    } else {
                        register_unicodemap(MI_HIRA_UPPER);
                    }
                    return false;
                } else if (dead_key_pressed_acute) {
                    dead_key_pressed_acute = false;
                    del_mods(MOD_MASK_SHIFT);
                    tap_code(KC_EQL);
                    if (shift_pressed){
                        register_mods(MOD_MASK_SHIFT);
                    }
                } else if (dead_key_pressed_caron) {
                    if (shift_pressed){
                        register_unicodemap(N_CARON_UPPER);
                    } else {
                        register_unicodemap(N_CARON_LOWER);
                    }
                    dead_key_pressed_caron = false;
                    return false;
                }
            }
            return true; // Let QMK send the press/release events

        case KC_R:
            if (record->event.pressed) {
                if (kana_toggled) {
                    if (shift_pressed){
                        register_unicodemap(SU_KATA_UPPER);
                    } else {
                        register_unicodemap(SU_HIRA_UPPER);
                    }
                    return false;
                } else if (dead_key_pressed_acute) {
                    if (shift_pressed){
                        register_unicodemap(R_ACUTE_UPPER);
                    } else {
                        register_unicodemap(R_ACUTE_LOWER);
                    }
                    dead_key_pressed_acute = false;
                    return false;
                } else if (dead_key_pressed_caron) {
                    dead_key_pressed_caron = false;
                    tap_code16(S(KC_EQL));
                }
            }
            return true; // Let QMK send the press/release events

        case KC_S:
            if (record->event.pressed) {
                if (kana_toggled) {
                    if (shift_pressed){
                        register_unicodemap(TO_KATA_UPPER);
                    } else {
                        register_unicodemap(TO_HIRA_UPPER);
                    }
                    return false;
                } else if (dead_key_pressed_acute) {
                    dead_key_pressed_acute = false;
                    del_mods(MOD_MASK_SHIFT);
                    tap_code(KC_EQL);
                    if (shift_pressed){
                        register_mods(MOD_MASK_SHIFT);
                    }
                } else if (dead_key_pressed_caron) {
                    if (shift_pressed){
                        register_unicodemap(S_CARON_UPPER);
                    } else {
                        register_unicodemap(S_CARON_LOWER);
                    }
                    dead_key_pressed_caron = false;
                    return false;
                }
            }
            return true; // Let QMK send the press/release events

        case KC_T:
            if (record->event.pressed) {
                if (kana_toggled) {
                    if (shift_pressed){
                        register_unicodemap(KA_KATA_UPPER);
                    } else {
                        register_unicodemap(KA_HIRA_UPPER);
                    }
                    return false;
                } else if (record->event.pressed && dead_key_pressed_acute) {
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
        case KC_GRV:
            return true;
        case KC_1:
            return true;
        case KC_2:
            return true:
        case KC_3:
            return true;
        case KC_4:
            return true;
        case KC_5:
            return true;
        case KC_6:
            return true;
        case KC_7:
            return true;
        case KC_8:
            return true;
        case KC_9:
            return true;
        case KC_0:
            return true;
        case KC_MINS:
            return true;
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
                                 EE_CLR,  KC_MSEL, KC_VOLD, KC_VOLU, KC_MUTE, KC_MSTP, KC_MPRV, KC_MPLY, KC_MNXT, KC_BRID, KC_BRIU, KC_MAIL, KC_CALC,           ____, ____, ____,                                  \
    ____, ____, ____, ____,      ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, ____, TG_KANA,                                         ____, ____, ____,       ____, ____, ____, ____,    \
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
