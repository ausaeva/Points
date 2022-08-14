#include "MyBtn.h"
#include <iostream>
#include "headers/graphics.h"

MyBtn controls[N_CONTROLS];

void create_control(int left, int top, int right, int bottom, int type) {
	MyBtn control;
	control.left = left;
	control.right = right;
	control.top = top;
	control.bottom = bottom;
	controls[type] = control;
}


void draw_buttons() {
	setfillstyle(SOLID_FILL, GREEN);
	setcolor(RED);

	for (int i = 0; i < N_CONTROLS; ++i) {
		bar(controls[i].left, controls[i].top, controls[i].right, controls[i].bottom);
		rectangle(controls[i].left, controls[i].top, controls[i].right, controls[i].bottom);
	}	
}

int select_control() {
	int x = mousex();
	int y = mousey();

	for (int i = 0; i < N_CONTROLS; ++i) {
		if (x >= controls[i].left && x <= controls[i].right && y >= controls[i].top && y <= controls[i].bottom) {
			return i;
		}
	}
	return  NONE;
}
