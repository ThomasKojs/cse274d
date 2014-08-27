#include "rectangle.h"

Rectangle::Rectangle() {
	width = 1;
	height = 2;
}

int Rectangle::perimeter() {
	return 2*width + 2*height;
}

void Rectangle::set_values (int x, int y) {
  width = x;
  height = y;
}

int Rectangle::area(){
	return height*width;
}


