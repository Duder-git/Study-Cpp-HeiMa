//#include<iostream>
//using namespace std;
//
//
//class Person
//{
//	friend ostream& operator<<(ostream& cout, Person& p);
//public:
//	// 构造函数
//	Person() {}
//	Person(int a, int b) : m_A(a), m_B(b) {}
//
//	// 成员函数重载+
//	Person operator+(Person& p)
//	{
//		Person temp;
//		temp.m_A = this->m_A + p.m_A;
//		temp.m_B = this->m_B + p.m_B;
//		return temp;
//	}
//
//	// 成员函数重载左移运算符
//	// 一般不会使用成员函数，无法实现cout<<p;
//	//void operator<<(cout)  // p<<cout
//	//{
//
//	//}
//
//
//	// 输出函数
//	void output()
//	{
//		cout << "m_A: " << m_A << "  " << "m_B: " << m_B << endl;
//	}
//
//private:
//	int m_A;
//	int m_B;
//};
//
//// 只能利用全局函数重载左移运算符
//ostream& operator<<(ostream& cout, Person& p)
//{
//	cout << "m_A= " << p.m_A << "  " << "m_B= " << p.m_B << endl;
//	return cout;
//}
//
//void test01()
//{
//	Person p1(10, 20);
//	Person p2(20, 20);
//	Person p3 = p1 + p2;
//	p3.output();
//	cout << p3;
//	cout << p3 << "hi";
//}
//
//int main()
//{
//	test01();
//	return 0;
//}