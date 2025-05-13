// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later
#include QMK_KEYBOARD_H

#include "keymap_spanish.h"

enum sofle_layers {
    /* _M_XYZ = Mac Os, _W_XYZ = Win/Linux */
    _QWERTY,
    _SPANISH,
    _LOWER,
    _RAISE,
    _ADJUST,
};

#define KC_QWERTY PDF(_QWERTY)
#define KC_SPANISH PDF(_SPANISH)

#define KC_C_TAB LCMD(KC_TAB)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  `   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  | Bspc |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | ESC  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  -   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|  MUTE |    |  PLAY |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LCTR | LAlt | LCMD |LOWER | /Enter  /       \Space \  |RAISE | RCMD | RAlt |  =   |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */

[_QWERTY] = LAYOUT(
  KC_GRV,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                     KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_BSPC,
  KC_ESC,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_MINS,
  KC_TAB,   KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                     KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,
  KC_LSFT,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B, KC_MUTE,    KC_MPLY,KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_RSFT,
                   KC_LCTL,KC_LALT,KC_LCMD, TL_LOWR, KC_ENT,      KC_SPC,  TL_UPPR, KC_RCMD, KC_RALT, KC_EQL
),
/*
 * SPANISH
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  `   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  | Bspc |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | ESC  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  ´   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   Ñ  |  Ç   |
 * |------+------+------+------+------+------|  MUTE |    |  PLAY |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LCTR | LAlt | LCMD |LOWER | /Enter  /       \Space \  |RAISE | RCMD | RAlt |  =   |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */

[_SPANISH] = LAYOUT(
  KC_GRV,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                     KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_BSPC,
  KC_ESC,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, ES_ACUT,
  KC_TAB,   KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                     KC_H,    KC_J,    KC_K,    KC_L, ES_NTIL, ES_CCED,
  KC_LSFT,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B, KC_MUTE,    KC_MPLY,KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_RSFT,
                   KC_LCTL,KC_LALT,KC_LCMD, TL_LOWR, KC_ENT,      KC_SPC,  TL_UPPR, KC_RCMD, KC_RALT, KC_EQL
),
/* LOWER
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  `   |  F1  |  F2  |  F3  |  F4  |  F5  |                    |  F6  |  F7  |  F8  |  F9  | F10  | F11  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Esc  |   1  |   2  |   3  |   4  |   5  |                    | PGUP | PWrd |  Up  | NWrd | DelLn| F12  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | C+Tab|   ]  |   }  |   )  |   |  |   -  |-------.    ,-------| PGDN | Left | Down | Rigth|  Del | Bspc |
 * |------+------+------+------+------+------|  MUTE |    |  PLAY |------+------+------+------+------+------|
 * |LShift|   [  |   {  |   (  |   \  |   =  |-------|    |-------|      | LnStr|      | LnEnd|      | Shift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LCTR | LAlt | LCMD |LOWER | /Enter  /       \Space \  |RAISE | RCMD | RAlt |  =   |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'            '------''---------------------------'
 */
[_LOWER] = LAYOUT(
  _______,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                     KC_F6,   KC_F7,      KC_F8,   KC_F9,      KC_F10,     KC_F11,
  _______,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                     KC_PGUP, A(KC_LEFT), KC_UP,   A(KC_RIGHT),G(KC_BSPC), KC_F12,
  KC_C_TAB,KC_RBRC, KC_RCBR, KC_RPRN, KC_PIPE, KC_MINS,                     KC_PGDN, KC_LEFT,    KC_DOWN, KC_RGHT,    KC_DEL,     KC_BSPC,
  _______, KC_LBRC, KC_LCBR, KC_LPRN, KC_BSLS,  KC_EQL, _______,   _______, XXXXXXX, KC_HOME,    XXXXXXX, KC_END,     XXXXXXX,    _______,
                    _______, _______, _______, _______, _______,   _______, _______, _______, _______, _______
),
/* RAISE
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  `   |  F1  |  F2  |  F3  |  F4  |  F5  |                    |  F6  |  F7  |  F8  |  F9  | F10  | F11  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Esc  |   1  |   2  |   3  |   4  |   5  |                    | PGUP | PWrd |  Up  | NWrd | DelLn| F12  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | C+Tab|   ]  |   }  |   )  |   |  |   -  |-------.    ,-------| PGDN | Left | Down | Rigth|  Del | Bspc |
 * |------+------+------+------+------+------|  MUTE |    |  PLAY |------+------+------+------+------+------|
 * |LShift|   [  |   {  |   (  |   \  |   =  |-------|    |-------|      | LnStr|      | LnEnd|      | Shift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LCTR | LAlt | LCMD |LOWER | /Enter  /       \Space \  |RAISE | RCMD | RAlt |  =   |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'            '------''---------------------------'
 */
[_RAISE] = LAYOUT(
  _______,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                     KC_F6,   KC_F7,      KC_F8,   KC_F9,      KC_F10,     KC_F11,
  _______,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                     KC_PGUP, A(KC_LEFT), KC_UP,   A(KC_RIGHT),G(KC_BSPC), KC_F12,
  KC_C_TAB,KC_RBRC, KC_RCBR, KC_RPRN, KC_PIPE, KC_MINS,                     KC_PGDN, KC_LEFT,    KC_DOWN, KC_RGHT,    KC_DEL,     KC_BSPC,
  _______, KC_LBRC, KC_LCBR, KC_LPRN, KC_BSLS,  KC_EQL, _______,   _______, XXXXXXX, KC_HOME,    XXXXXXX, KC_END,     XXXXXXX,    _______,
                    _______, _______, _______, _______, _______,   _______, _______, _______, _______, _______
),
/* ADJUST
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |QK_BOOT|QWERTY|SPANISH|    |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |     |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      | PREV | PLAY | NEXT |      |      |
 * |------+------+------+------+------+------|  MUTE |    |  PLAY |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------|      | VOLDO| MUTE | VOLUP|      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LCTR | LAlt | LCMD |LOWER | /Enter  /       \Space \  |RAISE | RCMD | RAlt |  =   |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
  [_ADJUST] = LAYOUT(
  QK_BOOT, KC_QWERTY, KC_SPANISH,  XXXXXXX,    XXXXXXX, XXXXXXX,               XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,      _______, XXXXXXX, KC_MPRV, KC_MPLY, KC_MNXT, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                        XXXXXXX, KC_VOLD, KC_MUTE, KC_VOLU, XXXXXXX, XXXXXXX,
                   _______, _______, _______, _______, _______,        _______, _______, _______, _______, _______
  )
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_PGUP, KC_PGDN) },
    { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_PGUP, KC_PGDN) },
    { ENCODER_CCW_CW(KC_VOLD, KC_UP  ), ENCODER_CCW_CW(KC_PGUP, KC_DOWN) },
    { ENCODER_CCW_CW(KC_VOLD, KC_UP  ), ENCODER_CCW_CW(KC_PGUP, KC_DOWN) },
    { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_PGUP, KC_PGDN) },
};
#endif

#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (!is_keyboard_master()) {
        return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
    }

    return rotation;
}

static void render_logo(void) {
    static const char PROGMEM qmk_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x8D, 0x8E, 0x8F, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0xAA, 0xAB, 0xAC, 0xAD, 0xAE, 0xAF, 0xB0, 0xB1, 0xB2, 0xB3, 0xB4,
        0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0xCA, 0xCB, 0xCC, 0xCD, 0xCE, 0xCF, 0xD0, 0xD1, 0xD2, 0xD3, 0xD4, 0x00
    };

    oled_write_P(qmk_logo, false);
    oled_write_P(PSTR("\n\n"), false);
    oled_write_ln_P(PSTR("tkanzakic"), false);
}

static void print_status_narrow(void) {
    // Print current layer
    oled_write_ln_P(PSTR("LAYER"), false);
    switch (get_highest_layer(layer_state)) {
        case _QWERTY:
            oled_write_P(PSTR("Base\n"), false);
            break;
        case _SPANISH:
            oled_write_P(PSTR("Spanish\n"), false);
            break;
        case _RAISE:
            oled_write_P(PSTR("Raise Fn"), false);
            break;
        case _LOWER:
            oled_write_P(PSTR("Lower Fn"), false);
            break;
        case _ADJUST:
            oled_write_P(PSTR("Adj\n"), false);
            break;
        default:
            oled_write_ln_P(PSTR("Undef"), false);
    }
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        print_status_narrow();
    } else {
        render_logo();  // Renders a static logo
        // oled_scroll_left();  // Turns on scrolling
    }
    return false;
}
#endif
