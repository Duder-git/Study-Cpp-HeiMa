#pragma once
#include <iostream>
#include <string>
using namespace std; 
#include "worker.h"

// ������
class Manager :public Worker
{
public:
	// ���캯��
	Manager(int id, string name, int dId,int post);

	// ��ʾ������Ϣ
	void showInfo();

	// ��ȡ��λ����
	string getDeptName();

	// ��ȡ��λְ��
	string getDeptDuty();
};

