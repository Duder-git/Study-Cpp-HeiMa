//#include<iostream>
//using namespace std;
//#include<string>
//// 重载关系运算符
//
//class Person
//{
//public:
//	Person(string name, int age)
//	{
//		m_Name = name;
//		m_Age = age;
//	}
//
	// 重载 ==
	//bool operator==(Person& p)
	//{
	//	if (this->m_Name == p.m_Name && this->m_Age == p.m_Age)
	//		return true;
	//	
	//	return false;
	//}

	//// 重载 !=
	//bool operator!=(Person& p)
	//{
	//	if (this->m_Name == p.m_Name && this->m_Age == p.m_Age)
	//		return false;

	//	return true;
	//}
//	string m_Name;
//	int m_Age;
//};
//
//void test01()
//{
//	Person p1("Tom", 18);
//	Person p2("Tom", 18);
//
//	if (p1 == p2)
//		cout << "两者相等" << endl;
//	else
//		cout << "两者不等" << endl;
//
//	if (p1 != p2)
//		cout << "两者不等" << endl;
//	else
//		cout << "两者相等" << endl;
//}
//
//int main()
//{
//	test01();
//	return 0;
//}
//
