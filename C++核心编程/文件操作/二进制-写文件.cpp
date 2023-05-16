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
////二进制文件  写文件
//void test01()
//{
//	//1、包含头文件
//
//	//2、创建输出流对象 并打开文件
//	//ofstream ofs("person.txt", ios::out | ios::binary); // '|' 位或操作符
//
//	//3、创建输出流对象 然后打开文件
//	ofstream ofs;
//	ofs.open("person.txt", ios::out | ios::binary);
//
//	// 打开文件并判断文件是否打开成功
//	if (!ofs.is_open())
//	{
//		cout << "文件打开失败" << endl;
//		return;
//	}
//
//	//4、写文件
//	Person p = { "张三"  , 18 };
//	ofs.write((const char*)&p, sizeof(p)); // 取地址 把类指针转为字符指针
//
//	//5、关闭文件
//	ofs.close();
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