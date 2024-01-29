#include QMK_KEYBOARD_H

#include "sten.h"
/*
 *  Key names are inherited from steno machines
 *  .-----------------------------------------------------.
 *  | LSU | LFT | LP | LH | ST1 | RF | RP | RL | RT | RD  |
 *  |-----------------------------------------------------|
 *  | LSD | LK  | LW | LR | ST2 | RR | RB | RG | RS | RZ  |
 *  '-----------------------------------------------------'
       A     S     D    F     G    H    J    K    L    ;
 */

// Function prefixes
#define DIR1 (RB)
#define DIR2 (RB | RG)
#define SYMB (LR | RB)
#define NUM1 (LR)
#define NUM2 (LW | LR)

/*
START TEMPLATE
P( DIR1
| LSU,    SEND(_______));
| LFT,    SEND(_______));
| LP,     SEND(_______));
| LH,     SEND(_______));
| ST1,    SEND(_______));
| RF,     SEND(_______));
| RP,     SEND(_______));
| RL,     SEND(_______));
| RT,     SEND(_______));
| RD,     SEND(_______));
| LSD,    SEND(_______));
| LK,     SEND(_______));
| LW,     SEND(_______));
| LR,     SEND(_______));
| ST2,    SEND(_______));
| RR,     SEND(_______));
| RB,     SEND(_______));
| RG,     SEND(_______));
| RS,     SEND(_______));
| RZ,     SEND(_______));
END TEMPLATE
*/
// QMK Layer Numbers
#define BASE 0
#define GAME 1
#define MACROBAR 2

// Do not change QMK Layer 0! This is your main keyboard.
// Make your QMK modifications to the later layers, to add
// keys/customize on the first layer modify processQwerty():
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [BASE] = LAYOUT_butter(
  	STN_S1,  STN_TL,  STN_PL,  STN_HL,  STN_ST1, STN_FR,  STN_PR,  STN_LR,  STN_TR,  STN_DR,
   	STN_S2,  STN_KL,  STN_WL,  STN_RL,  STN_ST2, STN_RR,  STN_BR,  STN_GR,  STN_SR,  STN_ZR
  ),

  [GAME] = LAYOUT_butter(
  	_______,	KC_MS_U,  _______, KC_ESC,   RESET,   KC_WH_L, 	KC_WH_D, KC_WH_U, KC_WH_R,      KC_CAPS,
  	KC_MS_L,	KC_MS_D,  KC_MS_R, _______,  _______, KC_BTN3,	KC_BTN1, KC_BTN2, TO(MACROBAR), TO(BASE)
  ),

  [MACROBAR] = LAYOUT_butter(
  	KC_E,    _______, _______, _______, _______, _______, _______, _______, _______, _______, 
  	_______, _______, _______, _______, _______, _______, _______, _______, _______, TO(BASE)
  )
};
// Note: You can only use basic keycodes here!
// P() is just a wrapper to make your life easier, any C code can be executed.
// Only the longest matched chord is run!
//
// http://docs.gboards.ca
uint32_t processQwerty(bool lookup) {
    // Minuscule Letters
    P(LSU, SEND(KC_Q));
    P(LFT, SEND(KC_W));
    P(LP, SEND(KC_E));
    P(LH, SEND(KC_R));
    P(ST1, SEND(KC_T));
    P(RF, SEND(KC_Y));
    P(RP, SEND(KC_U));
    P(RL, SEND(KC_I));
    P(RT, SEND(KC_O));
    P(RD, SEND(KC_P));
    P(LSU | LSD, SEND(KC_A));
    P(LFT | LK, SEND(KC_S));
    P(LP | LW, SEND(KC_D));
    P(LH | LR, SEND(KC_F));
    P(ST1 | ST2, SEND(KC_G));
    P(RF | RR, SEND(KC_H));
    P(RP | RB, SEND(KC_J));
    P(RG | RL, SEND(KC_K));
    P(RT | RS, SEND(KC_L));
    P(RD | RZ, SEND(KC_SPC));
    P(LSD, SEND(KC_Z));
    P(LK, SEND(KC_X));
    P(LW, SEND(KC_C));
    P(LR, SEND(KC_V));
    P(ST2, SEND(KC_B));
    P(RR, SEND(KC_N));
    P(RB, SEND(KC_M));
    P(RG, SEND(KC_COMM));
    P(RS, SEND(KC_DOT));
    P(RZ, SEND(KC_BSPC));

    // Majuscule Letters
    // right shift
    P(LSU | RD | RZ, SEND(KC_LSFT); SEND(KC_Q));
    P(LFT | RD | RZ, SEND(KC_LSFT); SEND(KC_W));
    P(LP | RD | RZ, SEND(KC_LSFT); SEND(KC_E));
    P(LH | RD | RZ, SEND(KC_LSFT); SEND(KC_R));
    P(ST1 | RD | RZ, SEND(KC_LSFT); SEND(KC_T));
    P(RF | RD | RZ, SEND(KC_LSFT); SEND(KC_Y));
    P(RP | RD | RZ, SEND(KC_LSFT); SEND(KC_U));
    P(RL | RD | RZ, SEND(KC_LSFT); SEND(KC_I));
    P(RT | RD | RZ, SEND(KC_LSFT); SEND(KC_O));
    P(LSU | LSD | RD | RZ, SEND(KC_LSFT); SEND(KC_A));
    P(LFT | LK | RD | RZ, SEND(KC_LSFT); SEND(KC_S));
    P(LP | LW | RD | RZ, SEND(KC_LSFT); SEND(KC_D));
    P(LH | LR | RD | RZ, SEND(KC_LSFT); SEND(KC_F));
    P(ST1 | ST2 | RD | RZ, SEND(KC_LSFT); SEND(KC_G));
    P(RF | RR | RD | RZ, SEND(KC_LSFT); SEND(KC_H));
    P(RP | RB | RD | RZ, SEND(KC_LSFT); SEND(KC_J));
    P(RG | RL | RD | RZ, SEND(KC_LSFT); SEND(KC_K));
    P(RT | RS | RD | RZ, SEND(KC_LSFT); SEND(KC_L));
    P(LSD | RD | RZ, SEND(KC_LSFT); SEND(KC_Z));
    P(LK | RD | RZ, SEND(KC_LSFT); SEND(KC_X));
    P(LW | RD | RZ, SEND(KC_LSFT); SEND(KC_C));
    P(LR | RD | RZ, SEND(KC_LSFT); SEND(KC_V));
    P(ST2 | RD | RZ, SEND(KC_LSFT); SEND(KC_B));
    P(RR | RD | RZ, SEND(KC_LSFT); SEND(KC_N));
    P(RG | RD | RZ, SEND(KC_LSFT); SEND(KC_COMM));
    P(RS | RD | RZ, SEND(KC_LSFT); SEND(KC_DOT));
    // left shift
    P(LFT | LSD, SEND(KC_LSFT); SEND(KC_W));
    P(LP | LSD, SEND(KC_LSFT); SEND(KC_E));
    P(LH | LSD, SEND(KC_LSFT); SEND(KC_R));
    P(ST1 | LSD, SEND(KC_LSFT); SEND(KC_T));
    P(RF | LSD, SEND(KC_LSFT); SEND(KC_Y));
    P(RP | LSD, SEND(KC_LSFT); SEND(KC_U));
    P(RL | LSD, SEND(KC_LSFT); SEND(KC_I));
    P(RT | LSD, SEND(KC_LSFT); SEND(KC_O));
    P(LSD | RD, SEND(KC_LSFT); SEND(KC_P));
    P(LFT | LK | LSD, SEND(KC_LSFT); SEND(KC_S));
    P(LP | LW | LSD, SEND(KC_LSFT); SEND(KC_D));
    P(LH | LR | LSD, SEND(KC_LSFT); SEND(KC_F));
    P(ST1 | ST2 | LSD, SEND(KC_LSFT); SEND(KC_G));
    P(RF | RR | LSD, SEND(KC_LSFT); SEND(KC_H));
    P(RP | RB | LSD, SEND(KC_LSFT); SEND(KC_J));
    P(RG | RL | LSD, SEND(KC_LSFT); SEND(KC_K));
    P(RT | RS | LSD, SEND(KC_LSFT); SEND(KC_L));
    P(LK | LSD, SEND(KC_LSFT); SEND(KC_X));
    P(LW | LSD, SEND(KC_LSFT); SEND(KC_C));
    P(LR | LSD, SEND(KC_LSFT); SEND(KC_V));
    P(ST2 | LSD, SEND(KC_LSFT); SEND(KC_B));
    P(RR | LSD, SEND(KC_LSFT); SEND(KC_N));
    P(RB | LSD, SEND(KC_LSFT); SEND(KC_M));
    P(RG | LSD, SEND(KC_LSFT); SEND(KC_COMM));
    P(RS | LSD, SEND(KC_LSFT); SEND(KC_DOT));
	
    // Movement Layer
    P(DIR1 | LSU, SEND(KC_TAB));
    P(DIR1 | LSU | RS, SEND(KC_LALT); SEND(KC_TAB));  // alt-tab (only once, cannot chain multiple tab taps)
    P(DIR1 | LFT, SEND(KC_UP));
    P(DIR1 | LH, SEND(KC_INS));
    P(DIR1 | RL, SEND(KC_HOME));
    P(DIR1 | RT, SEND(KC_MINS));
    P(DIR1 | RT | ST1 | ST2, SEND(KC_LSFT); SEND(KC_MINS));  // _
    P(DIR1 | RD, SEND(KC_EQL));
    P(DIR1 | RD | ST1 | ST2, SEND(KC_LSFT); SEND(KC_EQL));  // +
    P(DIR1 | LSD | LSU, SEND(KC_LEFT));
    P(DIR1 | LK | LFT, SEND(KC_DOWN));
    P(DIR1 | LP | LW, SEND(KC_RIGHT));
    P(DIR1 | LR | LH, SEND(KC_PSCR));
    P(DIR1 | RG, SEND(KC_END));
    P(DIR1 | RS | RT, SEND(KC_LBRC));
    P(DIR1 | RS | RT | ST1 | ST2, SEND(KC_LSFT); SEND(KC_LBRC));  // {
    P(DIR1 | RZ | RD, SEND(KC_RBRC));
    P(DIR1 | RZ | RD | ST1 | ST2, SEND(KC_LSFT); SEND(KC_RBRC));  // }
    P(DIR1 | RZ, SEND(KC_SLSH));                                  // /
    P(DIR1 | RZ | ST1 | ST2, SEND(KC_LSFT); SEND(KC_SLSH));       //?

    // Number Row
    P(NUM1 | LSU, SEND(KC_1));
    P(NUM1 | LFT, SEND(KC_2));
    P(NUM1 | LP, SEND(KC_3));
    P(NUM2 | LH, SEND(KC_4));
    P(NUM1 | ST1, SEND(KC_5));
    P(NUM1 | RF, SEND(KC_6));
    P(NUM1 | RP, SEND(KC_7));
    P(NUM1 | RL, SEND(KC_8));
    P(NUM1 | RT, SEND(KC_9));
    P(NUM1 | RD, SEND(KC_0));
    P(NUM1 | RR, SEND(KC_ENT));

    // Number Row, Function keys
    P(NUM2 | LSU, SEND(KC_F1));
    P(NUM2 | LFT, SEND(KC_F2));
    P(NUM2 | LP, SEND(KC_F3));
    P(NUM2 | LH, SEND(KC_F4));
    P(LR | ST2 | LH | RS, SEND(KC_LALT); SEND(KC_F4));  // alt-F4
    P(NUM2 | ST1, SEND(KC_F5));
    P(NUM2 | RF, SEND(KC_F6));
    P(NUM2 | RP, SEND(KC_F7));
    P(NUM2 | RL, SEND(KC_F8));
    P(NUM2 | RT, SEND(KC_F9));
    P(NUM2 | RD, SEND(KC_F10));
    P(NUM2 | LSD, SEND(KC_F11));
    P(NUM2 | LK, SEND(KC_F12));

    // Symbols
    P(SYMB | LSU, SEND(KC_LSFT); SEND(KC_1));         // !
    P(SYMB | LFT, SEND(KC_LSFT); SEND(KC_2));         // @
    P(SYMB | LP, SEND(KC_LSFT); SEND(KC_3));          // #
    P(SYMB | LH | LW, SEND(KC_LSFT); SEND(KC_4));     // $
    P(SYMB | ST1, SEND(KC_LSFT); SEND(KC_5));         // %
    P(SYMB | RF, SEND(KC_LSFT); SEND(KC_6));          // ^
    P(SYMB | RP, SEND(KC_LSFT); SEND(KC_7));          // &
    P(SYMB | RL, SEND(KC_PAST));                      // *
    P(SYMB | RT, SEND(KC_LSFT); SEND(KC_9));          // (
    P(SYMB | RD, SEND(KC_LSFT); SEND(KC_0));          // )
    P(ST2 | LSU, SEND(KC_GRV));                       // `
    P(ST2 | LSU | RF, SEND(KC_LSFT); SEND(KC_GRV));   // ~
    P(ST2 | RD, SEND(KC_BSLS));                       // backslash
    P(ST2 | ST1 | RD, SEND(KC_LSFT); SEND(KC_BSLS));  // |
    P(ST2 | RS, SEND(KC_SCLN));                       // ;
    P(ST2 | ST1 | RS, SEND(KC_LSFT); SEND(KC_SCLN));  // :
    P(ST2 | LSD | RS, SEND(KC_LSFT); SEND(KC_SCLN));  // :
    P(ST2 | RZ, SEND(KC_QUOT));                       // '
    P(ST2 | ST1 | RZ, SEND(KC_LSFT); SEND(KC_QUOT));  // "
    P(ST2 | LSD | RZ, SEND(KC_LSFT); SEND(KC_QUOT));  // "

    // Mods & Specials
    P(ST2 | RR, SEND(KC_LCTL); SEND(KC_LALT); SEND(KC_DEL));     // ctrl + alt + del
    P(ST2 | LH, SEND(KC_ESC));                                   // esc
    P(RB | RS, SEND(KC_LALT));                                   // alt
    P(LK | ST2, SEND(KC_CAPS));                                  // caps lock
    P(RZ | LH | LR, SEND(KC_LCTL); SEND(KC_F));                  // ctrl + f
    P(RZ | LFT | LK, SEND(KC_LCTL); SEND(KC_S));                 // ctrl + s
    P(RZ | LSU | LSD, SEND(KC_LCTL); SEND(KC_A));                // ctrl + a
    P(RZ | LR, SEND(KC_LCTL); SEND(KC_V));                       // ctrl + v
    P(RZ | LW, SEND(KC_LCTL); SEND(KC_C));                       // ctrl + c
    P(RZ | LSD, SEND(KC_LCTL); SEND(KC_Z));                      // ctrl + z
    P(RZ | LFT, SEND(KC_LCTL); SEND(KC_W));                      // ctrl + w
    P(RZ | ST1, SEND(KC_LCTL); SEND(KC_T));                      // ctrl + t
    P(RZ | RS | RD, SEND(KC_LCTL); SEND(KC_P));                  // ctrl + p
    P(RZ | RR, SEND(KC_LCTL); SEND(KC_N));                       // ctrl + n
    P(RG | LP, SEND(KC_LGUI); SEND(KC_E));                       // win + e
    P(RZ | ST1 | RS, SEND(KC_LSFT); SEND(KC_LCTL); SEND(KC_T));  // ctrl + t

    return 0;
}

// Don't touch this line
size_t keymapsCount = sizeof(keymaps) / sizeof(keymaps[0]);
