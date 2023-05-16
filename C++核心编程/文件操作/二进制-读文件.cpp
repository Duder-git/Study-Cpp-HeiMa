//#include <iostream>
//using namespace std;
//
//#include <fstream>
//#include <string>
//
//class Person
//{
//public:
//	char m_Name[64];
//	int m_Age;
//};
//
//void test01()
//{
//	// 创建流对象
//	ifstream ifs;
//	// 打开文件
//	ifs.open("person.txt", ios::in | ios::binary);
//	// 是否打开成功
//	if (!ifs.is_open())
//	{
//		cout << "文件打开失败" << endl;
//	}
//	// 都数据
//	Person p;
//	ifs.read((char*)&p, sizeof(p));
//
//	cout << "姓名： " << p.m_Name << " 年龄： " << p.m_Age << endl;
//}
//
//int main() {
//
//	test01();
//
//	system("pause");
//
//	return 0;
//}