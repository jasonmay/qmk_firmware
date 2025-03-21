// Copyright 2022 beekeeb
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

// #include "config.h"
// #include "quantum.h"
// #include "action.h"
// #include "version.h"


#define _QWERTY 0
#define _LEFTY  1
#define _LOWER  2
#define _RAISE  3
#define _LEFTY2 4
#define _JMSEQ  5

// 1=esc, 2=ctrl
#define XX_ESC LCTL_T(KC_ESC)

// 1=vimcmd, 2=lower
// #define XX_LJM JMSEQ
#define XX_LJM MO(_LOWER)

// 1=tab, 2=raise
#define XX_RTAB LT(_RAISE, KC_TAB)

// mod-tap [] on cmd/alt respectively
#define XX_CBRC LGUI_T(S(KC_LBRC))
#define XX_ABRC RALT_T(S(KC_RBRC))

// expose on my mac
#define XX_XPOS LCTL(KC_UP)

// browser back/forward
#define XX_BBK LGUI(KC_LEFT)
#define XX_BFD LGUI(KC_RIGHT)

// navigate workspaces
#define XX_LWKS LALT(KC_LBRC)
#define XX_RWKS LALT(KC_RBRC)

// left thumb out/middle/in/up
#define XX_LTO XX_CBRC
#define XX_LTM XX_LJM
#define XX_LTI KC_ENT
#define XX_LTU XX_LWKS

// right thumb out/middle/in/up
#define XX_RTO XX_ABRC
#define XX_RTM KC_SPC
#define XX_RTI KC_BSPC
#define XX_RTU XX_RWKS

// same as above but on LOWER layer
// #ifdef _______
// #define XY_LTO _______
// #define XY_LTM _______
// #define XY_LTI _______
// #define XY_LTU _______
// #else
#define XY_LTO KC_TRNS
#define XY_LTM KC_TRNS
#define XY_LTI KC_TRNS
#define XY_LTU KC_TRNS
// #endif

#define XY_RTO XX_FWIN
#define XY_RTM KC_RCBR
#define XY_RTI KC_LCBR
#define XY_RTU XX_XPOS

// divvy shortcuts for work
#define DIVVY_MOD(K) LCTL(LALT(LGUI(K)))
#define XX_LWIN DIVVY_MOD(KC_B)
#define XX_RWIN DIVVY_MOD(KC_N)
#define XX_FWIN DIVVY_MOD(KC_F)

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  JMSEQ,
};

const uint16_t PROGMEM combo1[] = {KC_J, KC_K, KC_A, COMBO_END};
const uint16_t PROGMEM combo2[] = {KC_J, KC_K, KC_S, COMBO_END};
const uint16_t PROGMEM combo3[] = {KC_J, KC_K, KC_D, COMBO_END};
const uint16_t PROGMEM combo4[] = {KC_J, KC_K, KC_F, COMBO_END};
const uint16_t PROGMEM combo5[] = {KC_J, KC_K, KC_G, COMBO_END};
const uint16_t PROGMEM combo6[] = {KC_D, KC_F, KC_H, COMBO_END};
const uint16_t PROGMEM combo7[] = {KC_D, KC_F, KC_J, COMBO_END};
const uint16_t PROGMEM combo8[] = {KC_D, KC_F, KC_K, COMBO_END};
const uint16_t PROGMEM combo9[] = {KC_D, KC_F, KC_L, COMBO_END};
const uint16_t PROGMEM combo0[] = {KC_D, KC_F, KC_SCLN, COMBO_END};

const uint16_t PROGMEM combo_s1[] = {KC_J, KC_K, KC_L, KC_A, COMBO_END};
const uint16_t PROGMEM combo_s2[] = {KC_J, KC_K, KC_L, KC_S, COMBO_END};
const uint16_t PROGMEM combo_s3[] = {KC_J, KC_K, KC_L, KC_D, COMBO_END};
const uint16_t PROGMEM combo_s4[] = {KC_J, KC_K, KC_L, KC_F, COMBO_END};
const uint16_t PROGMEM combo_s5[] = {KC_J, KC_K, KC_L, KC_G, COMBO_END};
const uint16_t PROGMEM combo_s6[] = {KC_S, KC_D, KC_F, KC_H, COMBO_END};
const uint16_t PROGMEM combo_s7[] = {KC_S, KC_D, KC_F, KC_J, COMBO_END};
const uint16_t PROGMEM combo_s8[] = {KC_S, KC_D, KC_F, KC_K, COMBO_END};
const uint16_t PROGMEM combo_s9[] = {KC_S, KC_D, KC_F, KC_L, COMBO_END};
const uint16_t PROGMEM combo_s0[] = {KC_S, KC_D, KC_F, KC_SCLN, COMBO_END};
const uint16_t PROGMEM combo_sa[] = {KC_S, KC_D, KC_F, KC_QUOT, COMBO_END};

// KC_TAB eventually. just make it work for now so we have QK_BOOT
const uint16_t PROGMEM combo_eql[] = {KC_J, KC_K, XX_RTAB, COMBO_END};
const uint16_t PROGMEM combo_plus[] = {KC_J, KC_K, XX_ESC, COMBO_END};
const uint16_t PROGMEM combo_mins[] = {KC_D, KC_F, KC_QUOT, COMBO_END};
const uint16_t PROGMEM combo_under[] = {KC_F, KC_J, COMBO_END};

const uint16_t PROGMEM combo_g1[] = {KC_L, KC_K, KC_SCLN, KC_A, COMBO_END};
const uint16_t PROGMEM combo_g2[] = {KC_L, KC_K, KC_SCLN, KC_S, COMBO_END};
const uint16_t PROGMEM combo_g3[] = {KC_L, KC_K, KC_SCLN, KC_D, COMBO_END};
const uint16_t PROGMEM combo_g4[] = {KC_L, KC_K, KC_SCLN, KC_F, COMBO_END};
const uint16_t PROGMEM combo_g5[] = {KC_L, KC_K, KC_SCLN, KC_G, COMBO_END};
const uint16_t PROGMEM combo_g6[] = {KC_A, KC_S, KC_D, KC_H, COMBO_END};
const uint16_t PROGMEM combo_g7[] = {KC_A, KC_S, KC_D, KC_J, COMBO_END};
const uint16_t PROGMEM combo_g8[] = {KC_A, KC_S, KC_D, KC_K, COMBO_END};
const uint16_t PROGMEM combo_g9[] = {KC_A, KC_S, KC_D, KC_L, COMBO_END};
const uint16_t PROGMEM combo_g0[] = {KC_A, KC_S, KC_D, KC_SCLN, COMBO_END};

const uint16_t PROGMEM combo_left_space[] = {KC_R, KC_T, KC_Y, COMBO_END};
const uint16_t PROGMEM combo_right_space[] = {KC_R, KC_T, KC_P, COMBO_END};

const uint16_t PROGMEM combo_seq[] = {KC_J, KC_K, KC_L, COMBO_END};
const uint16_t PROGMEM combo_seq2[] = {KC_H, KC_J, KC_K, COMBO_END};

const uint16_t PROGMEM combo_fscreen[] = {KC_E, KC_R, KC_U, KC_I, COMBO_END};
const uint16_t PROGMEM combo_lscreen[] = {KC_W, KC_E, KC_R, COMBO_END};
const uint16_t PROGMEM combo_rscreen[] = {KC_U, KC_I, KC_O, COMBO_END};

combo_t key_combos[] = {
    COMBO(combo1, KC_1),
    COMBO(combo2, KC_2),
    COMBO(combo3, KC_3),
    COMBO(combo4, KC_4),
    COMBO(combo5, KC_5),
    COMBO(combo6, KC_6),
    COMBO(combo7, KC_7),
    COMBO(combo8, KC_8),
    COMBO(combo9, KC_9),
    COMBO(combo0, KC_0),
    COMBO(combo_s1, KC_EXLM),
    COMBO(combo_s2, KC_AT),
    COMBO(combo_s3, KC_HASH),
    COMBO(combo_s4, KC_DLR),
    COMBO(combo_s5, KC_PERC),
    COMBO(combo_s6, KC_CIRC),
    COMBO(combo_s7, KC_AMPR),
    COMBO(combo_s8, KC_ASTR),
    COMBO(combo_s9, KC_GRV),
    COMBO(combo_s0, KC_TILD),
    COMBO(combo_g1, LGUI(KC_1)),
    COMBO(combo_g2, LGUI(KC_2)),
    COMBO(combo_g3, LGUI(KC_3)),
    COMBO(combo_g4, LGUI(KC_4)),
    COMBO(combo_g5, LGUI(KC_5)),
    COMBO(combo_g6, LGUI(KC_6)),
    COMBO(combo_g7, LGUI(KC_7)),
    COMBO(combo_g8, LGUI(KC_8)),
    COMBO(combo_g9, LGUI(KC_9)),
    COMBO(combo_g0, LGUI(KC_0)),

    COMBO(combo_plus, KC_PLUS),
    COMBO(combo_mins, KC_MINS),
    COMBO(combo_eql, KC_EQL),
    COMBO(combo_under, KC_UNDS),

    COMBO(combo_left_space, LALT(KC_LBRC)),
    COMBO(combo_right_space, LALT(KC_RBRC)),

    COMBO(combo_seq, JMSEQ),
    COMBO(combo_seq2, JMSEQ),

    COMBO(combo_fscreen, XX_FWIN),
    COMBO(combo_lscreen, XX_LWIN),
    COMBO(combo_rscreen, XX_RWIN),
};


#define lshift (get_mods() & MOD_BIT(KC_LSFT))
#define rshift (get_mods() & MOD_BIT(KC_RSFT))


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  // for second press of mod/layer tap combo
  // bool chorded = (record->tap.count && record->event.pressed);
  static bool lgui_pressed = false;
  static bool lgui_interrupted = false;
  bool reset_lgui_interrupted = false;

  uprintf("keycode: %u\n", keycode);

  if (lgui_pressed && record->event.pressed) {
    if (keycode != XX_ABRC) {
      register_code(KC_LGUI);
    }
  }

  if (!lgui_pressed && !record->event.pressed) {
    unregister_code(KC_LGUI);
  }
  if (lgui_interrupted && keycode != XX_CBRC && !record->event.pressed) {
    reset_lgui_interrupted = true;
    lgui_interrupted = false;
  }
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    // make rolling )( work
    case SC_LSPO:
      if (record->event.pressed && rshift == MOD_BIT(KC_RSFT)) {
        tap_code(KC_0);
      }
      break;
    // make rolling () work
    case SC_RSPC:
      if (record->event.pressed && lshift == MOD_BIT(KC_LSFT)) {
        tap_code(KC_9);
      }
      break;
    // code16 is overkill but this used to be {} so it was once necessary
    case XX_CBRC:
      lgui_pressed = record->event.pressed;
      if (record->tap.interrupted) {
        lgui_interrupted = true;
        return false;
      }
      break;
    case XX_ABRC:
      if (record->event.pressed) {
        if(reset_lgui_interrupted || lgui_interrupted) {
          tap_code(KC_LBRC);
        }
        //unregister_code16(XX_CBRC);
        // return false;
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
    case JMSEQ:
      if (record->event.pressed) {
        register_code(KC_BSLS);
        register_code(KC_K);
        register_code(KC_S);
      } else {
        unregister_code(KC_BSLS);
        unregister_code(KC_K);
        unregister_code(KC_S);
      }
      return false;
      break;
  }
  return true;
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT_split_3x6_3(
     XX_RTAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                               KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
     XX_ESC,   KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                               KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
     SC_LSPO,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                               KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,SC_RSPC,
                                    XX_LTO,  XX_LTM,  XX_LTI,                    XX_RTI,  XX_RTM,  XX_RTO
  ),

  [_LOWER] = LAYOUT_split_3x6_3(
     XX_LWIN,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                               KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  XX_RWIN,
     KC_DEL,  XX_LWKS, KC_HOME, _______, XX_XPOS, _______,                            KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT,XX_RWKS, KC_PIPE,
     KC_GRV,  _______, KC_END, _______, _______,  XX_BBK,                             XX_BFD,  KC_LCBR, KC_RCBR, _______, _______, QK_BOOT,
                                    XY_LTO,  XY_LTM,  XY_LTI,                    XY_RTI,  XY_RTM,  XY_RTO
  ),
  [_RAISE] = LAYOUT_split_3x6_3(
     _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                            KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______,
     RGB_MOD, KC_MPRV, KC_MNXT, KC_VOLU, KC_PGUP, _______,                            _______, _______, RGB_HUI, RGB_SAI, RGB_VAI, KC_BSLS,
     KC_MUTE, KC_MSTP, KC_MPLY, KC_VOLD, KC_PGDN, _______,                            _______, _______, RGB_HUD, RGB_SAD, RGB_VAD, _______,
                                    _______, _______, _______,                   _______, _______, QK_BOOT
  ),
};

bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case XX_LJM:
    case XX_ESC:
    case KC_LSFT:
    case KC_RSFT:
    // case XX_RTO:
    // case XX_LTO:
      return true;
    default:
        return false;
    }
}

bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
  case XX_LTO:
    return true;
  default:
    return false;
  }
}

bool get_retro_tapping(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
  case XX_LTO:
    return true;
  default:
    return false;
  }
}

bool get_ignore_mod_tap_interrupt(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
  case XX_LTO:
    return true;
  default:
    return false;
  }
}

