/* Copyright 2021 chpark
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
#include QMK_KEYBOARD_H
#include "print.h"
// Defines names for use in layer keycodes and the keymap

#define XXX KC_NO


enum layer_names {
    MACOS,  // default layer
    LOST_ARK,
    WINDOWS,  // for windows os
    MAC_FUNC,
    MAC_MAGNET,
    SYMB  // symbols
};

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
    QMKBEST = SAFE_RANGE,
    QMKURL,
//    MOD_MAC_FUNC = MO(MAC_FUNC),
    MOD_FUNC = SAFE_RANGE,
};

enum tab_dances {
    MAGNET_CENTER,
    DOUBLE_TAP_A,
    DOUBLE_TAP_E,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
     *
     * ,--------------------------------------------------.           ,--------------------------------------------------.
     * |   =    |   1  |  4 2  |   3  |   4  |   5  | LEFT |           | RIGHT|   6  |   7  |   8  |   9  |   0  |   -    |
     * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
     * | Del    |   Q  |   W  |   E  |   R  |   T  |  L1  |           |  L1  |   Y  |   U  |   I  |   O  |   P  |   \    |
     * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
     * | BkSp   |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |; / L2|' / Cmd |
     * |--------+------+------+------+------+------| Hyper|           | Meh  |------+------+------+------+------+--------|
     * | LShift |Z/Ctrl|   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |//Ctrl| RShift |
     * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
     *   |Grv/L1|  '"  |AltShf| Left | Right|                                       |  Up  | Down |   [  |   ]  | ~L1  |
     *   `----------------------------------'                                       `----------------------------------'
     *                                        ,-------------.       ,-------------.
     *                                        | App  | LGui |       | Alt  |Ctrl/Esc|
     *                                 ,------|------|------|       |------+--------+------.
     *                                 |      |      | Home |       | PgUp |        |      |
     *                                 | Space|Backsp|------|       |------|  Tab   |Enter |
     *                                 |      |ace   | End  |       | PgDn |        |      |
     *                                 `--------------------'       `----------------------'
     */
    [MACOS] = LAYOUT(
      // left hand
      KC_ESC,             KC_1,     KC_2,     KC_3,     KC_4,    KC_5,  KC_TRNS,            TG(LOST_ARK),     KC_6,    KC_7,    KC_8,    KC_9,    KC_0,     KC_MINS,
      KC_TAB,             KC_Q,     KC_W,     KC_E,     KC_R,    KC_T,  KC_DEL,             KC_QUOTE,         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,     KC_EQL,
      KC_CAPS,            KC_A,     KC_S,     KC_D,     KC_F,    KC_G,  KC_GRV,             KC_DOUBLE_QUOTE,  KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,  MO(SYMB),
      KC_LSFT,            KC_Z,     KC_X,     KC_C,     KC_V,    KC_B,                                        KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,  KC_RSFT,
      KC_LCTL,            KC_SLEP,  KC_TRNS,  KC_LALT,  MO(SYMB),                                             KC_LEFT, KC_UP,   KC_DOWN, KC_RGHT, KC_BSLS,
                                                                 KC_DEL,  KC_LGUI,            TG(SYMB),  KC_DOUBLE_QUOTE,
                                                                 KC_HOME,                     KC_PGUP,
                                                                 KC_BSPC, KC_LGUI, MO(SYMB),  KC_PGDN,   KC_ENT, KC_SPC
    ),
    [LOST_ARK] = LAYOUT(
          // left hand
          KC_ESC,             KC_1,     KC_2,     KC_3,     KC_4,    KC_5,    KC_TRNS,            TG(LOST_ARK),     KC_6,    KC_7,    KC_8,    KC_9,    KC_0,     KC_MINS,
          KC_TAB,             KC_Q,     KC_W,     KC_E,     KC_R,    KC_T,    KC_DEL,             KC_QUOTE,         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,     KC_EQL,
          LT(SYMB, KC_LNG1),  KC_A,     KC_S,     KC_D,    KC_F,    KC_G,     KC_GRV,             KC_DOUBLE_QUOTE,  KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,  MO(SYMB),
          KC_LSFT,            KC_Z,     KC_X,     KC_C,     KC_V,    KC_B,                                          KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,  KC_RSFT,
          KC_LCTL,            KC_QUOT,  KC_TRNS,  KC_LALT,  MOD_FUNC,                                                KC_LEFT, KC_UP,   KC_DOWN, KC_RGHT, KC_BSLS,
                                                                     KC_DEL,  KC_LGUI,            TG(SYMB), KC_DOUBLE_QUOTE,
                                                                     KC_HOME,                     KC_PGUP,
                                                                     KC_BSPC, KC_SPC, MO(SYMB),   KC_PGDN, KC_ENT, KC_SPC
    ),

    /* Keymap 2: window layer
     *
     * ,--------------------------------------------------.           ,--------------------------------------------------.
     * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
     * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
     * |        |      |      | MsUp |      |      |      |           |      |      |      |      |      |      |        |
     * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
     * |        |      |MsLeft|MsDown|MsRght|      |------|           |------|      |      |      |      |      |  Play  |
     * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
     * |        |      |      |      |      |      |      |           |      |      |      | Prev | Next |      |        |
     * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
     *   |      |      |      | Lclk | Rclk |                                       |VolUp |VolDn | Mute |      |      |
     *   `----------------------------------'                                       `----------------------------------'
     *                                        ,-------------.       ,-------------.
     *                                        |      |      |       |      |      |
     *                                 ,------|------|------|       |------+------+------.
     *                                 |      |      |      |       |      |      |Brwser|
     *                                 |      |      |------|       |------|      |Back  |
     *                                 |      |      |      |       |      |      |      |
     *                                 `--------------------'       `--------------------'
     */
    [MAC_FUNC] = LAYOUT(
          // left hand
         KC_ESC,   KC_TRNS,     KC_TRNS,     KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,            QK_BOOT,  KC_TRNS,     KC_TRNS,    KC_TRNS,    KC_TRNS,     KC_TRNS,  KC_TRNS,
         KC_TRNS,  KC_TRNS,     KC_TRNS,     KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,            QK_RBT,   KC_TRNS,     KC_TRNS,    C(KC_UP),   KC_TRNS,     KC_TRNS,  KC_TRNS,
         KC_TRNS,  KC_TRNS,     KC_TRNS,     KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,            KC_TRNS,  KC_TRNS,     C(KC_LEFT), C(KC_DOWN), C(KC_RIGHT), KC_TRNS,  KC_TRNS,
         KC_TRNS,  KC_TRNS,     KC_TRNS,     KC_TRNS,    KC_TRNS,    KC_TRNS,                                  KC_TRNS,     KC_TRNS,    KC_TRNS,    KC_TRNS,     KC_TRNS,  KC_TRNS,
         KC_TRNS,  KC_TRNS,     KC_TRNS,     KC_TRNS,    KC_TRNS,                                                           KC_TRNS,    KC_TRNS,    KC_TRNS,     KC_TRNS,  KC_TRNS,

                                                                     KC_TRNS, KC_TRNS,            KC_TRNS, KC_TRNS,
                                                                              KC_TRNS,            KC_TRNS,
                                                             KC_BSPC, KC_SPC, KC_TRNS,            KC_TRNS, KC_ENT, LCA(KC_BSPC)
    ),
    [MAC_MAGNET] = LAYOUT(
          // left hand
         KC_ESC,   KC_TRNS,     KC_TRNS,     KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,            QK_BOOT,  LCA(KC_D),   LCA(KC_E),    LCA(KC_F),    LCA(KC_T),   LCA(KC_G), KC_TRNS,
         KC_TRNS,  KC_TRNS,     KC_TRNS,     KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,            QK_RBT,   KC_TRNS,     LCA(KC_U),    LCA(KC_UP),   LCA(KC_I),   KC_TRNS,   KC_TRNS,
         KC_TRNS,  KC_TRNS,     KC_TRNS,     KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,            KC_TRNS,  KC_TRNS,     LCA(KC_LEFT), TD(MAGNET_CENTER),  LCA(KC_RIGHT),   KC_TRNS,   KC_TRNS,
         KC_TRNS,  KC_TRNS,     KC_TRNS,     KC_TRNS,    KC_TRNS,    KC_TRNS,                                  KC_TRNS,     LCA(KC_J),    LCA(KC_DOWN), LCA(KC_K),   KC_TRNS,   KC_TRNS,
         KC_TRNS,  KC_TRNS,     KC_TRNS,     KC_TRNS,    KC_TRNS,                                                           KC_TRNS,      KC_TRNS,      KC_TRNS,     KC_TRNS,   KC_TRNS,

                                                                     KC_TRNS, KC_TRNS,            KC_TRNS, KC_TRNS,
                                                                              KC_TRNS,            KC_TRNS,
                                                             KC_BSPC, KC_SPC, KC_TRNS,            KC_TRNS, KC_ENT, KC_TRNS
    ),
    [SYMB] = LAYOUT(
          // left hand
          KC_NO,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_TRNS,      KC_TRNS, KC_F6,   KC_F7,      KC_F8,    KC_F9,      KC_F10,       KC_F11,
          KC_TRNS, KC_EXLM, KC_AT,   KC_LCBR, KC_RCBR, KC_PIPE, KC_TRNS,      KC_TRNS, KC_MINS, KC_EQL,     KC_UP,    KC_BSLS,    KC_ASTR,      KC_F12,
          KC_TRNS, KC_HASH, KC_DLR,  KC_LPRN, KC_RPRN, KC_GRV,  KC_TRNS,      KC_DOWN, KC_TRNS, KC_LEFT,    KC_DOWN,  KC_RGHT,    KC_SLSH,      KC_PGUP,
          KC_TRNS, KC_PERC, KC_CIRC, KC_LBRC, KC_RBRC, KC_TILD,                        KC_AMPR, C(KC_A),    KC_PGUP,  C(KC_E),    KC_BSLS,      KC_PGDN,
          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                          C(KC_LEFT), C(KC_UP), C(KC_DOWN), C(KC_RIGHT),  KC_TRNS,
                                                       RGB_MOD, KC_TRNS,      TG(SYMB), RGB_M_P,
                                                                KC_TRNS,      KC_TRNS,
                                              RGB_VAD, RGB_VAI, KC_TRNS,      KC_TRNS, RGB_HUD, RGB_HUI
    ),
};
void dance_crtl_a_finished (tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    uprintf("KC_A single tap!\n");
    register_code (KC_A);
  } else {
    uprintf("KC_A double tap!\n");
    register_code (KC_LCTL);
    register_code (KC_A);
  }
}

void dance_crtl_a_reset (tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    unregister_code (KC_A);
  } else {
    unregister_code (KC_LCTL);
    unregister_code (KC_A);
  }
}

void dance_crtl_e_finished (tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    register_code (KC_E);
  } else {
    register_code (KC_LCTL);
    register_code (KC_E);
  }
}

void dance_crtl_e_reset (tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    unregister_code (KC_E);
  } else {
    unregister_code (KC_LCTL);
    unregister_code (KC_E);
  }
}

// tab dance
tap_dance_action_t tap_dance_actions[] = {
 [MAGNET_CENTER] = ACTION_TAP_DANCE_DOUBLE (LCA(KC_ENT), LCA(KC_BSPC)),
// [DOUBLE_TAP_A] = ACTION_TAP_DANCE_FN_ADVANCED (NULL, dance_crtl_a_finished, dance_crtl_a_reset),
};

bool is_activate_mod_pressed = false;
bool is_tap_pressed = false;
bool is_mod_pair_key_pressed = false;
bool is_mac_magnet_layer_activated = false;
void keyboard_post_init_user(void) {
  // Customise these values to desired behaviour
  debug_enable=true;
//  debug_matrix=true;
  debug_keyboard=true;
//  debug_mouse=true;
}
void check_mod_layer_activated(void) {
//    uprintf("%d, %d, %d \n", is_activate_mod_pressed, is_tap_pressed, is_mac_magnet_layer_activated);
//    uprintf("%d \n", (is_activate_mod_pressed && is_tap_pressed) && !is_mac_magnet_layer_activated);
//    uprintf("check_mod_layer_activated!\n");
    if (is_activate_mod_pressed && is_tap_pressed && !is_mac_magnet_layer_activated) {
        uprintf("turn on magnet layer!\n");
        layer_on(MAC_MAGNET);
        is_mac_magnet_layer_activated = true;
        return;
    } else if ((!is_activate_mod_pressed || !is_tap_pressed) && is_mac_magnet_layer_activated) {
        uprintf("turn off magnet layer!\n");
        layer_off(MAC_MAGNET);
        is_mac_magnet_layer_activated = false;
    }
}

void update_pair_key_state_true(void) {
    is_mod_pair_key_pressed = true;
}
void update_pair_key_state_false(void) {
    is_mod_pair_key_pressed = false;
}
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  bool return_val = true;
  switch (keycode) {
        case KC_TAB:
            if (record->event.pressed) {
                uprintf("KC_TAB pressed!\n");
                update_pair_key_state_true();
                is_tap_pressed = true;
            } else {
                uprintf("KC_TAB released!\n");
                update_pair_key_state_false();
                is_tap_pressed = false;
            }
            if (is_activate_mod_pressed) {
                uprintf("mod pressed when KC_TAB pressed!\n");
                return_val = false;
            }
            break;
        case MOD_FUNC:
            if (record->event.pressed) {
                uprintf("mod pressed!\n");
                is_activate_mod_pressed = true;
                layer_on(MAC_FUNC);
            } else {
                uprintf("mod released!\n");
                is_activate_mod_pressed = false;
                layer_off(MAC_FUNC);
            }
            break;
  }
  check_mod_layer_activated();
//#ifdef CONSOLE_ENABLE
//    uprintf("KL: kc: 0x%04X, col: %2u, row: %2u, pressed: %u, time: %5u, int: %u, count: %u\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed, record->event.time, record->tap.interrupted, record->tap.count);
//#endif
  return return_val;
}
