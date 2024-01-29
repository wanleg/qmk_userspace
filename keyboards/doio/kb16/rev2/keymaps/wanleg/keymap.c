#include QMK_KEYBOARD_H
#include "wanleg.h" //needed for mouseJiggler keycode definition

// OLED animation
#include "./lib/layer_status/layer_status.h"

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.

enum layer_names {
  _BASE,
  _FN0,
  _FN1,
  _FN2,
  hexA,
  hexB,
  hexC,
};

// Combo section start
// list combos
enum combo_events {
  ALPHA_MV,
  // THUMB_SPACE,
  // EM_EMAIL,
  COMBO_LENGTH // this is a required line for the COMBO_COUNT delete
};
uint16_t COMBO_LEN = COMBO_LENGTH; // remove the COMBO_COUNT define in config.h and use this instead!
// create keycombo name mappings
const uint16_t PROGMEM alphaMV[] = { TO(_BASE), TO(_FN2), COMBO_END };
// const uint16_t PROGMEM testing[] = {KC_BTN1, KC_BTN2, COMBO_END};
// const uint16_t PROGMEM twoKeySpace[] = {LT(_FN,KC_N), LT(gDIR,KC_M), COMBO_END};
// const uint16_t PROGMEM email_combo[] = {KC_G, KC_H, COMBO_END};

combo_t key_combos[] = {
  [ALPHA_MV] = COMBO_ACTION(alphaMV),
  //[THUMB_SPACE] = COMBO_ACTION(twoKeySpace),
  // COMBO(twoKeySpace, KC_SPC), //can define simple actions here
  //[EM_EMAIL] = COMBO_ACTION(email_combo), //complex actions can be described below
};
/* COMBO_ACTION(x) is same as COMBO(x, KC_NO) */

void process_combo_event(uint16_t combo_index, bool pressed) {
  switch (combo_index) {
    /*
        case EM_EMAIL:
          if (pressed) {
            SEND_STRING("john.doe@example.com");
          }
          break;

        case THUMB_SPACE:
          if (pressed) {
            tap_code16(KC_SPC);
          }
          break;
    */
    case ALPHA_MV:
      if (pressed) {
        // tap_code16(KC_SPC);
        // tap_code16(TO(_FN1)); //doesn't work
        // layer_move(_FN1);
        layer_move(hexA);
      }
      break;
  }
}
// Combo section end

// mouse jiggle section start
bool mouse_jiggle_mode = false; // first declared in wanleg.c
void matrix_scan_user(void) {
  if (mouse_jiggle_mode) {
    // SEND_STRING(SS_DELAY(15)); //in milliseconds
    tap_code(KC_MS_UP);
    tap_code(KC_MS_DOWN);
    // SEND_STRING(SS_DELAY(15)); //in milliseconds
    tap_code(KC_MS_LEFT);
    tap_code(KC_MS_RIGHT);
  }
  else { // not sure if this else-statement is necessary...
  }
}
// mouse jiggle section end

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /*
         ┌───┬───┬───┬───┐   ┌───┐ ┌───┐
         │1,1│1,2│1,3│1,4│   │1,5│ │2,5│
         ├───┼───┼───┼───┤   └───┘ └───┘
         │2,1│2,2│2,3│2,4│
         ├───┼───┼───┼───┤
         │3,1│3,2│3,3│3,4│      ┌───┐
         ├───┼───┼───┼───┤      │3,5│
         │4,1│4,2│4,3│4,4│      └───┘
         └───┴───┴───┴───┘
  */
  [_BASE] = LAYOUT(
    TO(_BASE), TO(_FN0), TO(_FN1), TO(_FN2), XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_MUTE,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX),

  [_FN0] = LAYOUT(
    _______, _______, _______, _______, _______,
    KC_BTN1, KC_BTN3, KC_BTN2, _______, _______,
    _______, _______, _______, _______, _______,
    MOUSEJIGGLERMACRO, _______, KC_PWR, KC_KB_POWER),

  [_FN1] = LAYOUT(
    _______, _______, _______, _______, _______,
    KC_Q,    KC_W,    KC_E,    KC_R,    _______,
    KC_A,    KC_S,    KC_D,    KC_F,    _______,
    KC_RCTL, KC_LALT, KC_SPC,  KC_SPC),
//    DASHER, _______, _______, _______),

  [_FN2] = LAYOUT(
    _______, _______, _______, _______, RGB_MOD,
    _______, _______, _______, _______, RGB_RMOD,
    _______, _______, _______, _______, RGB_TOG,
    _______, _______, _______, QK_BOOT),
  [hexA] = LAYOUT(
    TO(_BASE), _______, _______, _______, _______,
    _______, _______, _______, _______, _______,
    _______, _______, _______, _______, KC_A,
    _______, _______, _______, _______),
  [hexB] = LAYOUT(
    TO(_BASE), _______, _______, _______, _______,
    _______, _______, _______, _______, _______,
    _______, _______, _______, _______, KC_B,
    _______, _______, _______, _______),
  [hexC] = LAYOUT(
    TO(_BASE), _______, _______, _______, _______,
    _______, _______, _______, _______, _______,
    _______, _______, _______, _______, KC_C,
    _______, _______, _______, _______),
};

#ifdef OLED_ENABLE
bool oled_task_user(void) {
  switch (get_highest_layer(layer_state)) {
    /*
            case _BASE:
                //oled_write_P(PSTR("Default\n"), false);
                oled_write_P(PSTR("\nDefault\n\n\n"), false);
                break;
            case _FN:
          //oled_clear();
                //oled_write_P(PSTR("\nFN\n"), false);
                oled_write_P(PSTR("\nFN\n\n\n"), false);
                break;
            case _FN1:
                oled_write_P(PSTR("ADJ\n"), false);
                break;
            case _FN2:
                oled_write_P(PSTR("AXJ\n"), false);
                break;
    */
    case hexA:
      oled_write_P(PSTR("\nAlpha A\n\n\n"), false);
      break;
    case hexB:
      oled_write_P(PSTR("\nAlpha B\n\n\n"), false);
      break;
    case hexC:
      oled_write_P(PSTR("\nAlpha C\n\n\n"), false);
      break;
    default:
      // Or use the write_ln shortcut over adding '\n' to the end of your string
      // oled_write_ln_P(PSTR("Undefined"), false);
      if (mouse_jiggle_mode) {
        oled_write_P(PSTR("\n MouseJiggle Active\n\n\n"), false);
      }
      else {
        render_layer_status();
      }
  }
  return true; // copied from original block
}
#endif

#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
  [_BASE] = { ENCODER_CCW_CW(KC_WH_L, KC_WH_R), ENCODER_CCW_CW(KC_WH_D, KC_WH_U), ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
  [_FN0] = { ENCODER_CCW_CW(KC_MS_L, KC_MS_R), ENCODER_CCW_CW(KC_MS_D, KC_MS_U), ENCODER_CCW_CW(_______, _______) },
  [_FN1] = { ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______) },
  [_FN2] = { ENCODER_CCW_CW(RGB_HUD, RGB_HUI), ENCODER_CCW_CW(RGB_SAD, RGB_SAI), ENCODER_CCW_CW(RGB_VAD, RGB_VAI) },
  [hexA] = { ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(TO(hexC), TO(hexB))},
  [hexB] = { ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(TO(hexA), TO(hexC))},
  [hexC] = { ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(TO(hexB), TO(hexA))},
};
#endif