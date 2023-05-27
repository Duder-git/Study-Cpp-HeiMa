#include "teacher.h"
#include "orderFile.h"
#include<vector>

//构造
Teacher::Teacher()
{

}

// 有参构造
Teacher::Teacher(int id, string name, string pwd)
{
	m_EmpId = id;
	m_Name = name;
	m_Pwd = pwd;
}

//菜单界面
void Teacher::operMenu()
{
	cout << "欢迎教师：" << this->m_Name << "登录！" << endl;
	cout << "\t\t ---------------------------------- \n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          1.查看所有预约          |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          2.审核预约              |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          0.注销登录              |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t ---------------------------------- \n";
	cout << "请选择您的操作： " << endl;
}

//查看所有预约
void Teacher::showAllOrder()
{
	OrderFile of;
	of.showAllOrder();
}

//审核预约
void Teacher::validOrder()
{
	OrderFile of;
	if (of.m_Size == 0)
	{
		cout << "无预约记录" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "待审核的预约记录如下：" << endl;

	vector<int>v;
	int index = 1;

	// 展示预约记录
	map<string, string> m;
	for (map<int, map<string, string>>::iterator it = of.m_orderData.begin(); it != of.m_orderData.end(); it++)
	{
		m = (*it).second;
		if (m["status"] != "0")
		{
			v.push_back((*it).first);
			cout << index++ << "、";
			printOrder((*it).second);
		}

	}

	cout << "请输入审核的预约记录,0代表返回" << endl;
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
			cout << "请输入审核结果" << endl;
			cout << "1、通过" << endl;
			cout << "2、不通过" << endl;
			int ret = 0;
			cin >> ret;

			if (ret == 1)
			{
				// 通过
				of.m_orderData[v[select - 1]]["status"] = "2";
			}
			else
			{
				// 审核未通过
				of.m_orderData[v[select - 1]]["status"] = "-1";
			}

			of.updateOrder();

			cout << "审核完毕！" << endl;
			break;
		}
		cout << "输入有误，请重新输入" << endl;
	}

	system("pause");
	system("cls");
}



// 输出
void Teacher::showMassage()
{
	cout << "职工号：" << m_EmpId << "\t姓名：" << m_Name << endl;
}

// 菜单管理
void Teacher::showMenu()
{
	while (true)
	{
		// 教师菜单
		operMenu();

		int select = 0;

		cin >> select;

		if (select == 1)
		{
			cout << "查看所有预约" << endl;
			showAllOrder();
		}
		else if (select == 2)
		{
			cout << "审核预约" << endl;
			validOrder();
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

