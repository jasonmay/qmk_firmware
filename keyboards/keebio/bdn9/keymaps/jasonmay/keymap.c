/* Copyright 2019 Danny Nguyen <danny@keeb.io>
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

#include "quantum.h"

enum encoder_names {
  _LEFT,
  _RIGHT,
  _MIDDLE,
};

enum custom_keycodes {
  DUMMY_ENUM = SAFE_RANGE,
  TMUX_PREV,
  TMUX_NEXT,
  TILDE_SLASH,
  VIM_WINDOW_ONLY,
  VIM_WINDOW_LEFT,
  VIM_WINDOW_RIGHT,
  VIM_WINDOW_UP,
  VIM_WINDOW_DOWN,
  TMUX_PANE_LEFT,
  TMUX_PANE_RIGHT,
  TMUX_PANE_UP,
  TMUX_PANE_DOWN,
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        TMUX_PANE_LEFT, VIM_WINDOW_UP, TMUX_PANE_RIGHT,
        VIM_WINDOW_LEFT, QK_BOOT,       VIM_WINDOW_RIGHT,
        TILDE_SLASH,     VIM_WINDOW_DOWN,   VIM_WINDOW_ONLY
    ),
    // [1] = LAYOUT(
    //     QK_BOOT  , BL_STEP, KC_STOP,
    //     _______, _______, RGB_MOD,
    //     KC_MPRV, QK_BOOT , KC_MNXT
    // ),
};

// void keyboard_post_init_user(void) {
//     rgblight_sethsv(RGB_TEAL);
//     rgb_matrix_mode(RGB_MATRIX_SOLID_REACTIVE_SIMPLE);
// }

// const uint16_t PROGMEM boot_combo[] = {KC_1, KC_9, COMBO_END};
// const uint16_t PROGMEM k1_combo[] = {KC_1, KC_2, COMBO_END};
// const uint16_t PROGMEM k2_combo[] = {KC_2, KC_3, COMBO_END};
// const uint16_t PROGMEM k3_combo[] = {KC_3, KC_4, COMBO_END};
// const uint16_t PROGMEM k4_combo[] = {KC_4, KC_5, COMBO_END};
// const uint16_t PROGMEM k5_combo[] = {KC_5, KC_6, COMBO_END};
// const uint16_t PROGMEM k6_combo[] = {KC_6, KC_7, COMBO_END};
// const uint16_t PROGMEM k7_combo[] = {KC_7, KC_8, COMBO_END};
// const uint16_t PROGMEM k8_combo[] = {KC_8, KC_9, COMBO_END};
//
// const uint16_t PROGMEM vo_combo[] = {KC_4, KC_6, COMBO_END};
//
// const uint16_t PROGMEM tu_combo[] = {KC_1, KC_3, COMBO_END};
// const uint16_t PROGMEM td_combo[] = {KC_7, KC_9, COMBO_END};
// const uint16_t PROGMEM tl_combo[] = {KC_1, KC_7, COMBO_END};
// const uint16_t PROGMEM tr_combo[] = {KC_3, KC_9, COMBO_END};

// combo_t key_combos[COMBO_COUNT]  = {
//   COMBO(boot_combo, QK_BOOT),
//   COMBO(k1_combo, S(KC_1)),
//   COMBO(k2_combo, S(KC_2)),
//   COMBO(k3_combo, S(KC_3)),
//   COMBO(k4_combo, S(KC_4)),
//   COMBO(k5_combo, S(KC_5)),
//   COMBO(k6_combo, S(KC_6)),
//   COMBO(k7_combo, S(KC_7)),
//   COMBO(k8_combo, S(KC_8)),
//
//   COMBO(vo_combo, VIM_WINDOW_ONLY),
//
//   COMBO(tu_combo, TMUX_PANE_UP),
//   COMBO(td_combo, TMUX_PANE_DOWN),
//   COMBO(tl_combo, TMUX_PANE_LEFT),
//   COMBO(tr_combo, TMUX_PANE_RIGHT),
// };


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case TMUX_PREV:
      if (record->event.pressed) {
        SEND_STRING(SS_LCTL("f")"p");
        return false;
      }
      break;
    case TMUX_NEXT:
      if (record->event.pressed) {
        SEND_STRING(SS_LCTL("f")"n");
        return false;
      }
      break;
    case VIM_WINDOW_ONLY:
      if (record->event.pressed) {
        SEND_STRING(SS_LCTL("w")"o");
        return false;
      }
      break;
    case VIM_WINDOW_LEFT:
      if (record->event.pressed) {
        SEND_STRING(SS_LCTL("w")"h");
        return false;
      }
      break;
    case VIM_WINDOW_RIGHT:
      if (record->event.pressed) {
        SEND_STRING(SS_LCTL("w")"l");
        return false;
      }
      break;
    case VIM_WINDOW_UP:
      if (record->event.pressed) {
        SEND_STRING(SS_LCTL("w")"k");
        return false;
      }
      break;
    case VIM_WINDOW_DOWN:
      if (record->event.pressed) {
        SEND_STRING(SS_LCTL("w")"j");
        return false;
      }
      break;
    case TMUX_PANE_UP:
      if (record->event.pressed) {
        tap_code16(C(KC_F));
        tap_code(KC_UP);
        return false;
      }
      break;
    case TMUX_PANE_DOWN:
      if (record->event.pressed) {
        tap_code16(C(KC_F));
        tap_code(KC_DOWN);

        return false;
      }
      break;
    case TMUX_PANE_LEFT:
      if (record->event.pressed) {
        tap_code16(C(KC_F));
        tap_code(KC_LEFT);
        return false;
      }
      break;
    case TMUX_PANE_RIGHT:
      if (record->event.pressed) {
        tap_code16(C(KC_F));
        tap_code(KC_RIGHT);
        return false;
      }
      break;
    case TILDE_SLASH:
      if (record->event.pressed) {
        SEND_STRING("~/");
        return false;
      }
      break;
  }
  return true;
}
