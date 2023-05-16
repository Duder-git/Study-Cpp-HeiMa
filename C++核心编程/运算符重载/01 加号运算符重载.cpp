//#include<iostream>
//using namespace std;
//
//
//class Person
//{
//	friend Person operator+(Person& p1, Person& p2);
//	friend Person operator+(Person& p1, int a);
//public:
//	// 构造函数
//	Person(){}
//	Person(int a,int b): m_A(a),m_B(b){}
//
//	//// 成员函数重载+
//	//Person operator+(Person& p)
//	//{
//	//	Person temp;
//	//	temp.m_A = this->m_A + p.m_A;
//	//	temp.m_B = this->m_B + p.m_B;
//	//	return temp;
//	//}
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
//// 全局函数重载+号
//Person operator+(Person& p1, Person& p2)
//{
//	Person temp;
//	temp.m_A = p1.m_A + p2.m_A;
//	temp.m_B = p1.m_B + p2.m_B;
//	return temp;
//}
//
//// 全局函数重载+号 函数重载
//Person operator+(Person& p1, int a)
//{
//	Person temp;
//	temp.m_A = p1.m_A + a;
//	temp.m_B = p1.m_B;
//	return temp;
//}
//
//void test01()
//{
//	Person p1(10, 20);
//	Person p2(20, 20);
//	Person p3 = p1 + p2;
//	p3.output();
//	Person p4 = p1 + 10;
//	p4.output();
//}
//
//int main()
//{
//	test01();
//	return 0;
//}