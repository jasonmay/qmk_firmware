/* Copyright 2020 ZSA Technology Labs, Inc <@zsa>
 * Copyright 2020 Jack Humbert <jack.humb@gmail.com>
 * Copyright 2020 Christopher Courtney, aka Drashna Jael're  (@drashna) <drashna@live.com>
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
# define XX_SAFE_RANGE ML_SAFE_RANGE
#include "jm_common.h"

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT_moonlander(
    KC_EQL,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    _______,           _______, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,
    XX_RTAB, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    _______,           _______, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
    XX_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    _______,           _______, KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    KC_LSPO,  KC_Z,    KC_X,   KC_C,    KC_V,    KC_B,                                KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSPC,
    _______,WEBUSB_PAIR,_______,KC_LGUI,XX_CCBR,          _______,           _______,          XX_ACBR, _______, _______, _______, _______,
                                          XX_LJM,  KC_ENT,_______,           _______, KC_BSPC, KC_SPC
  ),

  [_LOWER] = LAYOUT_moonlander(
    KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, _______,           _______, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC,
    XX_LWIN, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    _______,           _______, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    XX_RWIN,
    KC_DEL,  XX_LWKS, _______, _______, XX_XPOS, _______, _______,           _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT,XX_RWKS, KC_PIPE,
    _______, _______, _______, _______, _______, XX_BBK,                              XX_BFD,  _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______,          _______,           XX_XPOS,          XX_FWIN, _______, _______, _______, _______,
                                        _______, _______, _______,           _______, KC_LCBR, KC_RCBR
 ),

  [_RAISE] = LAYOUT_moonlander(
    KC_F12,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,  LED_LEVEL,TOGGLE_LAYER_COLOR,KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
    _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, _______,           _______, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______,
    RGB_MOD, KC_MPRV, KC_MNXT, KC_VOLU, KC_PGUP, _______, _______,           _______, _______, _______, RGB_HUI, RGB_SAI, RGB_VAI, KC_BSLS,
    KC_MUTE, KC_MSTP, KC_MPLY, KC_VOLD, KC_PGDN, _______,                             _______, _______, RGB_HUD, RGB_SAD, RGB_VAD, _______,
    _______, _______, _______, _______, _______,          BL_STEP,           RGB_TOG,          RESET,   _______, _______, _______, _______,
                                        _______, _______, _______,           _______, _______, _______
  ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  uint16_t lshift = (get_mods() & MOD_BIT(KC_LSFT));
  uint16_t rshift = (get_mods() & MOD_BIT(KC_RSFT));
  // for second press of mod/layer tap combo
  bool chorded = (record->tap.count && record->event.pressed);
#ifdef CONSOLE_ENABLE
  uprintf("PRU: %u, pressed: %u, i:%u LS:%u, RS:%u\n", keycode, record->event.pressed, record->tap.interrupted, lshift, rshift);
#endif

  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    // make rolling )( work
    case KC_LSPO:
      if (record->event.pressed && rshift == MOD_BIT(KC_RSFT)) {
        tap_code(KC_0);
      }
      break;
    // make rolling () work
    case KC_RSPC:
      if (record->event.pressed && lshift == MOD_BIT(KC_LSFT)) {
        tap_code(KC_9);
      }
      break;
    case XX_CCBR:
      if (chorded) {
        tap_code16(KC_LCBR);
        return false;
      }
      break;
    case XX_ACBR:
      if (chorded) {
        tap_code16(KC_RCBR);
        return false;
      }
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
      } else {
        layer_off(_LOWER);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
      } else {
        layer_off(_RAISE);
      }
      return false;
      break;
    case XX_LJM:
      if (chorded) {
        SEND_STRING("\\ks");
        return false;
      }
      break;
  }
  return true;
}

bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case XX_LJM:
    case XX_ESC:
    case KC_LSFT:
    case KC_RSFT:
    case KC_LGUI:
    case KC_RALT:
      return true;
    default:
        return false;
    }
}
