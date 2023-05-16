#pragma once
#include <iostream>
#include <string>
using namespace std;
#include "worker.h"

// 普通员工文件

class Employee :public Worker
{
public:
	// 构造函数
	Employee(int id, string name, int dId, int Post);

	// 显示个人信息
	void showInfo();

	// 获取岗位名称
	string getDeptName();

	// 获取岗位职责
	string getDeptDuty();
};