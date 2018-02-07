#include "keycode.h"

const byte keyMap[ROW_NUM][COL_NUM*2]  = {
	/* --------------------------------- LEFT side ----------|------- RIGHT side ------------------------------------ */
	{KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    /*|*/ KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL  },
	{KC_TAB,  KC_q,    KC_w,    KC_e,    KC_r,    KC_t,    /*|*/ KC_y,    KC_u,    KC_i,    KC_o,    KC_p,    KC_EQL  },
	{KC_CAPS, KC_a,    KC_s,    KC_d,    KC_f,    KC_g,    /*|*/ KC_h,    KC_j,    KC_k,    KC_l,    KC_SCLN, KC_QUOT },
	{KC_LSFT, KC_z,    KC_x,    KC_c,    KC_v,    KC_b,    /*|*/ KC_n,    KC_m,    KC_COMM, KC_DOT,  KC_SLSH, KC_MINS },
	{KC_NULL, KC_LALT, KC_LGUI, KC_LSFT, KC_SPC,  KC_NULL, /*|*/ KC_NULL, KC_BSPC, KC_ENT,  KC_RGUI, KC_BSLS, KC_NULL }
	/* --------------------------------- LEFT side ----------|------- RIGHT side ------------------------------------ */
};
