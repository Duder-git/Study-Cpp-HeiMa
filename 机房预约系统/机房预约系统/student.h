#pragma once
#include<iostream>
#include<vector>
#include<map>
#include<fstream>
using namespace std;
#include "identify.h"
#include "computerRoom.h"
#include "globalFile.h"
#include "orderFile.h"


// ѧ����
class Student : public Identify
{
public:
	// Ĭ�Ϲ��캯��
	Student();

	// �вι���
	Student(int id, string name, string pwd);

	// �˵�����
	void showMenu();

	// �˵�����
	virtual void operMenu();

	// ����ԤԼ
	void applyOrder();

	// �鿴ԤԼ״̬
	void showMyOrder();

	void showAllOrder();

	// ȡ��ԤԼ
	void cancelOrder();
	
	// ���
	virtual void showMassage();


	// ��ʼ������
	void initVector();

	// д��ԤԼ�ļ�
	void writeMassage(int date, int interval, int room, bool status);

	// ���Order
	//void printOrder(map<string, string>& m);

public:
	// ѧ��ѧ��
	int m_Id;

	// ��������
	vector<ComputerRoom> vCom;


	// ����
	//string m_Name; ��������

	// ����
	// string m_Pwd; ��������
};