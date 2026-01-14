#include "wanleg.h" //needed for mouseJiggler keycode definition & combos

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


// mouse jiggle section start
bool mouse_jiggle_mode = false; // first declared in wanleg.c
void matrix_scan_user(void) {
  if (mouse_jiggle_mode) {
    // SEND_STRING(SS_DELAY(15)); //in milliseconds
    tap_code(MS_UP);
    tap_code(MS_DOWN);
    // SEND_STRING(SS_DELAY(15)); //in milliseconds
    tap_code(MS_LEFT);
    tap_code(MS_RGHT);
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
    MS_BTN1, MS_BTN3, MS_BTN2, _______, _______,
    _______, _______, _______, _______, _______,
    MOUSEJIGGLERMACRO, _______, KC_PWR, KC_KB_POWER),

  [_FN1] = LAYOUT(
    _______, _______, _______, _______, _______,
    KC_Q,    KC_W,    KC_E,    KC_R,    _______,
    KC_A,    KC_S,    KC_D,    KC_F,    _______,
    KC_RCTL, KC_LALT, KC_SPC,  KC_SPC),
//    DASHER, _______, _______, _______),

  [_FN2] = LAYOUT(
    _______, _______, _______, _______, RM_NEXT,
    _______, _______, _______, _______, RM_PREV,
    _______, _______, _______, _______, RM_TOGG,
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
  [_BASE] = { ENCODER_CCW_CW(MS_WHLL, MS_WHLR), ENCODER_CCW_CW(MS_WHLD, MS_WHLU), ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
  [_FN0] = { ENCODER_CCW_CW(MS_LEFT, MS_RGHT), ENCODER_CCW_CW(MS_DOWN, MS_UP), ENCODER_CCW_CW(_______, _______) },
  [_FN1] = { ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______) },
  [_FN2] = { ENCODER_CCW_CW(RM_HUED, RM_HUEU), ENCODER_CCW_CW(RM_SATD, RM_SATU), ENCODER_CCW_CW(RM_VALD, RM_VALU) },
  [hexA] = { ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(TO(hexC), TO(hexB))},
  [hexB] = { ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(TO(hexA), TO(hexC))},
  [hexC] = { ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(TO(hexB), TO(hexA))},
};
#endif
