#include "orderFile.h"



OrderFile::OrderFile()
{
	initOderFile();
}

void OrderFile::updateOrder()
{
	writeOrderFile();
	initOderFile();
}


void OrderFile::initOderFile()
{
	m_Size = 0;

	string date;		//����
	string interval;	//ʱ���
	string stuId;		//ѧ�����
	string stuName;		//ѧ������
	string roomId;		//�������
	string status;		//ԤԼ״̬

	ifstream ifs;
	ifs.open(ORDER_FILE, ios::in);
	while (ifs >> date && ifs >> interval && ifs >> stuId && ifs >> stuName && ifs >> roomId && ifs >> status)
	{
		map<string, string> m;
		// ԤԼʱ���ܼ�
		m.insert(sparator(date));
		// ������
		m.insert(sparator(interval));
		// ID
		m.insert(sparator(stuId));
		// ����
		m.insert(sparator(stuName));
		// �����
		m.insert(sparator(roomId));
		// ״̬
		m.insert(sparator(status));

		m_orderData.insert(make_pair(m_Size, m));
		m_Size++;
	}
}

pair<string,string> OrderFile::sparator(string date)
{
	int pos = date.find(":"); //�ҵ��ַ�":"
	if (pos != -1)
	{
		string key;
		string value;
		key = date.substr(0, pos);
		value = date.substr(pos + 1, date.size() - pos - 1);
		return make_pair(key, value);
	}
}

void OrderFile::writeOrderFile()
{
	if (m_Size == 0)
	{
		return;
	}

	ofstream ofs(ORDER_FILE, ios::out | ios::trunc);

	map<string, string> m;
	for (map<int, map<string, string>>::iterator it = m_orderData.begin(); it != m_orderData.end(); it++)
	{
		m = (*it).second;
		ofs << "date:" << m["date"] << "\t";
		ofs << "interval:" << m["interval"] << "\t";
		ofs << "stuId:" << m["stuId"] << "\t";
		ofs << "stuName:" << m["stuName"] << "\t";
		ofs << "roomId:" << m["roomId"] << "\t";
		ofs << "status:" << m["status"] << endl;
	}
	/*
	for (int i = 0; i < m_Size; i++)
	{
		ofs << "date:" << m_orderData[i]["date"] << "\t";
		ofs << "interval:" << m_orderData[i]["interval"] << "\t";
		ofs << "stuId:" << m_orderData[i]["stuId"] << "\t";
		ofs << "stuName:" <<m_orderData[i]["stuName"] << "\t";
		ofs << "roomId:" << m_orderData[i]["roomId"] << "\t";
		ofs << "status:" << m_orderData[i]["status"] << endl;
	}*/

	ofs.close();
}

//�鿴����ԤԼ
void OrderFile::showAllOrder()
{
	if (m_Size == 0)
	{
		cout << "��ԤԼ��¼" << endl;
		system("pause");
		system("cls");
		return;
	}

	map<string, string> m;
	for (map<int, map<string, string>>::iterator it = m_orderData.begin(); it != m_orderData.end(); it++)
	{
		cout << (*it).first + 1 << "��\t";
		m = (*it).second;
		printOrder(m);
	}
	system("pause");
	system("cls");
}


void printOrder(map<string, string>& m)
{
	cout << "ԤԼ���ڣ���" << m["date"] << "\t";

	string interval = "ʱ�Σ�";
	if (m["interval"] == "1") {
		interval += "����";
	}
	else if (m["interval"] == "2") {
		interval += "����";
	}
	else {
		interval += "����";
	}
	cout << interval << "\t";

	cout << " ������" << m["stuName"];

	cout << " ������" << m["roomId"] << "\t";

	string status = " ״̬��";  // 0 ȡ����ԤԼ   1 �����   2 ��ԤԼ -1 ԤԼʧ��
	if (m["status"] == "1") {
		status += "�����";
	}
	else if (m["status"] == "2") {
		status += "ԤԼ�ɹ�";
	}
	else if (m["status"] == "-1") {
		status += "���δͨ����ԤԼʧ��";
	}
	else {
		status += "ԤԼ��ȡ��";
	}
	cout << status << endl;
}
