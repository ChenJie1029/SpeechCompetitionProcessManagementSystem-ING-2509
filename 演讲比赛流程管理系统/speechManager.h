#pragma once
#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<deque>
#include<functional>
#include<numeric>

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
