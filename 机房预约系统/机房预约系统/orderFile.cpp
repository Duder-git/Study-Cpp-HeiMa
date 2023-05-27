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

	string date;		//日期
	string interval;	//时间段
	string stuId;		//学生编号
	string stuName;		//学生姓名
	string roomId;		//机房编号
	string status;		//预约状态

	ifstream ifs;
	ifs.open(ORDER_FILE, ios::in);
	while (ifs >> date && ifs >> interval && ifs >> stuId && ifs >> stuName && ifs >> roomId && ifs >> status)
	{
		map<string, string> m;
		// 预约时间周几
		m.insert(sparator(date));
		// 早中晚
		m.insert(sparator(interval));
		// ID
		m.insert(sparator(stuId));
		// 名字
		m.insert(sparator(stuName));
		// 房间号
		m.insert(sparator(roomId));
		// 状态
		m.insert(sparator(status));

		m_orderData.insert(make_pair(m_Size, m));
		m_Size++;
	}
}

pair<string,string> OrderFile::sparator(string date)
{
	int pos = date.find(":"); //找到字符":"
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

//查看所有预约
void OrderFile::showAllOrder()
{
	if (m_Size == 0)
	{
		cout << "无预约记录" << endl;
		system("pause");
		system("cls");
		return;
	}

	map<string, string> m;
	for (map<int, map<string, string>>::iterator it = m_orderData.begin(); it != m_orderData.end(); it++)
	{
		cout << (*it).first + 1 << "、\t";
		m = (*it).second;
		printOrder(m);
	}
	system("pause");
	system("cls");
}


void printOrder(map<string, string>& m)
{
	cout << "预约日期：周" << m["date"] << "\t";

	string interval = "时段：";
	if (m["interval"] == "1") {
		interval += "上午";
	}
	else if (m["interval"] == "2") {
		interval += "下午";
	}
	else {
		interval += "晚上";
	}
	cout << interval << "\t";

	cout << " 姓名：" << m["stuName"];

	cout << " 机房：" << m["roomId"] << "\t";

	string status = " 状态：";  // 0 取消的预约   1 审核中   2 已预约 -1 预约失败
	if (m["status"] == "1") {
		status += "审核中";
	}
	else if (m["status"] == "2") {
		status += "预约成功";
	}
	else if (m["status"] == "-1") {
		status += "审核未通过，预约失败";
	}
	else {
		status += "预约已取消";
	}
	cout << status << endl;
}
