#pragma once
//list combos
enum combo_events {
  PINKY_ENTER,
  THUMB_POWER,
  ALPHA_MV,
  //EM_EMAIL,
  COMBO_LENGTH //this is a required line for the COMBO_COUNT delete
};
uint16_t COMBO_LEN = COMBO_LENGTH; // remove the COMBO_COUNT define in config.h and use this instead!

//create keycombo name mappings
const uint16_t PROGMEM twoKeyEnter[] = {SFT_T(KC_SPC), RCTL_T(KC_BSPC), COMBO_END};
const uint16_t PROGMEM twoThumbPower[] = {ETCETERA, KC_LCTL, COMBO_END};
const uint16_t PROGMEM alphaMV[] = { TO(_BASE), TO(_FN2), COMBO_END };
//const uint16_t PROGMEM email_combo[] = {KC_G, KC_H, COMBO_END};

combo_t key_combos[] = {
    [PINKY_ENTER] = COMBO_ACTION(twoKeyEnter),
    [THUMB_POWER] = COMBO_ACTION(twoThumbPower),
    [ALPHA_MV] = COMBO_ACTION(alphaMV),
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

    case THUMB_POWER:
      if (pressed) {
        tap_code16(KC_PWR);
      }
      break;

    case ALPHA_MV:
      if (pressed) {
        layer_move(hexA);
      }
      break;
  }
}
