#pragma once
#include <iostream>
#include <string>
using namespace std;
#include "worker.h"

// ��ͨԱ���ļ�

class Employee :public Worker
{
public:
	// ���캯��
	Employee(int id, string name, int dId, int Post);

	// ��ʾ������Ϣ
	void showInfo();

	// ��ȡ��λ����
	string getDeptName();

	// ��ȡ��λְ��
	string getDeptDuty();
};