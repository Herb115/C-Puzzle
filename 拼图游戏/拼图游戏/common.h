#pragma once
#undef UNICODE
#undef _UNICODE//取消 Unicode 编码的宏定义，让后续编译都以 MBCS 编码
#include<iostream>
#include <graphics.h>  //图形库
#include <array>       //定长数组
#include <algorithm>   //乱序算法
#include <functional>  //仿函数
#include <ctime>       //time函数头文件
#include <string>
#include<mmsystem.h>

using namespace std;
//窗口属性类
//窗口的宽和高
#define WIDTH 800
#define HEIGHT 800
//每一小块图片的大小
#define IMGW 200
#define IMGH 200