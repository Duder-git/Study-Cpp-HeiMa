#pragma once // ��֤ͷ�ļ�ֻ����һ��
#include <iostream>
#include <string>
using namespace std;

// ְ��������
class Worker
{
public:
	// ��ʾ������Ϣ
	virtual void showInfo() = 0;

	// ��ȡ��λ����
	virtual string getDeptName() = 0;

	// ��ȡ��λְ��
	virtual string getDeptDuty() = 0;


	// ����
	int m_ID;		// ְ�����
	string m_Name;	// ְ������
	int m_DeptID;	// ���ű��
	int m_Post;	    // ��λ 1 ְ�� 2 ���� 3 �ϰ�

};