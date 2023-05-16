#pragma once // 保证头文件只编译一次
#include <iostream>
#include <string>
using namespace std;

// 职工抽象类
class Worker
{
public:
	// 显示个人信息
	virtual void showInfo() = 0;

	// 获取岗位名称
	virtual string getDeptName() = 0;

	// 获取岗位职责
	virtual string getDeptDuty() = 0;


	// 属性
	int m_ID;		// 职工编号
	string m_Name;	// 职工姓名
	int m_DeptID;	// 部门编号
	int m_Post;	    // 岗位 1 职工 2 经理 3 老板

};