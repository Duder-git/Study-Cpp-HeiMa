#include "manager.h"

// ���캯��
Manager::Manager(int id, string name, int dId, int post)
{
	m_ID = id;
	m_Name = name;
	m_DeptID = dId;
	m_Post = post;
}

// ��ʾ������Ϣ
void Manager::showInfo()
{
	cout << "ְ����ţ� " << m_ID
		<< "\tְ�������� " << m_Name
		<< "\t���ţ� " << m_DeptID
		<< "\t��λ�� " << getDeptName()
		<< "\t��λְ�� " << getDeptDuty()
		<< endl;
}

// ��ȡ��λ����
string Manager::getDeptName()
{
	return string("����");
}

// ��ȡ��λְ��
string Manager::getDeptDuty()
{
	return string("����ϰ彻�������񣬲�����Ա��");
}