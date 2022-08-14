#include "headers/graphics.h"
#include <iostream>
#include "MyBtn.h"
using namespace std;

const int MAX_DOTS = 100;

const int WIDTH = 800;                      //Ширина окна
const int HEIGHT = 700;
const int RADIUS = 5;  //Высота окна
bool Ext_Rectangle = FALSE;;

void Create_Arr_Dots();

void DrawDots();
void Draw_Ext_Rectangle();

struct For_Dots {
	int x;
	int y;
};

For_Dots Dots[MAX_DOTS];

void Create_Arr_Dots() {
	for (int i = 0; i < MAX_DOTS; ++i) {
		int x = rand() % (WIDTH - 300) + 200;
		int y = rand() % (HEIGHT - 200) + 100;
		Dots[i].x = x;
		Dots[i].y = y;
	}
}


void DrawDots() {
	for (int i = 0; i < MAX_DOTS; ++i) {
		fillellipse(Dots[i].x, Dots[i].y, RADIUS, RADIUS);
	}

}


void Draw_Ext_Rectangle() {
	int R_Left = HEIGHT;
	int R_Top = WIDTH;
	int R_Right = 0;
	int R_Botton = 0;
	for (int i = 0; i < MAX_DOTS; ++i) {
		if (Dots[i].x <= R_Left) {
			R_Left = Dots[i].x - RADIUS;
		}
		else if (Dots[i].x >= R_Right) {
			R_Right = Dots[i].x + RADIUS;
		}
		if (Dots[i].y <= R_Top) {
			R_Top = Dots[i].y - RADIUS;
		}
		else if (Dots[i].y >= R_Botton) {
			R_Botton = Dots[i].y + RADIUS;
		}
	}
	setcolor(MAGENTA);
	rectangle(R_Left, R_Top, R_Right, R_Botton);
}



int main() {
	
	srand(time(0));

	
	initwindow(WIDTH, HEIGHT, "Анимация", 0, 0, true); // режим 2-страниц

	Create_Arr_Dots();

	create_control(0, HEIGHT - 100, 100, HEIGHT, DRAW_DOTS);
	create_control(100, HEIGHT - 100, 200, HEIGHT, DRAW_EXT_RECTANGLE);
	create_control(200, HEIGHT - 100, 300, HEIGHT, EXIT);

	
	while (true) {
		setbkcolor(WHITE);
		clearviewport();
		
		draw_buttons();

		if (Ext_Rectangle) {
			Draw_Ext_Rectangle();
		}
		
		DrawDots();

		if (mousebuttons() == 1) {
			Ext_Rectangle = FALSE;
			int button = select_control();
			if (button == DRAW_DOTS) {
				Create_Arr_Dots();
			}
			else if (button == DRAW_EXT_RECTANGLE) {
				Ext_Rectangle = TRUE;
			}
			else if (button == EXIT) {
				break;
			}
		}

	
		swapbuffers(); // делаем активную страницу видимой
		delay(30); // задержка на 1/30 секунды
		if (kbhit()) break; // если нажата клавиша - завершить работу
	}
	closegraph();
}