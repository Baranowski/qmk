// Copyright 2023 Wojciech Baranowski
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
enum layer_names {
    l_alpha,
    l_num,
    l_func,
    l_special

};
#define FUNCS  MO(l_func)
#define NUMS MO(l_num)
#define SPEC OSL(l_special)
#define SPC_CTR LCTL_T(KC_SPC)
#define SFT_ONE OSM(MOD_LSFT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [l_alpha] = LAYOUT_4x8_10(
        KC_Q,    KC_W,    KC_S,    KC_R,                      KC_U,    KC_I,    KC_O,    KC_P,   
        KC_A,    KC_E,    KC_D,    KC_T,                      KC_H,    KC_J,    KC_K,    KC_L,   
                 KC_X,    KC_C,    KC_V,                      KC_N,    KC_M,    KC_B,
        KC_TAB,  KC_Z,    KC_G,    KC_F,                      KC_Y,    KC_COMM, KC_DOT,  KC_ENT,
        KC_LALT, XXXXXXX, FUNCS,   SPC_CTR, KC_LGUI, KC_RALT, SFT_ONE, NUMS,    KC_ESC,  KC_BSPC
    ),
    [l_num] = LAYOUT_4x8_10(
        KC_GRV,  KC_PLUS, KC_LCBR, KC_RCBR,                   KC_7,    KC_8,    KC_9,    KC_ASTR,
        KC_DQUO, KC_EQL,  KC_LT,   KC_GT,                     KC_4,    KC_5,    KC_6,    KC_SLSH,
                 KC_MINUS,KC_LPRN, KC_RPRN,                   KC_1,    KC_2,    KC_3,
        KC_QUOT, KC_SCLN, KC_LBRC, KC_RBRC,                   KC_0,    KC_QUES, KC_EXLM, _______,
        _______, _______, SPEC,    _______, _______, _______, _______, _______, _______, _______
    ),
    [l_func] = LAYOUT_4x8_10(
        XXXXXXX, KC_AT,   KC_CIRC, KC_DLR,                    KC_DEL,  KC_PGDN, KC_PGUP, KC_BSPC,
        KC_PERC, KC_BSLS, KC_TILD, KC_UNDS,                   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT,
                 KC_HASH, KC_PIPE, KC_AMPR,                   KC_BRIU, KC_VOLU, KC_BSPC,
        XXXXXXX, KC_COLN, XXXXXXX, XXXXXXX,                   KC_BRID, KC_VOLD, XXXXXXX, _______,
        _______, _______, _______, _______, _______, _______, _______, SPEC,    _______, _______
    ),
    [l_special] = LAYOUT_4x8_10(
        XXXXXXX, KC_F1,   KC_F2,   KC_F3,                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, KC_F4,   KC_F5,   KC_F6,                     KC_HOME, KC_INS,  KC_PSCR, KC_END, 
                 KC_F7,   KC_F8,   KC_F9,                     XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, KC_F10,  KC_F11,  KC_F12,                    XXXXXXX, KC_MUTE, XXXXXXX, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    )
};

const uint16_t PROGMEM flash_combo[] = {KC_U, KC_P, KC_RALT, COMBO_END};
combo_t key_combos[] = {
    COMBO(flash_combo, QK_BOOT),
};