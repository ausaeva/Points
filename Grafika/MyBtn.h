#ifndef _MYBTN_H
#define _MYBTN_H

struct MyBtn {
	int left;
	int top;
	int right;
	int bottom;
};

void create_control(int left, int top, int right, int bottom, int type);
void draw_buttons();
int select_control();

enum {
	NONE = -1, DRAW_DOTS, DRAW_EXT_RECTANGLE, EXIT, N_CONTROLS
};


#endif