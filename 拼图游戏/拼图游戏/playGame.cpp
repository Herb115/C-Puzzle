#include "game.h"
int main()
{
	Game g;
	mciSendString("open music.mp3", 0, 0, 0);
	mciSendString("play music.mp3", 0, 0, 0);
	g.Run();

	return 0;
}