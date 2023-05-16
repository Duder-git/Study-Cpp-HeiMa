//#include <iostream>
//using namespace std;
//
//// 赋值运算符重载
//
//class Person
//{
//public:
//	Person(int age)
//	{
//		m_Age = new int(age);
//	}
//	Person(const Person &p)
//	{
//		m_Age = new int(*p.m_Age);
//		cout << "调用拷贝构造函数" << endl;
//	}
//
//	//重载 赋值运算符
//	Person& operator=(Person& p)
//	{
//		// 浅拷贝
//		//m_Age = p.m_Age;
//		//先判断是否有属性在堆区，如果有先释放干净，再深拷贝
//		if (m_Age != NULL)
//		{
//			delete m_Age;
//			m_Age = NULL;
//		}
//		// 深拷贝
//		m_Age = new int(*p.m_Age);
//		return *this;
//	}
//
//	~Person()
//	{
//		if (m_Age != NULL)
//		{
//			delete m_Age;
//			m_Age = NULL;
//		}
//		cout << "调用析构函数" << endl;
//	}
//	int* m_Age;
//};
//
//void test01()
//{
//	Person p1(18);
//	cout << "p1的年龄为：" << *p1.m_Age << endl;
//	Person p2(20);
//	cout << "p2的年龄为：" << *p2.m_Age << endl;
//	p2 = p1; // 拷贝赋值
//	cout << "p2的年龄为：" << *p2.m_Age << endl;
//	Person p3(p1); // 拷贝构造
//	cout << "p3的年龄为：" << *p3.m_Age << endl;
//	Person p4 = p2 = p1; // 链式编程
//	cout << "p4的年龄为：" << *p4.m_Age << endl;
//}
//
//
//void test02()
//{
//	int a = 10;
//	int b = 20;
//	int c = 30;
//
//	c = b = a;
//	cout << "a = " << a << endl;
//	cout << "b = " << b << endl;
//	cout << "c = " << c << endl;
//}
//int main()
//{
//	test01();
//	//test02();
//
//	return 0;
//}
