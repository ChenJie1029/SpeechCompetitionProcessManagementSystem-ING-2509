#include "speechManager.h"

//构造
speechManager::speechManager() {
	//初始化容器和属性
	this->initSpeech();

	//创建12名选手
	this->createSpeacher();

	//加载往届记录
	this->loadRecord();
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

	//将记录容器清空
	this->m_Record.clear();
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
	this->speechContest();
	//3.显示晋级
	this->showScore();

	//第二轮开始比赛
	this->m_Index++;
	//1.抽签
	this->speechDraw();
	//2.演讲
	this->speechContest();
	//3.显示最终结果
	this->showScore();
	//4.保存分数到文件中
	this->saveRecord();

	//重置比赛，获取记录
	//初始化容器和属性
	this->initSpeech();

	//创建12名选手
	this->createSpeacher();

	//加载往届记录
	this->loadRecord();

	cout << "本届比赛完毕!" << endl;
	system("pause");
	system("cls");
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

//比赛
void speechManager::speechContest() {
	cout << "-------------------第" << this->m_Index << "轮比赛-------------------" << endl;

	//准备临时容器 存放小组成绩
	multimap<double, int, greater<double>> groupScore;
	//记录人员个数  6人一组
	int num = 0;

	vector<int> v_Src;//比赛选手容器
	if (this->m_Index == 1) {
		v_Src = vec1;
	}
	else {
		v_Src = vec2;
	}

	//遍历所有参赛选手
	for (vector<int>::iterator it = v_Src.begin(); it != v_Src.end(); it++) {
		//评委打分
		num++;
		deque<double> deq1;
		for (int i = 0; i < 10; i++) {
			double score = (rand() % 401 + 600) / 10.f;
			//cout << score << " ";
			deq1.push_back(score);
		}

		sort(deq1.begin(), deq1.end(), greater<double>());//排序
		deq1.pop_front();//去除最高分
		deq1.pop_back();//去除最低分

		double sum = accumulate(deq1.begin(), deq1.end(), 0);//总分
		double avg = sum / (double)deq1.size();
 
		//打印平均分
		//cout << "编号：" << *it << "\t" << "姓名：" << this->m_Speaker[*it].m_Name << "\t" << "平均分：" << avg << endl;

		//将平均分放入map容器中
		this->m_Speaker[*it].m_Score[this->m_Index - 1] = avg;

		//将打分数据放入到临时小组容器中
		groupScore.insert(make_pair(avg, *it));//key是平均分，value是编号
		//每6人取前三名
		if (num % 6 == 0) {
			cout << "第" << num / 6 << "小组比赛名次：" << endl;
			for (multimap<double, int, greater<double>>::iterator it = groupScore.begin(); it != groupScore.end(); it++) {
				cout << "编号：" << it->second << "\t" << "姓名：" << this->m_Speaker[it->second].m_Name << "\t" << "成绩：" << this->m_Speaker[it->second].m_Score[this->m_Index - 1] << endl;
			}

			//取走前三名
			int count = 0;
			for (multimap<double, int, greater<double>>::iterator it = groupScore.begin(); it != groupScore.end() && count < 3; it++, count++) {
				if (this->m_Index == 1) {
					vec2.push_back((*it).second);
				}
				else {
					vecVictory.push_back((*it).second);
				}
			}

			groupScore.clear();
			cout << endl;
		}
	}
	cout << "-------------------第" << this->m_Index << "轮比赛结束-------------------" << endl;
	system("pause");
}

//显示得分
void speechManager::showScore() {
	cout << "-------------------第" << this->m_Index << "轮比赛晋级选手----------------" << endl;

	vector<int> v;
	if (this->m_Index == 1) {
		v = vec2;
	}
	else {
		v = vecVictory;
	}

	for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		cout << "选手编号：" << *it << "姓名：" << this->m_Speaker[*it].m_Name << "得分：" << this->m_Speaker[*it].m_Score[this->m_Index - 1] << endl;
	}
	cout << endl;

	system("pause");
	system("cls");
	this->show_Menu();
}

//保存记录
void speechManager::saveRecord() {
	ofstream ofs;
	ofs.open("speech.csv", ios::out | ios::app);//用追加的方式写文件

	//将每个选手数据写入到文件中
	for (vector<int>::iterator it = vecVictory.begin(); it != vecVictory.end(); it++) {
		ofs << *it << "," << this->m_Speaker[*it].m_Score[1] << ",";
	}
	ofs << endl;

	//关闭
	ofs.close();
	cout << "文件记录已经保存" << endl;

	//更改文件不为空的状态
	this->fileIsEmpty = false;
}

//读取记录
void speechManager::loadRecord() {
	ifstream ifs("speech.csv", ios::in);//读文件
	if (!ifs.is_open()) {
		this->fileIsEmpty = true;
		//cout << "文件不存在" << endl;
		ifs.close();
		return;
	}

	//文件清空的情况
	char ch;
	ifs >> ch;
	if (ifs.eof()) {
		//cout << "文件为空" << endl;
		this->fileIsEmpty = true;
		ifs.close();
		return;
	}

	//文件不为空
	this->fileIsEmpty = false;
	ifs.putback(ch);//将上面读取的单个字符再放回来

	string data;
	int  index = 0;//届数

	while (ifs >> data) {
		//cout << data << endl;

		vector<string> v;//存放字符串 6个

		int pos = -1;//查到,位置的变量
		int start = 0;//起始位置

		while (1) {
			pos = data.find(",", start);
			if (pos == -1) {//没找到
				break;
			}
			string temp = data.substr(start, pos - start);
			//cout << temp << endl;
			v.push_back(temp);
			start = pos + 1;
		}
		this->m_Record.insert(make_pair(index, v));
		index++;
	}
	ifs.close();

	/*for (map<int, vector<string>>::iterator it = m_Record.begin(); it != m_Record.end(); it++) {
		cout << it->first << "冠军编号：" << it->second[0] << "分数：" << it->second[1] << endl;
	}*/
}

//显示往届记录
void speechManager::showRecord() {
	if (this->fileIsEmpty) {
		cout << "文件为空或文件不存在！" << endl;
	}
	else {
		for (int i = 0; i < this->m_Record.size(); i++) {
			cout << "第" << i + 1 << "届" << endl;
			cout << "冠军编号：" << this->m_Record[i][0] << "\t" << "得分：" << this->m_Record[i][1] << endl;
			cout << "亚军编号：" << this->m_Record[i][2] << "\t" << "得分：" << this->m_Record[i][3] << endl;
			cout << "季军编号：" << this->m_Record[i][4] << "\t" << "得分：" << this->m_Record[i][5] << endl;
		}
	}

	system("pause");
	system("cls");
}

//清空文件
void speechManager::clearRecord() {
	cout << "是否确定清空文件？" << endl;
	cout << "1.是" << "\t" << "2.否" << endl;

	int select = 0;

	cin >> select;
	if (select == 1) {
		ofstream ofs("speech.csv", ios::trunc);
		ofs.close();
		//初始化容器和属性
		this->initSpeech();
		//创建12名选手
		this->createSpeacher();
		//加载往届记录
		this->loadRecord();
		cout << "清空完成" << endl;
	}
	system("pause");
	system("cls");
}

//析构
speechManager::~speechManager() {

}