#include "game.h"

enum MenuOp
{
	Start,//开始
	Operate,//操作描述
	Exit,//退出
	Home//回到主目录

};
//鼠标是否在某个矩形区域
bool isInRect(ExMessage* msg, int x, int y, int w, int h)
{
	if (msg->x > x && msg->x<x + w && msg->y>y && msg->y < y + h)
	{
		return true;
	}
	return false;
}
enum MenuOp menuState = Home;
void startupScence(ExMessage* msg)
{
	IMAGE img;
	if (msg->message == WM_LBUTTONDOWN)
	{
		if (menuState == Home)
		{
			//1开始
			if (isInRect(msg, 79, 420, 151, 73))
			{
				menuState = Start;

			}
			//2操作描述
			else if (isInRect(msg, 314, 420, 151, 73))
			{
				menuState = Operate; 
			}
			//3退出
			else if (isInRect(msg, 567, 420, 151, 73))
			{
				menuState = Exit;exit(0);
			}
		}
		else
		{
			switch (menuState)
			{
			case Start:
				if (isInRect(msg, 0, 0, 70, 70))
				{
					menuState = Home;
				}
				break;
			case Operate:
				if (isInRect(msg, 0, 0, 70, 70))
				{
					menuState = Home;
				}
				break;
			}
		}
	}
	if (menuState == Operate)
	{
		loadimage(&img, "Operate.png", getwidth(), getheight());
		putimage(0, 0, &img);
	}
	else if (menuState == Home)
	{
		loadimage(&img, "Home.png", getwidth(), getheight());
		putimage(0, 0, &img);
	}
}
void HOME()
{
	if (menuState == Home) 
	{
		IMAGE img;
		//加载图片
		loadimage(&img, "Home.png", getwidth(), getheight());
		//绘制图片
		putimage(0, 0, &img);
	}
	while (true)
	{

		//处理鼠标消息
		ExMessage msg;
		while (peekmessage(&msg, EM_MOUSE))//不断获取鼠标消息，有消息返回true，否则返回false
		{
			startupScence(&msg);
			if (menuState == Start)
				break;
		}break;
	}
}
Game::Game() :pW(new Window(WIDTH, HEIGHT)), pM(new Map("white.png", "play2.jpeg"))
{
}

void Game::Run()
{
	EASYXMSG m;//定义一个鼠标变量储存鼠标消息
	while (1)
	{
		peekmessage(&m, EM_MOUSE);
		HOME();
		if (menuState == Start)
		{
			pM->drawMap();
			if (pM->isOrderly())
			{
				MessageBox(pW->getHwnd(), "你赢了！！", "游戏结束", MB_OK);
				break;
			}
			//得到白块的行列
			int i = pM->getWhiteRow();
			int j = pM->getWhiteCols();

			if (m.message == WM_LBUTTONDOWN)
			{
				//得到鼠标的行列
				int mi = m.y / IMGH;
				int mj = m.x / IMGW;
				if (i == mi && j + 1 == mj)
				{
					pM->setValue(i, j, pM->getValue(mi, mj));
					pM->setValue(mi, mj, 15);
				}
				if (i == mi && j - i == mj)
				{
					pM->setValue(i, j, pM->getValue(mi, mj));
					pM->setValue(mi, mj, 15);
				}
				if (i + 1 == mi && j == mj)
				{
					pM->setValue(i, j, pM->getValue(mi, mj));
					pM->setValue(mi, mj, 15);
				}
				if (i - 1 == mi && j == mj)
				{
					pM->setValue(i, j, pM->getValue(mi, mj));
					pM->setValue(mi, mj, 15);
				}
			}

		}
	}
}

Game::~Game()
{
	delete pM;
	delete pW;
}