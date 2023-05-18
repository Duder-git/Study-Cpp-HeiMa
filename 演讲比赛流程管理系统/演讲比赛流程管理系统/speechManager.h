#pragma once

#include<iostream>
#include<vector>
#include<map>
#include "speaker.h"
using namespace std;

// 演讲管理类
class SpeechManager
{
public:
	// 构造函数
	SpeechManager();

	// 展示菜单
	void show_Menu();

	// 退出系统
	void exitSystem();

	// 初始化属性
	void initSpeech();

	// 创建选手
	void createSpeaker();

	// 开始比赛-比赛流程控制
	void startSpeech();

	// 读取往届记录
	void loadRecord();

	//显示往届记录
	void showRecord();

	//清除数据
	void clearRecord();

	// 析构函数
	~SpeechManager();

private:
	// 抽签
	void _speechDraw();

	// 比赛（打分）
	void _speechContset();

	// 显示比赛分数
	void _showScore();

	// 保存记录
	void _saveRecord();

public:
	//比赛选手 容器  12人
	vector<int>v1;

	//第一轮晋级容器  6人
	vector<int>v2;

	//胜利前三名容器  3人
	vector<int>vVictory;

	//存放编号 以及对应的 具体选手 容器
	map<int, Speaker> m_Speaker;

	//比赛轮次
	int m_Index;

	//文件为空标志
	bool fileIsEmpty;

	//往届记录
	//map<int, vector<string>> m_Record;
	multimap<int, vector<string>> m_Record;


};

