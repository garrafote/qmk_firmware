/* Copyright 2020 Shulin Huang <mumu@x-bows.com>
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

enum custom_keycodes
{
  KVM_1 = SAFE_RANGE,  // Select input source 1 in display mode 1
  KVM_2,               // Select input source 2 in display mode 1
  KVM_3,               // Keyboard and mouse focus on dosktop of input source 1 in display mode 2
  KVM_4,               // Keyboard and mouse focus on desktop of input source 2 in display mode 2
  KVM_BUZ,             // Toggle buzzer sound
  KVM_PAS,             // Toggle keyboard and mouse pass through mode
  KVM_CHK,             // Check keyboard and mouse pass through state
  KVM_SWP,             // Switch mouse and keyboard control between input sources
};

bool process_record_user(uint16_t keycode, keyrecord_t *record)
{
  switch (keycode)
  {
    case KVM_1:
    {
      if (record->event.pressed)
      {
        tap_code(KC_SLCK);
        tap_code(KC_SLCK);
        tap_code(KC_1);
      }
    } break;

    case KVM_2:
    {
      if (record->event.pressed)
      {
        tap_code(KC_SLCK);
        tap_code(KC_SLCK);
        tap_code(KC_2);
      }
    } break;

    case KVM_3:
    {
      if (record->event.pressed)
      {
        tap_code(KC_SLCK);
        tap_code(KC_SLCK);
        tap_code(KC_3);
      }
    } break;

    case KVM_4:
    {
      if (record->event.pressed)
      {
        tap_code(KC_SLCK);
        tap_code(KC_SLCK);
        tap_code(KC_4);
      }
    } break;

    case KVM_BUZ:
    {
      if (record->event.pressed)
      {
        tap_code(KC_SLCK);
        tap_code(KC_SLCK);
        tap_code(KC_F11);
      }
    } break;

    case KVM_PAS:
    {
      if (record->event.pressed)
      {
        tap_code(KC_SLCK);
        tap_code(KC_SLCK);
        tap_code(KC_F2);
      }
    } break;

    case KVM_CHK:
    {
      if (record->event.pressed)
      {
        tap_code(KC_SLCK);
        tap_code(KC_SLCK);
        tap_code(KC_F3);
      }
    } break;

    case KVM_SWP:
    {
      if (record->event.pressed)
      {
        tap_code(KC_RALT);
        tap_code(KC_RALT);
      }
    } break;

    default: break;
  }

  return true;
}


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Keymap DVORAK: (Base Layer) Default Layer
   *
   * |----------------------------------------------------------------------------------------------------------------------------|
   * | Esc |  F1  |  F2  |  F3  |  F4  |      F5  |  F6  |  F7  |  F8  |      F9  |  F10 |  F11 |  F12 |   Delete   |    Prtsc    |
   * |----------------------------------------------------------------------------------------------------------------------------|
   * |  ~  |     1   |   2   |   3   |   4   |    5      |       6    |    7    |    8   |   9  |   0  |  [{  | ]}  |  Backspace  |
   * |----------------------------------------------------------------------------------------------------------------------------|
   * | Tab |   "    |   ,<   |  .>  |   P  |   Y  |            |    F   |    G   |    C  |   R  |   L  |  /?  | =+  |  \|  | PgUp |
   * |----------------------------------------------------------------------------------------------------------------------------|
   * | Ctl |   A   |   O   |   E  |   U  |   I  |      Bksp      |    D  |    H   |   T  |   N  |   S  |  -_  |    Enter   | PgDn |
   * |----------------------------------------------------------------------------------------------------------------------------|
   * |Shift|  ;:  |   Q  |   J  |   K  |   X  |       Enter       |    B  |    M   |  W  |   V  |  /?  | Shift|      |  Up |      |
   * |----------------------------------------------------------------------------------------------------------------------------|
   * |Ctrl | GUI |     Alter   |    Space   |   Ctrl   |   Shift   |     Space     |    Alter   |  FN  | Ctrl | Lft  |  Dn |  Rig |
   * |----------------------------------------------------------------------------------------------------------------------------|
   */
  [0] = LAYOUT(
    KC_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_DEL,             KC_PSCR,
    KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,                         KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_LBRC,  KC_RBRC,  KC_BSPC,
    KC_TAB,   KC_QUOT,  KC_COMM,  KC_DOT,   KC_P,     KC_Y,                         KC_F,     KC_G,     KC_C,     KC_R,     KC_L,     KC_SLSH,  KC_EQL,   KC_BSLS,  KC_PGUP,
    KC_ESC,   KC_A,     KC_O,     KC_E,     KC_U,     KC_I,     KC_BSPC,            KC_D,     KC_H,     KC_T,     KC_N,     KC_S,     KC_MINS,  KC_ENT,             KC_PGDN,
    KC_LSFT,  KC_SCLN,  KC_Q,     KC_J,     KC_K,     KC_X,     KC_ENT,             KC_B,     KC_M,     KC_W,     KC_V,     KC_Z,     KC_RSFT,            KC_UP,
    KC_LCTL,  KC_LGUI,  KC_LALT,            KC_SPC,             KC_LCTL,  KC_LSFT,  KC_MEH,             MO(2),              MO(1),    KC_RCTL,  KC_LEFT,  KC_DOWN,  KC_RGHT),
  // FN Key - Multimedia & Utility layer
  [1] = LAYOUT(
    RESET,    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_CALC,  KC_MYCM,  KC_MSEL,  KC_MAIL,  NK_TOGG,            EEP_RST,
    KVM_SWP,  KVM_1,    KVM_2,    KVM_3,    KVM_4,    KVM_PAS,                      KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_NLCK,
    RGB_TOG,  RGB_MOD,  RGB_VAI,  RGB_HUI,  KVM_BUZ,  KVM_CHK,                      KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_HOME,
    KC_TRNS,  RGB_SPD,  RGB_VAD,  RGB_SPI,  KC_TRNS,  KC_TRNS,  KC_TRNS,            KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_END,
    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,            KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_MUTE,            KC_VOLU,
    KC_TRNS,  KC_TRNS,  KC_TRNS,            KC_TRNS,            KC_TRNS,  KC_TRNS,  KC_TRNS,            KC_TRNS,            KC_TRNS,  KC_MPLY,  KC_MPRV,  KC_VOLD,  KC_MNXT),
  // QUERTY - NUMPAD
  [2] = LAYOUT(
    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,            KC_TRNS,
    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,                      KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
    KC_TRNS,  KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,                         KC_Y,     KC_P7,    KC_P8,    KC_P9,    KC_PAST,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
    KC_TRNS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_TRNS,            KC_H,     KC_P4,    KC_P5,    KC_P6,    KC_PPLS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
    KC_TRNS,  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_TRNS,            KC_N,     KC_P1,    KC_P2,    KC_P3,    KC_PDOT,  KC_PEQL,            KC_TRNS,
    KC_TRNS,  KC_TRNS,  KC_TRNS,            KC_TRNS,            KC_TRNS,  KC_TRNS,  KC_P0,              KC_TRNS,            KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS)
};
