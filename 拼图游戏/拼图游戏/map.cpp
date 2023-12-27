#include "map.h"
Map::Map(string whiteURL, string testURL)
{
    //加载资源
    loadimage(&whiteIMG, whiteURL.c_str(), IMGW, IMGH);
    loadimage(&testIMG, testURL.c_str(), WIDTH, HEIGHT);
    //乱序算法
    srand((unsigned int)time(nullptr));
    array<int, 16>temp = { 0,1,2,3,4,5,6,7,8,9,10,11,12,13,15,14};
    random_shuffle(temp.begin(), temp.end() - 1);

    int count = 0;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            map[i][j] = temp[count++];
        }
    }
}
void Map::drawMap()
{
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                //贴图坐标
                int x = j * IMGW;
                int y = i * IMGH;
                //根据数组中的值贴图
                if (map[i][j] == 15)
                {
                    putimage(x, y, &whiteIMG);

                }
                else
                {
                    int row = map[i][j] / 4;
                    int cols = map[i][j] % 4;
                    int xx = cols * IMGW;
                    int yy = row * IMGH;
                    putimage(x, y, IMGW, IMGH, &testIMG, xx, yy);

                }
            }
        }
}
int Map::getWhiteRow()
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (map[i][j] == 15)
                return i;
        }
    }
    return -1;
}

int Map::getWhiteCols()
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (map[i][j] == 15)
                return j;
        }
    }
    return -1;
    //
}

void Map::setValue(int row, int cols, int value)
{
    map[row][cols] = value;
}

int Map::getValue(int row, int cols)
{
    return map[row][cols];
}

bool Map::isOrderly()//胜负判断
{
    int count = 0;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (map[i][j] != count)
                return false;
            count++;
        }
    }
    return true;
}
