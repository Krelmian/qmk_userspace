// Copyright 2025 Carsten Thiel (@schildwaechter)
// SPDX-License-Identifier: GPL-2.0-or-later

/*
make avalanche/v4:schildwaechter
*/

#include QMK_KEYBOARD_H

enum layer {
    LAYER_0,
    LAYER_1,
    LAYER_2,
    LAYER_3,
};

#ifdef OLED_ENABLE

void render_mod_indicators(void) {
//    oled_clear();  // somehow it disables the OLED OFF timeout?????
    oled_set_cursor(0,1);
    oled_write_P(PSTR("Avalanche 4.2\nCaT's Layout"), false);
    uint8_t mods = get_mods() | get_oneshot_mods();

    oled_set_cursor(16,1);
    if (mods & MOD_MASK_SHIFT) {
        oled_write_P(PSTR("SFT"), false);
    } else {
        oled_write_P(PSTR("   "), false);
    }
    oled_set_cursor(16,2);
    if (mods & MOD_MASK_ALT) {
        oled_write_P(PSTR("ALT"), false);
    } else {
        oled_write_P(PSTR("   "), false);
    }
    oled_set_cursor(16,3);
    if (mods & MOD_MASK_CTRL) {
        oled_write_P(PSTR("CTL"), false);
    } else {
        oled_write_P(PSTR("   "), false);
    }
    oled_set_cursor(16,4);
    if (mods & MOD_MASK_GUI) {
        oled_write_P(PSTR("GUI"), false);
    } else {
        oled_write_P(PSTR("   "), false);
    }
}

bool oled_task_user() {
    render_mod_indicators();

    oled_set_cursor(0,6);
    switch (get_highest_layer(layer_state)) {
        case LAYER_0 :
            oled_write_ln_P(PSTR("Main Layer"), false);
            break;
        case LAYER_1 :
            oled_write_ln_P(PSTR("UP (Main)"), false);
            break;
        case LAYER_2 :
            oled_write_ln_P(PSTR("HomeRow Layer"), false);
            break;
        case LAYER_3 :
            oled_write_ln_P(PSTR("UP (HomeRow)"), false);
            break;
    }

    return false;
}
#endif

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {                                                                    //
    [LAYER_0] = LAYOUT(
                 KC_GRV,  KC_1,         KC_2,         KC_3,           KC_4,         KC_5,                                                                     KC_6,            KC_7,         KC_8,         KC_9,         KC_0,            KC_MINS,
                 KC_TAB,  KC_Q,         KC_W,         KC_E,           KC_R,         KC_T,                                                                     KC_Y,            KC_U,         KC_I,         KC_O,         KC_P,            KC_BSLS,
        XXXXXXX, KC_LSFT, KC_A,         KC_S,         KC_D,           KC_F,         KC_G,                                                                     KC_H,            KC_J,         KC_K,         KC_L,         KC_SCLN,         KC_RSFT, XXXXXXX,
                 KC_LCTL, KC_Z,         KC_X,         KC_C,           KC_V,         KC_B,           XXXXXXX,             KC_MUTE,    XXXXXXX, XXXXXXX,        KC_N,            KC_M,         KC_COMM,      KC_DOT,       KC_SLSH,         KC_RCTL,
                                                      XXXXXXX,        MEH(KC_NO),   RALT_T(KC_SPC), LT(LAYER_1, KC_ENT), XXXXXXX,    XXXXXXX, LCMD_T(KC_ESC), RALT_T(KC_BSPC), HYPR(KC_NO),  XXXXXXX
    ),                                                                                                                            //
    [LAYER_1] = LAYOUT(
                 _______, KC_BRID,      KC_BRIU,      KC_MPRV,        KC_MPLY,      KC_MNXT,                                                                  KC_MUTE,         KC_VOLD,      KC_VOLU,      KC_LBRC,      KC_RBRC,         KC_EQL,
                 _______, LCG(KC_Q),    XXXXXXX,      XXXXXXX,        QK_BOOT,      LCMD(KC_T),                                                               XXXXXXX,         XXXXXXX,      XXXXXXX,      KC_LBRC,      KC_RBRC,         KC_EQL,
        _______, _______, LCMD(KC_A),   LCMD(KC_S),   XXXXXXX,        LCMD(KC_F),   XXXXXXX,                                                                  KC_LEFT,         KC_DOWN,      KC_UP,        KC_RGHT,      XXXXXXX,         KC_QUOT,         _______,
                 _______, LCMD(KC_Z),   LCMD(KC_X),   LCMD(KC_C),     LCMD(KC_V),   XXXXXXX,        _______,             _______,    _______, _______,        KC_HOME,         KC_PGDN,      KC_PGUP,      KC_END,       _______,         _______,
                                                      _______,        _______,      _______,        _______,             _______,    _______, LCMD(KC_SPC),   RALT_T(KC_DEL),  _______,      _______
    ),                                                                                                                            //

};

