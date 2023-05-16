#include "workerManager.h"

WorkerManager::WorkerManager()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	// 1. 文件不存在情况
	if (!ifs.is_open())
	{
		//cout << "文件不存在" << endl;
		m_EmpNum = 0;// 初始化人数为0
		m_FileIsEmpty = true;
		m_EmpArray = NULL;// 初始化指针为空
		ifs.close();
		return;
	}

	// 2. 文件存在且数据为空
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		//cout << "文件为空！" << endl;
		m_EmpNum = 0;
		m_FileIsEmpty = true;
		m_EmpArray = NULL;
		ifs.close();
		return;
	}

	// 3. 文件存在且记录数据
	ifs.close();
	int num = get_EmpNum();
	//cout << "记录职工人数：" << num << endl;
	m_EmpNum = num;

	// 开辟空间
	m_EmpArray = new Worker * [m_EmpNum];
	// 将文件数据存入数组
	init_Emp();
	// 展示数据
	//show_Emp();
}

WorkerManager::~WorkerManager()
{
	if (m_EmpArray != NULL)
	{
		delete[] m_EmpArray;
		m_EmpArray = NULL;
	}
}


void WorkerManager::Show_Menu()
{
	cout << "********************************************" << endl;
	cout << "*********  欢迎使用职工管理系统！ **********" << endl;
	cout << "*************  0.退出管理程序  *************" << endl;
	cout << "*************  1.增加职工信息  *************" << endl;
	cout << "*************  2.显示职工信息  *************" << endl;
	cout << "*************  3.删除离职职工  *************" << endl;
	cout << "*************  4.修改职工信息  *************" << endl;
	cout << "*************  5.查找职工信息  *************" << endl;
	cout << "*************  6.按照编号排序  *************" << endl;
	cout << "*************  7.清空所有文档  *************" << endl;
	cout << "********************************************" << endl;
	cout << endl;
}

void WorkerManager::exitSystem()
{
	cout << "欢迎下次使用" << endl;
	//system("pause");
	exit(0); // 退出程序
}

// 保存文件
void WorkerManager::Save()
{
	ofstream ofs;
	ofs.open(FILENAME, ios::out);	// 写文件

	// 将每个人的数据写入文件中
	for (int i = 0; i < m_EmpNum; i++)
	{
		ofs << m_EmpArray[i]->m_ID << "\t"
			<< m_EmpArray[i]->m_Name << "\t"
			<< m_EmpArray[i]->m_DeptID << "\t"
			<< m_EmpArray[i]->m_Post << endl;
	}

	// 关闭文件
	ofs.close();
}

// 统计文件中人数
int WorkerManager::get_EmpNum()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);	// 打开文件

	int id;
	string name;
	int dId;
	int post;

	int num = 0;
	while (ifs >> id && ifs >> name && ifs >> dId && ifs >> post)
	{
		// 统计人数
		num++;
	}
	ifs.close();

	return num;
}

void WorkerManager::Add_Emp()
{
	cout << "请输入添加职工数量：" << endl;
	int addNum = 0;
	cin >> addNum;
	if (addNum > 0)
	{
		//添加
		// 计算新空间大小
		int newSize = m_EmpNum + addNum;

		// 开辟空间
		Worker** newSpace = new Worker * [newSize];

		// 将原来数据拷贝到新空间
		if (m_EmpArray != NULL)
		{
			for (int i = 0; i < m_EmpNum; i++)
			{
				newSpace[i] = m_EmpArray[i];
			}
		}

		// 添加新数据
		for (int i = 0; i < addNum; i++)
		{
			int id;
			string name;
			int deptID;
			int Post;

			cout << "请输入第 " << i + 1 << "个新职工信息：" << endl;
			cout << "编号ID：";
			cin >> id;
			cout << "姓名：";
			cin >> name;
			cout << "部门ID：";
			cin >> deptID;
			cout << "请选择新职工岗位：" << endl;
			cout << "1. 普通职工" << endl;
			cout << "2. 经理" << endl;
			cout << "3. 老板" << endl;
			cin >> Post;

			Worker* worker = NULL;
			switch (Post)
			{
			case 1:
				worker = new Employee(id, name, deptID, Post);
				break;
			case 2:
				worker = new Manager(id, name, deptID, Post);
				break;
			case 3:
				worker = new Boss(id, name, deptID, Post);
				break;
			default:
				break;
			}
			// 将创建的职工，保存到数组中
			newSpace[m_EmpNum + i] = worker;

		}
		// 释放空间
		delete[] m_EmpArray;
		// 更改新空间指向
		m_EmpArray = newSpace;

		// 更新职工人数
		m_EmpNum = newSize;

		// 更新职工不为空
		m_FileIsEmpty = false;

		// 从系统中保存到文件
		Save();

		// 提示
		cout << "成功添加" << addNum << "职工" << endl;

	}
	else
	{
		// 输入错误
		cout << "输入错误" << endl;
	}

	// 按任意键 清空屏幕返回上级
	system("pause");
	system("cls");
}

// 初始化员工
void WorkerManager::init_Emp()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int id;
	string name;
	int dId;
	int post;

	int index = 0;
	while (ifs >> id && ifs >> name && ifs >> dId && ifs >> post)
	{
		Worker* worker = NULL;
		if (post == 1)
			worker = new Employee(id, name, dId, post);
		else if (post == 2)
			worker = new Manager(id, name, dId, post);
		else if (post == 3)
			worker = new Boss(id, name, dId, post);

		m_EmpArray[index] = worker;
		index++;
	}
	// 关闭文件
	ifs.close();
}

// 展示数据库数据
void WorkerManager::show_Emp()
{
	if (m_FileIsEmpty)
	{
		cout << "文件不存在或者为空" << endl;
	}
	else
	{
		for (int i = 0; i < m_EmpNum; i++)
		{
			// 利用多态调用程序接口
			m_EmpArray[i]->showInfo();
		}
	}
	system("pause");
	system("cls");
	//for (int i = 0; i < m_EmpNum; i++)
	//{
	//	cout << "职工编号：" << m_EmpArray[i]->m_ID << "\t"
	//		<< "职工姓名：" << m_EmpArray[i]->m_Name << "\t"
	//		<< "职工部门：" << m_EmpArray[i]->m_DeptID << "\t"
	//		<< "职工职务：" << m_EmpArray[i]->m_Post << endl;
	//}
}

// 删除职工
void WorkerManager::Del_Emp()
{
	if (m_FileIsEmpty)
	{
		cout << "文件不存在或记录为空！" << endl;
	}
	else
	{
		//按职工编号删除
		cout << "请输入想要删除的职工号：" << endl;
		int id = 0;
		cin >> id;

		int index = IsExist(id);

		if (index != -1)  //说明index上位置数据需要删除
		{
			for (int i = index; i < m_EmpNum - 1; i++)
			{
				delete m_EmpArray[i];
				m_EmpArray[i] = m_EmpArray[i + 1];
			}
			m_EmpNum--;

			Save(); //删除后数据同步到文件中
			cout << "删除成功！" << endl;
		}
		else
		{
			cout << "删除失败，未找到该职工" << endl;
		}
	}
	system("pause");
	system("cls");
}

// 判断职工是否存在 存在返回职工所在数组位置 否则为-1
int WorkerManager::IsExist(int id)
{
	int index = -1;
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		if (m_EmpArray[i]->m_ID == id)
		{
			index = i;
			break;
		}
	}
	return index;
}

// 修改职工 根据职工编号对职工信息进行修改并保存
void WorkerManager::Mod_Emp()
{
	if (m_FileIsEmpty)
	{
		cout << "文件不存在或者记录为空！" << endl;
		return;
	}

	cout << "请输入修改职工的编号：" << endl;
	int id;
	cin >> id;

	int ret = IsExist(id);
	if (ret == -1)
	{
		cout << "修改失败，查无此人" << endl;
		return;
	}

	// 查到编号的职工
	delete m_EmpArray[ret];

	string newName = "";
	int newDeptId = 0;
	int newPost = 0;



	cout << "找到编号为" << id << "的职工" << endl;
	cout << "请输入新名字：";
	cin >> newName;
	cout << "请输入新部门：";
	cin >> newDeptId;
	cout << "请输入新职位：";
	cin >> newPost;

	Worker* worker = NULL;
	switch (newPost)
	{
	case 1:
		worker = new Employee(id, newName, newDeptId, newPost);
		break;
	case 2:
		worker = new Manager(id, newName, newDeptId, newPost);
		break;
	case 3:
		worker = new Boss(id, newName, newDeptId, newPost);
		break;
	default:
		break;
	}

	// 更改数据到数组中
	m_EmpArray[ret] = worker;
	cout << "修改成功！" << endl;

	// 保存到文件中
	Save();

	system("pause");
	system("cls");
}

// 查找职工
void WorkerManager::Find_Emp()
{
	if (m_FileIsEmpty)
	{
		cout << "文件不存在或记录为空！" << endl;
		return;
	}

	cout << "请输入查找方式" << endl;
	cout << "1. 按职工编号查找" << endl;
	cout << "2. 按姓名查找" << endl;

	int select = 0;
	cin >> select;

	switch (select)
	{
	case 1:
		_Find_EmpbyID();
		break;
	case 2:
		_Find_EmpbyName();
		break;
	default:
		cout << "输入有误" << endl;
		break;
	}
	system("pause");
	system("cls");
}

void WorkerManager::_Find_EmpbyID()
{
	int id;
	cout << "请输入查找职工编号：" << endl;
	cin >> id;

	// 查找职工
	int ret = IsExist(id);
	if (ret != -1)
	{
		cout << "查找成功！该职工信息如下：" << endl;
		this->m_EmpArray[ret]->showInfo();
	}
	else
	{
		cout << "查找失败，查无此人" << endl;
	}
}

void WorkerManager::_Find_EmpbyName()
{
	string name;
	cout << "请输入查找职工姓名：" << endl;
	cin >> name;

	// 查找职工
	bool flag = false;  //查找到的标志
	for (int i = 0; i < m_EmpNum; i++)
	{
		if (m_EmpArray[i]->m_Name == name)
		{
			cout << "查找成功！该职工信息如下：" << endl;
			m_EmpArray[i]->showInfo();

			flag = true;
		}
	}
	if (flag == false)
	{
		//查无此人
		cout << "查找失败，查无此人" << endl;
	}
}


// 对数据库进行排序
void WorkerManager::Sort_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或记录为空！" << endl;
		return;
	}

	cout << "请选择排序方式： " << endl;
	cout << "0、按职工号进行降序" << endl;
	cout << "1、按职工号进行升序" << endl;

	bool select = 0;
	cin >> select;

	// 冒泡排序
	for (int i = 0; i < m_EmpNum; i++)
	{
		int minOrMax = i;
		for (int j = i + 1; j < m_EmpNum; j++)
		{
			if (select) //升序
			{
				if (m_EmpArray[minOrMax]->m_ID > m_EmpArray[j]->m_ID)
				{
					minOrMax = j;
				}
			}
			else //降序
			{
				if (m_EmpArray[minOrMax]->m_ID < m_EmpArray[j]->m_ID)
				{
					minOrMax = j;
				}
			}
		}
		// 交换位置
		if (i != minOrMax)
		{
			Worker* temp = m_EmpArray[i];
			m_EmpArray[i] = m_EmpArray[minOrMax];
			m_EmpArray[minOrMax] = temp;
		}
	}

	cout << "排序成功,排序后结果为：" << endl;
	Save();
	show_Emp();
}

// 清空函数实现
void WorkerManager::Clean_File()
{
	cout << "是否确认清空数据库？" << endl;
	cout << "1. 确认" << endl;
	cout << "2. 返回" << endl;

	int select = 0;
	cin >> select;

	if (select != 1)
	{
		cout << "未清理，返回页面" << endl;
		system("pause");
		system("cls");
		return;
	}

	// 清理程序
	//打开模式 ios::trunc 如果存在删除文件并重新创建
	ofstream ofs(FILENAME, ios::trunc);
	ofs.close();

	
	if (m_EmpArray != NULL)
	{
		// 先删除每一个具象对象
		for (int i = 0; i < m_EmpNum; i++)
		{
			if (m_EmpArray[i] != NULL)
			{
				delete m_EmpArray[i];
			}
		}

		// 将计数归零
		m_EmpNum = 0;

		// 删除worker指针数组
		delete[] m_EmpArray;
		m_EmpArray = NULL;

		// 更改文件标识
		m_FileIsEmpty = true;
	}

	cout << "清空成功！" << endl;
	system("pause");
	system("cls");

}