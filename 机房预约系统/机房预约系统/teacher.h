#pragma once

#include<iostream>
using namespace std;
#include "identify.h"

class Teacher :public Identify
{
public:
	//默认构造
	Teacher();

	//有参构造 (职工编号，姓名，密码)
	Teacher(int empId, string name, string pwd);

	//菜单界面
	virtual void operMenu();

	//查看所有预约
	void showAllOrder();

	//审核预约
	void validOrder();

	//显示
	virtual void showMassage();

	// 菜单管理
	void showMenu();

public:
	int m_EmpId; //教师编号
};