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
////�������ļ�  д�ļ�
//void test01()
//{
//	//1������ͷ�ļ�
//
//	//2��������������� �����ļ�
//	//ofstream ofs("person.txt", ios::out | ios::binary); // '|' λ�������
//
//	//3��������������� Ȼ����ļ�
//	ofstream ofs;
//	ofs.open("person.txt", ios::out | ios::binary);
//
//	// ���ļ����ж��ļ��Ƿ�򿪳ɹ�
//	if (!ofs.is_open())
//	{
//		cout << "�ļ���ʧ��" << endl;
//		return;
//	}
//
//	//4��д�ļ�
//	Person p = { "����"  , 18 };
//	ofs.write((const char*)&p, sizeof(p)); // ȡ��ַ ����ָ��תΪ�ַ�ָ��
//
//	//5���ر��ļ�
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