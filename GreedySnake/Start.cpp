#define _CRT_SECURE_NO_WARNINGS
#include"acllib.h"
#include <time.h>
#include "food.h"
#include "map.h"
#include "Snake.h"
ACL_Image mapImage;
ACL_Image snakeImage;
ACL_Image foodImage;
ACL_Image background;
ACL_Sound Eat;
ACL_Sound Failed;
int Scored;
BOOL isOver;
BOOL flag;
Map map;
food foood;
Snake snake;
void keyEvent(int key, int event);
void timerEvent(int id);
void init();
int Setup() {
	srand((unsigned)time(NULL));
	initWindow("GreedySnake", 100, 50, 750, 600);
	loadSound("Failed.wav", &Failed);
	loadSound("Eat.wav",&Eat);
	map = Map();
	foood = food();
	snake = Snake();
	registerKeyboardEvent(keyEvent);
	registerTimerEvent(timerEvent);
	init();
	return 0;
}

void init() {
	Scored = 0;
	map.initMap(mapImage, background);
	char num[20];
	sprintf(num, "%d", 0);
	beginPaint();
	setTextColor(ACL_Color WHITE);
	setTextSize(20);
	setTextBkColor(ACL_Color BLACK);
	paintText(690, 40, num);
	endPaint();
	foood.x = (rand() % 28 + 1) * 20;
	foood.y = (rand() % 28 + 1) * 20;
	foood.drawFood(foodImage);
	snake.initSnake(snakeImage);
	isOver = FALSE;
}

void timerEvent(int id) {
	map.initMap(mapImage,background);
	if (!snake.isEatFood(foood))
	{
		snake.list.pop_back();					
	}
	else {
		Scored += 1;
		playSound(Eat, 0);
		foood.x = (rand() % 28 + 1) * 20;
		foood.y = (rand() % 28 + 1) * 20;
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
		playSound(Failed, 0);
		cancelTimer(0);
		beginPaint();
		char num[20];
		char reStart[27] = "Enter 学什么学我还要玩！";
		char exit[24] = "Esc   不玩了 我要去学习";
		sprintf(num, "%d", Scored);
		char result[20] = "游戏结束 得分：";
		setTextColor(ACL_Color WHITE);
		setTextSize(20);
		setTextBkColor(ACL_Color BLACK);
		paintText(400, 280, num);
		paintText(210, 340, reStart);
		paintText(210, 310, exit);
		paintText(240,280,result);
		endPaint();
		isOver = TRUE;
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
			if (isOver==TRUE)
			{
				exit(0);
			}
			else
			{
				if (flag)
				{
					cancelTimer(0);
					flag = FALSE;
				}
				else
				{
					startTimer(0, 100);
					flag = TRUE;
				}
			}
		}
		if (key==VK_RETURN)
		{
			if (isOver == FALSE)
			{
				startTimer(0, 100);
				flag = TRUE;
			}
			else
			{
				snake.list.clear();
				init();
			}
		}
	}
}
