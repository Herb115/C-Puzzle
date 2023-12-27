
#include "window.h"
Window::Window(int w, int h, string url, int flag)
{
	width = w;
	height = h;
	imgURL = url;
	//��������
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
	closegraph();//�ر�ͼ��ϵͳ
}

HWND Window::getHwnd()//����
{
	return hwnd;
}