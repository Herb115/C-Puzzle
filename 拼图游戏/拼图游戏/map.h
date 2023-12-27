#pragma once
#include "common.h"
class Map
{
public:
	Map(string whiteURL, string testURL);
	void drawMap();
	//白块定位
	int getWhiteRow();
	int getWhiteCols();
	//给类外提供接口，设置地图属性
	void setValue(int row, int cols, int value);
	int getValue(int row, int cols);
	//判断地图上的数字是否有序
	bool isOrderly();
	IMAGE img_Home;

protected:
	IMAGE whiteIMG;
	IMAGE testIMG;
	array<array<int, 4>, 4> map;


};