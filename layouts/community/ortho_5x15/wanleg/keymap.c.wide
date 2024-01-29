#include QMK_KEYBOARD_H
//quick and dirty wide spread setup
#include "wanleg.h"

//Combo section start
//list combos
enum combo_events {
  PINKY_ENTER,
  //EM_EMAIL,
  COMBO_LENGTH //this is a required line for the COMBO_COUNT delete
};
uint16_t COMBO_LEN = COMBO_LENGTH; // remove the COMBO_COUNT define in config.h and use this instead!
//create keycombo name mappings
const uint16_t PROGMEM twoKeyEnter[] = {SFT_T(KC_SPC), CTL_T(KC_BSPC), COMBO_END};
//const uint16_t PROGMEM email_combo[] = {KC_G, KC_H, COMBO_END};

combo_t key_combos[] = {
    [PINKY_ENTER] = COMBO_ACTION(twoKeyEnter),
    //COMBO(twoKeyEnter, KC_SPC), //can define simple actions here
    //[EM_EMAIL] = COMBO_ACTION(email_combo), //complex actions can be described below
};
/* COMBO_ACTION(x) is same as COMBO(x, KC_NO) */

void process_combo_event(uint16_t combo_index, bool pressed) {
  switch(combo_index) {
/*
    case EM_EMAIL:
      if (pressed) {
        SEND_STRING("john.doe@example.com");
      }
      break;
*/
    case PINKY_ENTER:
      if (pressed) {
        tap_code16(KC_ENT);
      }
      break;
  }
}
//Combo section end 

//#define LAYOUT_ortho_5x15_base( 

#define LAYOUT_ortho_5x15_base( \
    K00, K01, K02, K03, K04, K05, K06, K07, K08, K09, \
    K10, K11, K12, K13, K14, K15, K16, K17, K18, K19, \
    K20, K21, K22, K23, K24, K25, K26, K27, K28, K29 \
  ) \
   LAYOUT_ortho_5x15_wrapper( \
     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
     K00, K01, K02, K03, K04, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, K05, K06, K07, K08, K09, \
     K10, K11, K12, K13, K14, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, K15, K16, K17, K18, K19, \
     K20, K21, K22, K23, K24, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, K25, K26, K27, K28, K29, \
     XXXXXXX, XXXXXXX, KC_LCTL, NUMBER, ETCETERA, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, LT(_FN,KC_SPC), DIRECTION, KC_RGUI, XXXXXXX, XXXXXXX \
  )

#define LAYOUT_ortho_5x15_base_wrapper(...)       LAYOUT_ortho_5x15_base(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_GK] = LAYOUT_ortho_5x15_base_wrapper(
  _______________Gherkin_Row_0_______________, 
  _______________Gherkin_Row_1_______________, 
  SFT_T(KC_Z), 	KC_X, 	KC_C, 	KC_V,	LT(ETC,KC_B),  KC_N, 	KC_M, 	KC_COMM, ALT_T(KC_DOT),	CTL_T(KC_BSPC)
),

[NUM] = LAYOUT_ortho_5x15_wrapper(
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, 
    KC_F1,  KC_F2,  KC_F3,  KC_F4,   KC_F5,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_F6,  KC_F7,   KC_F8,   KC_F9,  KC_F10,
    KC_1,   KC_2,   KC_3,   KC_4,    KC_5,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_6,   KC_7,    KC_8,    KC_9,   KC_0,
    KC_F11, KC_F12, _______,_______, _______,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_ENT, KC_RSFT, KC_RGUI, ALT_T(KC_DOT), CTL_T(KC_BSPC),
    XXXXXXX, XXXXXXX, _______, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_ENT, KC_RSFT, _______, XXXXXXX, XXXXXXX
),

[DIR] = LAYOUT_ortho_5x15_base_wrapper(
  _______________Gherkin_DIR_0_______________,
  _______________Gherkin_DIR_1_______________,
  _______________Gherkin_DIR_2_______________
),

[ETC] = LAYOUT_ortho_5x15_wrapper(
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, 
  KC_GRV,  KC_MS_U, _______, KC_ESC,  QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_RSFT, KC_WH_D, KC_WH_U, _______, KC_BSLS,
  KC_MS_L, KC_MS_D, KC_MS_R, _______, KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_BTN3, KC_BTN1, KC_BTN2, KC_SCLN, KC_QUOT,
  TD(TD_SFT_CAPS),KC_CAPS, _______,_______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, LALT(LCTL(KC_DEL)),	KC_WH_L, KC_WH_R, KC_LALT, KC_DEL,
  XXXXXXX, XXXXXXX, _______, NUMBER, ETCETERA, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, LALT(LCTL(KC_DEL)), DIRECTION, KC_RGUI, XXXXXXX, XXXXXXX
),

[_FN] = LAYOUT_ortho_5x15_base_wrapper(
  _______________Gherkin_FN_0________________,
  _______________Gherkin_FN_1________________,
  _______________Gherkin_FN_2________________
),
};
