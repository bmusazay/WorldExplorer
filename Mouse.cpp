#include "Mouse.h"

Mouse::Mouse() {
	
}

void Mouse::mouseMotion(int newX, int newY) {

	difX = x - newX;
	difY = y - newY;

	x = newX;
	y = newY;
}