#include QMK_KEYBOARD_H

// OLED animation
#include "./lib/layer_status/layer_status.h"

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.

enum layer_names {
    _BASE,
    _FN,
    _FN1,
    _FN2
};

// enum layer_keycodes { };

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
		TO(_BASE),TO(_FN), TO(_FN1),TO(_FN2), XXXXXXX,
		XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,
		XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX,  KC_MUTE,
		XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX
            ),

    [_FN] = LAYOUT(
                _______, _______, _______, _______, _______,
                KC_BTN1, KC_BTN3, KC_BTN2, _______, _______,
                _______, _______, _______, _______, _______,
                _______, _______, KC_PWR, KC_KB_POWER 
            ),

    [_FN1] = LAYOUT(
                _______, _______, _______, _______, _______,
                _______, _______, _______, _______, _______,
                _______, _______, _______, _______, _______,
                _______, _______, _______, _______
            ),

    [_FN2] = LAYOUT(
                _______, _______, _______, _______, RGB_MOD,
		_______, _______, _______, _______, RGB_RMOD,
		_______, _______, _______, _______, RGB_TOG,
                _______, _______, _______, QK_BOOT
            ),
};

#ifdef OLED_ENABLE
    bool oled_task_user(void) {
        render_layer_status();

        return true;
    }
#endif

#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [_BASE] = { ENCODER_CCW_CW(KC_WH_L, KC_WH_R), ENCODER_CCW_CW(KC_WH_D, KC_WH_U), ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [_FN]   = { ENCODER_CCW_CW(KC_MS_L, KC_MS_R), ENCODER_CCW_CW(KC_MS_D, KC_MS_U), ENCODER_CCW_CW(_______, _______) },
    [_FN1]  = { ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______) },
    [_FN2]  = { ENCODER_CCW_CW(RGB_HUD, RGB_HUI), ENCODER_CCW_CW(RGB_SAD, RGB_SAI), ENCODER_CCW_CW(RGB_VAD, RGB_VAI) },
};
#endif
