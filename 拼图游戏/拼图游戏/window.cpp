
#include "window.h"
Window::Window(int w, int h, string url, int flag)
{
	width = w;
	height = h;
	imgURL = url;
	//创建窗口
	hwnd =initgraph(w, h, flag);
	if (url.size() != 0)
	{
		loadimage(&background, url.c_str(), w, h);
		putimage(0, 0, &background);
	}
}
void Window::refresh()
{
	if (imgURL.size() != 0)
	{
		putimage(0, 0, &background);
	}
	else
	{
		cleardevice();
	}
}

Window::~Window()
{
	closegraph();//关闭图形系统
}

HWND Window::getHwnd()//窗口
{
	return hwnd;
}