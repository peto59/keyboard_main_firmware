#pragma once

#include "quantum.h"

enum layers {
    _BASE,
    _COLEMAK,
    _FN,
};

enum unicode_names {
    A_ACUTE_UPPER,
    A_ACUTE_LOWER,
    A_DIAERESIS_UPPER,
    A_DIAERESIS_LOWER,
    E_ACUTE_UPPER,
    E_ACUTE_LOWER,
    I_ACUTE_UPPER,
    I_ACUTE_LOWER,
    O_ACUTE_UPPER,
    O_ACUTE_LOWER,
    O_CIRCUMFLEX_UPPER,
    O_CIRCUMFLEX_LOWER,
    U_ACUTE_UPPER,
    U_ACUTE_LOWER,
    Y_ACUTE_UPPER,
    Y_ACUTE_LOWER,

    C_CARON_UPPER,
    C_CARON_LOWER,
    D_CARON_UPPER,
    D_CARON_LOWER,
    L_ACUTE_UPPER,
    L_ACUTE_LOWER,
    L_CARON_UPPER,
    L_CARON_LOWER,
    N_CARON_UPPER,
    N_CARON_LOWER,
    R_ACUTE_UPPER,
    R_ACUTE_LOWER,
    S_CARON_UPPER,
    S_CARON_LOWER,
    T_CARON_UPPER,
    T_CARON_LOWER,
    Z_CARON_UPPER,
    Z_CARON_LOWER,
};

typedef union {
    uint32_t raw;
    struct {
        bool     config_written :1;
    };
} user_config_t;
