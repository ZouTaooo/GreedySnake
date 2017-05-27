#include "food.h"
#include<time.h>
#include"acllib.h"

void food::drawFood(ACL_Image foodImage) {
	loadImage("food.jpg", &foodImage);
	beginPaint();
	putImageScale(&foodImage, this->x, this->y, 20, 20);
	endPaint();
}
void food::appear( ) {
	this->x = (rand() % 28 + 1) * 20;
	this->y = (rand() % 28 + 1) * 20;
}


food::food()
{
}


food::~food()
{
}
