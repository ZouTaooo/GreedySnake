#include"acllib.h"
#include <time.h>
#include "food.h"
#include "map.h"
#include "Snake.h"
ACL_Image mapImage;
ACL_Image snakeImage;
ACL_Image foodImage;
ACL_Image background;
int Scored;
BOOL isAgain;
BOOL flag;
Map map;
food foood;
Snake snake;
void keyEvent(int key, int event);
void timerEvent(int id);
int Setup() {
	srand((unsigned)time(NULL));
	initWindow("GreedySnake", DEFAULT, DEFAULT, 750, 600);
	Scored = 0;
	map = Map();
	map.initMap(mapImage,background);
	char num[20];
	sprintf(num, "%d", 0);
	beginPaint();
	setTextColor(ACL_Color WHITE);
	setTextSize(20);
	setTextBkColor(ACL_Color BLACK);
	paintText(690, 40, num);
	endPaint();
	foood = food();
	foood.x = (rand() % 28 + 1)*20;
	foood.y = (rand() % 28 + 1)*20;
	foood.drawFood(foodImage);
	snake = Snake();
	snake.initSnake(snakeImage);
	registerKeyboardEvent(keyEvent);
	registerTimerEvent(timerEvent);
	return 0;
}

void timerEvent(int id) {
	map.initMap(mapImage,background);
	if (!snake.isEatFood(foood))
	{
		snake.list.pop_back();					
	}
	else {
		PointList::iterator i;
		Scored += 1;
		isAgain = TRUE;
		while (isAgain)
		{
			foood.x = (rand() % 28 + 1) * 20;
			foood.y = (rand() % 28 + 1) * 20;
			isAgain = FALSE;
			for (i = snake.list.begin();i != snake.list.end();++i)
			{
				if ((*i).x == foood.x && (*i).y == foood.y)
				{
					isAgain = TRUE;
					break;
				}
			}
		}
	}
	beginPaint();
	char num[20];
	sprintf(num, "%d", Scored);
	setTextColor(ACL_Color WHITE);
	setTextSize(20);
	setTextBkColor(ACL_Color BLACK);
	paintText(690, 40, num);
	endPaint();


	foood.drawFood(foodImage);
	snake.move(foood);
	snake.DrawSnake(snakeImage);
	if (snake.isOverEdge() || snake.isEatItself()) {
		cancelTimer(0);
		beginPaint();
		char num[20];
		sprintf(num, "%d", Scored);
		char result[20] = "游戏结束 得分：";
		setTextColor(ACL_Color WHITE);
		setTextSize(20);
		setTextBkColor(ACL_Color BLACK);
		paintText(400, 280, num);
		paintText(240,280,result);
		endPaint();
	}
}

void keyEvent (int key, int event) {
	if (event==KEY_DOWN)
	{
		if (key==VK_UP||key==VK_DOWN||key==VK_RIGHT||key==VK_LEFT)
		{
			snake.changeDirection(key);
		}
		if (key== VK_ESCAPE)
		{
			if (flag)
			{
				cancelTimer(0);
			}
			else
			{
				startTimer(0, 500);
			}
		}
		if (key==VK_RETURN)
		{
			startTimer(0,100);
			flag = TRUE;
		}
	}
}
