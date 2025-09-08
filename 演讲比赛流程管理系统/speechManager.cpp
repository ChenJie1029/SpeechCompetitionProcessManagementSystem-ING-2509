#include "speechManager.h"

//构造
speechManager::speechManager() {
	//初始化容器和属性
	this->initSpeech();

	//创建12名选手
	this->createSpeacher();
}

//菜单功能
void speechManager::show_Menu() {
	cout << "****************************************" << endl;
	cout << "*************欢迎参加演讲比赛***********" << endl;
	cout << "*************1.开始演讲比赛*************" << endl;
	cout << "*************2.查看往届记录*************" << endl;
	cout << "*************3.清空比赛记录*************" << endl;
	cout << "*************0.退出比赛程序*************" << endl;
	cout << "****************************************" << endl;
	cout << endl;
}

//退出系统
void speechManager::exitSystem() {
	cout << "欢迎下次使用" << endl;
	system("pause");
	exit(0);
}

//初始化容器和属性
void speechManager::initSpeech() {
	//容器都置空
	this->vec1.clear();
	this->vec2.clear();
	this->vecVictory.clear();
	this->m_Speaker.clear();

	//初始化比赛轮数
	this->m_Index = 1;
}

//创建12名选手
void speechManager::createSpeacher() {
	string nameSeed = "ABDCEFGHIJKL";
	for (int i = 0; i < nameSeed.size(); i++) {
		string name = "选手";
		name += nameSeed[i];

		//创建具体选手
		Speaker sp;
		sp.m_Name = name;
		for (int j = 0; j < 2; j++) {
			sp.m_Score[j] = 0;
		}

		//创建选手编号并且放到vec1中
		this->vec1.push_back(i + 10001);

		//选手编号以及对应选手放入到map中
		this->m_Speaker.insert(make_pair(i + 10001, sp));
	}
}

//开始比赛  比赛整个流程控制函数
void speechManager::startSpeech() {
	//第一轮开始比赛
	//1.抽签
	this->speechDraw();
	//2.演讲

	//3.显示晋级


	//第二轮开始比赛
	//1.抽签

	//2.演讲

	//3.显示最终结果

	//4.保存分数到文件中
}

//抽签
void speechManager::speechDraw() {
	cout << "第" << this->m_Index << "轮抽签" << endl;
	cout << "------------------------------" << endl;
	cout << "抽签结果如下：" << endl;

	if (this->m_Index == 1) {
		//第一轮
		random_shuffle(vec1.begin(), vec1.end());
		for (vector<int>::iterator it = vec1.begin(); it != vec1.end(); it++) {
			cout << *it << " ";
		}
		cout << endl;
	}
	else if (this->m_Index == 2) {
		//第二轮
		random_shuffle(vec2.begin(), vec2.end());
		for (vector<int>::iterator it = vec2.begin(); it != vec2.end(); it++) {
			cout << *it << " ";
		}
		cout << endl;
	}
	cout << "------------------------------" << endl;
	system("pause");
	cout << endl;
}

//析构
speechManager::~speechManager() {

}