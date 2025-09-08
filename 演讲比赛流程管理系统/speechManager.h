#pragma once
#include<iostream>

using namespace std;

//设计演讲管理类
class speechManager {
public:
	//构造
	speechManager();

	//菜单功能
	void show_Menu();

	//退出系统
	void exitSystem();

	//析构
	~speechManager();
};
