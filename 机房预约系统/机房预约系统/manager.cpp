#include "manager.h"
#include <fstream>
#include <algorithm>
#include "globalFile.h"


//默认构造
Manager::Manager()
{

}

//有参构造
Manager::Manager(string name, string pwd)
{
	m_Name = name;
	m_Pwd = pwd;

	// 初始化容器
	initVector();
}

//选择菜单
void Manager::operMenu()
{
	cout << "欢迎管理员：" << m_Name << "登录！" << endl;
	cout << "\t\t -------------------------------- \n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          1.添加账号            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          2.查看账号            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          3.查看机房            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          4.清空预约            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          0.注销登录            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t -------------------------------- \n";
	cout << "请选择您的操作： " << endl;
}

//添加账号  
void Manager::addPerson()
{
	cout << "请输入添加账号的类型" << endl;
	cout << "1、添加学生" << endl;
	cout << "2、添加老师" << endl;

	string fileName;
	string tip;
	string errorTip;
	
	int select = 0;
	cin >> select;
	if (select == 1)
	{
		fileName = STUDENT_FILE;
		tip = "请输入学号： ";
		errorTip = "学号重复，请重新输入";
	}
	else if(select == 2)
	{
		fileName = TEACHER_FILE;
		tip = "请输入职工编号：";
		errorTip = "职工号重复，请重新输入";
	}

	int id;
	string name;
	string pwd;

	cout << tip << endl;
	while (true)
	{
		cin >> id;
		bool ret = checkRepeat(id, select);
		if (ret)
			cout << errorTip << endl;
		else
			break;
	}
	cout << "请输入姓名： " << endl;
	cin >> name;
	cout << "请输入密码： " << endl;
	cin >> pwd;

	ofstream ofs;
	ofs.open(fileName, ios::out | ios::app);
	ofs << id << "\t" << name << "\t" << pwd << endl;
	ofs.close();
		
	cout << "添加成功" << endl;
	system("pause");
	system("cls");
}

//查看账号
void Manager::showPerson()
{
	cout << "请选择查看内容：" << endl;
	cout << "1、查看所有学生" << endl;
	cout << "2、查看所有老师" << endl;

	int select = 0;

	cin >> select;

	if (select == 1)
	{
		cout << "所有学生信息如下： " << endl;
		for (vector<Student>::iterator it = vStu.begin(); it != vStu.end(); it++)
		{
			(*it).showMassage();
		}
		//for_each(vStu.begin(), vStu.end(), printStudent);
	}
	else
	{
		cout << "所有老师信息如下： " << endl;
		for (vector<Teacher>::iterator it = vTea.begin(); it != vTea.end(); it++)
		{
			(*it).showMassage();
		}
		//for_each(vTea.begin(), vTea.end(), printTeacher);
	}
	system("pause");
	system("cls");
}


//查看机房信息
void Manager::showComputer()
{
	cout << "机房信息如下：" << endl;
	for (vector<ComputerRoom>::iterator it = vCom.begin(); it != vCom.end(); it++)
	{
		(*it).showMassage();
	}
	system("pause");
	system("cls");
}

//清空预约记录
void Manager::cleanFile()
{
	ofstream ofs(ORDER_FILE, ios::trunc); // 存在，先删除再创建
	ofs.close();

	cout << "清空成功！" << endl;
	system("pause");
	system("cls");

}

void Manager::showMenu()
{
	while (true)
	{
		// 管理员菜单
		operMenu();

		int select = 0;

		cin >> select;

		if (select == 1)  //添加账号
		{
			cout << "添加账号" << endl;
			addPerson();
		}
		else if (select == 2) //查看账号
		{
			cout << "查看账号" << endl;
			showPerson();
		}
		else if (select == 3) //查看机房
		{
			cout << "查看机房" << endl;
			showComputer();
		}
		else if (select == 4) //清空预约
		{
			cout << "清空预约" << endl;
			cleanFile();
		}
		else
		{
			//delete manager;
			cout << "注销成功" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}


void Manager::initVector()
{
	// 读取学生文件中信息
	ifstream ifs;
	ifs.open(STUDENT_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "学生文件读取失败！" << endl;
	}

	vStu.clear();
	Student s;
	while (ifs >> s.m_Id && ifs >> s.m_Name && ifs >> s.m_Pwd)
	{
		vStu.push_back(s);
	}
	cout << "当前学生数量为：" << vStu.size() << endl;
	ifs.close();


	// 读取老师文件中信息
	ifs.open(TEACHER_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "老师文件读取失败！" << endl;
	}

	vTea.clear();
	Teacher t;
	while (ifs >> t.m_EmpId && ifs >> t.m_Name && ifs >> t.m_Pwd)
	{
		vTea.push_back(t);
	}
	cout << "当前老师数量为：" << vStu.size() << endl;
	ifs.close();

	// 读取机房信息
	ifs.open(COMPUTER_FILE, ios::in);
	vCom.clear();
	ComputerRoom c;
	while (ifs >> c.m_ComId && ifs >> c.m_MaxNum)
	{
		vCom.push_back(c);
	}
	cout << "当前机房数量为：" << vCom.size() << endl;

	ifs.close();
}



bool Manager::checkRepeat(int id,int type)
{
	if (type == 1)
	{
		for (vector<Student>::iterator it = vStu.begin(); it != vStu.end(); it++)
		{
			if (id == it->m_Id)
			{
				return true;
			}
		}
	}
	else
	{
		for (vector<Teacher>::iterator it = vTea.begin(); it != vTea.end(); it++)
		{
			if (id == it->m_EmpId)
			{
				return true;
			}
		}
	}
	return false;
}

void Manager::showMassage()
{
	cout << "姓名：" << m_Name << "\t密码：" << m_Pwd << endl;
}




void printStudent(Student& s)
{
	cout << "学号：" << s.m_Id << "\t姓名：" << s.m_Name << "\t密码：" << s.m_Pwd << endl;
}

void printTeacher(Teacher& t)
{
	cout << "职工号：" << t.m_EmpId << "\t姓名：" << t.m_Name << "\t密码：" << t.m_Pwd << endl;
}