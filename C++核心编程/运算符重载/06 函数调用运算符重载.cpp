#include<iostream>
using namespace std;
#include<string>

// �����������������

class MyPrint
{
public:
	// ���غ������������
	void operator()(string test)
	{
		cout << test << endl;
	}
};

void MyPrint02(string test)
{
	cout << test << endl;
}

class MyAdd
{
public:
	int operator()(int num1, int num2)
	{
		return num1 + num2;
	}

};

void test01()
{
	MyPrint myPrint;
	myPrint("hello world"); // ʹ�������ǳ����ƺ������ã���˳�Ϊ�º���
	MyPrint02("hello world");
}

void test02()
{
	MyAdd myadd;
	int num = myadd(100, 100);
	cout << num << endl;
	// ������������
	cout << MyAdd()(100, 100) << endl;
}
int main()
{
	test01();
	test02();
	return 0;
}