#pragma once
#include"acllib.h"
class food
{
public:
	int x, y;
	food();
	~food();
	void drawFood(ACL_Image foodImage);
	void appear();
};

