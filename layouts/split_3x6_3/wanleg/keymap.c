#include QMK_KEYBOARD_H
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

#define LAYOUT_split_3x6_3_base( \
    K00, K01, K02, K03, K04, K05, K06, K07, K08, K09, K0A, K0B, \
    K10, K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, K1B, \
    K20, K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A, K2B  \
  ) \
  LAYOUT_split_3x6_3_wrapper( \
    K00, K01, K02, K03, K04, K05, K06, K07, K08, K09, K0A, K0B, \
    K10, K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, K1B, \
    K20, K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A, K2B, \
      KC_LCTL, NUMBER, ETCETERA,	KC_SPC, DIRECTION, KC_RGUI  \
  )
#define LAYOUT_split_3x6_3_base_wrapper(...)       LAYOUT_split_3x6_3_base(__VA_ARGS__)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_GK] = LAYOUT_split_3x6_3_base_wrapper(
    _______________GherkinLike_0_______________,
    _______________GherkinLike_1_______________,
    _______________GherkinLike_2_______________
  ),
  [NUM] = LAYOUT_split_3x6_3_wrapper(
    _______________NUMBERS_Row_0_______________,
    _______________NUMBERS_Row_1_______________,
    _______________NUMBERS_Row_2_______________,
    _______, _______, _______,	KC_ENT, KC_RSFT, _______
  ),
  [DIR] = LAYOUT_split_3x6_3_base_wrapper(
    _____________DIRECTIONS_Row__0_____________,
    _____________DIRECTIONS_Row__1_____________,
    _____________DIRECTIONS_Row__2_____________
  ),
  [ETC] = LAYOUT_split_3x6_3_wrapper(
    ______________ETCETERA_Row__0______________,
    ______________ETCETERA_Row__1______________,
    ______________ETCETERA_Row__2______________,
    _______, NUMBER, ETCETERA,	LALT(LCTL(KC_DEL)), DIRECTION, KC_RGUI
  )
};
