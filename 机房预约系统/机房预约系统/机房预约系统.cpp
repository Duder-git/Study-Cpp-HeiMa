#include "system.h"



int main()
{
	int select = 0;
	while (true)
	{

		cout << "======================  欢迎来到传智播客机房预约系统  ====================="
			<< endl;
		cout << endl << "请输入您的身份" << endl;
		cout << "\t\t -------------------------------\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          1.学生代表           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          2.老    师           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          3.管 理 员           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          0.退    出           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t -------------------------------\n";
		cout << "输入您的选择: ";

		cin >> select;
		switch (select)
		{
		case 1: // 学生
			LonginIn("student.txt", 1);
			break;

		case 2: // 老师
			LonginIn(TEACHER_FILE, 2);
			break;

		case 3: // 管理员
			LonginIn(ADMIN_FILE, 3);
			break;

		case 0: // 退出
			cout << "欢迎下次使用" << endl;
			system("pause");
			return 0;
			break;

		default:
			cout << "输入有误，请重新选择！" << endl;
			system("pause");
			system("cls");
			break;
		}

	}
	system("pause");

	return 0;
}

void LonginIn(string filename, int type)
{
	//Identify* person = NULL;

	ifstream ifs;
	ifs.open(filename, ios::in);

	// 文件不存在
	if (!ifs.is_open())
	{
		cout << "文件不存在" << endl;
		ifs.close();
		return;
	}

	int id = 0;
	string name;
	string pwd;

	if (type == 1) // 学生登录
	{
		cout << "请输入你的学号" << endl;
		cin >> id;
	}
	else if (type == 2) // 教师登录
	{
		cout << "请输入职工号" << endl;
		cin >> id;
	}
	cout << "请输入用户名：" << endl;
	cin >> name;

	cout << "请输入密码： " << endl;
	cin >> pwd;

	if (type == 1)
	{
		//学生登录验证
		int fId;
		string fName;
		string fPwd;
		while (ifs >> fId && ifs >> fName && ifs >> fPwd)
		{
			//cout << fId << " " << fName << " " << fPwd <<endl;
			if (id = fId && name == fName && pwd == fPwd)
			{
				cout << "学生验证登录成功！" << endl;
				system("pause");
				system("cls");
				Student student(id, name, pwd);
				// 进入学生菜单
				student.showMenu();
				return;
			}
		}

	}
	else if (type == 2)
	{
		//教师登录验证
		int fId;
		string fName;
		string fPwd;
		while (ifs >> fId && ifs >> fName && ifs >> fPwd)
		{
			//cout << fId << " " << fName << " " << fPwd <<endl;
			if (id = fId && name == fName && pwd == fPwd)
			{
				cout << "教师验证登录成功！" << endl;
				system("pause");
				system("cls");
				Teacher teacher(id, name, pwd);
				// 进入老师菜单
				teacher.showMenu();
				return;
			}
		}
	}
	else if (type == 3)
	{
		//管理员登录验证
		string fName;
		string fPwd;
		while (ifs >> fName && ifs >> fPwd)
		{
			//cout << fId << " " << fName << " " << fPwd <<endl;
			if (name == fName && pwd == fPwd)
			{
				cout << "管理员验证登录成功！" << endl;
				system("pause");
				system("cls");
				// 创建管理员对象
				//person = new Manager(name, pwd);
				Manager manager(name, pwd);
				// 进入管理员菜单
				manager.showMenu();
				return;
			}
		}
	}

	cout << "验证登录失败!" << endl;

	system("pause");
	system("cls");
	return;
}

