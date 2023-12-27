#pragma once
#include "common.h"
#include "window.h"
#include "map.h"
#pragma comment(lib,"winmm.lib")
class Game
{
public:
	Game();
	void Run();
	~Game();
protected:
	Map* pM;
	Window* pW;

};