// Author: Nathan Ross Powell <nathanrospowell@gmail.com>

#include "keymap_common.h"

const uint8_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
   /* 0: main layer
    * ,-----------------------.
    * | Esc | Tab |  =  | Bs  |
    * |-----------------------|
    * |-----------------------|
    * | Num |  /  |  *  |  -  |
    * |-----------------------|
    * |  7  |  8  |  9  |     |
    * |-----------------|  +  |
    * |  4  |  5  |  6  |     |
    * |-----------------------|
    * |  1  |  2  |  3  |     |
    * |-----------------| Ent |
    * |     0     |  .  |     |
    * `-----------------------'
    */
  [0] = KEYMAP(
       ESC,  TAB,  PEQL, BSPC,
       NLCK, PSLS, PAST, MINUS,
       P7,   P8,   P9,   NO,
       P4,   P5,   P6,   PSLS,
       P1,   P2,   P3,   NO,
       P0,   NO,   PDOT, PENT )
};

const uint16_t PROGMEM fn_actions[] = {};
