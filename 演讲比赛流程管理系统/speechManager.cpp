#include "speechManager.h"

//����
speechManager::speechManager() {
	//��ʼ������������
	this->initSpeech();

	//����12��ѡ��
	this->createSpeacher();
}

//�˵�����
void speechManager::show_Menu() {
	cout << "****************************************" << endl;
	cout << "*************��ӭ�μ��ݽ�����***********" << endl;
	cout << "*************1.��ʼ�ݽ�����*************" << endl;
	cout << "*************2.�鿴�����¼*************" << endl;
	cout << "*************3.��ձ�����¼*************" << endl;
	cout << "*************0.�˳���������*************" << endl;
	cout << "****************************************" << endl;
	cout << endl;
}

//�˳�ϵͳ
void speechManager::exitSystem() {
	cout << "��ӭ�´�ʹ��" << endl;
	system("pause");
	exit(0);
}

//��ʼ������������
void speechManager::initSpeech() {
	//�������ÿ�
	this->vec1.clear();
	this->vec2.clear();
	this->vecVictory.clear();
	this->m_Speaker.clear();

	//��ʼ����������
	this->m_Index = 1;
}

//����12��ѡ��
void speechManager::createSpeacher() {
	string nameSeed = "ABDCEFGHIJKL";
	for (int i = 0; i < nameSeed.size(); i++) {
		string name = "ѡ��";
		name += nameSeed[i];

		//��������ѡ��
		Speaker sp;
		sp.m_Name = name;
		for (int j = 0; j < 2; j++) {
			sp.m_Score[j] = 0;
		}

		//����ѡ�ֱ�Ų��ҷŵ�vec1��
		this->vec1.push_back(i + 10001);

		//ѡ�ֱ���Լ���Ӧѡ�ַ��뵽map��
		this->m_Speaker.insert(make_pair(i + 10001, sp));
	}
}

//��ʼ����  �����������̿��ƺ���
void speechManager::startSpeech() {
	//��һ�ֿ�ʼ����
	//1.��ǩ
	this->speechDraw();
	//2.�ݽ�

	//3.��ʾ����


	//�ڶ��ֿ�ʼ����
	//1.��ǩ

	//2.�ݽ�

	//3.��ʾ���ս��

	//4.����������ļ���
}

//��ǩ
void speechManager::speechDraw() {
	cout << "��" << this->m_Index << "�ֳ�ǩ" << endl;
	cout << "------------------------------" << endl;
	cout << "��ǩ������£�" << endl;

	if (this->m_Index == 1) {
		//��һ��
		random_shuffle(vec1.begin(), vec1.end());
		for (vector<int>::iterator it = vec1.begin(); it != vec1.end(); it++) {
			cout << *it << " ";
		}
		cout << endl;
	}
	else if (this->m_Index == 2) {
		//�ڶ���
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

//����
speechManager::~speechManager() {

}