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
#define KC_SLACK_NEXT_UNREAD LALT(LSFT(KC_DOWN))
#define KC_SLACK_PREV_UNREAD LALT(LSFT(KC_UP))

enum custom_keycodes {
  RGB_SLD = EZ_SAFE_RANGE,

  TEXT_WORDL,
  TEXT_WORDR,
  TEXT_SHIFT_WORDL,
  TEXT_SHIFT_WORDR,
  TEXT_HOME,
  TEXT_END,
  TEXT_SHIFT_HOME,
  TEXT_SHIFT_END,

  WEB_ZOOM_RESET,
  WEB_ZOOM_IN,
  WEB_ZOOM_OUT,

  WEB_TAB_1,
  WEB_TAB_9,
  WEB_TAB_CLOSE,
  WEB_TAB_NEW,
  WEB_TAB_REOPEN,
  WEB_TAB_REFRESH,
  WEB_TAB_NEXT,
  WEB_TAB_PREV,

  DEBUG_PRINT_MODE
};

#define _WINDEF 0
#define _BROWSER 1
#define _NUMPAD 2
#define _CTRL 3
#define _WINTEXT 4
#define _SHIFTBR 5 /* Shift Brackets */
#define _SHIFTPR 6 /* Shift Parens */
#define _ARROWS 7

enum tap_dance {
    TD_LAYER_TAP,
    TD_ESC_GRAVE,
    TD_CTRL_ESC_GRAVE
};

void tap_dance_layer_tap (qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        layer_move(_BROWSER);
    }
    else if (state->count == 2) {
        layer_move(_NUMPAD);
    }
}

void tap_dance_esc_grave(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        tap_code16(KC_ESC);
    }
    else if (state->count == 2) {
        tap_code16(KC_GRAVE);
    }
    else if (state->count == 3) {
        tap_code16(KC_TILDE);
    }
}

void tap_dance_ctrl_esc_grave(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        tap_code16(QK_LCTL | KC_ESC);
    }
    else if (state->count == 2) {
        tap_code16(QK_LCTL | KC_GRAVE);
    }
    else if (state->count == 3) {
        tap_code16(QK_LCTL | KC_TILDE);
    }
}

qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_LAYER_TAP] = ACTION_TAP_DANCE_FN(tap_dance_layer_tap),
    [TD_ESC_GRAVE] = ACTION_TAP_DANCE_FN(tap_dance_esc_grave),
    [TD_CTRL_ESC_GRAVE] = ACTION_TAP_DANCE_FN(tap_dance_ctrl_esc_grave)
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Windows: Default */
  [_WINDEF] = LAYOUT_ergodox_pretty(
    TD(TD_ESC_GRAVE),   KC_1,               KC_2,     KC_3,                 KC_4,               KC_5,           LCTL(KC_F4),                            LALT(KC_F4),        KC_6,           KC_7,               KC_8,               KC_9,                 KC_0,                     KC_MINUS,
    KC_TAB,             LT(_WINTEXT,KC_Q),  KC_W,     KC_E,                 KC_R,               KC_T,           TD(TD_LAYER_TAP),                       TD(TD_LAYER_TAP),   KC_Y,           KC_U,               KC_I,               KC_O,                 LT(_WINTEXT,KC_P),        LT(_ARROWS, KC_BSLASH),
    MO(_CTRL),          LT(_BROWSER,KC_A),  KC_S,     LT(_SHIFTPR,KC_D),    LT(_SHIFTBR, KC_F), KC_G,                                                                       KC_H,           LT(_SHIFTBR,KC_J),  LT(_SHIFTPR,KC_K),  KC_L,                 LT(_BROWSER,KC_SCOLON),   LT(_CTRL,KC_QUOTE),
    KC_LSHIFT,          LT(_NUMPAD,KC_Z),   KC_X,     KC_C,                 KC_V,               KC_B,           KC_EQUAL,                               KC_EQUAL,           KC_N,            KC_M,               KC_COMMA,           KC_DOT,               LT(_NUMPAD,KC_SLASH),     KC_RSHIFT,
    LGUI_T(KC_GRAVE),   LCTL_T(KC_QUOTE),   KC_LALT,  KC_LEFT,              KC_RIGHT,                                                                                                       KC_DOWN,            KC_UP,              RALT_T(KC_LBRACKET),  LT(_NUMPAD,KC_RBRACKET),  KC_RCTRL,
                                                                                                    LCTL(KC_TAB),   KC_HOME,         KC_LALT,        LCTL_T(KC_ESCAPE),
                                                                                                                    KC_END,          KC_PGUP,
                                                                                    KC_LALT,        KC_SPACE,       KC_LGUI,         KC_PGDOWN,      KC_ENTER,      KC_BSPACE
  ),

  /* Web Browser */
  [_BROWSER] = LAYOUT_ergodox_pretty(
    TO(_WINDEF),    KC_F1,              KC_F2,              KC_F3,          KC_F4,              KC_F5,          KC_ENTER,                                  KC_ENTER,    KC_F6,              KC_F7,              KC_F8,          KC_F9,              KC_F10,             KC_F11,
    KC_TAB,         WEB_ZOOM_RESET,     WEB_TAB_CLOSE,      KC_E,           WEB_TAB_REFRESH,    WEB_TAB_NEW,    KC_HOME,                                   KC_HOME,     WEB_TAB_NEW,        WEB_TAB_REFRESH,    KC_E,           WEB_TAB_CLOSE,      WEB_ZOOM_RESET,     KC_F12,
    KC_TRANSPARENT, KC_TRANSPARENT,     KC_LEFT,            KC_UP,          KC_DOWN,            KC_RIGHT,                                                               KC_LEFT,            KC_DOWN,            KC_UP,          KC_RIGHT,           KC_TRANSPARENT,     KC_TRANSPARENT,
    KC_TRANSPARENT, WEB_TAB_1,          KC_X,               KC_V,           WEB_TAB_PREV,       WEB_TAB_NEXT,   KC_END,                                    KC_END,      WEB_TAB_PREV,       WEB_TAB_NEXT,       KC_V,           KC_X,               WEB_TAB_9,          TO(_WINDEF),
    KC_TRANSPARENT, WEB_ZOOM_OUT,       WEB_ZOOM_IN,        KC_PGUP,        KC_PGDOWN,                                                                                                      KC_PGDOWN,          KC_PGUP,        WEB_ZOOM_OUT,       WEB_ZOOM_IN,   KC_RCTRL,
                                                                                                    KC_LGUI,        KC_TRANSPARENT,     WEB_TAB_NEW,        KC_TRANSPARENT,
                                                                                                                    WEB_TAB_REOPEN,     WEB_TAB_REOPEN,
                                                                                    KC_ENTER,       KC_LALT,        WEB_TAB_CLOSE,      WEB_TAB_CLOSE,      KC_WWW_HOME,    KC_WWW_BACK
  ),
  /* Windows: Mouse, Media, and numpad */
  [_NUMPAD] = LAYOUT_ergodox_pretty(
    KC_MEDIA_PLAY_PAUSE,    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                     MAGIC_TOGGLE_ALT_GUI, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,     KC_AUDIO_MUTE,  KC_AUDIO_VOL_UP,
    KC_MEDIA_NEXT_TRACK,    KC_TRANSPARENT, KC_MS_UP,       KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_MS_WH_UP,                        KC_TRANSPARENT,       KC_UP,          KC_KP_7,        KC_KP_8,        KC_KP_9,            KC_KP_MINUS,    KC_AUDIO_VOL_DOWN,
    KC_MEDIA_PREV_TRACK,    KC_MS_LEFT,     KC_MS_DOWN,     KC_MS_RIGHT,    KC_TRANSPARENT, KC_TRANSPARENT,                                                           KC_DOWN,        KC_KP_4,        KC_KP_5,        KC_KP_6,            KC_KP_PLUS,     KC_TRANSPARENT,
    KC_MS_BTN2,             KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_MS_WH_DOWN,                      KC_TRANSPARENT,       KC_KP_0,        KC_KP_1,        KC_KP_2,        KC_KP_3,            KC_TRANSPARENT, TO(_WINDEF),
    DEBUG_PRINT_MODE,         KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_MS_BTN3,                                                                                                         KC_KP_0,        KC_KP_0,        LALT_T(KC_KP_DOT),  KC_EQUAL,       KC_TRANSPARENT,
                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_LGUI,
                                                                                                                    KC_HOME,        KC_TRANSPARENT,
                                                                                    KC_MS_BTN1,     KC_TRANSPARENT, KC_END,         KC_TRANSPARENT, KC_SPACE,      KC_DELETE
  ),
  /* CTRL */
  [_CTRL] = LAYOUT_ergodox_pretty(
    TD(TD_CTRL_ESC_GRAVE),LCTL(KC_1),     LCTL(KC_2),     LCTL(KC_3),     LCTL(KC_4),     LCTL(KC_5),     KC_TRANSPARENT,                                 KC_TRANSPARENT, LCTL(KC_6),     LCTL(KC_7),     LCTL(KC_8),     LCTL(KC_9),     LCTL(KC_0),     LCTL(KC_MINUS),
    LCTL(KC_TAB),   LCTL(KC_Q),     LCTL(KC_W),     LCTL(KC_E),     LCTL(KC_R),     LCTL(KC_T),     KC_TRANSPARENT,                                 KC_TRANSPARENT, LCTL(KC_Y),     LCTL(KC_U),     LCTL(KC_I),     LCTL(KC_O),     LCTL(KC_P),     LCTL(KC_BSLASH),
    KC_TRANSPARENT, LCTL(KC_A),     LCTL(KC_S),     LCTL(KC_D),     LCTL(KC_F),     LCTL(KC_G),                                                                     LCTL(KC_H),     LCTL(KC_J),     LCTL(KC_K),     LCTL(KC_L),     LCTL(KC_SCOLON),KC_TRANSPARENT,
    LCTL(KC_LSHIFT),LCTL(KC_Z),     LCTL(KC_X),     LCTL(KC_C),     LCTL(KC_V),     LCTL(KC_B),     LCTL(KC_EQUAL),                                 LCTL(KC_KP_PLUS),LCTL(KC_N),     LCTL(KC_M),     LCTL(KC_COMMA), LCTL(KC_DOT),   LCTL(KC_SLASH), LCTL(KC_LSHIFT),
    LCTL(KC_GRAVE), LCTL(KC_QUOTE), LCTL(KC_LALT),  LCTL(KC_LEFT),  LCTL(KC_RIGHT),                                                                                                 LCTL(KC_DOWN),    LCTL(KC_UP),  LCTL(KC_LBRACKET),LCTL(KC_RBRACKET),KC_TRANSPARENT,
                                                                                                    LCTL(KC_LGUI),  LCTL(KC_TAB),   LCTL(KC_LALT),  LCTL(KC_ESCAPE),
                                                                                                                    LCTL(KC_ENTER), LCTL(KC_PGUP),
                                                                                    LCTL(KC_LALT),  LCTL(KC_SPACE), KC_ENTER,       LCTL(KC_PGDOWN),LCTL(KC_ENTER),LCTL(KC_BSPACE)
  ),
  /* Windows: Text Navigation */
  [_WINTEXT] = LAYOUT_ergodox_pretty(
    KC_TRANSPARENT,     KC_TRANSPARENT, KC_TRANSPARENT,     KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,     KC_TRANSPARENT,                     KC_TRANSPARENT,     KC_TRANSPARENT,     KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,     KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT,     KC_TRANSPARENT, TEXT_SHIFT_WORDL,   LSFT(KC_UP),    LSFT(KC_DOWN),  TEXT_SHIFT_WORDR,   TEXT_SHIFT_WORDR,                   TEXT_SHIFT_WORDR,   TEXT_SHIFT_WORDL,   LSFT(KC_UP),    LSFT(KC_DOWN),  TEXT_SHIFT_WORDR,   KC_TRANSPARENT, KC_TRANSPARENT,
    TEXT_SHIFT_HOME,    KC_TRANSPARENT, TEXT_WORDL,         KC_UP,          KC_DOWN,        TEXT_WORDR,                                                                 TEXT_WORDL,         KC_DOWN,        KC_UP,          TEXT_WORDR,         KC_TRANSPARENT, TEXT_SHIFT_HOME,
    TEXT_SHIFT_END,     KC_TRANSPARENT, KC_TRANSPARENT,     KC_TRANSPARENT, TEXT_HOME,      TEXT_END,           TEXT_SHIFT_WORDL,                   TEXT_SHIFT_WORDL,   TEXT_HOME,          TEXT_END,       KC_TRANSPARENT, KC_TRANSPARENT,     KC_TRANSPARENT, TEXT_SHIFT_END,
    KC_TRANSPARENT,     KC_TRANSPARENT, KC_TRANSPARENT,     KC_TRANSPARENT, KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,     KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                    KC_LSHIFT,      KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_LSHIFT
  ),
  /* Shift: [] {} <> */
  [_SHIFTBR] = LAYOUT_ergodox_pretty(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,     KC_TRANSPARENT,         KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_LBRACKET,    KC_RBRACKET,    KC_TRANSPARENT,     KC_TRANSPARENT,         KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_LBRACKET,    KC_RBRACKET,    KC_TRANSPARENT,
    KC_DQUO,        KC_LCBR,        KC_RCBR,        KC_TRANSPARENT,     KC_TRANSPARENT,         KC_TRANSPARENT,                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_LCBR,        KC_RCBR,        KC_DQUO,
    KC_TRANSPARENT, KC_LABK,        KC_RABK,        KC_TRANSPARENT,     KC_TRANSPARENT,         KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_LABK,        KC_RABK,        KC_RBRACKET,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,     KC_TRANSPARENT,                                                                                                         KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
  /* Shift: [] () <> and slack navigation*/
  [_SHIFTPR] = LAYOUT_ergodox_pretty(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,     KC_TRANSPARENT,         KC_TRANSPARENT,     KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT,         KC_TRANSPARENT,         KC_TRANSPARENT,     KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_LBRACKET,    KC_RBRACKET,    KC_TRANSPARENT,     KC_TRANSPARENT,         KC_TRANSPARENT,     KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT,         KC_TRANSPARENT,         KC_TRANSPARENT,     KC_LBRACKET,    KC_RBRACKET,    KC_TRANSPARENT,
    KC_DQUO,        KC_LPRN,        KC_RPRN,        KC_TRANSPARENT,     KC_SLACK_NEXT_UNREAD,   KC_SLACK_PREV_UNREAD,                                                               KC_SLACK_PREV_UNREAD,   KC_SLACK_NEXT_UNREAD,   KC_TRANSPARENT,     KC_LPRN,        KC_RPRN,        KC_DQUO,
    KC_TRANSPARENT, KC_LABK,        KC_RABK,        KC_TRANSPARENT,     KC_TRANSPARENT,         KC_TRANSPARENT,     KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT,         KC_TRANSPARENT,         KC_TRANSPARENT,     KC_LABK,        KC_RABK,        KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,     KC_TRANSPARENT,                                                                                                                     KC_TRANSPARENT,         KC_TRANSPARENT,     KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [_ARROWS] = LAYOUT_ergodox_pretty(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,     KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_UP,          KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,     KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_UP,          KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_LEFT,        KC_DOWN,        KC_RIGHT,       KC_TRANSPARENT, KC_TRANSPARENT,                                                                     KC_TRANSPARENT, KC_LEFT,        KC_DOWN,        KC_RIGHT,       KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,     KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                                                     KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    bool isMac = keymap_config.swap_lalt_lgui == true;

    uint16_t webModifier = isMac ? QK_LGUI : QK_LCTL;
    uint16_t wordSelectionModifier = isMac ? QK_LALT : QK_LCTL;
    uint16_t home = isMac ? QK_LGUI | KC_LEFT : KC_HOME;
    uint16_t end = isMac ? QK_LGUI | KC_RIGHT : KC_END;

    if (record->event.pressed) {
        switch (keycode) {
            case TEXT_WORDL:
                tap_code16(wordSelectionModifier | KC_LEFT);
                return false;
            case TEXT_WORDR:
                tap_code16(wordSelectionModifier | KC_RIGHT);
                return false;
            case TEXT_SHIFT_WORDL:
                tap_code16(wordSelectionModifier | QK_LSFT | KC_LEFT);
                return false;
            case TEXT_SHIFT_WORDR:
                tap_code16(wordSelectionModifier | QK_LSFT | KC_RIGHT);
                return false;
            case TEXT_HOME:
                tap_code16(home);
                return false;
            case TEXT_END:
                tap_code16(end);
                return false;
            case TEXT_SHIFT_HOME:
                tap_code16(QK_LSFT | home);
                return false;
            case TEXT_SHIFT_END:
                tap_code16(QK_LSFT | end);
                return false;
            case WEB_ZOOM_RESET:
                tap_code16(webModifier | KC_0);
                return false;
            case WEB_ZOOM_IN:
                tap_code16(webModifier | KC_EQUAL);
                return false;
            case WEB_ZOOM_OUT:
                tap_code16(webModifier | KC_MINUS);
                return false;
            case WEB_TAB_1:
                tap_code16(webModifier | KC_1);
                return false;
            case WEB_TAB_9:
                tap_code16(webModifier | KC_9);
                return false;
            case WEB_TAB_CLOSE:
                tap_code16(webModifier | KC_W);
                return false;
            case WEB_TAB_NEW:
                tap_code16(webModifier | KC_T);
                return false;
            case WEB_TAB_REOPEN:
                tap_code16(webModifier | QK_LSFT | KC_T);
                return false;
            case WEB_TAB_REFRESH:
                tap_code16(webModifier | KC_R);
                return false;
            case WEB_TAB_NEXT:
                tap_code16(QK_LCTL | KC_TAB);
                return false;
            case WEB_TAB_PREV:
                tap_code16(QK_LCTL | QK_LSFT | KC_TAB);
                return false;

            default:
                break;
        }
    }
    else { /* key up */
        switch (keycode) {
            case DEBUG_PRINT_MODE:
                if (isMac) {
                    SEND_STRING("mac mode");
                }
                else {
                    SEND_STRING("windows mode");
                }
                return false;
            default:
                break;
        }
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
