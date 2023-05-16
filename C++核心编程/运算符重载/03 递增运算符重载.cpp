//#include <iostream>
//using namespace std;
//
//
//class MyInteger
//{
//	friend ostream& operator<<(ostream& cout, MyInteger myint);
//public:
//	// 构造函数
//	MyInteger() {}
//	MyInteger(int num) : m_Num(num) {}
//
//	// 重载前置++运算符
//	// 返回引用，一直对一个对象做递增
//	MyInteger& operator++()
//	{
//		// 先++
//		m_Num++;
//		return *this;
//	}
//
//	// 重载后置++运算符
//	// 使用int 做占位，区分前置++和后置++
//	// 后置返回值
//	MyInteger operator++(int)
//	{
//		MyInteger temp = *this;
//		m_Num++;
//		return temp;
//	}
//	
//private:
//	int m_Num = 0;
//};
//
//ostream& operator<<(ostream& cout, MyInteger myint)
//{
//	cout << "m_Num= " << myint.m_Num << endl;
//	return cout;
//}
//
//// 前置递增 测试用例
//void test01()
//{
//	MyInteger myint;
//
//	cout << ++(++myint);
//	cout << myint;
//}
//
//// 后置递增 测试用例
//void test02()
//{
//	MyInteger myint;
//
//	cout << myint++;
//	cout << myint++;
//	cout << myint;
//}
//
//
//int main()
//{
//	test01();
//	test02();
//	return 0;
//}
//
