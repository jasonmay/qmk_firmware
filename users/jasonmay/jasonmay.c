#include "jasonmay.h"

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
#ifdef CONSOLE_ENABLE
  uprintf("PRU: %u, pressed: %u, i:%u M:%u%u%u%u\n", keycode, record->event.pressed, record->tap.interrupted, lshift, lgui, ralt, rshift);
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
    // code16 is overkill but this used to be {} so it was once necessary
    case XX_CBRC:
      if (chorded) {
        tap_code16(KC_LBRC);
        return false;
      }
      break;
    case XX_ABRC:
      if (chorded) {
        tap_code16(KC_RBRC);
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
