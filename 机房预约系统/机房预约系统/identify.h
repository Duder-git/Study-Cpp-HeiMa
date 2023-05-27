#pragma once
#include<iostream>
using namespace std;

// 身份抽象类
class Identify
{
public:
	// 操作菜单
	virtual void operMenu() = 0;

	// 显示菜单
	virtual void showMenu() = 0;

	// 展示
	virtual void showMassage() = 0;


public:
	string m_Name;	// 名字
	string m_Pwd;	// 密码

};