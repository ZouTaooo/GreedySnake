#include "Snake.h"
#include <list>
#include "acllib.h"
#include "food.h"

void Snake::changeDirection(int key) {
	if ((key==VK_UP&&this->Direction==VK_DOWN)|| (key == VK_DOWN&&
		this->Direction == VK_UP)|| (key == VK_LEFT&&this->Direction 
			== VK_RIGHT)|| (key== VK_RIGHT&&this->Direction == VK_LEFT))
	{
		return;
	}
	this->Direction = key;
}

bool Snake::isOverEdge() {
	if (this->list.front().x <= 0 || this->list.front().x >= 580
		|| this->list.front().y<=0 || this->list.front().y >= 580)
	{
		return TRUE;
	}
	return FALSE;
}

bool Snake::isEatItself() {
	BOOL flag=FALSE;
	Point p = this->list.front();
	int x = p.x;
	int y = p.y;
	//还未移动的尾巴不用比较
	//TODO
	PointList::iterator i;
	i = list.begin();
	for (i++; i != list.end(); i++)
	{
		if ((*i).x==x&&(*i).y==y)
		{
			flag = TRUE;
		}
	}
	return flag;
}

bool Snake::isEatFood(food fd) {
	if (list.front().x == fd.x&&list.front().y == fd.y)
	{
		return TRUE;
	}
	return FALSE;
}

void Snake::move(food fd) {
	Point point;
	
	point.x = list.front().x;
	point.y = list.front().y;
	
	switch (this->Direction)
	{
	case VK_UP:
		point.y -=20;
		break;
	case VK_DOWN:
		point.y += 20;
		break;
	case VK_RIGHT:
		point.x += 20;
		break;
	case VK_LEFT:
		point.x-= 20;
		break;
	default:
		break;
	}
	//添加第一个元素
	list.push_front(point);
}

void Snake::initSnake(ACL_Image snakeImage) {
	loadImage("Snake.jpg", &snakeImage);
	this->Direction = VK_UP;
	Point firstPoint;
	firstPoint.x = 300;
	firstPoint.y = 260;
	list.push_back(firstPoint);
	Point secondPoint;
	secondPoint.x = 300;
	secondPoint.y = 280;
	list.push_back(secondPoint);
	Point thirdPoint;
	thirdPoint.x = 300;
	thirdPoint.y = 300;
	list.push_back(thirdPoint);
	DrawSnake(snakeImage);
}

void Snake::DrawSnake(ACL_Image snakeImage) {
	loadImage("Snake.jpg", &snakeImage);
	PointList::iterator i;
	beginPaint();
	for (i = list.begin(); i != list.end(); i++)
	{
		putImageScale(&snakeImage, (*i).x, (*i).y, 20, 20);
	}
	endPaint();
}

Snake::Snake()
{
}

Snake::~Snake()
{
}
