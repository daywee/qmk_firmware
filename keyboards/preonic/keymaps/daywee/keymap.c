/* Copyright 2015-2017 Jack Humbert
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "preonic.h"
#include "action_layer.h"

enum preonic_layers {
  _QWERTY,
  _NUMPAD,
  _LOWER,
  _RAISE,
  _ADJUST
};

enum preonic_keycodes {
  QWERTY = SAFE_RANGE,
  COLEMAK,
  DVORAK,
  LOWER,
  RAISE,
  BACKLIT
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
* ,-----------------------------------------------------------------------------------.
* |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
* |------+------+------+------+------+------+------+------+------+------+------+------|
* | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  |   \  |
* |------+------+------+------+------+-------------+------+------+------+------+------|
* | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
* |------+------+------+------+------+------|------+------+------+------+------+------|
* | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  | Shift|
* |------+------+------+------+------+------+------+------+------+------+------+------|
* | Ctrl | GUI  |  Alt |      |Lower |Lower |Space |Raise |      |      |      |      |
* `-----------------------------------------------------------------------------------'
*/
[_QWERTY] = {
  {KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC},
  {KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLASH},
  {KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT},
  {KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT},
  {KC_LCTL, KC_LGUI, KC_LALT, _______, LOWER  , KC_ENT,  KC_SPC,  RAISE,   KC_CAPS, _______, _______, _______}
},

/* Numpad
* ,-----------------------------------------------------------------------------------.
* |      |   x  |   x  |   x  |   x  |   x  |   x  |   x  |   /  |   *  |   -  |      |
* |------+------+------+------+------+------+------+------+------+------+------+------|
* |      |   x  | Home |  Up  |  End | PgUp |   x  |   7  |   8  |   9  |   +  |      |
* |------+------+------+------+------+-------------+------+------+------+------+------|
* |      |   x  | Left | Down | Right| PgDn |   x  |   4  |   5  |   6  |   +  |   x  |
* |------+------+------+------+------+------|------+------+------+------+------+------|
* |      |   /  |   *  |   -  |   +  | Enter|   x  |   1  |   2  |   3  | Enter| Enter|
* |------+------+------+------+------+------+------+------+------+------+------+------|
* |      |      |      |      |   x  |             |   0  |   0  |   .  | Enter|   =  |
* `-----------------------------------------------------------------------------------'
*/
[_NUMPAD] = {
  {_______, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_PSLS, KC_PAST, KC_PMNS, _______},
  {_______, KC_NO,   KC_HOME, KC_UP,   KC_END,  KC_PGUP, KC_NO,   KC_P7, KC_P8,   KC_P9,   KC_PPLS, _______},
  {_______, KC_NO,   KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, KC_NO,   KC_P4, KC_P5,   KC_P6,   KC_PPLS, KC_NO},
  {_______, KC_PSLS, KC_PAST, KC_PMNS, KC_PPLS, KC_PENT, KC_NO,   KC_P1, KC_P2,   KC_P3,   KC_PENT, KC_PENT},
  {_______, _______, _______, _______, KC_NO,   _______, _______, KC_P0, KC_P0,   KC_PDOT, KC_PENT, KC_PEQL}
},

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |      | Home |  Up  | End  |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |      | Left | Down |Right |  [   |  ]   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = {
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, KC_DEL},
  {_______, _______, _______, _______, _______, _______, _______, KC_HOME, KC_UP,   KC_END,   KC_MINS, KC_EQL},
  {_______, _______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_RIGHT, KC_LBRC, KC_RBRC},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______}
},

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      | Vol+ |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |      | Prev | Vol- | Next |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = {
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, KC_VOLU, _______, _______, _______},
  {_______, _______, _______, _______, _______, _______, _______, KC_MPRV, KC_VOLD, KC_MNXT, KC_MPLY, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, }
},

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | Reset|      |      |      |      |      |      |      |      |      |  Del |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |Aud on|AudOff|AGnorm|AGswap|Qwerty|Colemk|Dvorak|      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |Voice-|Voice+|Mus on|MusOff|MidiOn|MidOff|      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = {
  {KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12},
  {_______, RESET,   DEBUG,   _______, _______, _______, _______, TERM_ON, TERM_OFF,_______, _______, KC_DEL},
  {_______, _______, MU_MOD,  AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, QWERTY,  COLEMAK, DVORAK,  _______, _______},
  {_______, MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  _______, _______, _______, _______, _______},
  {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______}
}


};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
        case QWERTY:
          if (record->event.pressed) {
            set_single_persistent_default_layer(_QWERTY);
          }
          return false;
        case LOWER:
          if (record->event.pressed) {
            layer_on(_LOWER);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          } else {
            layer_off(_LOWER);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          }
          return false;
        case RAISE:
          if (record->event.pressed) {
            layer_on(_RAISE);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          } else {
            layer_off(_RAISE);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          }
          return false;
      }
    return true;
};
