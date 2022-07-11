#import "combos_conf.h"

uint16_t get_combo_term(uint16_t index, combo_t *combo) { 
   switch (index) {
      case FN_LEAD_R:
      case FN_LEAD_L:
         return 1500;
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
      case FN_ENTER:
      case FN_VOLUP:
      case FN_VOLDN:
      case FN_ZMIN:
      case FN_ZMOT:
         return 6000; 
      }
     return 800;
}

