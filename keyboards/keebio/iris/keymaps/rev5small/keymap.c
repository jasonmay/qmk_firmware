#include QMK_KEYBOARD_H

#include "config.h"
#include "quantum.h"
#include "action.h"
#include "version.h"


enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  JMSEQ, // sequence for jason may (for env-determined vim dev stuff)
};

bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
  uint16_t lshift = (get_mods() & MOD_BIT(KC_LSFT));
  uint16_t rshift = (get_mods() & MOD_BIT(KC_RSFT));
  // for second press of mod/layer tap combo
  bool chorded = (record->tap.count && record->event.pressed);
  static bool lgui_pressed = false;
  static bool lgui_interrupted = false;
  bool reset_lgui_interrupted = false;

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
    case XX_LJM:
      if (chorded) {
        SEND_STRING("\\ks");
        return false;
      }
      break;
  }
  return true;
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_EQL,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                               KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     XX_RTAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                               KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     XX_ESC,   KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                               KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     SC_LSPO,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,   XX_LTU,           XX_RTU,   KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,SC_RSPC,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    XX_LTO,  XX_LTM,  XX_LTI,                    XX_RTI,  XX_RTM,  XX_RTO
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_LEFTY] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_EQL,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                               _______,    _______,    _______,    _______,    _______,    _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                               _______,    KC_UP,    _______,    _______,    _______,    _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     XX_ESC,   KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                               KC_LEFT,    KC_DOWN,    KC_RIGHT,    _______,    _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     SC_LSPO,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,   XX_LTI,           _______,   _______,    _______,    _______, _______,  _______,_______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    XX_LTO,  LT(_LEFTY2, KC_SPC),  KC_BSPC,      _______,  _______,  _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),
  [_LOWER] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                            KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     XX_LWIN,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                               KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  XX_RWIN,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_DEL,  XX_LWKS, KC_HOME, _______, XX_XPOS, _______,                            KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT,XX_RWKS, KC_PIPE,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_GRV,  _______, KC_END, _______, _______,  XX_BBK,  XX_LTU,           XX_RTU,  XX_BFD,  KC_LCBR, KC_RCBR, _______, _______, _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴─── ─────┘
                                    XY_LTO,  XY_LTM,  XY_LTI,                    XY_RTI,  XY_RTM,  XY_RTO
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_RAISE] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_F12,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                              KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                            KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├───H────┼───J────┼───K────┼───L────┼───;────┼────────┤
     RGB_MOD, KC_MPRV, KC_MNXT, KC_VOLU, KC_PGUP, TO(_LEFTY),                         _______, _______, RGB_HUI, RGB_SAI, RGB_VAI, KC_BSLS,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_MUTE, KC_MSTP, KC_MPLY, KC_VOLD, KC_PGDN, _______, BL_STEP,          RGB_TOG, _______, _______, RGB_HUD, RGB_SAD, RGB_VAD, _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______,                   _______, _______, QK_BOOT
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),
  [_LEFTY2] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_MINS,  KC_0,    KC_9,    KC_8,    KC_7,    KC_6,                               _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_BSLS,  KC_P,    KC_O,    KC_I,    KC_U,    KC_Y,                               _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_QUOT,  KC_SCLN, KC_L,    KC_K,    KC_J,    KC_H,                               _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     SC_RSPC,  KC_SLSH, KC_DOT,  KC_COMM, KC_M,    KC_N,   KC_LBRC,          _______,  _______, _______, _______, _______, _______, _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    XX_RTO,  _______,  KC_RBRC,                  _______, TO(_QWERTY), _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
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

