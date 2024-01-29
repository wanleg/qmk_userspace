#include QMK_KEYBOARD_H
#include "wanleg.h"

//Combo section start
//list combos
enum combo_events {
  THUMB_SPACE,
  PINKY_ENTER,
  //EM_EMAIL,
  COMBO_LENGTH //this is a required line for the COMBO_COUNT delete
};
uint16_t COMBO_LEN = COMBO_LENGTH; // remove the COMBO_COUNT define in config.h and use this instead!
//create keycombo name mappings
const uint16_t PROGMEM twoKeySpace[] = {LT(_FN,KC_N), LT(gDIR,KC_M), COMBO_END};
const uint16_t PROGMEM twoKeyEnter[] = {SFT_T(KC_SPC), RCTL_T(KC_BSPC), COMBO_END};
//const uint16_t PROGMEM email_combo[] = {KC_G, KC_H, COMBO_END};

combo_t key_combos[] = {
    [THUMB_SPACE] = COMBO_ACTION(twoKeySpace),
    [PINKY_ENTER] = COMBO_ACTION(twoKeyEnter),
    //COMBO(twoKeySpace, KC_SPC), //can define simple actions here
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
    case THUMB_SPACE:
      if (pressed) {
        tap_code16(KC_SPC);
      }
      break;
    
    case PINKY_ENTER:
      if (pressed) {
        tap_code16(KC_ENT);
      }
      break;
  }
}
//Combo section end

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[gGK] = LAYOUT_ortho_3x10_wrapper(
  _______________Gherkin_Row_0_______________,
  _______________Gherkin_Row_1_______________,
  _______________Gherkin_Row_2_______________
),

[gNUM] = LAYOUT_ortho_3x10_wrapper(
  _______________Gherkin_NUM_0_______________,
  _______________Gherkin_NUM_1_______________,
  _______________Gherkin_NUM_2_______________
),

[gDIR] = LAYOUT_ortho_3x10_wrapper(
  _______________Gherkin_DIR_0_______________,
  _______________Gherkin_DIR_1_______________,
  _______________Gherkin_DIR_2_______________
),

[gETC] = LAYOUT_ortho_3x10_wrapper(
  _______________Gherkin_ETC_0_______________,
  _______________Gherkin_ETC_1_______________,
  _______________Gherkin_ETC_2_______________
),

[_FN] = LAYOUT_ortho_3x10_wrapper(
  _______________Gherkin_FN_0________________,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),
};
