#pragma once
#include <iostream>
#include <string>
using namespace std;
#include "worker.h"

// �ϰ���
class Boss :public Worker
{
public:
	// ���캯��
	Boss(int id, string name, int dId, int post);

	// ��ʾ������Ϣ
	void showInfo();

	// ��ȡ��λ����
	string getDeptName();

	// ��ȡ��λְ��
	string getDeptDuty();
};

