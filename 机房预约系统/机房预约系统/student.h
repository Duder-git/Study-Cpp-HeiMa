#pragma once
#include<iostream>
#include<vector>
#include<map>
#include<fstream>
using namespace std;
#include "identify.h"
#include "computerRoom.h"
#include "globalFile.h"
#include "orderFile.h"


// 学生类
class Student : public Identify
{
public:
	// 默认构造函数
	Student();

	// 有参构造
	Student(int id, string name, string pwd);

	// 菜单管理
	void showMenu();

	// 菜单界面
	virtual void operMenu();

	// 申请预约
	void applyOrder();

	// 查看预约状态
	void showMyOrder();

	void showAllOrder();

	// 取消预约
	void cancelOrder();
	
	// 输出
	virtual void showMassage();


	// 初始化容器
	void initVector();

	// 写入预约文件
	void writeMassage(int date, int interval, int room, bool status);

	// 输出Order
	//void printOrder(map<string, string>& m);

public:
	// 学生学号
	int m_Id;

	// 机房容器
	vector<ComputerRoom> vCom;


	// 姓名
	//string m_Name; 基类里有

	// 密码
	// string m_Pwd; 基类里有
};