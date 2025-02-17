#pragma once

#include "quantum.h"

enum layers {
    _BASE,
    _COLEMAK,
    _FN,
};

enum custom_keycodes {
    TG_KANA = QK_KB_0,
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

    //kana
    VOWEL_ELONGATION,
    A_HIRA_UPPER,
    A_HIRA_LOWER,
    A_KATA_UPPER,
    A_KATA_LOWER,
    I_HIRA_UPPER,
    I_HIRA_LOWER,
    I_KATA_UPPER,
    I_KATA_LOWER,
    U_HIRA_UPPER,
    U_HIRA_LOWER,
    U_KATA_UPPER,
    U_KATA_LOWER,
    E_HIRA_UPPER,
    E_HIRA_LOWER,
    E_KATA_UPPER,
    E_KATA_LOWER,
    O_HIRA_UPPER,
    O_HIRA_LOWER,
    O_KATA_UPPER,
    O_KATA_LOWER,
    KA_HIRA_UPPER,
    KA_KATA_UPPER,
    KI_HIRA_UPPER,
    KI_KATA_UPPER,
    KU_HIRA_UPPER,
    KU_KATA_UPPER,
    KE_HIRA_UPPER,
    KE_KATA_UPPER,
    KO_HIRA_UPPER,
    KO_KATA_UPPER,
    SA_HIRA_UPPER,
    SA_KATA_UPPER,
    SI_HIRA_UPPER,
    SI_KATA_UPPER,
    SU_HIRA_UPPER,
    SU_KATA_UPPER,
    SU_KATA_LOWER,
    SE_HIRA_UPPER,
    SE_KATA_UPPER,
    SO_HIRA_UPPER,
    SO_KATA_UPPER,
    TA_HIRA_UPPER,
    TA_KATA_UPPER,
    TI_HIRA_UPPER,
    TI_KATA_UPPER,
    TU_HIRA_UPPER,
    TU_HIRA_LOWER,
    TU_KATA_UPPER,
    TU_KATA_LOWER,
    TE_HIRA_UPPER,
    TE_KATA_UPPER,
    TO_HIRA_UPPER,
    TO_KATA_UPPER,
    NA_HIRA_UPPER,
    NA_KATA_UPPER,
    NI_HIRA_UPPER,
    NI_KATA_UPPER,
    NU_HIRA_UPPER,
    NU_KATA_UPPER,
    NE_HIRA_UPPER,
    NE_KATA_UPPER,
    NO_HIRA_UPPER,
    NO_KATA_UPPER,
    HA_HIRA_UPPER,
    HA_KATA_UPPER,
    HI_HIRA_UPPER,
    HI_KATA_UPPER,
    HU_HIRA_UPPER,
    HU_KATA_UPPER,
    HE_HIRA_UPPER,
    HE_KATA_UPPER,
    HO_HIRA_UPPER,
    HO_KATA_UPPER,
    MA_HIRA_UPPER,
    MA_KATA_UPPER,
    MI_HIRA_UPPER,
    MI_KATA_UPPER,
    MU_HIRA_UPPER,
    MU_KATA_UPPER,
    ME_HIRA_UPPER,
    ME_KATA_UPPER,
    MO_HIRA_UPPER,
    MO_KATA_UPPER,
    YA_HIRA_UPPER,
    YA_HIRA_LOWER,
    YA_KATA_UPPER,
    YA_KATA_LOWER,
    YU_HIRA_UPPER,
    YU_HIRA_LOWER,
    YU_KATA_UPPER,
    YU_KATA_LOWER,
    YO_HIRA_UPPER,
    YO_HIRA_LOWER,
    YO_KATA_UPPER,
    YO_KATA_LOWER,
    RA_HIRA_UPPER,
    RA_KATA_UPPER,
    RI_HIRA_UPPER,
    RI_KATA_UPPER,
    RU_HIRA_UPPER,
    RU_KATA_UPPER,
    RE_HIRA_UPPER,
    RE_KATA_UPPER,
    RO_HIRA_UPPER,
    RO_KATA_UPPER,
    WA_HIRA_UPPER,
    WA_HIRA_LOWER,
    WA_KATA_UPPER,
    WA_KATA_LOWER,
    WI_HIRA_UPPER,
    WI_KATA_UPPER,
    WE_HIRA_UPPER,
    WE_KATA_UPPER,
    WO_HIRA_UPPER,
    WO_KATA_UPPER,
    N_HIRA_UPPER,
    N_KATA_UPPER,

    //dakuon
    GA_HIRA_UPPER,
    GA_KATA_UPPER,
    GI_HIRA_UPPER,
    GI_KATA_UPPER,
    GU_HIRA_UPPER,
    GU_KATA_UPPER,
    GE_HIRA_UPPER,
    GE_KATA_UPPER,
    GO_HIRA_UPPER,
    GO_KATA_UPPER,
    ZA_HIRA_UPPER,
    ZA_KATA_UPPER,
    ZI_HIRA_UPPER,
    ZI_KATA_UPPER,
    ZU_HIRA_UPPER,
    ZU_KATA_UPPER,
    ZE_HIRA_UPPER,
    ZE_KATA_UPPER,
    ZO_HIRA_UPPER,
    ZO_KATA_UPPER,
    DA_HIRA_UPPER,
    DA_KATA_UPPER,
    DI_HIRA_UPPER,
    DI_KATA_UPPER,
    DU_HIRA_UPPER,
    DU_KATA_UPPER,
    DE_HIRA_UPPER,
    DE_KATA_UPPER,
    DO_HIRA_UPPER,
    DO_KATA_UPPER,
    BA_HIRA_UPPER,
    BA_KATA_UPPER,
    BI_HIRA_UPPER,
    BI_KATA_UPPER,
    BU_HIRA_UPPER,
    BU_KATA_UPPER,
    BE_HIRA_UPPER,
    BE_KATA_UPPER,
    BO_HIRA_UPPER,
    BO_KATA_UPPER,

    PA_HIRA_UPPER,
    PA_KATA_UPPER,
    PI_HIRA_UPPER,
    PI_KATA_UPPER,
    PU_HIRA_UPPER,
    PU_KATA_UPPER,
    PE_HIRA_UPPER,
    PE_KATA_UPPER,
    PO_HIRA_UPPER,
    PO_KATA_UPPER,
};

typedef union {
    uint32_t raw;
    struct {
        bool     config_written :1;
    };
} user_config_t;
