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

/* no numrow layout
#define LAYOUT_iris_base( \
    K01, K02, K03, K04, K05, K06, K07, K08, K09, K0A, K0B, K0C, \
    K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, K1B, K1C, \
    K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A, K2B, K2C, \
    K31, K32, K33, K34, K35, K36, K37, K38, K39, K3A, K3B, K3C  \
  ) \
  LAYOUT_wrapper( \
     K01,	K02,	K03,	K04,	K05,	K06,						K07,	K08,	K09,	K0A,	K0B,	K0C, \
     K11,	K12,	K13,	K14,	K15,	K16,						K17,	K18,	K19,	K1A,	K1B,	K1C, \
     K21,	K22,	K23,	K24,	K25,	K26,						K27,	K28,	K29,	K2A,	K2B,	K2C, \
     K31,	K32,	K33,	K34,	K35,	K36,	DIRECTION, NUMBER,	K37,	K38,	K39,	K3A,	K3B,	K3C, \
                               _______, _______, SH_MON,			SH_MON, _______, _______                  \
  )
*/


#define LAYOUT_iris_base( \
    K01, K02, K03, K04, K05, K06, K07, K08, K09, K0A, K0B, K0C, \
    K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, K1B, K1C, \
    K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A, K2B, K2C, \
	K31, K32, K33, K34, K35, K36, K37, K38, K39, K3A, K3B, K3C  \
  ) \
  LAYOUT_wrapper( \
     K01,	K02,	K03,	K04,	K05,	K06,						K07,	K08,	K09,	K0A,	K0B,	K0C, \
     K11,	K12,	K13,	K14,	K15,	K16,						K17,	K18,	K19,	K1A,	K1B,	K1C, \
     K21,	K22,	K23,	K24,	K25,	K26,						K27,	K28,	K29,	K2A,	K2B,	K2C, \
     K31,	K32,	K33,	K34,	K35,	K36,	SH_MON, SH_MON,		K37,	K38,	K39,	K3A,	K3B,	K3C, \
                               KC_LCTL, NUMBER, ETCETERA,			LT(_FN,KC_SPC), DIRECTION, KC_RGUI                  \
  )
#define LAYOUT_iris_base_wrapper(...)       LAYOUT_iris_base(__VA_ARGS__)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_GK] = LAYOUT_iris_base_wrapper(
    _______________SUBTER_Row__1_______________,
    _______________GherkinLike_0_______________,
    _______________GherkinLike_1_______________,
    _______________GherkinLike_2_______________
  ),
/*  
  [ONE] = LAYOUT_wrapper(
    _______________SUBTER_Row__1_______________,
    _______________Qwerty_Row__0_______________,
    _______________Qwerty_Row__1_______________,
//	_______________Qwerty_Row__2_______________,
	TD(TD_SFT_CAPS),  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,     _______, _______,		KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, SFT_T(KC_ENT),
//	KC_LCTL, KC_LGUI, KC_LALT, GHERKIN, SUBTER, SH_T(KC_SPC),		_______, _______,		SH_T(KC_SPC), SUPRA, KC_RGUI, KC_RALT, GHERKIN, KC_RCTL,
												_______, _______, _______,		_______, _______, _______
  ),

  [SUP] = LAYOUT_iris_base_wrapper(
    ________________SUPRA_Row_0________________,
    ________________SUPRA_Row_1________________,
    ________________SUPRA_Row_2________________,
	________________SUPRA_Row_3________________
  ),
  [SUB] = LAYOUT_wrapper(
    _______________SUBTER_Row__1_______________,
    _______________SUBTER_Row__0_______________,
    _______________SUBTER_Row__1_______________,
    _______, KC_F11,  KC_F12,  _______, _______, _______, _______, _______, _______, _______,  KC_RGUI,ALT_T(KC_DOT),  	CTL_T(KC_BSPC), _______,
												_______, _______, _______,		KC_ENT,  KC_LSFT, _______
  ),
*/
  [NUM] = LAYOUT_wrapper(
    _______________SUBTER_Row__1_______________,
    _______________NUMBERS_Row_0_______________,
    _______________NUMBERS_Row_1_______________,
    _______, KC_F11, KC_F12, _______,_______, _______, _______, _______,  KC_ENT, KC_RSFT, KC_RGUI, ALT_T(KC_DOT), CTL_T(KC_BSPC), _______,
												_______, _______, _______,		KC_ENT,  KC_LSFT, _______
  ),
  [DIR] = LAYOUT_iris_base_wrapper(
    _______________SUBTER_Row__1_______________,
    _____________DIRECTIONS_Row__0_____________,
    _____________DIRECTIONS_Row__1_____________,
    _____________DIRECTIONS_Row__2_____________
  ),
  [ETC] = LAYOUT_wrapper(
    _______________SUBTER_Row__1_______________,
    ______________ETCETERA_Row__0______________,
    ______________ETCETERA_Row__1______________,
    //_______, TD(TD_SFT_CAPS),KC_CAPS, _______,_______, _______, _______, _______,  LALT(LCTL(KC_DEL)),	KC_WH_L, KC_WH_R, KC_LALT, KC_DEL, _______,
    _______, KC_LSFT, KC_CAPS, _______,_______, _______, _______, _______,  LALT(LCTL(KC_DEL)),	KC_WH_L, KC_WH_R, KC_LALT, KC_DEL, _______,
												_______, _______, _______,		LALT(LCTL(KC_DEL)), _______, _______
  )
  
};


void matrix_init_keymap(void) {
  DDRD &= ~(1<<5);
  PORTD &= ~(1<<5);

  DDRB &= ~(1<<0);
  PORTB &= ~(1<<0);
}
