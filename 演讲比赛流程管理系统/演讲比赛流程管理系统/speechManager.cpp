#include "speechManager.h"
#include <algorithm>
#include <deque>
#include <numeric>
#include <iostream>
#include <fstream>
SpeechManager::SpeechManager()
{
	// ��ʼ���ݽ�ϵͳ
	initSpeech();

	// ����ѡ��
	createSpeaker();

	// ��ȡ�����¼
	loadRecord();
}


void SpeechManager::show_Menu()
{
	cout << "********************************************" << endl;
	cout << "************* ��ӭ�μ��ݽ����� *************" << endl;
	cout << "*************  1.��ʼ�ݽ�����  *************" << endl;
	cout << "*************  2.�鿴�����¼  *************" << endl;
	cout << "*************  3.��ձ�����¼  *************" << endl;
	cout << "*************  0.�˳���������  *************" << endl;
	cout << "********************************************" << endl;
	cout << endl;
}


void SpeechManager::exitSystem()
{
	cout << "��ӭ�´�ʹ��" << endl;
	system("pause");
	exit(0);
}

void SpeechManager::initSpeech()
{
	// ������֤Ϊ��
	v1.clear();
	v2.clear();
	vVictory.clear();
	m_Speaker.clear();

	// ��ʼ����������
	m_Index = 1;

	// ��ʼ����¼����
	m_Record.clear();  // ��m_RecordΪmapʱ���������������ʼ��
}

void SpeechManager::createSpeaker()
{
	string nameSeed = "ABCDEFGHIJKL"; // 12��
	for (int i = 0; i < nameSeed.size(); i++)
	{
		string name = "ѡ��";
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
	//��һ�ֱ���
	// 1 ��ǩ
	_speechDraw();
	// 2 ����(��֣�
	_speechContset();
	// 3 չʾ�������
	_showScore();
	//�ڶ��ֱ���
	m_Index++;
	// 1 ��ǩ
	_speechDraw();
	// 2 ����(��֣�
	_speechContset();
	// 3 ��ʾ���ս��
	_showScore();
	// 4 �������
	_saveRecord();

	// 5 �����������ϵͳ
		// ��ʼ���ݽ�ϵͳ
		initSpeech();
		// ����ѡ��
		createSpeaker();
		// ��ȡ���ݵ�������
		loadRecord();

	cout << "���������ϣ�" << endl;
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
	cout << "------------- ��" << m_Index << "�ֱ��� ѡ�����ڳ�ǩ------------- " << endl;
	cout << "---------------------------" << endl;
	cout << "��ǩ���ݽ�˳��:" << endl;
	// ��һ�ֱ���
	if (m_Index == 1)
	{
		// �������
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
		// �������
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
	cout << "------------- ��" << m_Index << "����ʽ������ʼ------------- " << endl;
	multimap<double, int, greater<int>> groupScore;// ��ʱ����������key���� valueѡ�ֱ��
	int num = 0; // ��¼��Ա����6��Ϊһ��

	vector<int> v_Src;	// ������Ա����
	if (m_Index == 1)
	{
		v_Src = v1;
	}
	else if (m_Index == 2)
	{
		v_Src = v2;
	}

	// �������в���ѡ��
	for (vector<int>::iterator it = v_Src.begin(); it != v_Src.end(); it++)
	{
		num++;

		// ��ί���
		deque<double>d;
		for (int i = 0; i < 10; i++)  // ��ί���� 10��
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


		// ����һС�飬����ʱ�������棬ȡǰ��������
		groupScore.insert(make_pair(avg, *it));
		if (num % 6 == 0)
		{
			cout << "��" << num / 6 << "С��������Σ�" << endl;
			for (multimap<double, int, greater<int>>::iterator it = groupScore.begin(); it != groupScore.end(); ++it)
			{
				cout << "��ţ�" << it->second << "\t������" 
					<< m_Speaker[it->second].m_Name << "\t�÷֣�" << m_Speaker[it->second].m_Score[m_Index - 1] << endl;
			}

			int count = 0;
			//ȡǰ����
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
	cout << "------------- ��" << m_Index << "�ֱ������  ------------- " << endl;
	system("pause");
	cout << endl;
}

void SpeechManager::_showScore()
{
	cout << "---------��" << m_Index << "�ֽ���ѡ����Ϣ���£�-----------" << endl;
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
		cout << "��ţ�" << *it << "\t������" << m_Speaker[*it].m_Name << "\t�÷֣�" << m_Speaker[*it].m_Score[m_Index - 1] << endl;
	}
	system("pause");
	cout << endl;
	system("cls");
	//show_Menu();
}

void SpeechManager::_saveRecord()
{
	ofstream ofs;
	ofs.open("speech.csv", ios::out | ios::app); // ������ķ�ʽ���ļ� --д�ļ�

	// д��ÿ��������
	for (vector<int>::iterator it = vVictory.begin(); it != vVictory.end(); it++)
	{
		ofs << *it << "," << m_Speaker[*it].m_Score[1] << ",";
	}
	ofs << endl;

	// �ر��ļ�
	ofs.close();

	cout << "��¼�Ѿ����棡" << endl;

	fileIsEmpty = false; // �����ļ���־

}


void SpeechManager::loadRecord()
{
	ifstream ifs("speech.csv", ios::in); // ����������

	// ��ʧ��
	if (!ifs.is_open())
	{
		fileIsEmpty = true;
		cout << "�ļ������ڣ�" << endl;
		ifs.close();
		return;
	}

	// �ļ�Ϊ��
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		cout << "�ļ�Ϊ�գ�" << endl;
		fileIsEmpty = true;
		ifs.close();
		return;
	}

	// �ļ���Ϊ��
	fileIsEmpty = false;
	ifs.putback(ch);	// ��ȡ�ĵ����ַ��Ż�ȥ

	string data;
	int index = 0;
	while (ifs >> data) // һ�ζ�һ��
	{
		//cout << data << endl;
		vector<string>v;

		int pos = -1;
		int start = 0;

		while (true) // һ�ζ�һ���ַ�
		{
			pos = data.find(",", start); // ��0��ʼ��','
			if (pos == -1)
			{
				break;	// �Ҳ���
			}
			string tmp = data.substr(start, pos - start); // �ҵ� ���зָ�
			v.push_back(tmp);
			start = pos + 1;
		}
		m_Record.insert(make_pair(index, v));
		index++;
	}
	ifs.close();
}

//��ʾ�����¼
void SpeechManager::showRecord()
{
	if (fileIsEmpty)
	{
		cout << "�ļ������ڻ��߼�¼Ϊ�գ�" << endl;
	}
	else
	{
	// ����map ���
	//for (int i = 0; i < m_Record.size(); i++)
	//{
	//	cout << "--------------��" << i + 1 << "�����---------------" << endl;
	//	cout << "�ھ�\t��ţ�" << m_Record[i][0] << "\t�÷֣�" << m_Record[i][1] << endl;
	//	cout << "�Ǿ�\t��ţ�" << m_Record[i][2] << "\t�÷֣�" << m_Record[i][3] << endl;
	//	cout << "����\t��ţ�" << m_Record[i][4] << "\t�÷֣�" << m_Record[i][5] << endl;
	//	cout << "--------------------------------------------" << endl;
	//}

	// ����multimap ���� map���
	for (multimap<int, vector<string>>::iterator it = m_Record.begin(); it != m_Record.end(); it++)
	{
		cout << "--------------��" << it->first+1 << "�����---------------" << endl;
		cout << "�ھ�\t��ţ�" << it->second[0] << "\t�÷֣�" << it->second[1] << endl;
		cout << "�Ǿ�\t��ţ�" << it->second[2] << "\t�÷֣�" << it->second[3] << endl;
		cout << "����\t��ţ�" << it->second[4] << "\t�÷֣�" << it->second[5] << endl;
		cout << "--------------------------------------------" << endl;
	}

	}
	system("pause");
	system("cls");
}


//�������
void SpeechManager::clearRecord()
{
	cout << "ȷ������������ݣ�" << endl;
	cout << "1. ȷ��" << endl;
	cout << "2. ����" << endl;

	int select = 0;
	cin >> select;

	if (select == 1)
	{
		//��ģʽ ios::trunc �������ɾ���ļ������´���
		ofstream ofs("speech.csv", ios::trunc);
		ofs.close();

		// ��ʼ���ݽ�ϵͳ
		initSpeech();
		// ����ѡ��
		createSpeaker();
		// ��ȡ���ݵ�������
		loadRecord();

		cout << "��ճɹ���" << endl;
	}

	system("pause");
	system("cls");
}