#include <Windows.h>
#include "speechManager.h"
#include <algorithm>

void print1(pair<int, Speaker> p)
{
	cout << "ѡ�ֱ�ţ�" << p.first
		<< " ������ " << p.second.m_Name
		<< " �ɼ��� " << p.second.m_Score[0] << endl;
}

void test()
{
	SpeechManager sm;
	
	for (map<int, Speaker>::iterator it = sm.m_Speaker.begin(); it != sm.m_Speaker.end(); it++)
	{
		cout << "ѡ�ֱ�ţ�" << it->first
			<< " ������ " << it->second.m_Name
			<< " �ɼ��� " << it->second.m_Score[0] << endl;
	}
	// ʹ��for_each��ʽ����
	//cout << "-----------------------------------------" << endl;
	//for_each(sm.m_Speaker.begin(),sm.m_Speaker.end(), print1);
}

void Task()
{
	SpeechManager sm;
	int choice = 0;
	while (true)
	{
		sm.show_Menu();

		cout << "����ѡ��" << endl;
		cin >> choice;

		switch (choice)
		{
		case 1:	// ��ʼ����
			sm.startSpeech();
			break;
		case 2: // �鿴��¼
			sm.showRecord();
			break;
		case 3: // ��ձ�����¼
			sm.clearRecord();
			break;
		case 0: // �˳� 
			sm.exitSystem();
			break;
		default:
			cout << "�����������������!" << endl;
			Sleep(1000);
			system("cls");
			break;
		}
	}
}

int main()
{
	// ���������
	srand((unsigned int)time(NULL));
	//test();
	Task();

	system("pause");
	return 0;
}