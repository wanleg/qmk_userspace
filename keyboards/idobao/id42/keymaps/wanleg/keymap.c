#include "wanleg.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Layer 1
     * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┐
     * │Esc│ Q │ W │ E │ R │ T │ Y │ U │ I │ O │ P │BSp│
     * ├───┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴───┤
     * │ Tab│ A │ S │ D │ F │ G │ H │ J │ K │ L │  ;   │
     * ├────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴──┬┴──┬───┤
     * │ Sft │ Z │ X │ C │ V │ B │ N │ M │  ,  │Bsp│BSp│
     * ├────┬┴──┬┴───┼───┴───┴─┬─┴───┴───┼─┬───┼───┼───┤
     * │Ctrl│Win│Alt │  NumLyr │Direction│ │Win│Alt│Ctl│
     * └────┴───┴────┴─────────┴─────────┘ └───┴───┴───┘
     */
    [_GK] = LAYOUT_wrapper(
        QK_GESC, _______________Gherkin_Row_0_______________,    KC_BSPC,
        KC_TAB,  _______________Gherkin_Row_1_______________,
        //KC_TAB,  KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, SFT_T(KC_SCLN),
        //KC_LSFT,   SFT_T(KC_Z),    KC_X,    KC_C,    LT(ETC, KC_V),    KC_B, LT(_FN, KC_N), KC_M, KC_COMM, ALT_T(KC_DOT), CTL_T(KC_BSPC),
        KC_LSFT,   SFT_T(KC_Z),    KC_X,    KC_C,    LT(ETC, KC_V),    KC_B, LT(_FN, KC_N), KC_M, ALT_T(KC_COMM), ALT_T(KC_BSPC), CTL_T(KC_DOT),
        KC_LCTL, KC_LGUI, KC_LALT,          NUMBER,          LT(DIRECTION, KC_SPC),                  KC_RGUI, KC_RALT, KC_RCTL
    ),

    [NUM] = LAYOUT_wrapper(
        _______________NUMBERS_Row_0_______________,
        _______, _______________Gherkin_NUM_1_______________,
        _______, _______________Gherkin_NUM_2_______________,
        _______, _______, _______,          _______,         KC_RSFT,                    _______, _______, _______
    ),

    [DIR] = LAYOUT_wrapper(
        _____________DIRECTIONS_Row__0_____________,
        _______, _______________Gherkin_DIR_1_______________,
        //_______, _______________Gherkin_DIR_2_______________,
        _______, KC_PAUS, _______, _______, _______, _______, _______, _______, KC_LALT, KC_LALT, KC_SLSH,
        _______, _______, _______,          _______,         _______,                    _______, _______, _______
    ),

    [ETC] = LAYOUT_wrapper(
        ______________ETCETERA_Row__0______________,
        _______, _______________Gherkin_ETC_1_______________,
        _______, _______________Gherkin_ETC_2_______________,
        _______, _______, _______,          _______,         _______,                    _______, _______, _______
    ),

    [_FN] = LAYOUT_wrapper(
        _______, _______, _______, _______, _______, _______,  _______, _______, _______, _______, _______, _______,
        _______, RGB_M_B, RGB_VAD, RGB_VAI, RGB_TOG, RGB_MOD,  _______, _______, _______, _______, _______,
        _______, RGB_HUD, RGB_HUI, RGB_SAD, RGB_SAI, _______,  _______, _______, _______, _______, _______,
        _______, _______, _______,          _______,         _______,                    _______, _______, _______
    )
};
