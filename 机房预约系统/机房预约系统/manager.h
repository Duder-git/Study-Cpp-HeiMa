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
	//默认构造
	Manager();

	//有参构造  管理员姓名，密码
	Manager(string name, string pwd);

	//选择菜单
	virtual void operMenu();

	//添加账号  
	void addPerson();

	//查看账号
	void showPerson();

	//查看机房信息
	void showComputer();

	//清空预约记录
	void cleanFile();

	//菜单
	void showMenu();

	//检测重复
	bool checkRepeat(int id, int type);

	// 显示
	void showMassage();

public:
	//初始化容器
	void initVector();

	//学生容器
	vector<Student> vStu;

	//教师容器
	vector<Teacher> vTea;

	// 机房容器
	vector<ComputerRoom> vCom;


};


void printStudent(Student& s);
void printTeacher(Teacher& t);
