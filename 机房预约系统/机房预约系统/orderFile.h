#pragma once
#include<iostream>
#include "globalFile.h"
#include<fstream>
#include<map>
using namespace std;


class OrderFile
{
public:
	friend class Student;
	friend class Teacher;
public:
	// 构造函数
	//OrderFile(int id, string name, int date = 0, int interval = 0, int room = 0, int status = 0);
	OrderFile();

	// 更新预约记录
	void updateOrder();

	// 写入预约信息
	//void writeOrder();

	// 读入
	void initOderFile();

	// 分割函数
	pair<string, string> sparator(string date);

	// 写入
	void writeOrderFile();

	// 展示所有数据
	void showAllOrder();


public:
	// 记录的容器 
	//		key   --- 记录条数
	//		value --- 具体记录的信息
	//			[1] --- 说明
	//			[2] --- 数值
	map<int, map<string, string>> m_orderData;
	int m_Size;		// 预约记录条数

};


// 输出
void printOrder(map<string, string>& m);