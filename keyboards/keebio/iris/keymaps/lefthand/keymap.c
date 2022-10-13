#include QMK_KEYBOARD_H

#define _FROG 0
#define _SYM 1
#define _NUM 2
#define _EXT 3
#define _WOO 4

enum custom_keycodes {
  JM_CMB = SAFE_RANGE,
  JM_HDM, // home dir macro
  JM_PRN, // open close
  JM_BRC, // open close
  JM_CBR, // open close
  JM_VKS, // vim universal execute key
};

// Layer Mode aliases
// #define BSP_EXT LT(_EXT,KC_BSPC)
#define OSYM OSL(_SYM)
#define ONUM OSL(_NUM)
#define OEXT OSL(_EXT)
#define OSFT OSM(MOD_LSFT)
#define OGUI OSM(MOD_LGUI)
#define ATAB LCA(KC_TAB)
#define OALT OSM(MOD_LALT)
#define OCTL OSM(MOD_LCTL)
#define CBSP C(KC_BSPC)
#define WLEFT LALT(KC_LBRC)
#define WRIGHT LALT(KC_RBRC)
#define OPW LGUI(KC_BSLS)
#define JNDO LGUI(KC_Z)
#define JCUT LGUI(KC_X)
#define JCPY LGUI(KC_C)
#define JPST LGUI(KC_V)
#define JSAV LGUI(KC_S)
#define JSFK LGUI(KC_ENT)

// #define JM_JUST_QWERTY

#define XW00 KC_SLSH
#define XW01 KC_LEFT
#define XW02 KC_DOWN
#define XW03 KC_UP
#define XW04 KC_RIGHT
#define XW05 OPW

#define XW10 KC_ESC
#define XW20 KC_BSPC
#define XW30 OSFT

#define XXW00 KC_BSLS
#define XXW01 JM_BRC
#define XXW02 JM_CBR
#define XXW03 JM_PRN
// TODO: repurpose
#define XXW04 _______
#define XXW05 _______

#define XXW10 KC_ENT
#define XXW20 OEXT
#define XXW30 _______

#ifdef JM_JUST_QWERTY

#define XW11 KC_Q
#define XW12 KC_W
#define XW13 KC_E
#define XW14 KC_R
#define XW15 KC_T

#define XW21 KC_A
#define XW22 KC_S
#define XW23 KC_D
#define XW24 KC_F
#define XW25 KC_G

#define XW31 KC_Z
#define XW32 KC_X
#define XW33 KC_C
#define XW34 KC_V
#define XW35 KC_B

#define XXW11 KC_P
#define XXW12 KC_O
#define XXW13 KC_I
#define XXW14 KC_U
#define XXW15 KC_Y

#define XXW21 KC_SCLN
#define XXW22 KC_L
#define XXW23 KC_K
#define XXW24 KC_J
#define XXW25 KC_H

#define XXW31 KC_SLSH
#define XXW32 KC_DOT
#define XXW33 KC_COMM
#define XXW34 KC_M
#define XXW35 KC_N

#else

#define XW11 KC_F
#define XW12 KC_D
#define XW13 KC_N
#define XW14 KC_I
#define XW15 KC_G

#define XW21 KC_S
#define XW22 KC_T
#define XW23 KC_H
#define XW24 KC_E
#define XW25 KC_O

#define XW31 KC_C
#define XW32 KC_W
#define XW33 KC_R
#define XW34 KC_A
#define XW35 KC_U

#define XXW11 KC_J
#define XXW12 KC_K
#define XXW13 KC_M
#define XXW14 KC_QUOT
#define XXW15 KC_UNDS

#define XXW21 KC_Y
#define XXW22 KC_P
#define XXW23 KC_L
#define XXW24 KC_DOT
#define XXW25 KC_Q

#define XXW31 KC_X
#define XXW32 KC_B
#define XXW33 KC_V
#define XXW34 KC_COMM
#define XXW35 KC_Z

#endif

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_FROG] = LAYOUT(
//┌────────┬────────┬────────┬────────┬────────┬────────┐                      ┌────────┬────────┬────────┬────────┬────────┬────────┐
     XW00,  XW01,    XW02,    XW03,    XW04,    XW05,                           KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
  //|-----------------------------------------------------.                    ,-----------------------------------------------------.
     XW10,  XW11,    XW12,    XW13,    XW14,    XW15,                           KC_G,    KC_I,    KC_N,    KC_D,    KC_F,  KC_ESC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XW20,  XW21,    XW22,    XW23,    XW24,    XW25,                          KC_O,    KC_E,    KC_H,    KC_T,    KC_S, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      XW30,  XW31,    XW32,    XW33,    XW34,    XW35,    KC_TAB,         _______, KC_U,    KC_A,    KC_R,    KC_W,    KC_C,    OSFT,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                         ONUM,    OSYM,  KC_SPC,          KC_SPC,    OSYM,    ONUM \
                                      //`--------------------------'  `--------------------------'
  ),
  [_SYM] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_SCLN, KC_EXLM, KC_AT, KC_HASH, KC_DLR,  KC_PERC,                            KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
    S(KC_BSLS),S(KC_QUOT), KC_ASTR, KC_LCBR, KC_RCBR, KC_MINS,                             KC_CIRC,   KC_AT, KC_LPRN, KC_LCBR, KC_LBRC,  KC_TAB,
  //|--------+--------+--------+--------+--------+--------|                         |--------+--------+--------+--------+--------+--------|
      KC_AMPR, KC_COLN, KC_SCLN, KC_LPRN, KC_RPRN, KC_PLUS,                           KC_SLSH, KC_EXLM, KC_QUES, KC_SCLN, KC_COLN, KC_BSLS,
  //|--------+--------+--------+--------+--------+--------|                         |--------+--------+--------+--------+--------+--------|
     KC_TILD, S(KC_COMM), S(KC_DOT), KC_LBRC, KC_RBRC, KC_EQL,  _______,_______, KC_ASTR, KC_AMPR, KC_RPRN, KC_RCBR, KC_RBRC, KC_TILD,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                    _______, _______, _______,                   _______, _______, _______ \
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),
  [_NUM] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     QK_BOOT,  JNDO,   JCUT,   JCPY,   JPST,      KC_GRV,                              KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_CIRC,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                       KC_DOT,    KC_9,    KC_8,    KC_7,    KC_6,  KC_EQL,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_QUOT, KC_6,    KC_7,    KC_8,    KC_9,   KC_0,                         KC_5,    KC_4,    KC_3,    KC_2,    KC_1, KC_PLUS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_UNDS, KC_H,    KC_J,    KC_K,    KC_L,   _______,    _______,       _______, KC_COMM,  KC_0, KC_PERC,  KC_DLR, KC_HASH, KC_MINS,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                    _______, _______,    _______,                OGUI, _______, _______ \
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  ),
  [_EXT] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
     RGB_MOD, RGB_TOG, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
      _______, _______,WLEFT,    KC_K,    WRIGHT,  OGUI,                         KC_DOT,    KC_9,    KC_8,    KC_7,    KC_6,  KC_EQL,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      JSAV, KC_H,    KC_J,    KC_L,    JSFK,                         KC_5,    KC_4,    KC_3,    KC_2,    KC_1, KC_PLUS,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      QK_BOOT, _______, _______, _______,    _______, _______,  _______,_______,      KC_COMM,    KC_0, KC_PERC,  KC_DLR, KC_HASH, KC_MINS,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                     _______, _______,    _______,               OGUI, _______, _______ \
                                // └────────┴────────┴────────┘                 └────────┴────────┴────────┘
  )
};

#include "jason_keys.gen.h"

// Setting ADJUST layer RGB back to default
/*void update_tri_layer_RGB(uint8_t layer1, uint8_t layer2, uint8_t layer3) {
  if (IS_LAYER_ON(layer1) && IS_LAYER_ON(layer2)) {
    layer_on(layer3);
  } else {
    layer_off(layer3);
  }
}*/

layer_state_t layer_state_set_user(layer_state_t state) {
#ifdef COMBO_ENABLE
	combo_disable();
    if (layer_state_cmp(state, _FROG)) {
        combo_enable();
    }
    return state;
#endif
    state = update_tri_layer_state(state, _SYM, _NUM, _EXT);
    return state;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case JM_HDM:
            if (record->event.pressed) {
                SEND_STRING("~/");
                return false;
            }
        case JM_VKS:
            if (record->event.pressed) {
                SEND_STRING("\\ks");
                return false;
            }
        case JM_PRN:
            if (record->event.pressed) {
                SEND_STRING("()");
                return false;
            }
        case JM_BRC:
            if (record->event.pressed) {
                SEND_STRING("[]");
                return false;
            }
        case JM_CBR:
            if (record->event.pressed) {
                SEND_STRING("{}");
                return false;
            }
    }
    return true;
}