#include<iostream>
#include "speechManager.h"

using namespace std;

//�ݽ��������̹���ϵͳ

int main() {
	//�������������
	speechManager sm;

	//���� ����12��ѡ����Ϣ
	/*for (map<int, Speaker>::iterator it = sm.m_Speaker.begin(); it != sm.m_Speaker.end(); it++) {
		cout << "ѡ�ֱ�ţ�" << it->first << " " << "ѡ��������" << it->second.m_Name << " " << "ѡ�ֵ÷֣�" << it->second.m_Score[0] << endl;
	}*/

	cout << "����������ѡ��" << endl;
	int choice = 0;

	while (1) {
		sm.show_Menu();
		cin >> choice;

		switch (choice)
		{
		case 1://��ʼ�ݽ�����
			sm.startSpeech();
			break;
		case 2://�鿴�����¼
			break;
		case 3://��ձ�����¼
			break;
		case 0://�˳���������
			sm.exitSystem();
			break;
		default:
			system("cls");//����
			break;
		}
	}
	//
	//
	//

	return 0;
}