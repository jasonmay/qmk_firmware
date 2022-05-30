#include QMK_KEYBOARD_H

#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _JMSEQ 3

// 1=esc, 2=ctrl
#define XX_ESC LCTL_T(KC_ESC)

// 1=], 2=lower
#define XX_LJM LT(_LOWER, JMSEQ)

// 1=[, 2=lower
// #define XX_RTAB LT(_RAISE, KC_TAB)
#define XX_RTAB LSFT_T(KC_TAB)

#define XX_CCBR LGUI_T(S(KC_LBRC))
#define XX_ACBR RALT_T(S(KC_RBRC))
// expose on my mac
#define XX_XPOS LCTL(KC_UP)
// browser back
#define XX_BBK LGUI(KC_LEFT)
// browser forward
#define XX_BFD LGUI(KC_RIGHT)

// navigate workspaces
#define XX_LWKS LALT(KC_LBRC)
#define XX_RWKS LALT(KC_RBRC)

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  JMSEQ, // sequences for jason may
};
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_EQL,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                               KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     XX_RTAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                               KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     XX_ESC,   KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                               KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LSPO,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_LBRC,          KC_RBRC,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,KC_RSPC,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    XX_CCBR, XX_LJM,  KC_ENT,                    KC_BSPC,  KC_SPC, XX_ACBR
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_LOWER] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                            KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     RESET,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                               KC_6,    KC_LBRC, KC_RBRC, KC_LCBR, KC_RCBR, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_DEL,  XX_LWKS, _______, _______, _______, _______,                            KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT,XX_RWKS, KC_PIPE,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     BL_STEP, _______, _______, _______, _______, XX_BBK,  KC_F3,            XX_XPOS,  XX_BFD, KC_LCBR, KC_RCBR, _______, _______, _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴─── ─────┘
                                    _______, _______, _______,                   KC_LCBR, KC_RCBR, KC_P0
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),

  [_RAISE] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_F12,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                              KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                            KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     RGB_MOD, KC_MPRV, KC_MNXT, KC_VOLU, KC_PGUP, KC_LCBR,                            KC_RCBR,  KC_HOME, RGB_HUI, RGB_SAI, RGB_VAI, KC_BSLS,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_MUTE, KC_MSTP, KC_MPLY, KC_VOLD, KC_PGDN, KC_LBRC, _______,          RGB_TOG, KC_RBRC, KC_END,  RGB_HUD, RGB_SAD, RGB_VAD, _______,
  //└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘
                                    _______, _______, _______,                   _______, _______, _______
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  uint16_t lshift = (get_mods() & MOD_BIT(KC_LSFT));
  uint16_t rshift = (get_mods() & MOD_BIT(KC_RSFT));
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
      if (record->tap.count && record->event.pressed) {
        tap_code16(KC_LCBR);
        return false;
      }
      break;
    case XX_ACBR:
      if (record->tap.count && record->event.pressed) {
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
      if (record->tap.count && record->event.pressed) {
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
