#include "jasonmay.h"

#ifndef SKIP_USERSPACE_PROCESSING
__attribute__ ((weak))
bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
  return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  uint16_t lshift = (get_mods() & MOD_BIT(KC_LSFT));
  uint16_t rshift = (get_mods() & MOD_BIT(KC_RSFT));
  uint16_t lgui = (get_mods() & MOD_BIT(KC_LGUI));
  uint16_t ralt = (get_mods() & MOD_BIT(KC_RALT));
  // for second press of mod/layer tap combo
  bool chorded = (record->tap.count && record->event.pressed);
  static bool lgui_pressed = false;
  static bool lgui_interrupted = false;
  bool reset_lgui_interrupted = false;
#ifdef CONSOLE_ENABLE
  uprintf("PRU: %u, pressed: %u, i:%u M:%u%u%u%u\n", keycode, record->event.pressed, record->tap.interrupted, lshift, lgui, ralt, rshift);
#endif

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
#endif

