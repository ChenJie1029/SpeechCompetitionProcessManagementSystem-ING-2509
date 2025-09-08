#include<iostream>
#include "speechManager.h"

using namespace std;

//演讲比赛流程管理系统

int main() {
	//创建管理类对象
	speechManager sm;

	//测试 创建12名选手信息
	/*for (map<int, Speaker>::iterator it = sm.m_Speaker.begin(); it != sm.m_Speaker.end(); it++) {
		cout << "选手编号：" << it->first << " " << "选手姓名：" << it->second.m_Name << " " << "选手得分：" << it->second.m_Score[0] << endl;
	}*/

	cout << "请输入您的选择：" << endl;
	int choice = 0;

	while (1) {
		sm.show_Menu();
		cin >> choice;

		switch (choice)
		{
		case 1://开始演讲比赛
			sm.startSpeech();
			break;
		case 2://查看往届记录
			break;
		case 3://清空比赛记录
			break;
		case 0://退出比赛程序
			sm.exitSystem();
			break;
		default:
			system("cls");//清屏
			break;
		}
	}
	//
	//
	//

	return 0;
}