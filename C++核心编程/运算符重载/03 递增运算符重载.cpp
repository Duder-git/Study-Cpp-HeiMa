//#include <iostream>
//using namespace std;
//
//
//class MyInteger
//{
//	friend ostream& operator<<(ostream& cout, MyInteger myint);
//public:
//	// ���캯��
//	MyInteger() {}
//	MyInteger(int num) : m_Num(num) {}
//
//	// ����ǰ��++�����
//	// �������ã�һֱ��һ������������
//	MyInteger& operator++()
//	{
//		// ��++
//		m_Num++;
//		return *this;
//	}
//
//	// ���غ���++�����
//	// ʹ��int ��ռλ������ǰ��++�ͺ���++
//	// ���÷���ֵ
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
//// ǰ�õ��� ��������
//void test01()
//{
//	MyInteger myint;
//
//	cout << ++(++myint);
//	cout << myint;
//}
//
//// ���õ��� ��������
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
