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
	this->speechContest();
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
void speechManager::speechContest() {
	cout << "-------------------��" << this->m_Index << "�ֱ���-------------------" << endl;

	//׼����ʱ���� ���С��ɼ�
	multimap<double, int, greater<double>> groupScore;
	//��¼��Ա����  6��һ��
	int num = 0;

	vector<int> v_Src;//����ѡ������
	if (this->m_Index == 1) {
		v_Src = vec1;
	}
	else {
		v_Src = vec2;
	}

	//�������в���ѡ��
	for (vector<int>::iterator it = v_Src.begin(); it != v_Src.end(); it++) {
		//��ί���
		num++;
		deque<double> deq1;
		for (int i = 0; i < 10; i++) {
			double score = (rand() % 401 + 600) / 10.f;
			//cout << score << " ";
			deq1.push_back(score);
		}

		sort(deq1.begin(), deq1.end(), greater<double>());//����
		deq1.pop_front();//ȥ����߷�
		deq1.pop_back();//ȥ����ͷ�

		double sum = accumulate(deq1.begin(), deq1.end(), 0);//�ܷ�
		double avg = sum / (double)deq1.size();
 
		//��ӡƽ����
		//cout << "��ţ�" << *it << "\t" << "������" << this->m_Speaker[*it].m_Name << "\t" << "ƽ���֣�" << avg << endl;

		//��ƽ���ַ���map������
		this->m_Speaker[*it].m_Score[this->m_Index - 1] = avg;

		//��������ݷ��뵽��ʱС��������
		groupScore.insert(make_pair(avg, *it));//key��ƽ���֣�value�Ǳ��
		//ÿ6��ȡǰ����
		if (num % 6 == 0) {
			cout << "��" << num / 6 << "С��������Σ�" << endl;
			for (multimap<double, int, greater<double>>::iterator it = groupScore.begin(); it != groupScore.end(); it++) {
				cout << "��ţ�" << it->second << "\t" << "������" << this->m_Speaker[it->second].m_Name << "\t" << "�ɼ���" << this->m_Speaker[it->second].m_Score[this->m_Index - 1] << endl;
			}

			//ȡ��ǰ����
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
	cout << "-------------------��" << this->m_Index << "�ֱ�������-------------------" << endl;
	system("pause");
}

//����
speechManager::~speechManager() {

}