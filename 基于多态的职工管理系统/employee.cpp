#include "employee.h"

// 构造函数
//Employee::Employee(int id, string name, int dId) :m_ID(id), m_Name(name), m_DeptID(dId){}
Employee::Employee(int id, string name, int dId, int post)
{
	m_ID = id;
	m_Name = name;
	m_DeptID = dId;
	m_Post = post;
}

// 显示个人信息
void Employee::showInfo()
{
	cout << "职工编号： " << m_ID
		<< "\t职工姓名： " << m_Name
		<< "\t部门： " << m_DeptID
		<< "\t岗位： " << getDeptName()
		<< "\t岗位职责： " << getDeptDuty() 
		<< endl;
}

// 获取岗位名称
string Employee::getDeptName()
{
	return string("员工");
}

string Employee::getDeptDuty()
{
	return string("完成经理交给的任务");
}