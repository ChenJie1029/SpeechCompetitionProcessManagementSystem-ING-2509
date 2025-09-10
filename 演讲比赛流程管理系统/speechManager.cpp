#include "speechManager.h"

//����
speechManager::speechManager() {
	//��ʼ������������
	this->initSpeech();

	//����12��ѡ��
	this->createSpeacher();

	//���������¼
	this->loadRecord();
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

	//����¼�������
	this->m_Record.clear();
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
	this->showScore();

	//�ڶ��ֿ�ʼ����
	this->m_Index++;
	//1.��ǩ
	this->speechDraw();
	//2.�ݽ�
	this->speechContest();
	//3.��ʾ���ս��
	this->showScore();
	//4.����������ļ���
	this->saveRecord();

	//���ñ�������ȡ��¼
	//��ʼ������������
	this->initSpeech();

	//����12��ѡ��
	this->createSpeacher();

	//���������¼
	this->loadRecord();

	cout << "����������!" << endl;
	system("pause");
	system("cls");
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

//��ʾ�÷�
void speechManager::showScore() {
	cout << "-------------------��" << this->m_Index << "�ֱ�������ѡ��----------------" << endl;

	vector<int> v;
	if (this->m_Index == 1) {
		v = vec2;
	}
	else {
		v = vecVictory;
	}

	for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		cout << "ѡ�ֱ�ţ�" << *it << "������" << this->m_Speaker[*it].m_Name << "�÷֣�" << this->m_Speaker[*it].m_Score[this->m_Index - 1] << endl;
	}
	cout << endl;

	system("pause");
	system("cls");
	this->show_Menu();
}

//�����¼
void speechManager::saveRecord() {
	ofstream ofs;
	ofs.open("speech.csv", ios::out | ios::app);//��׷�ӵķ�ʽд�ļ�

	//��ÿ��ѡ������д�뵽�ļ���
	for (vector<int>::iterator it = vecVictory.begin(); it != vecVictory.end(); it++) {
		ofs << *it << "," << this->m_Speaker[*it].m_Score[1] << ",";
	}
	ofs << endl;

	//�ر�
	ofs.close();
	cout << "�ļ���¼�Ѿ�����" << endl;

	//�����ļ���Ϊ�յ�״̬
	this->fileIsEmpty = false;
}

//��ȡ��¼
void speechManager::loadRecord() {
	ifstream ifs("speech.csv", ios::in);//���ļ�
	if (!ifs.is_open()) {
		this->fileIsEmpty = true;
		//cout << "�ļ�������" << endl;
		ifs.close();
		return;
	}

	//�ļ���յ����
	char ch;
	ifs >> ch;
	if (ifs.eof()) {
		//cout << "�ļ�Ϊ��" << endl;
		this->fileIsEmpty = true;
		ifs.close();
		return;
	}

	//�ļ���Ϊ��
	this->fileIsEmpty = false;
	ifs.putback(ch);//�������ȡ�ĵ����ַ��ٷŻ���

	string data;
	int  index = 0;//����

	while (ifs >> data) {
		//cout << data << endl;

		vector<string> v;//����ַ��� 6��

		int pos = -1;//�鵽,λ�õı���
		int start = 0;//��ʼλ��

		while (1) {
			pos = data.find(",", start);
			if (pos == -1) {//û�ҵ�
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
		cout << it->first << "�ھ���ţ�" << it->second[0] << "������" << it->second[1] << endl;
	}*/
}

//��ʾ�����¼
void speechManager::showRecord() {
	if (this->fileIsEmpty) {
		cout << "�ļ�Ϊ�ջ��ļ������ڣ�" << endl;
	}
	else {
		for (int i = 0; i < this->m_Record.size(); i++) {
			cout << "��" << i + 1 << "��" << endl;
			cout << "�ھ���ţ�" << this->m_Record[i][0] << "\t" << "�÷֣�" << this->m_Record[i][1] << endl;
			cout << "�Ǿ���ţ�" << this->m_Record[i][2] << "\t" << "�÷֣�" << this->m_Record[i][3] << endl;
			cout << "������ţ�" << this->m_Record[i][4] << "\t" << "�÷֣�" << this->m_Record[i][5] << endl;
		}
	}

	system("pause");
	system("cls");
}

//����ļ�
void speechManager::clearRecord() {
	cout << "�Ƿ�ȷ������ļ���" << endl;
	cout << "1.��" << "\t" << "2.��" << endl;

	int select = 0;

	cin >> select;
	if (select == 1) {
		ofstream ofs("speech.csv", ios::trunc);
		ofs.close();
		//��ʼ������������
		this->initSpeech();
		//����12��ѡ��
		this->createSpeacher();
		//���������¼
		this->loadRecord();
		cout << "������" << endl;
	}
	system("pause");
	system("cls");
}

//����
speechManager::~speechManager() {

}