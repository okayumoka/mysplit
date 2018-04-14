// This is keymap.h for MySplit.

// JSON
// null

// Pro micro
#include "keycode.h"
const int keyMapLower[ROW_NUM][COL_NUM_2] = {
	{ KC_TILD, KC_EXLM, KC_AT  , KC_HASH, KC_DLR , KC_PERC, KC_NULL, KC_NULL, KC_CRET, KC_AMP , KC_ASTR, KC_LPRN, KC_RPRN, KC_NULL },
	{ KC_NULL, KC_NULL, KC_NULL, KC_DEL , KC_END , KC_PGDN, KC_NULL, KC_NULL, KC_USCR, KC_PLUS, KC_LCB , KC_RCB , KC_VBAR, KC_NULL },
	{ KC_NULL, KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  , KC_NULL, KC_NULL, KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11  },
	{ KC_NULL, KC_NULL, KC_NULL, KC_NULL, KC_NULL, KC_ESC , KC_NULL, KC_NULL, KC_ESC , KC_NULL, KC_NULL, KC_NULL, KC_NULL, KC_NULL }
};

const int keyMap[ROW_NUM][COL_NUM_2] = {
	{ KC_TAB , KC_q   , KC_w   , KC_e   , KC_r   , KC_t   , KC_NULL, KC_NULL, KC_y   , KC_u   , KC_i   , KC_o   , KC_p   , KC_BS   },
	{ KC_LCTL, KC_a   , KC_s   , KC_d   , KC_f   , KC_g   , KC_NULL, KC_NULL, KC_h   , KC_j   , KC_k   , KC_l   , KC_SCLN, KC_RET  },
	{ KC_LSFT, KC_z   , KC_x   , KC_c   , KC_v   , KC_b   , KC_NULL, KC_NULL, KC_n   , KC_m   , KC_COMM, KC_DOT , KC_SLSH, KC_QUOT },
	{ KC_ESC , KC_LALT, KC_ESC , KC_LGUI, KC_LOWR, KC_SPC , KC_ESC , KC_ESC , KC_SPC , KC_RISE, KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT }
};

const int keyMapRaise[ROW_NUM][COL_NUM_2] = {
	{ KC_GRAV, KC_1   , KC_2   , KC_3   , KC_4   , KC_5   , KC_NULL, KC_NULL, KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_NULL },
	{ KC_NULL, KC_NULL, KC_NULL, KC_INS , KC_HOME, KC_PGUP, KC_NULL, KC_NULL, KC_MINS, KC_EQL , KC_LB  , KC_RB  , KC_BSLS, KC_NULL },
	{ KC_NULL, KC_PSCR, KC_SCLK, KC_PAUS, KC_NULL, KC_NULL, KC_NULL, KC_NULL, KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, KC_NULL, KC_F12  },
	{ KC_NULL, KC_NULL, KC_NULL, KC_NULL, KC_NULL, KC_ESC , KC_NULL, KC_NULL, KC_ESC , KC_NULL, KC_NULL, KC_NULL, KC_NULL, KC_NULL }
};
