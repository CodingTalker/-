#pragma once//提供本项目所有的头文件，以便每个类只用引用一个头文件（即本文件）
#include<stdlib.h>//用到了里面的exit()以及一些转化函数（如snprintf）
#include<easyx.h>//需要用easyX来设计程序UI
#include<graphics.h>//绘制背景图
#include<vector>//管理Flight、Train、Route等一系列数据或类
#include<fstream>//读取、保存数据
#include<iostream>//用于控制台调试
#include<algorithm>//用于排序数据
#include<set>//用于检查插入数据是否重复
#include<stdio.h>//保留C基本函数，在底层数据交互用到
#include<string>//需要用到C++里string里的函数，来处理string数据的传输，同时用string来配合搭建UI界面更为方便
#include<string.h>//用到了里面的memset和对C字符串处理的函数
#include<Windows.h>//用到了里面的sleep函数,因为点击按钮会触发多次,需要用sleep函数来解决
#include<map>//用于检测列车车班是否完整
#define MaxCitySize 100//城市最多有100个
using namespace std;
