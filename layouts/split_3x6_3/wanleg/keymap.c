#include "wanleg.h"

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
