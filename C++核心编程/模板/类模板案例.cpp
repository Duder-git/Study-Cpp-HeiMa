#include<iostream>
using namespace std;
#include "MyArray.hpp"
#include<string>

//����������������
void test01()
{
	MyArray<int> arr1(10);
	MyArray<int> arr2(arr1);
	MyArray<int> arr3(100);
	arr3 = arr1;
}


void printPersonArray(MyArray<int>& arr)
{
	cout << "��ӡ�����" << endl;
	for (int i = 0; i < arr.getSize(); i++) {
		cout <<arr[i] << "\t";
	}
	cout << endl;

	cout << "����: " << arr.getCapacity() << endl;
	cout<<"��С: "<< arr.getSize() << endl;

}

void test02()
{
	MyArray <int>arr1(5);
	for (int i = 0; i < 5; i++)
	{
		// ����β�巨�������в�������
		arr1.Push_Back(i);
	}
	printPersonArray(arr1);

	MyArray <int>arr2(arr1);
	printPersonArray(arr2);
	arr2.Pop_Back(); // βɾ
	printPersonArray(arr2);
}


//�����Զ�����������
class Person {
public:
	Person() {}
	Person(string name, int age) :m_Name(name), m_Age(age) {}
public:
	string m_Name;
	int m_Age;
};

void printPersonArray(MyArray<Person>& personArr)
{
	for (int i = 0; i < personArr.getSize(); i++) {
		cout << "������" << personArr[i].m_Name << " ���䣺 " << personArr[i].m_Age << endl;
	}
	cout << "����: " << personArr.getCapacity() << endl;
	cout << "��С: " << personArr.getSize() << endl;
}

void test03()
{
	MyArray<Person> arr(10);
	Person p1("�����", 30);
	Person p2("����", 20);
	Person p3("槼�", 18);
	Person p4("���Ѿ�", 15);
	Person p5("����", 24);
	//��������
	arr.Push_Back(p1);
	arr.Push_Back(p2);
	arr.Push_Back(p3);
	arr.Push_Back(p4);
	arr.Push_Back(p5);

	printPersonArray(arr);


}
//void test02()
//{
//	//��������
//	MyArray<Person> pArray(10);
//	Person p1("�����", 30);
//	Person p2("����", 20);
//	Person p3("槼�", 18);
//	Person p4("���Ѿ�", 15);
//	Person p5("����", 24);
//
//	//��������
//	pArray.Push_back(p1);
//	pArray.Push_back(p2);
//	pArray.Push_back(p3);
//	pArray.Push_back(p4);
//	pArray.Push_back(p5);
//
//	printPersonArray(pArray);
//
//	cout << "pArray�Ĵ�С��" << pArray.getSize() << endl;
//	cout << "pArray��������" << pArray.getCapacity() << endl;
//
//}

int main() {

	test03();

	//system("pause");

	return 0;
}