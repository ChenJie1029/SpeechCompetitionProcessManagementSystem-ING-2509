#pragma once
#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<deque>
#include<functional>
#include<numeric>
#include<fstream>

#include "speaker.h"

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

	//初始化容器和属性
	void initSpeech();

	//创建12名选手
	void createSpeacher();

	//开始比赛  比赛整个流程控制函数
	void startSpeech();

	//抽签
	void speechDraw();

	//比赛
	void speechContest();

	//显示得分
	void showScore();

	//保存记录
	void saveRecord();

	//读取记录
	void loadRecord();

	//判断文件是否为空
	bool fileIsEmpty;

	//存放往届记录的容器
	map<int, vector<string>>m_Record;

	//成员属性
	//保存第一轮比赛选手编号容器
	vector<int> vec1;
	//第一轮晋级选手编号容器
	vector<int> vec2;
	//胜出前三名编号容器
	vector<int> vecVictory;
	
	//存放编号以及对应具体选手的容器
	map<int, Speaker>m_Speaker;

	//存放比赛轮数
	int m_Index;
};
