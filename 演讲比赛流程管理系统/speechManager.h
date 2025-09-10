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

//����ݽ�������
class speechManager {
public:
	//����
	speechManager();

	//�˵�����
	void show_Menu();

	//�˳�ϵͳ
	void exitSystem();

	//����
	~speechManager();

	//��ʼ������������
	void initSpeech();

	//����12��ѡ��
	void createSpeacher();

	//��ʼ����  �����������̿��ƺ���
	void startSpeech();

	//��ǩ
	void speechDraw();

	//����
	void speechContest();

	//��ʾ�÷�
	void showScore();

	//�����¼
	void saveRecord();

	//��ȡ��¼
	void loadRecord();

	//�ж��ļ��Ƿ�Ϊ��
	bool fileIsEmpty;

	//��������¼������
	map<int, vector<string>>m_Record;

	//��Ա����
	//�����һ�ֱ���ѡ�ֱ������
	vector<int> vec1;
	//��һ�ֽ���ѡ�ֱ������
	vector<int> vec2;
	//ʤ��ǰ�����������
	vector<int> vecVictory;
	
	//��ű���Լ���Ӧ����ѡ�ֵ�����
	map<int, Speaker>m_Speaker;

	//��ű�������
	int m_Index;
};
