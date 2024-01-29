/*
 * Good on you for modifying your layout, this is the most nonQMK layout you will come across
 * There are three modes, Steno (the default), QWERTY (Toggleable) and a Momentary symbol layer
 *
 * Don't modify the steno layer directly, instead add chords using the keycodes and macros
 * from sten.h to the layout you want to modify.
 *
 * Observe the comment above processQWERTY!
 *
 * http://docs.gboards.ca
 */

#include QMK_KEYBOARD_H
#include "sten.h"
#include "keymap_steno.h"
#define IGNORE_MOD_TAP_INTERRUPT

// Proper Layers
#define DIR     (RU)
#define NUM     (LA)
#define SYMB    (LA | RU)
#define ETC     (LO)

// QMK Layers
#define STENO_LAYER   0

/* Keyboard Layout
			A     S     D    F    G			 H    J    K    L    ;
 * .---------------------------------.    .------------------------------.
 * | FN  | LSU | LFT | LP | LH | ST1 |    | ST3 | RF | RP | RL | RT | RD |
 * |-----+-----+-----+----+----|-----|    |-----|----+----+----+----+----|
 * | PWR | LSD | LK  | LW | LR | ST2 |    | ST4 | RR | RB | RG | RS | RZ |
 * '---------------------------------'    '------------------------------'
 *                   .---------------.    .---------------.
 *                   | LNO | LA | LO |    | RE | RU | RNO |
 *                   '---------------'    '---------------'
 */

// Note: You can only use basic keycodes here!
// P() is just a wrapper to make your life easier.
// PC() applies the mapping to all of the StenoLayers.
//   To overload, declare it with P() first.
//   Be sure to enable in rules.mk and see colemak-dh for usage 
//
// FN is unavailable. That is reserved for system use.
// Chords containing PWR are always available, even in steno mode.
//
// http://docs.gboards.ca
uint32_t processQwerty(bool lookup) {
	// Letters (gherkin layout)
	P( LSU,          SEND(KC_Q));
    P( LFT,          SEND(KC_W));
    P( LP,           SEND(KC_E));
    P( LH,           SEND(KC_R));
    P( ST1,          SEND(KC_T));
    P( ST3,          SEND(KC_Y));
    P( RF,           SEND(KC_U));
    P( RP,           SEND(KC_I));
    P( RL,           SEND(KC_O));
    P( RT,           SEND(KC_P));
    P( LSU | LSD,    SEND(KC_A));
    P( LFT | LK,     SEND(KC_S));
    P( LP  | LW,     SEND(KC_D));
    P( LH  | LR,     SEND(KC_F));
    P( ST1 | ST2,    SEND(KC_G));
    P( ST3 | ST4,    SEND(KC_H));
    P( RF  | RR,     SEND(KC_J));
    P( RP  | RB,     SEND(KC_K));
    P( RG  | RL,     SEND(KC_L));
    P( RT  | RS,     SEND(KC_SPC));
    P( LSD,          SEND(KC_Z));
    P( LK,           SEND(KC_X));
    P( LW,           SEND(KC_C));
    P( LR,           SEND(KC_V));
    P( ST2,          SEND(KC_B));
    P( ST4,          SEND(KC_N));
    P( RR,           SEND(KC_M));
    P( RB,           SEND(KC_COMM));
    P( RG,           SEND(KC_DOT));
    P( RS,           SEND(KC_BSPC));
	P( RE,           SEND(KC_SPC));

    // Direction Layer
    P( DIR | LSU,		   SEND(KC_TAB));
	P( DIR | LFT,          SEND(KC_UP));
    P( DIR | LH,           SEND(KC_INS));
    P( DIR | ST1,          SEND(KC_LCTL));
    P( DIR | ST3,          SEND(KC_RSFT));
    P( DIR | RF,           SEND(KC_PGUP));
    P( DIR | RP,           SEND(KC_HOME));
    P( DIR | RL,           SEND(KC_MINS));
    P( DIR | RT,           SEND(KC_EQL));
    P( DIR | LSU | LSD,    SEND(KC_LEFT));
    P( DIR | LFT | LK,     SEND(KC_DOWN));
    P( DIR | LP  | LW,     SEND(KC_RGHT));
    P( DIR | LH  | LR,     SEND(KC_PSCR));
    P( DIR | ST1 | ST2,    SEND(KC_LSFT));
    P( DIR | ST3 | ST4,    SEND(KC_RCTL));
    P( DIR | RF  | RR,     SEND(KC_PGDN));
    P( DIR | RP  | RB,     SEND(KC_END));
    P( DIR | RG  | RL,     SEND(KC_LBRC));
    P( DIR | RT  | RS,     SEND(KC_RBRC));
    P( DIR | LSD,          SEND(KC_PAUS));
    P( DIR | RB,           SEND(KC_RGUI));
    P( DIR | RG,           SEND(KC_LALT));
    P( DIR | RS,           SEND(KC_SLSH));
	
	// Number Layer
    P( NUM | LSU,          SEND(KC_F1));
    P( NUM | LFT,          SEND(KC_F2));
    P( NUM | LP,           SEND(KC_F3));
    P( NUM | LH,           SEND(KC_F4));
    P( NUM | ST1,          SEND(KC_F5));
    P( NUM | ST3,          SEND(KC_F6));
    P( NUM | RF,           SEND(KC_F7));
    P( NUM | RP,           SEND(KC_F8));
    P( NUM | RL,           SEND(KC_F9));
    P( NUM | RT,           SEND(KC_F10));
    P( NUM | LSU | LSD,    SEND(KC_1));
    P( NUM | LFT | LK,     SEND(KC_2));
    P( NUM | LP  | LW,     SEND(KC_3));
    P( NUM | LH  | LR,     SEND(KC_4));
    P( NUM | ST1 | ST2,    SEND(KC_5));
    P( NUM | ST3 | ST4,    SEND(KC_6));
    P( NUM | RF  | RR,     SEND(KC_7));
    P( NUM | RP  | RB,     SEND(KC_8));
    P( NUM | RG  | RL,     SEND(KC_9));
    P( NUM | RT  | RS,     SEND(KC_0));
    P( NUM | LSD,          SEND(KC_F11));
    P( NUM | LK,           SEND(KC_F12)); 	
    P( NUM | RE,           SEND(KC_ENT));
    P( NUM | RR,           SEND(KC_RSFT));
    P( NUM | RB,           SEND(KC_RGUI));
    P( NUM | RG,           SEND(KC_DOT));
    P( NUM | RS,           SEND(KC_BSPC));
	
	// Symbols	
    P( SYMB | LSU | LSD,   SEND(KC_LSFT); SEND(KC_1));   // !
    P( SYMB | LFT | LK,    SEND(KC_LSFT); SEND(KC_2));   // @
    P( SYMB | LP  | LW,    SEND(KC_LSFT); SEND(KC_3));   // #
    P( SYMB | LH  | LR,    SEND(KC_LSFT); SEND(KC_4));   // $
    P( SYMB | ST1 | ST2,   SEND(KC_LSFT); SEND(KC_5));   // %
    P( SYMB | ST3 | ST4,   SEND(KC_LSFT); SEND(KC_6));   // ^
    P( SYMB | RF  | RR,    SEND(KC_LSFT); SEND(KC_7));   // &
	P( SYMB | RP  | RB,    SEND(KC_PAST)); 			     // * 
    P( SYMB | RG  | RL,    SEND(KC_LSFT); SEND(KC_9)); 	 // (
    P( SYMB | RT  | RS,    SEND(KC_LSFT); SEND(KC_0)); 	 // )
	
	// ETC
	P( ETC | LSU,          SEND(KC_GRV));
    P( ETC | LH,           SEND(KC_ESC));
    P( ETC | ST3,          SEND(KC_RSFT));
    P( ETC | RT,           SEND(KC_BSLS));
    P( ETC | ST1 | ST2,    SEND(KC_LSFT));
    P( ETC | RG  | RL,     SEND(KC_SCLN));
    P( ETC | RT  | RS,     SEND(KC_QUOT));
    P( ETC | LK,           SEND(KC_CAPS));
    P( ETC | RG,           SEND(KC_LALT));
    P( ETC | RS,           SEND(KC_DEL));
	P( ETC | RE,           SEND(KC_LCTL); SEND(KC_LALT); SEND(KC_DEL));

    // Mouse Keys
    P( LO  | LSD | LK,    CLICK_MOUSE(KC_MS_BTN2));
    P( LO  | LR  | LW,    CLICK_MOUSE(KC_MS_BTN1));
	
	
	// Mods
	P( RD | RZ,     SEND(KC_RSFT));
	P( RZ,     		SEND(KC_RCTL));
	P( LNO,     	SEND(KC_LSFT));
	P( LNO | LA,    SEND(KC_LCTL));

    return 0;
}

// "Layers"
// Steno layer should be first in your map.
// Note: If using NO_ACTION_TAPPING, LT will not work!

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // Main layer, everything goes through here
    [STENO_LAYER] = LAYOUT_georgi(
        STN_FN,  STN_S1,  STN_TL,  STN_PL,  STN_HL,  STN_ST1,       STN_ST3, STN_FR,  STN_PR,  STN_LR,  STN_TR,  STN_DR,
        STN_PWR, STN_S2,  STN_KL,  STN_WL,  STN_RL,  STN_ST2,       STN_ST4, STN_RR,  STN_BR,  STN_GR,  STN_SR,  STN_ZR,
                                   STN_N1,  STN_A,   STN_O,         STN_E,   STN_U,   STN_N7
    ),
};

// Don't fuck with this, thanks.
size_t keymapsCount  = sizeof(keymaps)/sizeof(keymaps[0]);
