#ifndef __INCLUDED_KEYMAP_H__
#define __INCLUDED_KEYMAP_H__

#include "keycode.h"

#define ROW_NUM 4
#define COL_NUM 7
#define COL_NUM_2 COL_NUM*2

extern const int keyMap[ROW_NUM][COL_NUM_2];
extern const int keyMapRaise[ROW_NUM][COL_NUM_2];
extern const int keyMapLower[ROW_NUM][COL_NUM_2];

#endif
