
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <ctime>
using namespace std;

/*
- ��˾������Ƹ��10��Ա����ABCDEFGHIJ����10��Ա�����빫˾֮����Ҫָ��Ա�����Ǹ����Ź���
- Ա����Ϣ��: ����  ������ɣ����ŷ�Ϊ���߻����������з�
- �����10��Ա�����䲿�ź͹���
- ͨ��multimap������Ϣ�Ĳ���  key(���ű��) value(Ա��)
- �ֲ�����ʾԱ����Ϣ
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
		worker.m_Name = "Ա��";
		worker.m_Name += nameSeed[i];

		worker.m_Salary = rand() % 10000 + 10000; // 0~9999 +10000

		v.push_back(worker);
	}
}


// Ա������
void setGroup(vector<Worker>& v, multimap<int, Worker, MyCompare>& m)
{
	for (vector<Worker>::iterator it = v.begin(); it != v.end(); it++)
	{
		// ����������
		int deptId = rand() % 3; //0 1 2

		// ��Ա�����뵽������
		m.insert(make_pair(deptId, *it));
	}
}

// 
void showWorkerByGrourp(multimap<int, Worker, MyCompare>& m)
{
	int count;
	multimap<int, Worker, MyCompare>::iterator pos;
	cout << "�߻����ţ�" << endl;
	pos = m.find(CEHUA);
	count = m.count(CEHUA);
	for (int index = 0;pos != m.end() && index<count; pos++,index++)
	{
		cout << "������" << pos->second.m_Name << " ���ʣ�" << pos->second.m_Salary << endl;
	}

	cout << "----------------------" << endl;
	cout << "�������ţ�" << endl;
	pos = m.find(MEISHU);
	count = m.count(MEISHU);
	for (int index = 0; pos != m.end() && index < count; pos++, index++)
	{
		cout << "������" << pos->second.m_Name << " ���ʣ�" << pos->second.m_Salary << endl;
	}

	cout << "----------------------" << endl;
	cout << "�з����ţ�" << endl;
	pos = m.find(YANFA);
	count = m.count(YANFA);
	for (int index = 0; pos != m.end() && index < count; pos++, index++)
	{
		cout << "������" << pos->second.m_Name << " ���ʣ�" << pos->second.m_Salary << endl;
	}
}


int main()
{
	srand((unsigned int)time(NULL));

	// 1 ����Ա��
	vector<Worker>vWorker;
	createWorker(vWorker);

	// 2 Ա������
	multimap<int, Worker, MyCompare>mWorker;
	setGroup(vWorker, mWorker);

	// 3 ������ʾԱ��
	showWorkerByGrourp(mWorker);

	// 4 ���������Ա��
	


	return 0;
}