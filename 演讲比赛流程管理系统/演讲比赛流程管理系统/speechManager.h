#pragma once

#include<iostream>
#include<vector>
#include<map>
#include "speaker.h"
using namespace std;

// �ݽ�������
class SpeechManager
{
public:
	// ���캯��
	SpeechManager();

	// չʾ�˵�
	void show_Menu();

	// �˳�ϵͳ
	void exitSystem();

	// ��ʼ������
	void initSpeech();

	// ����ѡ��
	void createSpeaker();

	// ��ʼ����-�������̿���
	void startSpeech();

	// ��ȡ�����¼
	void loadRecord();

	//��ʾ�����¼
	void showRecord();

	//�������
	void clearRecord();

	// ��������
	~SpeechManager();

private:
	// ��ǩ
	void _speechDraw();

	// ��������֣�
	void _speechContset();

	// ��ʾ��������
	void _showScore();

	// �����¼
	void _saveRecord();

public:
	//����ѡ�� ����  12��
	vector<int>v1;

	//��һ�ֽ�������  6��
	vector<int>v2;

	//ʤ��ǰ��������  3��
	vector<int>vVictory;

	//��ű�� �Լ���Ӧ�� ����ѡ�� ����
	map<int, Speaker> m_Speaker;

	//�����ִ�
	int m_Index;

	//�ļ�Ϊ�ձ�־
	bool fileIsEmpty;

	//�����¼
	//map<int, vector<string>> m_Record;
	multimap<int, vector<string>> m_Record;


};

