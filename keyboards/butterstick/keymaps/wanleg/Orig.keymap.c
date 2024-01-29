#include QMK_KEYBOARD_H

#include "sten.h"
/* 	 	
 *  Key names are inherited from steno machines
 *  .-----------------------------------------------------.
 *	| LSU | LFT | LP | LH | ST1 | RF | RP | RL | RT | RD  |
 *  |-----------------------------------------------------|
 *	| LSD | LK  | LW | LR | ST2 | RR | RB | RG | RS | RZ  |
 *  '-----------------------------------------------------'
       A    S     D    F     G    H    J    K    L    ;
 */

// Function prefixes
#define DIR1	(RB)	
#define DIR2	(RB | RG)	
#define SYMB	(LR | RB)	
#define NUM1    (LR)
#define NUM2    (LW  | LR)	

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

// Do not change QMK Layer 0! This is your main keyboard.
// Make your QMK modifications to the later layers, to add 
// keys/customize on the first layer modify processQwerty():
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [BASE] = LAYOUT_butter(
  	STN_S1,  STN_TL,  STN_PL,  STN_HL,  STN_ST1, STN_FR,  STN_PR,  STN_LR,  STN_TR,  STN_DR,
   	STN_S2,  STN_KL,  STN_WL,  STN_RL,  STN_ST2, STN_RR,  STN_BR,  STN_GR,  STN_SR,  STN_ZR
  ),
  // I don't game don't roast me thanks
  [GAME] = LAYOUT_butter(
  	KC_Q,  KC_W,  KC_E,  KC_R,  KC_T, KC_Y, KC_U, KC_I,  KC_O, KC_ENT,
  	KC_A,  KC_S,  KC_D,  KC_F,  KC_G, KC_H, KC_J, KC_K,  KC_L, TO(BASE)
  )
};

// Note: You can only use basic keycodes here!
// P() is just a wrapper to make your life easier, any C code can be executed.
// Only the longest matched chord is run!
//
// http://docs.gboards.ca
uint32_t processQwerty(bool lookup) {
    // Dual chords
    P( LP  | LH,    			CLICK_MOUSE(KC_MS_BTN2));
    P( ST1 | RF,    			CLICK_MOUSE(KC_MS_BTN1));
    P( LSU | LFT,               SEND(KC_ESC));
	P( LSD | LK,				SEND(KC_LSFT));
	P( RZ  | RS,				SEND(KC_RSFT));
    P( RG  | RS,    			SEND(KC_LGUI));
    P( RB  | RS,    			SEND(KC_LALT));
	P( LSU | LSD | LFT | LK,	SEND(KC_LCTL));
	P( RS  | RT  | RD  | RZ,	SEND(KC_RCTL));

    // Movement Layer
    P( DIR1 | LSU,    SEND(KC_TAB));
	P( DIR1 | LSU | RS,    SEND(KC_LALT); SEND(KC_TAB)); //alt-tab (only once, cannot chain multiple tab taps)
    P( DIR1 | LFT,    SEND(KC_UP));
    P( DIR1 | LH,     SEND(KC_INS));
    P( DIR1 | ST1,    SEND(KC_LCTL));
    P( DIR1 | RF,     SEND(KC_RSFT));
    P( DIR2 | RP,     SEND(KC_PGUP));
    P( DIR1 | RL,     SEND(KC_HOME));
    P( DIR1 | RT,     SEND(KC_MINS));
    P( DIR1 | RD,     SEND(KC_EQL));
    P( DIR1 | LSD,    SEND(KC_LEFT));
    P( DIR1 | LK,     SEND(KC_DOWN));
    P( DIR1 | LW,     SEND(KC_RIGHT));
    P( DIR1 | LR,     SEND(KC_PSCR));
    P( DIR1 | ST2,    SEND(KC_LSFT));
    P( DIR1 | RR,     SEND(KC_RCTL));
    P( DIR2 | RL,     SEND(KC_PGDN));
    P( DIR1 | RG,     SEND(KC_END));
    P( DIR1 | RS | RT,     SEND(KC_LBRC));
    P( DIR1 | RZ | RD,     SEND(KC_RBRC));
	P( DIR1 | RZ,     SEND(KC_SLSH));			// /
	P( DIR1 | ST2 | RZ,     SEND(KC_LSFT); SEND(KC_SLSH)); // ?
	

    // Number Row
    P( NUM1 | LSU,    SEND(KC_1));
    P( NUM1 | LFT,    SEND(KC_2));
    P( NUM1 | LP,     SEND(KC_3));
    P( NUM2 | LH,     SEND(KC_4));
    P( NUM1 | ST1,    SEND(KC_5));
    P( NUM1 | RF,     SEND(KC_6));
    P( NUM1 | RP,     SEND(KC_7));
    P( NUM1 | RL,     SEND(KC_8));
    P( NUM1 | RT,     SEND(KC_9));
    P( NUM1 | RD,     SEND(KC_0));
	P( NUM1 | RR,     SEND(KC_ENT));

    // Number Row, Function keys
    P( NUM2 | LSU,    SEND(KC_F1));
    P( NUM2 | LFT,    SEND(KC_F2));
    P( NUM2 | LP,     SEND(KC_F3));
    P( NUM2 | LH,     SEND(KC_F4));
	P( LR | ST2 | LH | RS,     SEND(KC_LALT); SEND(KC_F4)); //alt-F4
    P( NUM2 | ST1,    SEND(KC_F5));
    P( NUM2 | RF,     SEND(KC_F6));
    P( NUM2 | RP,     SEND(KC_F7));
    P( NUM2 | RL,     SEND(KC_F8));
    P( NUM2 | RT,     SEND(KC_F9));
    P( NUM2 | RD,     SEND(KC_F10));
	P( NUM2 | LSD,    SEND(KC_F11));
	P( NUM2 | LK,     SEND(KC_F12));


    // Symbols	
    P( SYMB | LSU,    SEND(KC_LSFT); SEND(KC_1));       // !
    P( SYMB | LFT,    SEND(KC_LSFT); SEND(KC_2));       // @
    P( SYMB | LP,     SEND(KC_LSFT); SEND(KC_3));       // #
    P( SYMB | LH,     SEND(KC_LSFT); SEND(KC_4));       // $
    P( SYMB | ST1,    SEND(KC_LSFT); SEND(KC_5));       // %
    P( SYMB | RF,     SEND(KC_LSFT); SEND(KC_6));       // ^
    P( SYMB | RP,     SEND(KC_LSFT); SEND(KC_7));       // &
    P( SYMB | RL,     SEND(KC_PAST));  					// * 
    P( SYMB | RT,     SEND(KC_LSFT); SEND(KC_9));       // (
    P( SYMB | RD,     SEND(KC_LSFT); SEND(KC_0));       // )
    P( ST2  | LSU,    SEND(KC_GRV));					// `
	P( ST2  | LSU | RF,   SEND(KC_LSFT); SEND(KC_GRV)); // ~
	P( ST2  | RD,     SEND(KC_BSLS));					// backslash 
	P( ST2  | ST1 | RD,   SEND(KC_LSFT); SEND(KC_BSLS));// |
	P( ST2  | RS,     SEND(KC_SCLN));					// ;
	P( ST2  | ST1 | RS,   SEND(KC_LSFT); SEND(KC_SCLN));// :
	P( ST2  | LSD | RS,   SEND(KC_LSFT); SEND(KC_SCLN));// :
	P( ST2  | RZ,     SEND(KC_QUOT));					// '
	P( ST2  | ST1 | RZ,   SEND(KC_LSFT); SEND(KC_QUOT));// "
	P( ST2  | LSD | RZ,   SEND(KC_LSFT); SEND(KC_QUOT));// "

    // Letters
    P( LSU | LSD,    SEND(KC_A));
    P( LFT | LK,     SEND(KC_S));
    P( LP  | LW,     SEND(KC_D));
    P( LH  | LR,     SEND(KC_F));
    P( ST1 | ST2,    SEND(KC_G));
    P( RF  | RR,     SEND(KC_H));
    P( RT  | RS,     SEND(KC_L));
    P( RD  | RZ,     SEND(KC_SPC));
    P( RG  | RL,     SEND(KC_K));
    P( RP  | RB,     SEND(KC_J));
    P( LSU,          SEND(KC_Q));
    P( LSD,          SEND(KC_Z));
    P( LFT,          SEND(KC_W));
    P( LK,           SEND(KC_X));
    P( LP,           SEND(KC_E));
    P( LW,           SEND(KC_C));
    P( LH,           SEND(KC_R));
    P( LR,           SEND(KC_V));
    P( ST1,          SEND(KC_T));
    P( ST2,          SEND(KC_B));
    P( RF,           SEND(KC_Y));
    P( RR,           SEND(KC_N));
    P( RP,           SEND(KC_U));
    P( RB,           SEND(KC_M));
    P( RL,           SEND(KC_I));
    P( RG,           SEND(KC_COMM));
    P( RT,           SEND(KC_O));
    P( RS,           SEND(KC_DOT));
    P( RD,           SEND(KC_P));
    P( RZ,           SEND(KC_BSPC));

    return 0;
}


// Don't fuck with this, thanks.
size_t keymapsCount  = sizeof(keymaps)/sizeof(keymaps[0]);
