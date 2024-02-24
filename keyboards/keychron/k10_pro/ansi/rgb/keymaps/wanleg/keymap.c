//DO NOT COMPILE THIS AS A 'wanleg' KEYMAP
//COPY TO 'default' AND COMPILE AS DEFAULT
#include QMK_KEYBOARD_H

#define LAYOUT_k10Pro_base( \
    K01, K02, K03, K04, K05, K06, K07, K08, K09, K0A, K0B, K0C, K0D, K0E, K0F, \
    K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, K1B, K1C, K1D, K1E, \
    K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A, K2B, K2C, K2D, K2E, \
    K31, K32, K33, K34, K35, K36, K37, K38, K39, K3A, K3B, K3C, K3D, \
    K41, K42, K43, K44, K45, K46, K47, K48, K49, K4A, K4B, K4C, \
    K51, K52, K53, K54, K55, K56, K57, K58 \
  ) \
  LAYOUT_ansi_108( \
     K01,	K02,	K03,	K04,	K05,	K06,	K07,	K08,	K09,	K0A,	K0B,	K0C,	K0D,			    K0E,      K0F,      RGB_MOD,            KC_F13,   KC_F14,   KC_F15,   KC_F16, \
     K11,	K12,	K13,	K14,	K15,	K16,	K17,	K18,	K19,	K1A,	K1B,	K1C,    K1D,    K1E,		KC_INS,   KC_HOME,  KC_PGUP,            KC_NUM,   KC_PSLS,  KC_PAST,  KC_PMNS,\
     K21,	K22,	K23,	K24,	K25,	K26,	K27,	K28,	K29,	K2A,	K2B,	K2C,    K2D,	K2E,		KC_DEL,   KC_END,   KC_PGDN,            KC_P7,    KC_P8,    KC_P9,    KC_PPLS, \
     K31,	K32,	K33,	K34,	K35,	K36,	K37,	K38,	K39,	K3A,	K3B,	K3C,	K3D,                                                        KC_P4,    KC_P5,    KC_P6, \
     K41,	K42,	K43,	K44,	K45,	K46,	K47,	K48,	K49,	K4A,	K4B,	K4C,                                  KC_UP,                        KC_P1,    KC_P2,    KC_P3,    KC_PENT,\
     K51,	K52,	K53,	K54,	K55,	K56,	K57,	K58,								                        KC_LEFT,  KC_DOWN,  KC_RGHT,            KC_P0,              KC_PDOT         \
  )

#define LAYOUT_k10Pro_base_wrapper(...)       LAYOUT_k10Pro_base(__VA_ARGS__)

// clang-format off
enum layers{
  MAC_BASE,
  GAME,
  WIN_BASE,
  ONE,
  _FN
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
//Windows
    [WIN_BASE] = LAYOUT_k10Pro_base_wrapper(
    KC_ESC,		  KC_F1,    KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,         KC_F9,           KC_F10,   KC_F11,  KC_F12,   KC_PSCR,  KC_CTANA,
    QK_GESC, KC_1,        KC_2,     KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,          KC_0,            KC_MINS,  KC_EQL,  KC_BSPC,
    KC_TAB,  KC_Q,        KC_W,     KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,          KC_P,            KC_LBRC,  KC_RBRC, KC_BSLS,
    KC_CAPS, KC_A,	  KC_S,     KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,          RSFT_T(KC_SCLN), KC_QUOT,  KC_ENT,
    KC_LSFT, SFT_T(KC_Z), KC_X,     KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, ALT_T(KC_DOT), RCTL_T(KC_BSPC), KC_RSFT,
    KC_LCTL, KC_LGUI, KC_LALT,			LT(ONE,KC_SPC),                      KC_RALT, KC_RGUI, MO(_FN), KC_RCTL
    ),

//MacOS
    [MAC_BASE] = LAYOUT_k10Pro_base_wrapper(
    KC_ESC,                KC_BRID, KC_BRIU, KC_MCTL, KC_LPAD, RGB_VAD, RGB_VAI, KC_MPRV, KC_MPLY,       KC_MNXT,           KC_MUTE,  KC_VOLD,  KC_VOLU,  KC_SNAP,  KC_SIRI, 
    QK_GESC, KC_1,         KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,          KC_0,              KC_MINS,  KC_EQL,   KC_BSPC,
    KC_TAB,  KC_Q,         KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,          KC_P,              KC_LBRC,  KC_RBRC,  KC_BSLS,
    KC_CAPS, KC_A,	   KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,          RSFT_T(KC_SCLN),   KC_QUOT,  KC_ENT,
    KC_LSFT, SFT_T(KC_Z),  KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, ALT_T(KC_DOT), RCTL_T(KC_BSPC),   KC_RSFT,
    KC_LCTL, KC_LOPTN, KC_LCMMD,                LT(ONE,KC_SPC),			     KC_RCMMD, KC_ROPTN, MO(_FN),   KC_RCTL
    ),

    [ONE] = LAYOUT_k10Pro_base_wrapper(
    _______,            _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,  _______,
    KC_GRV,  KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, _______,  _______,  KC_DEL,
    KC_GRV,  KC_TAB, KC_UP, _______, KC_INS, KC_LCTL, KC_RSFT, KC_PGUP, KC_HOME, KC_MINS, KC_EQL, _______, _______, _______,
    KC_GRV,  KC_LEFT, KC_DOWN, KC_RGHT, KC_PSCR, KC_LSFT, KC_RCTL, KC_PGDN, KC_END, KC_LBRC, KC_RBRC, _______, _______,
    _______, KC_PAUS, _______, _______, _______, _______, _______, _______, KC_RGUI, KC_LALT, KC_SLSH, _______,
    QK_BOOT,   _______, _______,                  _______,            _______,  _______,  _______, QK_BOOT
    ),

    [_FN] = LAYOUT_k10Pro_base_wrapper(
    _______,            _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,  _______,
    _______,  BT_HST1,  BT_HST2,  BT_HST3,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______, 
    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,
    _______,  RGB_M_B,  RGB_VAD,  RGB_VAI,  RGB_TOG,  RGB_MOD,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
    _______,            RGB_HUD,  RGB_HUI,  RGB_SAD,  RGB_SAI,  BAT_LVL,  NK_TOGG,  _______,  _______,  _______,  _______,  _______,
    _______,  _______,  _______,                                _______,                                DF(MAC_BASE),  DF(WIN_BASE),  _______,    DF(GAME)
    ),
//Game
    [GAME] = LAYOUT_k10Pro_base_wrapper(
    KC_ESC,		  KC_F1,    KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,         KC_F9,           KC_F10,   KC_F11,  KC_F12,   KC_PSCR,  KC_CTANA,
    QK_GESC, KC_1,        KC_2,     KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,          KC_0,            KC_MINS,  KC_EQL,  KC_BSPC,
    KC_TAB,  KC_Q,        KC_W,     KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,          KC_P,            KC_LBRC,  KC_RBRC, KC_BSLS,
    KC_CAPS, KC_A,	  KC_S,     KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,          RSFT_T(KC_SCLN), KC_QUOT,  KC_ENT,
    KC_LSFT, SFT_T(KC_Z), KC_X,     KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, ALT_T(KC_DOT), RCTL_T(KC_BSPC), KC_RSFT,
    KC_LCTL, KC_LGUI, KC_LALT,			KC_SPC,                      KC_RALT, KC_RGUI, MO(_FN), KC_RCTL
    )

};
