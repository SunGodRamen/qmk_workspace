#include QMK_KEYBOARD_H
#include "g/keymap_combo.h" 
#include "keymap_steno.h" 
#include "stdio.h"

const key_override_t s_colon_override = ko_make_basic(MOD_MASK_SHIFT, KC_COLN, KC_SCLN);
const key_override_t s_comma_override = ko_make_basic(MOD_MASK_SHIFT, KC_COMM, KC_QUES);
const key_override_t s_dot_override = ko_make_basic(MOD_MASK_SHIFT, KC_DOT, KC_EXLM);
const key_override_t s_dquote_override = ko_make_basic(MOD_MASK_SHIFT, KC_DQUO, KC_QUOT);
const key_override_t s_minus_override = ko_make_basic(MOD_MASK_SHIFT, KC_MINS, KC_PLUS);
const key_override_t s_lt_override = ko_make_basic(MOD_MASK_SHIFT, KC_LT, KC_GT);

const key_override_t a_unds_override = ko_make_basic(MOD_MASK_ALT, KC_UNDS, KC_TILD);
const key_override_t a_s_override = ko_make_basic(MOD_MASK_ALT, KC_S, KC_DLR);
const key_override_t a_a_override = ko_make_basic(MOD_MASK_ALT, KC_A, KC_AT);
const key_override_t a_h_override = ko_make_basic(MOD_MASK_ALT, RCTL_T(KC_H), KC_HASH);
const key_override_t a_v_override = ko_make_basic(MOD_MASK_ALT, KC_V, KC_CIRC);
const key_override_t a_dot_override = ko_make_basic(MOD_MASK_ALT, KC_DOT, KC_ASTR);
const key_override_t a_dquo_override = ko_make_basic(MOD_MASK_ALT, KC_DQUO, KC_GRAVE);
const key_override_t a_slsh_override = ko_make_basic(MOD_MASK_ALT, KC_SLSH, KC_PERC);

const key_override_t **key_overrides = (const key_override_t *[]){
	&s_colon_override,
  &s_comma_override,
  &s_dot_override,
  &s_dquote_override,
  &s_lbracket_override,
  &s_lcurlbracket_override,
  &s_lparenths_override,
  &s_rbracket_override,
  &s_rcurlbracket_override,
  &s_rparenths_override,
  &s_pipe_override,
  &s_minus_override,
  &s_lt_override,
  &s_space_override,
  &a_unds_override, 
  &a_s_override, 
  &a_a_override, 
  &a_h_override, 
  &a_v_override,
  &a_dot_override, 
  &a_slsh_override, 
  &a_dquo_override, 
	NULL
};

enum custom_keycodes {
  RGB_SLD = SAFE_RANGE,
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
//                                                    DVORAK
	[0] = LAYOUT(
      KC_COLN,  KC_COMM,  KC_DOT, LT(10, KC_P), LT(7, KC_Y),    KC_F, KC_G,         KC_C,     KC_R,    KC_L,
      KC_A,     KC_O,     KC_E,   LCTL_T(KC_U), KC_I,           KC_D, RCTL_T(KC_H), KC_T,     KC_N,    KC_S,
      KC_DQT,   KC_Q,     KC_J,   KC_K,         KC_X,           KC_B, KC_M,         KC_W,     KC_V,    KC_Z,
  
                  HYPR_T(LSFT(KC_TAB)), LSFT_T(KC_TAB),     LT(1, KC_SPACE), TT(2) 
  ),

//                                                     NAV
  [1] = LAYOUT(
      KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,    KC_TRNS,  KC_TRNS,  KC_TRNS,   KC_TRNS, KC_TRNS,
      KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,    KC_TGSFT, KC_LEFT,  KC_DOWN,   KC_UP,   KC_RGHT,
      KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,    KC_VIM,  KC_HOME,  KC_PGDN,   KC_PGUP, KC_END,
      
                                      KC_TRNS, KC_TRNS,   KC_TRNS, KC_TRNS
        ),
//                                                   MOUSE
  [2] = LAYOUT(
      KC_TRNS,  KC_TRNS,  KC_WH_U,  KC_TRNS,  KC_TRNS,    KC_TRNS,  KC_TRNS,  KC_BTN1,  KC_TRNS,  KC_TRNS,
      KC_BTN4,  KC_BTN2,  KC_BTN3,  KC_BTN1,  KC_BTN5,    KC_TRNS,  KC_MS_L,  KC_MS_D,  KC_MS_U,  KC_MS_R,
      KC_TRNS,  KC_WH_L,  KC_WH_D,  KC_WH_R,  KC_TRNS,    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
             
                                      KC_ACL0, KC_ACL2,   KC_TRNS, KC_TRNS
        ),
//                                                    STENO
  [4] = LAYOUT(
      STN_N1,   STN_N2,   STN_N3,   STN_N4,   STN_N5,     STN_N6,   STN_N7,   STN_N8,   STN_N9,   TO(0),
      STN_S1,   STN_TL,   STN_PL,   STN_HL,   STN_ST1,    STN_FR,   STN_BR,   STN_LR,   STN_TR,   STN_DR,
      STN_S2,   STN_KL,   STN_WL,   STN_RL,   STN_ST2,    STN_RR,   STN_PR,   STN_GR,   STN_SR,   STN_ZR,

                                        STN_A, STN_O,     STN_E, STN_U
      ),  
//                                                   SEQUENCER1
  [5] = LAYOUT(
      KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  TO(0),
      KC_TRNS,  KC_TRNS,  KC_TRNS,  SQ_SALL,  KC_TRNS,    SQ_ON,  SQ_TMPU,  SQ_RESU,  KC_TRNS,  KC_TRNS,
      KC_TRNS,  KC_TRNS,  KC_TRNS,  SQ_SCLR,  KC_TRNS,    SQ_OFF, SQ_TMPD, SQ_RESD,  KC_TRNS,  KC_TRNS,
             
                                      KC_TRNS, KC_TRNS,   KC_TRNS, MO(6)
        ),
//                                                   SEQUENCER2
  [6] = LAYOUT(
      KC_TRNS,  SQ_S(1),    SQ_S(2),  SQ_S(3),  SQ_S(4),    SQ_S(13),    SQ_S(14),  SQ_S(15),  SQ_S(16),  KC_NO,
      SQ_RES_2, SQ_RES_2T,  SQ_RES_4, SQ_RES_4T, SQ_RES_8,  SQ_RES_8T,  SQ_RES_16,  SQ_RES_16T,  SQ_RES_32,  KC_TRNS,
      KC_TRNS,  SQ_S(8),    SQ_S(7),  SQ_S(6),  SQ_S(5),    SQ_S(9),   SQ_S(10),    SQ_S(11), SQ_S(12),  KC_TRNS,
             
                                      KC_TRNS, KC_TRNS,   KC_TRNS, KC_TRNS
        ),
//                                                FUNCTION1
  [7] = LAYOUT(
      KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,    KC_F9,    KC_F10,      KC_TRNS,    KC_TRNS, KC_TRNS,
      KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,    KC_F1,     KC_F2,      KC_F3,      KC_F4,   KC_TRNS,
      KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,    KC_F5,     KC_F6,      KC_F7,      KC_F8,   KC_TRNS,
             
                                      KC_TRNS, KC_TRNS,   MO(9), MO(8)
        ), 
//                                                FUNCTION2
  [8] = LAYOUT(
      KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,    KC_F19,     KC_F20,      KC_TRNS,     KC_TRNS,  KC_TRNS,
      KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,    KC_F11,     KC_F12,      KC_F13,      KC_F14,  KC_TRNS,
      KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,    KC_F15,     KC_F16,      KC_F17,      KC_F18,  KC_TRNS,
             
                                      KC_TRNS, KC_TRNS,   MO(9), KC_TRNS
        ),
//                                                FUNCTION3
  [9] = LAYOUT(
      KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,    KC_TRNS,     KC_TRNS,      KC_TRNS,     KC_TRNS,  KC_TRNS,
      KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,    KC_F21,     KC_F22,      KC_F23,      KC_F24,  KC_TRNS,
      KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,    KC_TRNS,     KC_TRNS,      KC_TRNS,      KC_TRNS,  KC_TRNS,
             
                                      KC_TRNS, KC_TRNS,   KC_TRNS, KC_TRNS
        ),
//                                                PROGRAMMABLE1
  [10] = LAYOUT(
      KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,    PB_16,    PB_17,     PB_18,     PB_19,    KC_TRNS,
      KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,    PB_6,     PB_7,      PB_8,      PB_9,     PB_10,
      KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,    PB_11,    PB_12,     PB_13,     PB_14,    PB_15,
             
                                      KC_TRNS, KC_TRNS,   MO(11), KC_TRNS
        ),
//                                                PROGRAMMABLE2
  [11] = LAYOUT(
      KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,    PB_30,    PB_31,     PB_32,     KC_TRNS,    KC_TRNS,
      KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,    PB_20,    PB_21,     PB_22,     PB_23,    PB_24,
      KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,    PB_25,    PB_26,     PB_27,     PB_28,    PB_29,
             
                                      KC_TRNS, KC_TRNS,   KC_TRNS, KC_TRNS
        ),

};


LEADER_EXTERNS();

//Timer variables
uint32_t const_time_max = 2147483646;
uint32_t tick = 0;
uint32_t epoch = 0;

//Timer strings
char tick_str[32];
char epoch_str[32];

//for shift toggle
bool sft_pressed = false;
bool sft_toggled = false;
bool sft_tgl_on_timeout = false;
bool sft_tgl_off_timeout = false;
uint32_t sft_start_ticks;
uint32_t sft_start_epochs;
uint32_t const_sft_tgl_on_ticks = 120;
uint32_t const_sft_tgl_on_epochs = 0;
uint32_t const_sft_tgl_off_ticks = 80;
uint32_t const_sft_tgl_off_epochs = 0;

bool vim_insert = false;

void matrix_scan_user(void) {
//                                                                  TIMER  
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
  
  if ( sft_pressed ) {
    if ( ( epoch - sft_start_epochs ) >= const_sft_tgl_on_epochs ) {
      if ( (tick - sft_start_ticks ) >= const_sft_tgl_off_ticks ) {
        // shift held longer than a tap, untoggle when released
        sft_tgl_on_timeout = true;
      }
    }
  } 
  if ( sft_pressed ) {
    if ( ( epoch - sft_start_epochs ) >= const_sft_tgl_off_epochs ) {
      if ( (tick - sft_start_ticks ) >= const_sft_tgl_off_ticks ) {
        // shift held longer than a tap, untoggle when released
        sft_tgl_on_timeout = true;
      }
    }
  } 

  
//                                                                  LEADER
  LEADER_DICTIONARY() {
    leading = false;
    leader_end();

    SEQ_ONE_KEY(LT(1, KC_SPACE)) {
      if (layer_state_is(4)) {
        layer_on(0);
      } else {
        layer_on(4);
      }
    } else

    SEQ_ONE_KEY(LSFT_T(KC_TAB)) {
      if (layer_state_is(5)) {
        layer_on(0);
      } else {
        layer_on(5);
      }
    } else
    SEQ_ONE_KEY(KC_B) {
      register_code(KC_LCTL);
      register_code(KC_GRAVE);
      unregister_code(KC_LCTL);
      unregister_code(KC_GRAVE);
    } else
    SEQ_ONE_KEY(KC_O) {
      register_code(KC_LBRC);
      unregister_code(KC_LBRC);
    } else
    SEQ_ONE_KEY(KC_E) {
      register_code(KC_LSFT);
      register_code(KC_LBRC);
      unregister_code(KC_LBRC);
      unregister_code(KC_LSFT);
    } else
    SEQ_ONE_KEY(KC_U) {
      register_code(KC_LSFT);
      register_code(KC_9);
      unregister_code(KC_9);
      unregister_code(KC_LSFT);
    } else
    SEQ_ONE_KEY(KC_I) {
      register_code(KC_LSFT);
      register_code(KC_COMM);
      unregister_code(KC_COMM);
      unregister_code(KC_LSFT);
    } else
    SEQ_ONE_KEY(KC_D) {
      register_code(KC_RSFT);
      register_code(KC_DOT);
      unregister_code(KC_DOT);
      unregister_code(KC_RSFT);
    } else
    SEQ_ONE_KEY(KC_H) {
      register_code(KC_RSFT);
      register_code(KC_0);
      unregister_code(KC_0);
      unregister_code(KC_RSFT);
    } else
    SEQ_ONE_KEY(KC_T) {
      register_code(KC_RSFT);
      register_code(KC_RBRC);
      unregister_code(KC_RBRC);
      unregister_code(KC_RSFT);
    } else
    SEQ_ONE_KEY(KC_N) {
      register_code(KC_RBRC);
      unregister_code(KC_RBRC);
    }  else
    SEQ_TWO_KEYS(KC_G,KC_S) {
      SEND_STRING("git status");
      register_code(KC_ENTER);
      unregister_code(KC_ENTER);
    } else
    SEQ_TWO_KEYS(KC_G,KC_A) {
      SEND_STRING("git add ");
    } else
    SEQ_TWO_KEYS(KC_G,KC_C) {
      SEND_STRING("git commit -m ");
      register_code(KC_RSFT);
      register_code(KC_QUOT);
      unregister_code(KC_QUOT);
      register_code(KC_QUOT);
      unregister_code(KC_QUOT);
      unregister_code(KC_RSFT);
      register_code(KC_LEFT);
      unregister_code(KC_LEFT);
    } else
    SEQ_TWO_KEYS(KC_E,KC_M) {
      SEND_STRING("@gmail.com");
    } else
    SEQ_TWO_KEYS(KC_C,KC_M) {
      SEND_STRING(".com");
    } else
    SEQ_THREE_KEYS(KC_S,KC_B,KC_G) {
      SEND_STRING("#!/usr/bin/env ");
    } else
    SEQ_THREE_KEYS(KC_H,KC_T,KC_P) {
      SEND_STRING("https://");
    } 
  }
}
//                                                                      MACRO
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case KC_VIM:
      if (record->event.pressed) {
        if (!vim_insert) {
          SEND_STRING(SS_TAP(X_I)); 
        } else {
          SEND_STRING(SS_TAP(X_ESC) SS_TAP(X_ESC) SS_TAP(X_RIGHT)); 
        }
        vim_insert = !vim_insert;
      }
      break;
    case KC_WRIT:
      if (record->event.pressed) {
          SEND_STRING(SS_TAP(X_ESC)":w");
          tap_code(KC_ENTER); 
      }
      break;

    case KC_TMPI:
      if (record->event.pressed) {
        if (!vim_insert) {
          vim_insert = true;
        }
        SEND_STRING(SS_TAP(X_I));  
      } else {
        if (vim_insert) {
          vim_insert = false;
        }
        SEND_STRING(SS_TAP(X_ESC) SS_TAP(X_ESC) SS_TAP(X_RIGHT));  
      }
      break;
    case KC_ESC:
      if (record->event.pressed) {
        if (vim_insert) {
          vim_insert = false;
        }
      }
      break;
    case KC_I:
      if (record->event.pressed) {
        if (!vim_insert) {
          vim_insert = true;
        }
      }
      break;
    case KC_O:
      if (record->event.pressed) {
        if (!vim_insert) {
          vim_insert = true;
        } 
      }
      break;
    case KC_TGSFT:
      if (record->event.pressed) {
        if (!sft_toggled) {
          register_code(KC_RSFT);
          sft_pressed = true;
          sft_toggled = true;
          sft_start_epochs = epoch;
          sft_start_ticks = tick;
          sft_tgl_on_timeout = false;
        } else {
          unregister_code(KC_RSFT);
          sft_toggled = false;
        }
      } else {
        sft_pressed = false;
        if ( sft_tgl_on_timeout ) {
          unregister_code(KC_RSFT);
          sft_toggled = false;
        }
      }
      break;
   }
   return true;
}

//                                                            COMBOS 
uint16_t get_combo_term(uint16_t index, combo_t *combo) {
    switch (index) {
        case FN_LEAD:
          return 2000;
        case NUM_0:
        case NUM_1:
        case NUM_2:
        case NUM_4:
        case NUM_8:
        case NUM_3:
        case NUM_5:
        case NUM_6:
        case NUM_7:
        case NUM_9:
        case SYMB_MINS:
        case SYMB_EQUAL:
        case SYMB_UNDRS:
        case SYMB_PIPE:
            return 3000;
        case FN_BSPCE:
        case FN_DEL:
        case FN_ENTER_L:
        case FN_ENTER_R:
        case FN_TAB:
        case FN_SFT_TAB:
        case FN_ESC_R:
        case FN_ESC_L:
        case FN_VOLUP:
        case FN_VOLDN:
        case FN_ZMIN:
        case FN_ZMOT:
            return 6000; 
    }

    return 800;
}

