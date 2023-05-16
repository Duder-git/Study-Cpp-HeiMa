
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <ctime>
using namespace std;

/*
- 公司今天招聘了10个员工（ABCDEFGHIJ），10名员工进入公司之后，需要指派员工在那个部门工作
- 员工信息有: 姓名  工资组成；部门分为：策划、美术、研发
- 随机给10名员工分配部门和工资
- 通过multimap进行信息的插入  key(部门编号) value(员工)
- 分部门显示员工信息
*/

# define CEHUA 0
# define MEISHU 1
# define YANFA 2

class Worker
{
public:
	string m_Name;
	int m_Salary;
};

class MyCompare {
public:
	bool operator()(int v1,int v2) const{
		return v1 > v2;
	}
};

void createWorker(vector<Worker>& v)
{
	string nameSeed = "ABCDEFGHIJ";
	for (int i = 0; i < 10; i++)
	{
		Worker worker;
		worker.m_Name = "员工";
		worker.m_Name += nameSeed[i];

		worker.m_Salary = rand() % 10000 + 10000; // 0~9999 +10000

		v.push_back(worker);
	}
}


// 员工分组
void setGroup(vector<Worker>& v, multimap<int, Worker, MyCompare>& m)
{
	for (vector<Worker>::iterator it = v.begin(); it != v.end(); it++)
	{
		// 产生随机编号
		int deptId = rand() % 3; //0 1 2

		// 将员工插入到分组中
		m.insert(make_pair(deptId, *it));
	}
}

// 
void showWorkerByGrourp(multimap<int, Worker, MyCompare>& m)
{
	int count;
	multimap<int, Worker, MyCompare>::iterator pos;
	cout << "策划部门：" << endl;
	pos = m.find(CEHUA);
	count = m.count(CEHUA);
	for (int index = 0;pos != m.end() && index<count; pos++,index++)
	{
		cout << "姓名：" << pos->second.m_Name << " 工资：" << pos->second.m_Salary << endl;
	}

	cout << "----------------------" << endl;
	cout << "美术部门：" << endl;
	pos = m.find(MEISHU);
	count = m.count(MEISHU);
	for (int index = 0; pos != m.end() && index < count; pos++, index++)
	{
		cout << "姓名：" << pos->second.m_Name << " 工资：" << pos->second.m_Salary << endl;
	}

	cout << "----------------------" << endl;
	cout << "研发部门：" << endl;
	pos = m.find(YANFA);
	count = m.count(YANFA);
	for (int index = 0; pos != m.end() && index < count; pos++, index++)
	{
		cout << "姓名：" << pos->second.m_Name << " 工资：" << pos->second.m_Salary << endl;
	}
}


int main()
{
	srand((unsigned int)time(NULL));

	// 1 创建员工
	vector<Worker>vWorker;
	createWorker(vWorker);

	// 2 员工分组
	multimap<int, Worker, MyCompare>mWorker;
	setGroup(vWorker, mWorker);

	// 3 分组显示员工
	showWorkerByGrourp(mWorker);

	// 4 排序各部门员工
	


	return 0;
}