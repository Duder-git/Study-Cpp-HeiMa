#pragma once
#include<iostream>
using namespace std;

// ��ݳ�����
class Identify
{
public:
	// �����˵�
	virtual void operMenu() = 0;

	// ��ʾ�˵�
	virtual void showMenu() = 0;

	// չʾ
	virtual void showMassage() = 0;


public:
	string m_Name;	// ����
	string m_Pwd;	// ����

};