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
	// ���캯��
	//OrderFile(int id, string name, int date = 0, int interval = 0, int room = 0, int status = 0);
	OrderFile();

	// ����ԤԼ��¼
	void updateOrder();

	// д��ԤԼ��Ϣ
	//void writeOrder();

	// ����
	void initOderFile();

	// �ָ��
	pair<string, string> sparator(string date);

	// д��
	void writeOrderFile();

	// չʾ��������
	void showAllOrder();


public:
	// ��¼������ 
	//		key   --- ��¼����
	//		value --- �����¼����Ϣ
	//			[1] --- ˵��
	//			[2] --- ��ֵ
	map<int, map<string, string>> m_orderData;
	int m_Size;		// ԤԼ��¼����

};


// ���
void printOrder(map<string, string>& m);