#include<iostream>
#include "speechManager.h"

using namespace std;

//�ݽ��������̹���ϵͳ

int main() {
	//�������������
	speechManager sm;

	cout << "����������ѡ��" << endl;
	int choice = 0;

	while (1) {
		sm.show_Menu();
		cin >> choice;

		switch (choice)
		{
		case 1://��ʼ�ݽ�����
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

	return 0;
}