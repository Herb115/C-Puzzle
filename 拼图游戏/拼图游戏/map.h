#pragma once
#include "common.h"
class Map
{
public:
	Map(string whiteURL, string testURL);
	void drawMap();
	//�׿鶨λ
	int getWhiteRow();
	int getWhiteCols();
	//�������ṩ�ӿڣ����õ�ͼ����
	void setValue(int row, int cols, int value);
	int getValue(int row, int cols);
	//�жϵ�ͼ�ϵ������Ƿ�����
	bool isOrderly();
	IMAGE img_Home;

protected:
	IMAGE whiteIMG;
	IMAGE testIMG;
	array<array<int, 4>, 4> map;


};