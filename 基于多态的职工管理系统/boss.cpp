#include "boss.h"

// 构造函数
Boss::Boss(int id, string name, int dId, int post)
{
	m_ID = id;
	m_Name = name;
	m_DeptID = dId;
	m_Post = post;
}

// 显示个人信息
void Boss::showInfo()
{
	cout << "职工编号： " << m_ID
		<< "\t职工姓名： " << m_Name
		<< "\t部门： " << m_DeptID
		<< "\t岗位： " << getDeptName()
		<< "\t岗位职责： " << getDeptDuty()
		<< endl;
}

// 获取岗位名称
string Boss::getDeptName()
{
	return string("老板");
}

// 获取岗位职责
string Boss::getDeptDuty()
{
	return string("管理公司所有事务");
}