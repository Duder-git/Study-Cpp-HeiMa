#pragma once
#include <iostream>
#include <fstream>
using namespace std;
#include "worker.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"

constexpr auto FILENAME = "empFile.txt";
//​管理类：
// 1. 与用户的沟通菜单界面
// 2. 对职工增删改查的操作
// 3. 与文件的读写交互
class WorkerManager
{
public:

	//构造函数
	WorkerManager();

	//析构函数
	~WorkerManager();

	// 展示菜单
	void Show_Menu();

	// 退出程序
	void exitSystem();

	// 添加职工
	void Add_Emp();

	// 保存文件
	void Save();

	// 属性
	// 记录职工人数
	int m_EmpNum;	

	// 职工数组指针
	Worker** m_EmpArray;	

	// 文件标志
	bool m_FileIsEmpty;		

	// 统计文件中人数
	int get_EmpNum();

	// 初始化员工
	void init_Emp();

	// 展示数据库数据
	void show_Emp();

	// 删除职工
	void Del_Emp();

	// 判断职工是否存在 存在返回职工所在数组位置 否则为-1
	int IsExist(int id);

	// 修改职工 根据职工编号对职工信息进行修改并保存
	void Mod_Emp();

	// 查找职工
	void Find_Emp();

	// 使用ID查职工
	void _Find_EmpbyID();

	// 使用Name查职工
	void _Find_EmpbyName();

	// 对数据库进行排序
	void Sort_Emp();

	// 清空函数实现
	void Clean_File();
};