#include QMK_KEYBOARD_H
#include "jasonmay.h"

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_QWERTY] = LAYOUT_ergodox_pretty(
  // left hand
  KC_EQL,  KC_1,    KC_2,    KC_3,    KC_4,   KC_5, KC_TRNS,         KC_TRNS, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,
  XX_RTAB, KC_Q,    KC_W,    KC_E,    KC_R,   KC_T, KC_TRNS,         KC_TRNS, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
  XX_ESC,  KC_A,    KC_S,    KC_D,    KC_F,   KC_G,                           KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  KC_LSPO, KC_Z,    KC_X,    KC_C,    KC_V,   KC_B, KC_TRNS,         KC_TRNS, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSPC,
  KC_GRV,  KC_TRNS, KC_TRNS, KC_LGUI, XX_LTO,                                          XX_RTO,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                                 XX_LTU, XX_LTU,     XX_RTU,  XX_RTU,
                                                         XX_LTU,     XX_RTU,
                                         XX_LTM, XX_LTI, XX_LTU,     XX_RTU,  XX_RTI,  XX_RTM
),
[_LOWER] = LAYOUT_ergodox_pretty(
  // left hand
  KC_TILD, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_TRNS,     KC_TRNS, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
  XX_LWIN, KC_EXLM, KC_AT,   KC_LCBR, KC_RCBR, KC_PIPE, KC_TRNS,     KC_TRNS, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    XX_RWIN,
  KC_TRNS, KC_HASH, KC_DLR,  KC_LPRN, KC_RPRN, KC_GRV,                        KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT,XX_RWKS, KC_TRNS,
  KC_TRNS, KC_PERC, KC_CIRC, KC_LBRC, KC_RBRC, XX_BBK,  XX_BFD,      XX_BFD,  XX_BFD,  KC_1,    KC_2,    KC_3,    KC_BSLS, KC_TRNS,
  EEP_RST, KC_TRNS, KC_TRNS, KC_TRNS, XY_LTO,                                          XY_RTO,  KC_DOT,  KC_0,    KC_EQL,  KC_TRNS,
                                               XY_LTU,  XY_LTU,      XY_RTU,  XY_RTU,
                                                        XY_LTU,      XY_RTU,
                                       XY_LTM, XY_LTI,  XY_LTU,      XY_RTU,  XY_RTI,  XY_RTM
),
[_RAISE] = LAYOUT_ergodox_pretty(
  // left hand
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_MS_U, KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  RGB_MOD, KC_TRNS, KC_MS_L, KC_MS_D, KC_MS_R, KC_TRNS,                       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MPLY,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS, RGB_HUI, RGB_SAI, RGB_VAI, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_BTN1, KC_BTN2,                                         KC_VOLU, RGB_HUD, RGB_SAD, RGB_VAD, KC_TRNS,

                                               KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS,
                                                        KC_TRNS,     RGB_TOG,
                                      KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, RESET
),
};
// clang-format on

// Runs just one time when the keyboard initializes.
void keyboard_post_init_keymap(void) {
#ifdef RGBLIGHT_COLOR_LAYER_0
    rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
#endif
};

// Runs whenever there is a layer state change.
bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
  return true;
}
