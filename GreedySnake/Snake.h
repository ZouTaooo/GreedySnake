#pragma once
#include<list>
#include"acllib.h"
#include "food.h"
using namespace std;
typedef struct Point
{
	int x;
	int y;
};
typedef list<Point> PointList;
class Snake
{
public:
	int Direction;
	PointList list;
	ACL_Image snakeImage;
	void DrawSnake(ACL_Image snakeImage);
	void changeDirection(int key);
	bool isOverEdge();
	bool isEatItself();
	bool isEatFood(food fd);
	void move(food fd);
	void initSnake(ACL_Image snakeImage);
	Snake();
	~Snake();
};

