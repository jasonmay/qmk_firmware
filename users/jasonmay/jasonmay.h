#include QMK_KEYBOARD_H

#pragma once

#include "quantum.h"
#include "action.h"
#include "version.h"

#define _QWERTY 0
#define _LEFTY  1
#define _LOWER  2
#define _RAISE  3
#define _LEFTY2 4
#define _JMSEQ  5

// 1=esc, 2=ctrl
#define XX_ESC LCTL_T(KC_ESC)

// 1=vimcmd, 2=lower
#define XX_LJM LT(_LOWER, JMSEQ)


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
  JMSEQ, // sequence for jason may (for env-determined vim dev stuff)
};
