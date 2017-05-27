#include "Map.h"
#include"acllib.h"
#include<sstream>
#include<string>

void Map::initMap(ACL_Image mapImage,ACL_Image background) {
	loadImage("Map.jpg", &mapImage);
	loadImage("background.jpg", &background);
	beginPaint();
	clearDevice();
	putImageScale(&background, 0, 0, 750, 600);
	for (int i = 0; i < 600; i += 20)
	{
		putImageScale(&mapImage, 0, i, 20, 20);
		putImageScale(&mapImage, 580, i, 20, 20);
		putImageScale(&mapImage, i, 0, 20, 20);
		putImageScale(&mapImage, i, 580, 20, 20);
	}
	char scored[8] = "得分:";
	char Esc[10] = "ESC键暂停";
	char Enter[12] = "Enter键开始";
	
	setTextColor(ACL_Color WHITE);
	setTextSize(20);
	setTextBkColor(ACL_Color BLACK);
	paintText(610, 40, scored);
	paintText(610, 400, Esc);
	paintText(610, 500, Enter);
	endPaint();
}

Map::Map()
{
}


Map::~Map()
{
}
