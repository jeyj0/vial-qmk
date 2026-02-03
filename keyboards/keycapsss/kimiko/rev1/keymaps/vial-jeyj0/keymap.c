/* Copyright 2019 Leo Batyuk
 * Copyright 2020 Drashna Jaelre <@drashna>
 * Copyright 2020 @ben_roe (keycapsss.com)
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

enum layers {
    // _QWERTY,
    _HANDS_ON,
    _LAYER_1,
    _LAYER_2,
    _LAYER_3,
    _LAYER_4,
    _LAYER_5,
    // _LAYER_7,
};

enum custom_keycodes {
    COM_QUS = QK_KB_0,
    DOT_EXC,
    SLS_BSL,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    bool isShifted = false;
    if (record->event.pressed) {
        isShifted = get_mods() & MOD_MASK_SHIFT;
    }
    switch (keycode) {
        case COM_QUS: {
            static uint8_t kc;
            if (record->event.pressed) {
                if (isShifted) {
                    kc = KC_SLASH;
                } else {
                    kc = KC_COMM;
                }

                register_code(kc);
            } else {
                unregister_code(kc);
            }
            break;
        }
        case DOT_EXC: {
            static uint8_t kc;
            if (record->event.pressed) {
                if (isShifted) {
                    kc = KC_1;
                } else {
                    kc = KC_DOT;
                }

                register_code(kc);
            } else {
                unregister_code(kc);
            }
            break;
        }
        case SLS_BSL: {
            static uint8_t kc;
            if (record->event.pressed) {
                if (isShifted) {
                    del_mods(MOD_MASK_SHIFT);
                    kc = KC_BACKSLASH;
                } else {
                    kc = KC_SLASH;
                }

                register_code(kc);

                if (isShifted) {
                    register_code(KC_LSFT);
                }
            } else {
                unregister_code(kc);
            }
            break;
        }
    }
    return true;
}

#define LT2_E    LT(_LAYER_2, KC_E)
#define LT2_SPC  LT(_LAYER_2, KC_SPACE)
#define LT5__    LT(_LAYER_5, _______)
#define LT4_BSPC LT(_LAYER_4, KC_BACKSPACE)
#define LT4_ENTR LT(_LAYER_4, KC_ENTER)
#define LCTL_N   LCTL_T(KC_N)
#define _LSFT_T   LSFT_T(KC_T)
#define RSFT_A   RSFT_T(KC_A)
#define RCTL_O   RCTL_T(KC_O)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_HANDS_ON] = LAYOUT(
    KC_Q,    KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX,                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    KC_TAB,  KC_W,    KC_G,    KC_M,    KC_P,    KC_ESC,                      KC_QUOT, KC_U,    KC_K,    KC_J,    KC_SCLN, XXXXXXX,
    KC_Z,    KC_R,    KC_S,    LCTL_N,  _LSFT_T, KC_B,                        KC_Y,    RSFT_A,  RCTL_O,  KC_I,    KC_H,    KC_Q,
    KC_LCTL, KC_X,    KC_C,    KC_L,    KC_D,    KC_V,     KC_MUTE, KC_MUTE,  KC_MINS, KC_F,    COM_QUS, DOT_EXC, SLS_BSL, KC_RCTL,
                      KC_CAPS, KC_LALT, KC_LGUI, KC_E,     LT4_BSPC,LT4_ENTR, LT2_SPC, KC_RALT, KC_RGUI, KC_CAPS
),

[_LAYER_1] = LAYOUT(
    _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

[_LAYER_2] = LAYOUT(
    _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
    _______, _______, _______, KC_LBRC, KC_RBRC, _______,                   _______, KC_7,    KC_8,    KC_9,    _______, _______,
    _______, _______, _______, KC_LPRN, KC_RPRN, _______,                   _______, KC_4,    KC_5,    KC_6,    _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_1,    KC_2,    KC_3,    _______, _______,
                      _______, _______, _______, _______, _______, _______, KC_0,    _______, _______, _______
),

[_LAYER_3] = LAYOUT(
    _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),
  
[_LAYER_4] = LAYOUT(
    LT5__,   _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, LT5__,
    _______, _______, _______, KC_UP,   _______, _______,                   _______, _______, KC_UP,   _______, _______, _______,
    _______, KC_HOME, KC_LEFT, KC_DOWN, KC_RGHT, KC_END,                    KC_HOME, KC_LEFT, KC_DOWN, KC_RGHT, KC_END,  _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

[_LAYER_5] = LAYOUT(
    _______, _______, _______, _______, _______, QK_BOOT,                   QK_BOOT, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

// [_LAYER_7] = LAYOUT(
//     _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
//     _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
//     _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
//     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
//                       _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
// )
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [_HANDS_ON] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [_LAYER_1] =  { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [_LAYER_2] =  { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [_LAYER_3] =  { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [_LAYER_4] =  { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [_LAYER_5] =  { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    // [_LAYER_7] =  { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
};
#endif // ENCODER_MAP_ENABLE
