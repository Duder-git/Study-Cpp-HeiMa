#include "speechManager.h"
#include <algorithm>
#include <deque>
#include <numeric>
#include <iostream>
#include <fstream>
SpeechManager::SpeechManager()
{
	// 初始化演讲系统
	initSpeech();

	// 创建选手
	createSpeaker();

	// 获取往届记录
	loadRecord();
}


void SpeechManager::show_Menu()
{
	cout << "********************************************" << endl;
	cout << "************* 欢迎参加演讲比赛 *************" << endl;
	cout << "*************  1.开始演讲比赛  *************" << endl;
	cout << "*************  2.查看往届记录  *************" << endl;
	cout << "*************  3.清空比赛记录  *************" << endl;
	cout << "*************  0.退出比赛程序  *************" << endl;
	cout << "********************************************" << endl;
	cout << endl;
}


void SpeechManager::exitSystem()
{
	cout << "欢迎下次使用" << endl;
	system("pause");
	exit(0);
}

void SpeechManager::initSpeech()
{
	// 容器保证为空
	v1.clear();
	v2.clear();
	vVictory.clear();
	m_Speaker.clear();

	// 初始化比赛轮数
	m_Index = 1;

	// 初始化记录容器
	m_Record.clear();  // 当m_Record为map时，由于特性无需初始化
}

void SpeechManager::createSpeaker()
{
	string nameSeed = "ABCDEFGHIJKL"; // 12人
	for (int i = 0; i < nameSeed.size(); i++)
	{
		string name = "选手";
		name += nameSeed[i];

		Speaker sp;
		sp.m_Name = name;
		for (int i = 0; i < 2; i++)
		{
			sp.m_Score[i] = 0;
		}

		v1.push_back(i + 10001);

		m_Speaker.insert(make_pair(i + 10001, sp));


	}
}

void SpeechManager::startSpeech()
{
	system("cls");
	//第一轮比赛
	// 1 抽签
	_speechDraw();
	// 2 比赛(打分）
	_speechContset();
	// 3 展示晋级结果
	_showScore();
	//第二轮比赛
	m_Index++;
	// 1 抽签
	_speechDraw();
	// 2 比赛(打分）
	_speechContset();
	// 3 显示最终结果
	_showScore();
	// 4 保存分数
	_saveRecord();

	// 5 比赛完毕重置系统
		// 初始化演讲系统
		initSpeech();
		// 创建选手
		createSpeaker();
		// 读取数据到程序中
		loadRecord();

	cout << "本届比赛完毕！" << endl;
	system("pause");
	system("cls");
}

SpeechManager::~SpeechManager()
{

}


void print2(int v)
{
	cout << v << " ";
}


// Private
void SpeechManager::_speechDraw()
{
	cout << "------------- 第" << m_Index << "轮比赛 选手正在抽签------------- " << endl;
	cout << "---------------------------" << endl;
	cout << "抽签后演讲顺序:" << endl;
	// 第一轮比赛
	if (m_Index == 1)
	{
		// 随机打乱
		random_shuffle(v1.begin(), v1.end());
		for (vector<int>::iterator it = v1.begin(); it != v1.end(); it++)
		{
			cout << *it << " ";
		}
		//for_each(v1.begin(), v1.end(), print2);
		cout << endl;
	}
	else if (m_Index == 2)
	{
		// 随机打乱
		random_shuffle(v2.begin(), v2.end());
		for (vector<int>::iterator it = v2.begin(); it != v2.end(); it++)
		{
			cout << *it << " ";
		}
		//for_each(v2.begin(), v2.end(), print2);
		cout << endl;
	}
	cout << "---------------------------" << endl;

	system("pause");
	cout << endl;
}



void SpeechManager::_speechContset()
{
	cout << "------------- 第" << m_Index << "轮正式比赛开始------------- " << endl;
	multimap<double, int, greater<int>> groupScore;// 临时容器，保存key分数 value选手编号
	int num = 0; // 记录人员数，6个为一组

	vector<int> v_Src;	// 比赛人员容器
	if (m_Index == 1)
	{
		v_Src = v1;
	}
	else if (m_Index == 2)
	{
		v_Src = v2;
	}

	// 遍历所有参赛选手
	for (vector<int>::iterator it = v_Src.begin(); it != v_Src.end(); it++)
	{
		num++;

		// 评委打分
		deque<double>d;
		for (int i = 0; i < 10; i++)  // 评委人数 10人
		{
			double score;
			if (m_Index == 1)
			{
				score = (rand() % 401 + 600) / 10.f;
			}
			else if (m_Index == 2)
			{
				score = (rand() % 201 + 800) / 10.f;
			}
			//double score = (rand() % 401 + 600) / 10.f;
			//cout << score << "";
			d.push_back(score);
		}
		sort(d.begin(), d.end(),greater<double>());
		d.pop_front();
		d.pop_back();

		double sum = accumulate(d.begin(), d.end(), 0.0f);
		double avg = sum / (double)d.size();
		m_Speaker[*it].m_Score[m_Index - 1] = avg;


		// 六人一小组，用临时容器保存，取前三名晋级
		groupScore.insert(make_pair(avg, *it));
		if (num % 6 == 0)
		{
			cout << "第" << num / 6 << "小组比赛名次：" << endl;
			for (multimap<double, int, greater<int>>::iterator it = groupScore.begin(); it != groupScore.end(); ++it)
			{
				cout << "编号：" << it->second << "\t姓名：" 
					<< m_Speaker[it->second].m_Name << "\t得分：" << m_Speaker[it->second].m_Score[m_Index - 1] << endl;
			}

			int count = 0;
			//取前三名
			for (multimap<double, int, greater<int>>::iterator it = groupScore.begin(); it != groupScore.end() && count < 3; it++, count++)
			{
				if (m_Index == 1)
				{
					v2.push_back((*it).second);
				}
				else if (m_Index == 2)
				{
					vVictory.push_back((*it).second);
				}
			}
			groupScore.clear();
			cout << endl;
		}
	}
	cout << "------------- 第" << m_Index << "轮比赛完毕  ------------- " << endl;
	system("pause");
	cout << endl;
}

void SpeechManager::_showScore()
{
	cout << "---------第" << m_Index << "轮晋级选手信息如下：-----------" << endl;
	vector<int>v;
	if (m_Index == 1){
		v = v2;
	}
	else if (m_Index == 2) {
		v = vVictory;
	}

	sort(v.begin(), v.end(), greater<double>());
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << "编号：" << *it << "\t姓名：" << m_Speaker[*it].m_Name << "\t得分：" << m_Speaker[*it].m_Score[m_Index - 1] << endl;
	}
	system("pause");
	cout << endl;
	system("cls");
	//show_Menu();
}

void SpeechManager::_saveRecord()
{
	ofstream ofs;
	ofs.open("speech.csv", ios::out | ios::app); // 用输出的方式打开文件 --写文件

	// 写入每个人数据
	for (vector<int>::iterator it = vVictory.begin(); it != vVictory.end(); it++)
	{
		ofs << *it << "," << m_Speaker[*it].m_Score[1] << ",";
	}
	ofs << endl;

	// 关闭文件
	ofs.close();

	cout << "记录已经保存！" << endl;

	fileIsEmpty = false; // 更新文件标志

}


void SpeechManager::loadRecord()
{
	ifstream ifs("speech.csv", ios::in); // 输入流对象

	// 打开失败
	if (!ifs.is_open())
	{
		fileIsEmpty = true;
		cout << "文件不存在！" << endl;
		ifs.close();
		return;
	}

	// 文件为空
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		cout << "文件为空！" << endl;
		fileIsEmpty = true;
		ifs.close();
		return;
	}

	// 文件不为空
	fileIsEmpty = false;
	ifs.putback(ch);	// 读取的单个字符放回去

	string data;
	int index = 0;
	while (ifs >> data) // 一次读一行
	{
		//cout << data << endl;
		vector<string>v;

		int pos = -1;
		int start = 0;

		while (true) // 一次读一个字符
		{
			pos = data.find(",", start); // 从0开始找','
			if (pos == -1)
			{
				break;	// 找不到
			}
			string tmp = data.substr(start, pos - start); // 找到 进行分割
			v.push_back(tmp);
			start = pos + 1;
		}
		m_Record.insert(make_pair(index, v));
		index++;
	}
	ifs.close();
}

//显示往届记录
void SpeechManager::showRecord()
{
	if (fileIsEmpty)
	{
		cout << "文件不存在或者记录为空！" << endl;
	}
	else
	{
	// 适配map 输出
	//for (int i = 0; i < m_Record.size(); i++)
	//{
	//	cout << "--------------第" << i + 1 << "届比赛---------------" << endl;
	//	cout << "冠军\t编号：" << m_Record[i][0] << "\t得分：" << m_Record[i][1] << endl;
	//	cout << "亚军\t编号：" << m_Record[i][2] << "\t得分：" << m_Record[i][3] << endl;
	//	cout << "季军\t编号：" << m_Record[i][4] << "\t得分：" << m_Record[i][5] << endl;
	//	cout << "--------------------------------------------" << endl;
	//}

	// 适配multimap 或者 map输出
	for (multimap<int, vector<string>>::iterator it = m_Record.begin(); it != m_Record.end(); it++)
	{
		cout << "--------------第" << it->first+1 << "届比赛---------------" << endl;
		cout << "冠军\t编号：" << it->second[0] << "\t得分：" << it->second[1] << endl;
		cout << "亚军\t编号：" << it->second[2] << "\t得分：" << it->second[3] << endl;
		cout << "季军\t编号：" << it->second[4] << "\t得分：" << it->second[5] << endl;
		cout << "--------------------------------------------" << endl;
	}

	}
	system("pause");
	system("cls");
}


//清除数据
void SpeechManager::clearRecord()
{
	cout << "确认清空所有数据？" << endl;
	cout << "1. 确认" << endl;
	cout << "2. 返回" << endl;

	int select = 0;
	cin >> select;

	if (select == 1)
	{
		//打开模式 ios::trunc 如果存在删除文件并重新创建
		ofstream ofs("speech.csv", ios::trunc);
		ofs.close();

		// 初始化演讲系统
		initSpeech();
		// 创建选手
		createSpeaker();
		// 读取数据到程序中
		loadRecord();

		cout << "清空成功！" << endl;
	}

	system("pause");
	system("cls");
}