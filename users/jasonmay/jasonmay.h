#include QMK_KEYBOARD_H

#pragma once

#include "quantum.h"
#include "action.h"
#include "version.h"

#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _JMSEQ 3

// 1=esc, 2=ctrl
#define XX_ESC LCTL_T(KC_ESC)

// 1=vimcmd, 2=lower
#define XX_LJM LT(_LOWER, JMSEQ)

// 1=tab, 2=raise
#define XX_RTAB LT(_RAISE, KC_TAB)

// mod-tap {} on cmd/alt respectively
#define XX_CCBR LGUI_T(S(KC_LBRC))
#define XX_ACBR RALT_T(S(KC_RBRC))

// expose on my mac
#define XX_XPOS LCTL(KC_UP)

// browser back/forward
#define XX_BBK LGUI(KC_LEFT)
#define XX_BFD LGUI(KC_RIGHT)

// navigate workspaces
#define XX_LWKS LALT(KC_LBRC)
#define XX_RWKS LALT(KC_RBRC)

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
