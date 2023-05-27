#include "student.h"


//构造
Student::Student()
{

}

// 有参构造
Student::Student(int id, string name, string pwd)
{
	m_Id = id;
	m_Name = name;
	m_Pwd = pwd;

	initVector();
}


//菜单界面
void Student::operMenu()
{
	cout << "欢迎学生代表：" << m_Name << "登录！" << endl;
	cout << "\t\t ---------------------------------- \n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          1.申请预约              |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          2.查看我的预约          |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          3.查看所有预约          |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          4.取消预约              |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          0.注销登录              |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t ---------------------------------- \n";
	cout << "请选择您的操作：" << endl;
}

//申请预约
void Student::applyOrder()
{
	cout << "机房开放时间为周一至周五！" << endl;
	cout << "请输入申请预约的时间：" << endl;
	cout << "1、周一" << endl;
	cout << "2、周二" << endl;
	cout << "3、周三" << endl;
	cout << "4、周四" << endl;
	cout << "5、周五" << endl;


	int date = 0;		// 周几
	int interval = 0;	// 早中晚
	int room = 0;		// 几号机房

	while (true)
	{
		cin >> date;
		if (date >= 1 && date <= 5)
		{
			break;
		}
		cout << "输入有误，请重新输入" << endl;
	}


	cout << "请输入申请预约的时间段：" << endl;
	cout << "1、上午" << endl;
	cout << "2、下午" << endl;
	cout << "3、晚上" << endl;

	while (true)
	{
		cin >> interval;
		if (interval >= 1 && interval <= 3)
		{
			break;
		}
		cout << "输入有误，请重新输入" << endl;
	}


	cout << "机房号和容量如下！" << endl;
	for (vector<ComputerRoom>::iterator it = vCom.begin(); it != vCom.end(); it++)
	{
		(*it).showMassage();
	}
	cout << "请选择机房：" << endl;
	while (true)
	{
		cin >> room;
		if (room >= 1 && room <= 3)
		{
			break;
		}
		cout << "输入有误，请重新输入" << endl;
	}

	// 写入预约文件
	writeMassage(date, interval, room, 1);


	cout << "预约成功！审核中" << endl;

	system("pause");
	system("cls");
}

//查看我的预约
void Student::showMyOrder()
{
	OrderFile of;
	if (of.m_Size == 0)
	{
		cout << "无预约记录" << endl;
		system("pause");
		system("cls");
		return;
	}
	map<string, string> m;
	for (map<int, map<string, string>>::iterator it = of.m_orderData.begin(); it != of.m_orderData.end(); it++)
	{
		m = (*it).second;
		if (atoi(m["stuId"].c_str()) == m_Id)// string转char转int
		{
			printOrder(m);
		}
	}
	system("pause");
	system("cls");
}

void Student::showAllOrder()
{
	OrderFile of;
	of.showAllOrder();
}


//取消预约
void Student::cancelOrder()
{
	OrderFile of;
	if (of.m_Size == 0)
	{
		cout << "无预约记录" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "审核中或预约成功的记录如下：" << endl;

	vector<int>v; // 存放需要修改的记录
	int index = 1;

	map<string, string> m;
	for (map<int, map<string, string>>::iterator it = of.m_orderData.begin(); it != of.m_orderData.end(); it++)
	{
		m = (*it).second;
		if (atoi(m["stuId"].c_str()) == m_Id)
		{
			if (m["status"] == "1" || m["status"] == "2")
			{
				v.push_back((*it).first);
				cout << index++ << "、";
				printOrder(m);
			}
		}
	}

	cout << "请输入取消的记录, 0 返回" << endl;
	int select = 0;
	while (true)
	{
		cin >> select;
		if (select == 0)
		{
			break;
		}
		
		if (select > 0 && select <= v.size())
		{
			of.m_orderData[v[select - 1]]["status"] = "0";

			of.updateOrder();

			cout << "已取消预约" << endl;
			break;
		}
		cout << "输入有误，请重新输入" << endl;
	}

	system("pause");
	system("cls");
}

// 输出
void Student::showMassage()
{
	cout << "学号：" << m_Id << "\t姓名：" << m_Name << endl;
}


// 菜单管理
void Student::showMenu()
{
	while (true)
	{
		// 学生菜单
		operMenu();
		OrderFile of;

		int select = 0;
		cin >> select;

		if (select == 1)  //申请预约
		{
			cout << "申请预约" << endl;
			applyOrder();
		}
		else if (select == 2) //查看自身预约
		{
			cout << "查看自身预约" << endl;
			showMyOrder();
		}
		else if (select == 3) //查看机房
		{
			cout << "查看所有预约" << endl;
			showAllOrder();

		}
		else if (select == 4) //取消预约
		{
			cout << "取消预约" << endl;
			cancelOrder();
		}
		else
		{
			cout << "注销成功" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}

void Student::initVector()
{
	// 读取机房信息
	ifstream ifs;
	ifs.open(COMPUTER_FILE, ios::in);
	vCom.clear();
	ComputerRoom c;
	while (ifs >> c.m_ComId && ifs >> c.m_MaxNum)
	{
		vCom.push_back(c);
	}
	//cout << "当前机房数量为：" << vCom.size() << endl;

	ifs.close();
}

// 写入order文件 一行
void Student::writeMassage(int date, int interval, int room, bool status)
{
	ofstream ofs(ORDER_FILE, ios::app);
	ofs << "date:" << date << "\t";
	ofs << "interval:" << interval << "\t";
	ofs << "stuId:" << m_Id << "\t";
	ofs << "stuName:" << m_Name << "\t";
	ofs << "roomId:" << room << "\t";
	ofs << "status:" << status << endl;
	ofs.close();
}

