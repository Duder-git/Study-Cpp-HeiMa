//#include <iostream>
//using namespace std;
//
//// ��ֵ���������
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
//		cout << "���ÿ������캯��" << endl;
//	}
//
//	//���� ��ֵ�����
//	Person& operator=(Person& p)
//	{
//		// ǳ����
//		//m_Age = p.m_Age;
//		//���ж��Ƿ��������ڶ�������������ͷŸɾ��������
//		if (m_Age != NULL)
//		{
//			delete m_Age;
//			m_Age = NULL;
//		}
//		// ���
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
//		cout << "������������" << endl;
//	}
//	int* m_Age;
//};
//
//void test01()
//{
//	Person p1(18);
//	cout << "p1������Ϊ��" << *p1.m_Age << endl;
//	Person p2(20);
//	cout << "p2������Ϊ��" << *p2.m_Age << endl;
//	p2 = p1; // ������ֵ
//	cout << "p2������Ϊ��" << *p2.m_Age << endl;
//	Person p3(p1); // ��������
//	cout << "p3������Ϊ��" << *p3.m_Age << endl;
//	Person p4 = p2 = p1; // ��ʽ���
//	cout << "p4������Ϊ��" << *p4.m_Age << endl;
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
