#include "manager.h"

// 构造函数
Manager::Manager(int id, string name, int dId, int post)
{
	m_ID = id;
	m_Name = name;
	m_DeptID = dId;
	m_Post = post;
}

// 显示个人信息
void Manager::showInfo()
{
	cout << "职工编号： " << m_ID
		<< "\t职工姓名： " << m_Name
		<< "\t部门： " << m_DeptID
		<< "\t岗位： " << getDeptName()
		<< "\t岗位职责： " << getDeptDuty()
		<< endl;
}

// 获取岗位名称
string Manager::getDeptName()
{
	return string("经理");
}

// 获取岗位职责
string Manager::getDeptDuty()
{
	return string("完成老板交给的任务，并管理员工");
}