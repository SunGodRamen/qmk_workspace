#ifndef OVERRIDES_H
#define OVERRIDES_H

#include "quantum/process_keycode/process_key_override.h"

const key_override_t s_colon_override = ko_make_basic(MOD_MASK_SHIFT, KC_COLN, KC_SCLN);
const key_override_t s_comma_override = ko_make_basic(MOD_MASK_SHIFT, KC_COMM, KC_QUES);
const key_override_t s_dot_override = ko_make_basic(MOD_MASK_SHIFT, KC_DOT, KC_EXLM);
const key_override_t s_dquote_override = ko_make_basic(MOD_MASK_SHIFT, KC_DQUO, KC_QUOT);
const key_override_t s_minus_override = ko_make_basic(MOD_MASK_SHIFT, KC_MINS, KC_PLUS);
const key_override_t s_lt_override = ko_make_basic(MOD_MASK_SHIFT, KC_LT, KC_GT);
  
const key_override_t a_unds_override = ko_make_basic(MOD_MASK_ALT, KC_UNDS, KC_TILD);
const key_override_t a_s_override = ko_make_basic(MOD_MASK_ALT, KC_S, KC_DLR);
const key_override_t a_a_override = ko_make_basic(MOD_MASK_ALT, KC_A, KC_AT);
const key_override_t a_h_override = ko_make_basic(MOD_MASK_ALT, KC_H, KC_HASH);
const key_override_t a_v_override = ko_make_basic(MOD_MASK_ALT, KC_V, KC_CIRC);
const key_override_t a_dot_override = ko_make_basic(MOD_MASK_ALT, KC_DOT, KC_ASTR);
const key_override_t a_dquo_override = ko_make_basic(MOD_MASK_ALT, KC_DQUO, KC_QUOT);
const key_override_t a_slsh_override = ko_make_basic(MOD_MASK_ALT, KC_SLSH, KC_BSLS);

const key_override_t **key_overrides = (const key_override_t *[]){
     &s_colon_override,
     &s_comma_override,
     &s_dot_override,
     &s_dquote_override,
     &s_minus_override,
     &s_lt_override,
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
#endif
