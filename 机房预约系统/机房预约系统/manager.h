#pragma once
#include<iostream>
#include<vector>
using namespace std;
#include "identify.h"
#include "student.h"
#include "teacher.h"
#include "computerRoom.h"

class Manager :public Identify
{
public:
	//Ĭ�Ϲ���
	Manager();

	//�вι���  ����Ա����������
	Manager(string name, string pwd);

	//ѡ��˵�
	virtual void operMenu();

	//����˺�  
	void addPerson();

	//�鿴�˺�
	void showPerson();

	//�鿴������Ϣ
	void showComputer();

	//���ԤԼ��¼
	void cleanFile();

	//�˵�
	void showMenu();

	//����ظ�
	bool checkRepeat(int id, int type);

	// ��ʾ
	void showMassage();

public:
	//��ʼ������
	void initVector();

	//ѧ������
	vector<Student> vStu;

	//��ʦ����
	vector<Teacher> vTea;

	// ��������
	vector<ComputerRoom> vCom;


};


void printStudent(Student& s);
void printTeacher(Teacher& t);
