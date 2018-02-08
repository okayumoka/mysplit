#ifndef __INCLUDED_KEYMAP_H__
#define __INCLUDED_KEYMAP_H__

#include "keycode.h"

#define ROW_NUM 5
#define COL_NUM 6
#define COL_NUM_2 COL_NUM*2

extern const byte keyMap[ROW_NUM][COL_NUM_2];
extern const byte keyMapUpper[ROW_NUM][COL_NUM_2];
extern const byte keyMapLower[ROW_NUM][COL_NUM_2];

#endif
