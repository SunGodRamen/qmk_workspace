#include QMK_KEYBOARD_H
#include "g/keymap_combo.h" 
#include "keymap_steno.h" 
#include "stdio.h"

#include "overrides/overrides.h"

//LEADER_EXTERNS();
//#include "leader_dict/leader_dict.h"

enum custom_keycodes {
  RGB_SLD = SAFE_RANGE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
//                                                    DVORAK
	[0] = LAYOUT(
      KC_COLN,  KC_COMM,  KC_DOT,       KC_P,    KC_Y,      LT(4, KC_F), KC_G,       KC_C,     KC_R,    KC_L,
      KC_A,     KC_O,     KC_E,         KC_U,    KC_I,           KC_D,   KC_H,        KC_T,     KC_N,    KC_S,
      KC_DQT,   KC_Q,     LGUI_T(KC_J),   KC_K,  KC_X,           KC_B,   KC_M, RGUI_T(KC_W),     KC_V,    KC_Z,
  
                                    HYPR_T(KC_EXEC), LSFT_T(KC_TAB),     RSFT_T(KC_SPACE), LT(1, KC_ESC) 
  ),

//                                                     NAV
  [1] = LAYOUT(
      KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,    KC_TRNS, KC_TRNS,    KC_TRNS,     KC_TRNS,   KC_TRNS,
      KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,    KC_TAB, KC_LEFT,  KC_DOWN,   KC_UP,   KC_RGHT,
      KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,    RSFT(KC_TAB), KC_HOME,  KC_PGDN,   KC_PGUP, KC_END,
      
                                      KC_TRNS, KC_TRNS,   KC_TRNS, KC_TRNS
        ),
//                                                   MOUSE
  [2] = LAYOUT(
      KC_TRNS,  KC_TRNS,  KC_WH_U,  KC_TRNS,  KC_TRNS,    KC_TRNS,  KC_BTN4,  KC_TRNS,  KC_BTN5,  KC_TRNS,
      KC_BTN4,  KC_BTN2,  KC_BTN3,  KC_BTN1,  KC_BTN5,    KC_WH_D,  KC_MS_L,  KC_MS_D,  KC_MS_U,  KC_MS_R,
      KC_TRNS,  KC_WH_L,  KC_WH_D,  KC_WH_R,  KC_TRNS,    KC_WH_U,  KC_BTN1,  KC_BTN3,  KC_BTN2,  KC_TRNS,
             
                                      KC_TRNS, KC_TRNS,   TO(0), TO(2) 
        ),
//                                                  PARENTHESIS
  [3] = LAYOUT(
      KC_TRNS,  KC_RCBR,  KC_RBRC,  KC_RPRN,  KC_GT,      KC_GT,  KC_RPRN,  KC_RBRC,  KC_RCBR,KC_TRNS,
      KC_TRNS,  KC_LCBR,  KC_LBRC,  KC_LPRN,  KC_LT,        KC_LT,  KC_LPRN,  KC_LBRC,  KC_LCBR, KC_TRNS,
      KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,      KC_TRNS,   KC_TRNS,    KC_TRNS,    KC_TRNS, KC_TRNS,
             
                                      KC_TRNS, KC_TRNS,   KC_TRNS, KC_TRNS
        ), 

//                                                    STENO
  [4] = LAYOUT(
      STN_N1,   STN_N2,   STN_N3,   STN_N4,   STN_N5,     STN_N6,   STN_N7,   STN_N8,   STN_N9,   TO(0),
      STN_S1,   STN_TL,   STN_PL,   STN_HL,   STN_ST1,    STN_FR,   STN_BR,   STN_LR,   STN_TR,   STN_DR,
      STN_S2,   STN_KL,   STN_WL,   STN_RL,   STN_ST2,    STN_RR,   STN_PR,   STN_GR,   STN_SR,   STN_ZR,

                                        STN_A, STN_O,     STN_E, STN_U
      ),
//                                                FUNCTION1
  [5] = LAYOUT(
        KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,    KC_F9,    KC_F10,      KC_TRNS,    KC_TRNS, KC_TRNS,
      KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,    KC_F1,     KC_F2,      KC_F3,      KC_F4,   KC_TRNS,
      KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,    KC_F5,     KC_F6,      KC_F7,      KC_F8,   KC_TRNS,
             
                                      KC_TRNS, KC_TRNS,   MO(6), MO(7)
        ), 
//                                                FUNCTION2
  [6] = LAYOUT(
      KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,    KC_F19,     KC_F20,      KC_TRNS,     KC_TRNS,  KC_TRNS,
      KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,    KC_F11,     KC_F12,      KC_F13,      KC_F14,  KC_TRNS,
      KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,    KC_F15,     KC_F16,      KC_F17,      KC_F18,  KC_TRNS,
             
                                      KC_TRNS, KC_TRNS,   KC_TRNS, MO(7)
        ),
//                                                FUNCTION3
  [7] = LAYOUT(
      KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,    KC_TRNS,     KC_TRNS,      KC_TRNS,     KC_TRNS,  KC_TRNS,
      KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,    KC_F21,     KC_F22,      KC_F23,      KC_F24,  KC_TRNS,
      KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,    KC_TRNS,     KC_TRNS,      KC_TRNS,      KC_TRNS,  KC_TRNS,
             
                                      KC_TRNS, KC_TRNS,   KC_TRNS, KC_TRNS
        ),

};

//                                                                  TIMER  
//Timer variables
uint32_t const_time_max = 2147483646;
uint32_t tick = 0;
uint32_t epoch = 0;

//Timer strings
char tick_str[32];
char epoch_str[32];

void matrix_scan_user(void) {
  if ( tick < const_time_max ) {
    tick = tick+1; 
  } else {
    tick = 0;
    if ( epoch < const_time_max ) {
      epoch = epoch+1;
    } else {
      epoch = 0;
    }
  }
 } 

