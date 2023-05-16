#include<iostream>
using namespace std;
#include<string>

// 函数调用运算符重载

class MyPrint
{
public:
	// 重载函数调用运算符
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
	myPrint("hello world"); // 使用起来非常类似函数调用，因此成为仿函数
	MyPrint02("hello world");
}

void test02()
{
	MyAdd myadd;
	int num = myadd(100, 100);
	cout << num << endl;
	// 匿名函数对象
	cout << MyAdd()(100, 100) << endl;
}
int main()
{
	test01();
	test02();
	return 0;
}