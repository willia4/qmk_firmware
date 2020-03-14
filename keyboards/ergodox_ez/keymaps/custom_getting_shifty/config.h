/*
  Set any config.h overrides for your specific keymap here.
  See config.h options at https://docs.qmk.fm/#/config_options?id=the-configh-file
*/
#define ORYX_CONFIGURATOR
#undef DEBOUNCE
#define DEBOUNCE 30

#undef TAPPING_TERM
#define TAPPING_TERM 280

#define RETRO_TAPPING

#define PERMISSIVE_HOLD
#undef PERMISSIVE_HOLD

#undef BOOTMAGIC_KEY_SALT
#define BOOTMAGIC_KEY_SALT KC_SPACE
