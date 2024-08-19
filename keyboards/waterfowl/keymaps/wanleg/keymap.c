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

#define LAYOUT_waterfowl_base( \
    K01, K02, K03, K04, K05, K06, K07, K08, K09, K0A, \
    K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, \
    K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A  \
  ) \
  LAYOUT_wrapper( \
     K01,	K02,	K03,	K04,	K05,	K06,	K07,	K08,	K09,	K0A, \
     K11,	K12,	K13,	K14,	K15,	K16,	K17,	K18,	K19,	K1A, \
     K21,	K22,	K23,	K24,	K25,	K26,	K27,	K28,	K29,	K2A, \
	KC_NO,	KC_LCTL, NUMBER, ETCETERA,	KC_MUTE, KC_NO,	KC_SPC, DIRECTION, KC_RGUI, KC_NO \
  )
#define LAYOUT_waterfowl_base_wrapper(...)       LAYOUT_waterfowl_base(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QWERTY
 *
 * ,----------------------------------.                      ,----------------------------------.
 * |   Q  |   W  |   E  |   R  |   T  |                      |   Y  |   U  |   I  |   O  |   P  |
 * |------+------+------+------+------|                      |------+------+------+------+------|
 * |   A  |   S  |   D  |   F  |   G  |                      |   H  |   J  |   K  |   L  |   ;  |
 * |------+------+------+------+------|  ,-----.    ,-----.  |------+------+------+------+------|
 * |   Z  |   X  |   C  |   V  |   B  |  |  2  |    |  3  |  |   N  |   M  |   ,  |   .  |   /  |
 * `----------------------------------'  `-----'    `-----'  `----------------------------------'
 *          ,-----.   ,--------------------.            ,--------------------.   ,-----. 
 *          |  1  |   | CTRL | NUM  |  ETC |            |  SPC | DIR |  GUI  |   |  4  |
 *          `-----'   `--------------------'            `--------------------'   `-----'
KC_LCTL, NUMBER, ETCETERA,	KC_SPC, DIRECTION, KC_RGUI
 */
[_GK] = LAYOUT_waterfowl_base_wrapper(
  _______________Gherkin_Row_0_______________, 
  _______________Gherkin_Row_1_______________, 
  SFT_T(KC_Z), 	KC_X, 	KC_C, 	KC_V,	LT(ETC,KC_B),  KC_N, 	KC_M, 	KC_COMM,	ALT_T(KC_DOT),	CTL_T(KC_BSPC)  
),

[NUM] = LAYOUT_wrapper(
  _______________Gherkin_NUM_0_______________,
  _______________Gherkin_NUM_1_______________,
  _______________Gherkin_NUM_2_______________,
  _______,	 _______, _______, _______,	 _______,  _______, 	KC_ENT, KC_RSFT, _______, 		_______
),

[DIR] = LAYOUT_waterfowl_base_wrapper(
  _______________Gherkin_DIR_0_______________,
  _______________Gherkin_DIR_1_______________,
  _______________Gherkin_DIR_2_______________
),

[ETC] = LAYOUT_wrapper(
  _______________Gherkin_ETC_0_______________,
  _______________Gherkin_ETC_1_______________,
  _______________Gherkin_ETC_2_______________,
  _______,	_______, NUMBER, ETCETERA,	 _______,  _______, 	LALT(LCTL(KC_DEL)), DIRECTION, KC_RGUI,			_______	
),
};
