/*
Copyright 2012,2013 Jun Wako <wakojun@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#include <stdint.h>
#include <stdbool.h>
#include <avr/pgmspace.h>
#include "keycode.h"
#include "action.h"
#include "action_macro.h"
#include "report.h"
#include "host.h"
#include "print.h"
#include "debug.h"
#include "keymap.h"

#define KEYMAP( \
    K00, K01, K02, K03, \
    K10, K11, K12, K13, \
    K20, K21, K22, K23, \
    K30, K31, K32, K33, \
    K40, K41, K42, K43, \
    K50, K51, K52, K53  \
) { \
    { KC_##K00, KC_##K01, KC_##K02, KC_##K03 }, \
    { KC_##K10, KC_##K11, KC_##K12, KC_##K13 }, \
    { KC_##K20, KC_##K21, KC_##K22, KC_##K23 }, \
    { KC_##K30, KC_##K31, KC_##K32, KC_##K33 }, \
    { KC_##K40, KC_##K41, KC_##K42, KC_##K43 }, \
    { KC_##K50, KC_##K51, KC_##K52, KC_##K53 }, \
}

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
       NLCK, PSLS, PAST, PMNS,
       P7,   P8,   P9,   NO,
       P4,   P5,   P6,   PPLS,
       P1,   P2,   P3,   NO,
       P0,   NO,   PDOT, PENT )
};/*
 * Fn action definition
 */
static const uint16_t PROGMEM fn_actions[] = {
};



#define KEYMAPS_SIZE    (sizeof(keymaps) / sizeof(keymaps[0]))
#define FN_ACTIONS_SIZE (sizeof(fn_actions) / sizeof(fn_actions[0]))

/* translates key to keycode */
uint8_t keymap_key_to_keycode(uint8_t layer, keypos_t key)
{
    if (layer < KEYMAPS_SIZE) {
        return pgm_read_byte(&keymaps[(layer)][(key.row)][(key.col)]);
    } else {
        // fall back to layer 0
        return pgm_read_byte(&keymaps[0][(key.row)][(key.col)]);
    }
}

/* translates Fn keycode to action */
action_t keymap_fn_to_action(uint8_t keycode)
{
    action_t action;
    if (FN_INDEX(keycode) < FN_ACTIONS_SIZE) {
        action.code = pgm_read_word(&fn_actions[FN_INDEX(keycode)]);
    } else {
        action.code = ACTION_NO;
    }
    return action;
}
