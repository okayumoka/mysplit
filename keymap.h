#ifndef __INCLUDED_KEYMAP_H__
#define __INCLUDED_KEYMAP_H__

// const int rowNum = 5;
// const int colNum = 6;

// LeftSide
const byte keyMapL[rowNum*2][colNum]  = {
	{KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5    },
	{KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T    },
	{KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G    },
	{KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B    },
	{KC_NULL, KC_LALT, KC_LGUI, KC_LSFT, KC_SPC,  KC_NULL }
};
// RightSide
const byte keyMapR[rowNum][colNum]  = {
	{KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL  },
	{KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_EQL  },
	{KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT },
	{KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_MINS },
	{KC_NULL, KC_BSPC, KC_ENT,  KC_RGUI, KC_BSLS, KC_NULL }
};

#endif
