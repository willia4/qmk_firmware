#include QMK_KEYBOARD_H
#include "version.h"
#include "keymap_german.h"
#include "keymap_nordic.h"
#include "keymap_french.h"
#include "keymap_spanish.h"
#include "keymap_hungarian.h"
#include "keymap_swedish.h"
#include "keymap_br_abnt2.h"
#include "keymap_canadian_multilingual.h"
#include "keymap_german_ch.h"
#include "keymap_jp.h"
#include "keymap_bepo.h"

#define KC_MAC_UNDO LGUI(KC_Z)
#define KC_MAC_CUT LGUI(KC_X)
#define KC_MAC_COPY LGUI(KC_C)
#define KC_MAC_PASTE LGUI(KC_V)
#define KC_PC_UNDO LCTL(KC_Z)
#define KC_PC_CUT LCTL(KC_X)
#define KC_PC_COPY LCTL(KC_C)
#define KC_PC_PASTE LCTL(KC_V)
#define ES_LESS_MAC KC_GRAVE
#define ES_GRTR_MAC LSFT(KC_GRAVE)
#define ES_BSLS_MAC ALGR(KC_6)
#define NO_PIPE_ALT KC_GRAVE
#define NO_BSLS_ALT KC_EQUAL

enum custom_keycodes {
  RGB_SLD = EZ_SAFE_RANGE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Windows: Default */
  [0] = LAYOUT_ergodox_pretty(
    KC_ESCAPE,       KC_1,              KC_2,     KC_3,           KC_4,           KC_5,           LCTL(KC_F4),                                    LALT(KC_F4),    KC_6,           KC_7,           KC_8,           KC_9,                 KC_0,           KC_MINUS,
    KC_TAB,          LT(4,KC_Q),        KC_W,     KC_E,           KC_R,           KC_T,           TT(1),                                          TT(2),          KC_Y,           KC_U,           KC_I,           KC_O,                 LT(4,KC_P),     KC_BSLASH,
    MO(3),           LT(1,KC_A),        KC_S,     LT(6,KC_D),     LT(5, KC_F),    KC_G,                                                                           KC_H,           LT(5,KC_J),     LT(6,KC_K),     KC_L,                 LT(1,KC_SCOLON),LT(3,KC_QUOTE),
    KC_LSHIFT,       LT(2,KC_Z),        KC_X,     KC_C,           KC_V,           KC_B,           KC_EQUAL,                                       KC_EQUAL,       KC_N,           KC_M,           KC_COMMA,       KC_DOT,               LT(2,KC_SLASH),     KC_RSHIFT,
    LGUI_T(KC_GRAVE),LCTL_T(KC_QUOTE),  KC_LALT,  KC_LEFT,        KC_RIGHT,                                                                                                       KC_DOWN,        KC_UP,          RALT_T(KC_LBRACKET),  LT(2,KC_RBRACKET),    KC_RCTRL,
                                                                                                    KC_LGUI,        LCTL(KC_TAB),   KC_LALT,        LCTL_T(KC_ESCAPE),
                                                                                                                    KC_HOME,        KC_PGUP,
                                                                                    KC_LALT,        KC_SPACE,       KC_END,         KC_PGDOWN,      KC_BSPACE,      KC_ENTER
  ),
  /* Windows: Web Browser */
  [1] = LAYOUT_ergodox_pretty(
    KC_ESCAPE,      KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,          KC_ENTER,                                      KC_ENTER,         KC_F6,          KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_F11,
    KC_TAB,         LCTL(KC_0),     LCTL(KC_W),     KC_E,           LCTL(KC_R),     LCTL(KC_T),     KC_HOME,                                        KC_HOME,        LCTL(KC_T),     LCTL(KC_R),     KC_E,           LCTL(KC_W),     LCTL(KC_0),     KC_F12,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_LEFT,        KC_UP,          KC_DOWN,        KC_RIGHT,                                                                       KC_LEFT,        KC_DOWN,        KC_UP,          KC_RIGHT,       KC_TRANSPARENT, KC_TRANSPARENT,
    TO(0),          LCTL(KC_1),     KC_X,           KC_V,           LCTL(LSFT(KC_TAB)), LCTL(KC_TAB), KC_END,                                    KC_END,       LCTL(LSFT(KC_TAB)), LCTL(KC_TAB),   KC_V,        KC_X,           LCTL(KC_9),     TO(0),
    KC_TRANSPARENT, LCTL(KC_KP_MINUS),LCTL(KC_KP_PLUS),KC_PGUP,        KC_PGDOWN,                                                                                                    KC_PGDOWN,          KC_PGUP,        LCTL(KC_KP_MINUS),LCTL(KC_KP_PLUS),KC_RCTRL,
                                                                                                    KC_LGUI,        KC_TRANSPARENT, LCTL(KC_T),     KC_TRANSPARENT,
                                                                                                                    LCTL(LSFT(KC_T)),LCTL(LSFT(KC_T)),
                                                                                    KC_ENTER,       KC_LALT,        LCTL(KC_W),     LCTL(KC_W),     KC_WWW_BACK,    KC_WWW_HOME
  ),
  /* Windows: Mouse, Media, and numpad */
  [2] = LAYOUT_ergodox_pretty(
    KC_MEDIA_PLAY_PAUSE,    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                     MAGIC_TOGGLE_ALT_GUI, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,     KC_AUDIO_MUTE,  KC_AUDIO_VOL_UP,
    KC_MEDIA_NEXT_TRACK,    KC_TRANSPARENT, KC_MS_UP,       KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_MS_WH_UP,                        KC_TRANSPARENT,     KC_UP,          KC_KP_7,        KC_KP_8,        KC_KP_9,            KC_KP_MINUS,    KC_AUDIO_VOL_DOWN,
    KC_MEDIA_PREV_TRACK,    KC_MS_LEFT,     KC_MS_DOWN,     KC_MS_RIGHT,    KC_TRANSPARENT, KC_TRANSPARENT,                                                         KC_DOWN,        KC_KP_4,        KC_KP_5,        KC_KP_6,            KC_KP_PLUS,     KC_TRANSPARENT,
    KC_MS_BTN2,             KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_MS_WH_DOWN,                      KC_TRANSPARENT,     KC_KP_0,        KC_KP_1,        KC_KP_2,        KC_KP_3,            KC_TRANSPARENT, TO(0),
    KC_TRANSPARENT,         KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_MS_BTN3,                                                                                                         KC_KP_0,        KC_KP_0,        LALT_T(KC_KP_DOT),  KC_EQUAL,       KC_TRANSPARENT,
                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, LCTL(KC_T),     KC_TRANSPARENT,
                                                                                                                    KC_HOME,        LCTL(LSFT(KC_T)),
                                                                                    KC_MS_BTN1,     KC_TRANSPARENT, KC_END,         LCTL(KC_W),     KC_DELETE,      KC_KP_ENTER
  ),
  /* CTRL */
  [3] = LAYOUT_ergodox_pretty(
    LCTL(KC_ESCAPE),LCTL(KC_1),     LCTL(KC_2),     LCTL(KC_3),     LCTL(KC_4),     LCTL(KC_5),     KC_TRANSPARENT,                                 KC_TRANSPARENT, LCTL(KC_6),     LCTL(KC_7),     LCTL(KC_8),     LCTL(KC_9),     LCTL(KC_0),     LCTL(KC_MINUS),
    LCTL(KC_TAB),   LCTL(KC_Q),     LCTL(KC_W),     LCTL(KC_E),     LCTL(KC_R),     LCTL(KC_T),     KC_TRANSPARENT,                                 KC_TRANSPARENT, LCTL(KC_Y),     LCTL(KC_U),     LCTL(KC_I),     LCTL(KC_O),     LCTL(KC_P),     LCTL(KC_BSLASH),
    KC_TRANSPARENT, LCTL(KC_A),     LCTL(KC_S),     LCTL(KC_D),     LCTL(KC_F),     LCTL(KC_G),                                                                     LCTL(KC_H),     LCTL(KC_J),     LCTL(KC_K),     LCTL(KC_L),     LCTL(KC_SCOLON),KC_TRANSPARENT,
    LCTL(KC_LSHIFT),LCTL(KC_Z),     LCTL(KC_X),     LCTL(KC_C),     LCTL(KC_V),     LCTL(KC_B),     LCTL(KC_EQUAL),                                 LCTL(KC_KP_PLUS),LCTL(KC_N),     LCTL(KC_M),     LCTL(KC_COMMA), LCTL(KC_DOT),   LCTL(KC_SLASH), LCTL(KC_LSHIFT),
    LCTL(KC_GRAVE), LCTL(KC_QUOTE), LCTL(KC_LALT),  LCTL(KC_LEFT),  LCTL(KC_RIGHT),                                                                                                 LCTL(KC_DOWN),    LCTL(KC_UP),  LCTL(KC_LBRACKET),LCTL(KC_RBRACKET),KC_TRANSPARENT,
                                                                                                    LCTL(KC_LGUI),  LCTL(KC_TAB),   LCTL(KC_LALT),  LCTL(KC_ESCAPE),
                                                                                                                    LCTL(KC_ENTER), LCTL(KC_PGUP),
                                                                                    LCTL(KC_LALT),  LCTL(KC_SPACE), KC_ENTER,       LCTL(KC_PGDOWN),LCTL(KC_BSPACE),LCTL(KC_ENTER)
  ),
  /* Windows: Text Navigation */
  [4] = LAYOUT_ergodox_pretty(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,  KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT,       KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, LCTL(LSFT(KC_LEFT)), LSFT(KC_UP), LSFT(KC_DOWN),  LCTL(LSFT(KC_RIGHT)), LCTL(LSFT(KC_RIGHT)),                           LCTL(LSFT(KC_RIGHT)), LCTL(LSFT(KC_LEFT)), LSFT(KC_UP), LSFT(KC_DOWN), LCTL(LSFT(KC_RIGHT)), KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, LCTL(KC_LEFT),  KC_UP,          KC_DOWN,         LCTL(KC_RIGHT),                                                                       LCTL(KC_LEFT),  KC_DOWN,        KC_UP,          LCTL(KC_RIGHT), KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_HOME, KC_END, LCTL(LSFT(KC_LEFT)),                                            LCTL(LSFT(KC_LEFT)),  KC_HOME, KC_END, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                                        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                    KC_LSHIFT,      KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_LSHIFT
  ),
  /* Shift: [] {} <> */
  [5] = LAYOUT_ergodox_pretty(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,     KC_TRANSPARENT,         KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_LBRACKET,    KC_RBRACKET,    KC_TRANSPARENT,     KC_TRANSPARENT,         KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_LBRACKET,    KC_RBRACKET,    KC_TRANSPARENT,
    KC_DQUO,        KC_LCBR,        KC_RCBR,        KC_TRANSPARENT,     KC_TRANSPARENT,         KC_TRANSPARENT,                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_LCBR,        KC_RCBR,        KC_DQUO,
    KC_TRANSPARENT, KC_LABK,        KC_RABK,        KC_TRANSPARENT,     KC_TRANSPARENT,         KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_LABK,        KC_RABK,        KC_RBRACKET,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,     KC_TRANSPARENT,                                                                                                         KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
  /* Shift: [] () <> */
  [6] = LAYOUT_ergodox_pretty(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,     KC_TRANSPARENT,         KC_TRANSPARENT,     KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT,         KC_TRANSPARENT,         KC_TRANSPARENT,     KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_LBRACKET,    KC_RBRACKET,    KC_TRANSPARENT,     KC_TRANSPARENT,         KC_TRANSPARENT,     KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT,         KC_TRANSPARENT,         KC_TRANSPARENT,     KC_LBRACKET,    KC_RBRACKET,    KC_TRANSPARENT,
    KC_DQUO,        KC_LPRN,        KC_RPRN,        KC_TRANSPARENT,     LALT(LSFT(KC_DOWN)),    LALT(LSFT(KC_UP)),                                                                  LALT(LSFT(KC_UP)),    LALT(LSFT(KC_DOWN)),      KC_TRANSPARENT,     KC_LPRN,        KC_RPRN,        KC_DQUO,
    KC_TRANSPARENT, KC_LABK,        KC_RABK,        KC_TRANSPARENT,     KC_TRANSPARENT,         KC_TRANSPARENT,     KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT,         KC_TRANSPARENT,         KC_TRANSPARENT,     KC_LABK,        KC_RABK,        KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,     KC_TRANSPARENT,                                                                                                                 KC_TRANSPARENT,         KC_TRANSPARENT,     KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
  }
  return true;
}

uint32_t layer_state_set_user(uint32_t state) {
  uint8_t layer = biton32(state);
  ergodox_board_led_off();
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();
  switch (layer) {
    case 1:
      ergodox_right_led_1_on();
      break;
    case 2:
      ergodox_right_led_2_on();
      break;
    case 3:
      ergodox_right_led_3_on();
      break;
    case 4:
      ergodox_right_led_1_on();
      ergodox_right_led_2_on();
      break;
    case 5:
      ergodox_right_led_1_on();
      ergodox_right_led_3_on();
      break;
    case 6:
      ergodox_right_led_2_on();
      ergodox_right_led_3_on();
      break;
    case 7:
      ergodox_right_led_1_on();
      ergodox_right_led_2_on();
      ergodox_right_led_3_on();
      break;
    default:
      break;
  }
  return state;
};
