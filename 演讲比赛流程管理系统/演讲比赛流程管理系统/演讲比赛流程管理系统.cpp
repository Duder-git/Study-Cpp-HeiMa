#include <Windows.h>
#include "speechManager.h"
#include <algorithm>

void print1(pair<int, Speaker> p)
{
	cout << "选手编号：" << p.first
		<< " 姓名： " << p.second.m_Name
		<< " 成绩： " << p.second.m_Score[0] << endl;
}

void test()
{
	SpeechManager sm;
	
	for (map<int, Speaker>::iterator it = sm.m_Speaker.begin(); it != sm.m_Speaker.end(); it++)
	{
		cout << "选手编号：" << it->first
			<< " 姓名： " << it->second.m_Name
			<< " 成绩： " << it->second.m_Score[0] << endl;
	}
	// 使用for_each方式遍历
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

		cout << "输入选择：" << endl;
		cin >> choice;

		switch (choice)
		{
		case 1:	// 开始比赛
			sm.startSpeech();
			break;
		case 2: // 查看记录
			sm.showRecord();
			break;
		case 3: // 清空比赛记录
			sm.clearRecord();
			break;
		case 0: // 退出 
			sm.exitSystem();
			break;
		default:
			cout << "输入错误，请重新输入!" << endl;
			Sleep(1000);
			system("cls");
			break;
		}
	}
}

int main()
{
	// 随机数种子
	srand((unsigned int)time(NULL));
	//test();
	Task();

	system("pause");
	return 0;
}