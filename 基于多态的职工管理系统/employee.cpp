#include "employee.h"

// ���캯��
//Employee::Employee(int id, string name, int dId) :m_ID(id), m_Name(name), m_DeptID(dId){}
Employee::Employee(int id, string name, int dId, int post)
{
	m_ID = id;
	m_Name = name;
	m_DeptID = dId;
	m_Post = post;
}

// ��ʾ������Ϣ
void Employee::showInfo()
{
	cout << "ְ����ţ� " << m_ID
		<< "\tְ�������� " << m_Name
		<< "\t���ţ� " << m_DeptID
		<< "\t��λ�� " << getDeptName()
		<< "\t��λְ�� " << getDeptDuty() 
		<< endl;
}

// ��ȡ��λ����
string Employee::getDeptName()
{
	return string("Ա��");
}

string Employee::getDeptDuty()
{
	return string("��ɾ�����������");
}