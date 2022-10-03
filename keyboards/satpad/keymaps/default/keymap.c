#include QMK_KEYBOARD_H


enum satpad_layers {
    _QWERTY,
    LAYER_LENGTH
};

enum satpad_combos {
    COMBO_SPACE,
    COMBO_SHIFT,
    COMBO_BACKSP,
    COMBO_ENTER,
    COMBO_LENGTH
};

enum satpad_tapdances {
    TD_QESC, 
    TD_ATAB,
    TD_QENT,
    TAPDANCE_LENGTH
};

#define QESC TD(TD_QESC)
#define ATAB TD(TD_ATAB)
#define BALT LALT_T(KC_B)
#define VCTL LCTL_T(KC_V)
#define CGUI LGUI_T(KC_C)
#define OSM_SFT OSM(MOD_LSFT)


uint16_t COMBO_LEN = COMBO_LENGTH;
const uint16_t PROGMEM combo_space[]        = { KC_F, KC_J, COMBO_END };
const uint16_t PROGMEM combo_shift[]        = { KC_S, KC_D, COMBO_END };
const uint16_t PROGMEM combo_backspace[]    = { KC_J, KC_K, COMBO_END };
const uint16_t PROGMEM combo_enter[]        = { KC_K, KC_L, COMBO_END };



combo_t key_combos[] = { 
    [COMBO_SPACE]   = COMBO(combo_space, KC_SPC),
    [COMBO_SHIFT]   = COMBO(combo_shift, OSM_SFT), 
    [COMBO_BACKSP]  = COMBO(combo_backspace, KC_BSPC),
    [COMBO_ENTER]   = COMBO(combo_enter, KC_ENT),
};


qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_QESC]   = ACTION_TAP_DANCE_DOUBLE(KC_Q, KC_ESC),
    [TD_ATAB]   = ACTION_TAP_DANCE_DOUBLE(KC_A, KC_TAB)
};

const key_override_t **key_overrides = (const key_override_t *[]) {
    NULL
};

#define ______ KC_NO
/*
 *  ,---------------------------------------------------------------------------------------.
 *  |  L00  |  L01  |  L02  |  L03  |  L04  |       |  R00  |  R01  |  R02  |  R03  |  R04  |
 *  |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 *  |  L10  |  L11  |  L12  |  L13  |  L14  |       |  R10  |  R11  |  R12  |  R13  |  R14  |
 *  |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 *  |  L20  |  L21  |  L22  |  L23  |  L24  |  M20  |  R20  |  R21  |  R22  |  R23  |  R24  |
 *  `---------------------------------------------------------------------------------------'
 */
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT(
        QESC,   KC_W,   KC_E,   KC_R,   KC_T,   ______,     KC_Y,   KC_U,   KC_I,       KC_O,   KC_P,    \
        ATAB,   KC_S,   KC_D,   KC_F,   KC_G,   ______,     KC_H,   KC_J,   KC_K,       KC_L,   KC_QUOT,    \
        KC_Z,   KC_X,   CGUI,   VCTL,   BALT,   KC_SPC,     KC_N,   KC_M,   KC_COMM,    KC_DOT, KC_SLSH
    ),
};

const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [_QWERTY] = { ENCODER_CCW_CW(KC_DOWN, KC_UP) },
};

oled_rotation_t oled_init_user(oled_rotation_t rotation){   
    return OLED_ROTATION_270;
}

bool oled_task_user(void) {
    uint8_t modifiers = get_mods() | get_oneshot_mods();

    oled_set_cursor(0, 11); 
    oled_write_P(PSTR("SHIFT"), (modifiers & MOD_MASK_SHIFT) || is_caps_word_on());
    oled_write_P(PSTR("CNTRL"), (modifiers & MOD_MASK_CTRL));

    return true;
}

