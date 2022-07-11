#include "leader_dict.h"

void LEADER_DICTIONARY () {
   leading = false;
   leader_end();
   
   SEQ_ONE_KEY(KC_W) {
     register_code(KC_LCTRL);
     register_code(KC_RSFT);
     register_code(KC_TAB);
     unregister_code(KC_TAB);
     unregister_code(KC_RSFT);
     unregister_code(KC_LCTRL);
   } else
   SEQ_ONE_KEY(KC_T) {
     register_code(KC_LCTRL);
     register_code(KC_TAB);
     unregister_code(KC_TAB);
     unregister_code(KC_LCTRL);
   } else
   SEQ_ONE_KEY(KC_L) {
     SEND_STRING("ls -a");
     register_code(KC_ENTER);
     unregister_code(KC_ENTER);
   } else
   SEQ_TWO_KEYS(KC_C,KC_N) {
     SEND_STRING("cn166862");
   } else
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
     SEQ_THREE_KEYS(KC_S,KC_B,KC_G) {
       SEND_STRING("#!/usr/bin/env ");
   } else 
     SEQ_THREE_KEYS(KC_E,KC_M,KC_L) {
       SEND_STRING("avons394@gmail.com");
     }
   }
 }
