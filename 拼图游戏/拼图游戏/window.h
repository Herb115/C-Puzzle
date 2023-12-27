
#pragma once
#include "common.h"
class Window
{
public:
	Window(int w, int h, string url = "", int flag = 0);
	void refresh();
	~Window();
	HWND getHwnd();
protected:
	int width;
	int height;
	IMAGE background;
	string imgURL;
	HWND hwnd;//¾ä±ú
};