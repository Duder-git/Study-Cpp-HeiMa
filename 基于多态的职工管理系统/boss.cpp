#include "boss.h"

// ���캯��
Boss::Boss(int id, string name, int dId, int post)
{
	m_ID = id;
	m_Name = name;
	m_DeptID = dId;
	m_Post = post;
}

// ��ʾ������Ϣ
void Boss::showInfo()
{
	cout << "ְ����ţ� " << m_ID
		<< "\tְ�������� " << m_Name
		<< "\t���ţ� " << m_DeptID
		<< "\t��λ�� " << getDeptName()
		<< "\t��λְ�� " << getDeptDuty()
		<< endl;
}

// ��ȡ��λ����
string Boss::getDeptName()
{
	return string("�ϰ�");
}

// ��ȡ��λְ��
string Boss::getDeptDuty()
{
	return string("����˾��������");
}