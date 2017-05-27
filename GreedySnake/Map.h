#pragma once
#include "acllib.h"
class Map
{
public:
	ACL_Image mapImage;
	void initMap(ACL_Image mapImage,ACL_Image background);
	Map();
	~Map();
};

