#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define FALL_TIME 3 //(3 SECONDS)
#define SCREEN_Y_MAX 480

/* Type => 1 - apple, 2 - orange, 3 - lemon, 4 - watermelon */

typedef struct fruit {

		uint8_t style;
		uint16_t curr_X;
		uint16_t curr_Y;

		uint16_t x_S;
		uint16_t x_E;
		uint16_t y_T;


		float dy;
		float dx;
} Fruit;

Fruit newFruit(uint8_t type, uint16_t start, uint16_t end, uint16_t top ){
	Fruit f;
	f.style= type;
	f.x_S = start;
	f.x_E = end;
	f.y_T = top;
	f.curr_X = f.x_S;
	f.curr_Y = SCREEN_Y_MAX;

	f.dy = 4*(f.y_T) / (float)(2*f.x_E*f.x_S - f.x_E*f.x_E - f.x_S*f.x_S);
	f.dx = (abs(f.x_E-f.x_S))/FALL_TIME;
	return f;
}

void setNewPos(Fruit f, double time){
	f.curr_X += f.dx * time;
	f.curr_Y = f.dy * (f.curr_X- f.x_S)*(f.curr_X- f.x_E);
}

//void newPath(Fruit f, uint16_t start, uint16_t end, uint16_t top) {
//
//	f.x_S;
//}
