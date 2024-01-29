#include QMK_KEYBOARD_H
#include "wanleg.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_GK] = LAYOUT_60_ansi_wrapper(
 QK_GESC, _______________Gherkin_NUM_1_______________,    KC_MINS, KC_EQL,  KC_BSPC,
 KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,
 KC_CAPS, KC_A,	   KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    RSFT_T(KC_SCLN),  KC_QUOT, KC_ENT,
 KC_LSFT, SFT_T(KC_Z),	    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, ALT_T(KC_DOT),    RCTL_T(KC_BSPC), KC_RSFT,
 KC_LCTL, KC_LGUI, KC_LALT,                   LT(ONE,KC_SPC),                     KC_RALT, KC_RGUI, MO(_FN), KC_RCTL
), 

[_QW] = LAYOUT_60_ansi_wrapper(
 QK_GESC, _______________Gherkin_NUM_1_______________,    KC_MINS, KC_EQL,  KC_BSPC,
 KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,
 KC_CAPS, KC_A,	   KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    RSFT_T(KC_SCLN),  KC_QUOT, KC_ENT,
 KC_LSFT, SFT_T(KC_Z),	    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, ALT_T(KC_DOT),    RCTL_T(KC_BSPC), KC_RSFT,
 KC_LCTL, KC_LALT, KC_LGUI,                   LT(ONE,KC_SPC),                     KC_RGUI, KC_RALT, MO(_FN), KC_RCTL
),

[ONE] = LAYOUT_60_ansi_wrapper(
KC_GRV,  _______________Gherkin_NUM_0_______________, KC_F11,  KC_F12,  KC_DEL, 
KC_GRV,  _______________Gherkin_DIR_0_______________, _______, _______, _______,
KC_GRV,  _______________Gherkin_DIR_1_______________, _______, _______,
_______, _______________Gherkin_DIR_2_______________, _______, 
QK_BOOT,   _______, _______,                  _______,            _______,  _______,  _______, QK_BOOT 
),

[_FN] = LAYOUT_60_ansi_wrapper(
_______, _______, _______, _______, _______, _______, _______, _______, KC_MEDIA_REWIND, KC_MEDIA_FAST_FORWARD, KC_VOLD, KC_VOLU, KC_MUTE, KC_MEDIA_PLAY_PAUSE,
_______, BL_BRTG, BL_DEC,  BL_INC,  BL_TOGG, BL_STEP,  BL_ON,   _______, _______, _______, _______, _______, _______, _______,
_______, RGB_M_B, RGB_VAD, RGB_VAI, RGB_TOG, RGB_MOD,  _______, _______, _______, _______, _______, _______, _______,
_______, RGB_HUD, RGB_HUI, RGB_SAD, RGB_SAI, _______,  _______, _______, _______, _______, _______, _______, 
_______,   _______, _______,                   _______,                  QWERTY,  GHERKIN, _______, KC_SLEP
)
};
