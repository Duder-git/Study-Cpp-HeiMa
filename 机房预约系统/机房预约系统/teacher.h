#pragma once

#include<iostream>
using namespace std;
#include "identify.h"

class Teacher :public Identify
{
public:
	//Ĭ�Ϲ���
	Teacher();

	//�вι��� (ְ����ţ�����������)
	Teacher(int empId, string name, string pwd);

	//�˵�����
	virtual void operMenu();

	//�鿴����ԤԼ
	void showAllOrder();

	//���ԤԼ
	void validOrder();

	//��ʾ
	virtual void showMassage();

	// �˵�����
	void showMenu();

public:
	int m_EmpId; //��ʦ���
};