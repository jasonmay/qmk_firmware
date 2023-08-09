/* Copyright 2021 @ Keychron (https://www.keychron.com)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H

// clang-format off

enum layers{
    MAC_BASE,
    WIN_BASE,
    _FN1,
    _FN2,
    _FN3
};

#define KC_TASK LGUI(KC_TAB)
#define KC_FLXP LGUI(KC_E)

#define XX_ESC LCTL_T(KC_ESC)

const uint16_t PROGMEM test_combo1[] = {KC_J, KC_K, KC_A, COMBO_END};
const uint16_t PROGMEM test_combo2[] = {KC_J, KC_K, KC_S, COMBO_END};
const uint16_t PROGMEM test_combo3[] = {KC_J, KC_K, KC_D, COMBO_END};
const uint16_t PROGMEM test_combo4[] = {KC_J, KC_K, KC_F, COMBO_END};
const uint16_t PROGMEM test_combo5[] = {KC_J, KC_K, KC_G, COMBO_END};
const uint16_t PROGMEM test_combo6[] = {KC_D, KC_F, KC_H, COMBO_END};
const uint16_t PROGMEM test_combo7[] = {KC_D, KC_F, KC_J, COMBO_END};
const uint16_t PROGMEM test_combo8[] = {KC_D, KC_F, KC_K, COMBO_END};
const uint16_t PROGMEM test_combo9[] = {KC_D, KC_F, KC_L, COMBO_END};
const uint16_t PROGMEM test_combo0[] = {KC_D, KC_F, KC_SCLN, COMBO_END};

const uint16_t PROGMEM test_combo_s1[] = {KC_J, KC_K, KC_L, KC_A, COMBO_END};
const uint16_t PROGMEM test_combo_s2[] = {KC_J, KC_K, KC_L, KC_S, COMBO_END};
const uint16_t PROGMEM test_combo_s3[] = {KC_J, KC_K, KC_L, KC_D, COMBO_END};
const uint16_t PROGMEM test_combo_s4[] = {KC_J, KC_K, KC_L, KC_F, COMBO_END};
const uint16_t PROGMEM test_combo_s5[] = {KC_J, KC_K, KC_L, KC_G, COMBO_END};
const uint16_t PROGMEM test_combo_s6[] = {KC_S, KC_D, KC_F, KC_H, COMBO_END};
const uint16_t PROGMEM test_combo_s7[] = {KC_S, KC_D, KC_F, KC_J, COMBO_END};
const uint16_t PROGMEM test_combo_s8[] = {KC_S, KC_D, KC_F, KC_K, COMBO_END};
const uint16_t PROGMEM test_combo_s9[] = {KC_S, KC_D, KC_F, KC_L, COMBO_END};
const uint16_t PROGMEM test_combo_s0[] = {KC_S, KC_D, KC_F, KC_SCLN, COMBO_END};
const uint16_t PROGMEM test_combo_sa[] = {KC_S, KC_D, KC_F, KC_QUOT, COMBO_END};

const uint16_t PROGMEM test_combo_plus[] = {KC_D, KC_F, KC_LBRC, COMBO_END};
const uint16_t PROGMEM test_combo_mins[] = {KC_D, KC_F, KC_RBRC, COMBO_END};
const uint16_t PROGMEM test_combo_under[] = {KC_F, KC_J, COMBO_END};
const uint16_t PROGMEM test_combo_eql[] = {KC_J, KC_K, KC_TAB, COMBO_END};

const uint16_t PROGMEM test_combo_g1[] = {KC_L, KC_K, KC_SCLN, KC_A, COMBO_END};
const uint16_t PROGMEM test_combo_g2[] = {KC_L, KC_K, KC_SCLN, KC_S, COMBO_END};
const uint16_t PROGMEM test_combo_g3[] = {KC_L, KC_K, KC_SCLN, KC_D, COMBO_END};
const uint16_t PROGMEM test_combo_g4[] = {KC_L, KC_K, KC_SCLN, KC_F, COMBO_END};
const uint16_t PROGMEM test_combo_g5[] = {KC_L, KC_K, KC_SCLN, KC_G, COMBO_END};
const uint16_t PROGMEM test_combo_g6[] = {KC_A, KC_S, KC_D, KC_H, COMBO_END};
const uint16_t PROGMEM test_combo_g7[] = {KC_A, KC_S, KC_D, KC_J, COMBO_END};
const uint16_t PROGMEM test_combo_g8[] = {KC_A, KC_S, KC_D, KC_K, COMBO_END};
const uint16_t PROGMEM test_combo_g9[] = {KC_A, KC_S, KC_D, KC_L, COMBO_END};
const uint16_t PROGMEM test_combo_g0[] = {KC_A, KC_S, KC_D, KC_SCLN, COMBO_END};

combo_t key_combos[] = {
    COMBO(test_combo1, KC_1),
    COMBO(test_combo2, KC_2),
    COMBO(test_combo3, KC_3),
    COMBO(test_combo4, KC_4),
    COMBO(test_combo5, KC_5),
    COMBO(test_combo6, KC_6),
    COMBO(test_combo7, KC_7),
    COMBO(test_combo8, KC_8),
    COMBO(test_combo9, KC_9),
    COMBO(test_combo0, KC_0),

    COMBO(test_combo_s1, S(KC_1)),
    COMBO(test_combo_s2, S(KC_2)),
    COMBO(test_combo_s3, S(KC_3)),
    COMBO(test_combo_s4, S(KC_4)),
    COMBO(test_combo_s5, S(KC_5)),
    COMBO(test_combo_s6, S(KC_6)),
    COMBO(test_combo_s7, S(KC_7)),
    COMBO(test_combo_s8, S(KC_8)),
    COMBO(test_combo_s9, KC_GRV),
    COMBO(test_combo_s0, KC_TILD),

    COMBO(test_combo_g1, LGUI(KC_1)),
    COMBO(test_combo_g2, LGUI(KC_2)),
    COMBO(test_combo_g3, LGUI(KC_3)),
    COMBO(test_combo_g4, LGUI(KC_4)),
    COMBO(test_combo_g5, LGUI(KC_5)),
    COMBO(test_combo_g6, LGUI(KC_6)),
    COMBO(test_combo_g7, LGUI(KC_7)),
    COMBO(test_combo_g8, LGUI(KC_8)),
    COMBO(test_combo_g9, LGUI(KC_9)),
    COMBO(test_combo_g0, LGUI(KC_0)),

    COMBO(test_combo_plus, KC_PLUS),
    COMBO(test_combo_mins, KC_MINS),
    COMBO(test_combo_eql, KC_EQL),
    COMBO(test_combo_under, S(KC_MINS)),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [MAC_BASE] = LAYOUT_ansi_52(
        KC_TAB,  KC_Q,     KC_W,     KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,     KC_LBRC,  KC_RBRC,  KC_BSPC,          KC_BSLS,
        XX_ESC,  KC_A,     KC_S,     KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,  KC_QUOT,            KC_ENT,           KC_HOME,
        SC_LSPO,           KC_Z,     KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,   KC_SLSH,            SC_RSPC, KC_UP,
        KC_LCTL, MO(_FN1),  KC_LCMD,                             KC_SPC,                             KC_RCMD,  KC_LOPT, MO(_FN3), KC_LEFT, KC_DOWN, KC_RGHT),

    [WIN_BASE] = LAYOUT_ansi_52(
        KC_TAB,  KC_Q,     KC_W,     KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,          KC_DEL,
        XX_ESC,  KC_A,     KC_S,     KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,  KC_QUOT,            KC_ENT,           KC_HOME,
        _______,           KC_Z,     KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,   KC_SLSH,            KC_RSFT, KC_UP,
        KC_LCTL, MO(_FN2),  KC_LALT,                             KC_SPC,                             KC_RALT,  KC_LGUI, MO(_FN3), KC_LEFT, KC_DOWN, KC_RGHT),

    [_FN1] = LAYOUT_ansi_52(
        KC_GRV,  KC_BRID,  KC_BRIU,  KC_NO,   KC_NO,   RGB_VAD, RGB_VAI, KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE,  KC_VOLD,  KC_VOLU,  _______,          _______,
        KC_1, KC_2,  KC_3,  KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, _______,  _______,            _______,          _______,
        _______,           RGB_RMOD, RGB_VAD, RGB_HUD, RGB_SAD, RGB_SPD, NK_TOGG, _______, _______, _______,  _______,            _______, _______,
        _______, _______,  _______,                             _______,                            _______,  _______,  _______,  _______, _______, _______),

    [_FN2] = LAYOUT_ansi_52(
        KC_GRV,  KC_BRID,  KC_BRIU,  KC_TASK, KC_FLXP, RGB_VAD, RGB_VAI, KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE,  KC_VOLD,  KC_VOLU,  _______,          _______,
        KC_1, KC_2,  KC_3,  KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, _______,  _______,            _______,          _______,
        _______,           RGB_RMOD, RGB_VAD, RGB_HUD, RGB_SAD, RGB_SPD, NK_TOGG, _______, _______, _______,  _______,            _______, _______,
        _______, _______,  _______,                             _______,                            _______,  _______,  _______,  _______, _______, _______),

    [_FN3] = LAYOUT_ansi_52(
        KC_TILD, KC_F1,    KC_F2,    KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,   KC_F11,   KC_F12,   KC_BSLS,          KC_MPLY,
        KC_ESC,  KC_1,     KC_2,     KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,     _______,            _______,          KC_MUTE,
        _______,           _______,  _______, _______, _______, _______, _______, _______, _______, _______,  _______,            _______, KC_HOME,
        _______, _______,  _______,                             _______,                            _______,  _______,  _______,  KC_PGUP, KC_END, KC_PGDN)
};
