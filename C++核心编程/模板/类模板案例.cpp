#include<iostream>
using namespace std;
#include "MyArray.hpp"
#include<string>

//测试内置数据类型
void test01()
{
	MyArray<int> arr1(10);
	MyArray<int> arr2(arr1);
	MyArray<int> arr3(100);
	arr3 = arr1;
}


void printPersonArray(MyArray<int>& arr)
{
	cout << "打印输出：" << endl;
	for (int i = 0; i < arr.getSize(); i++) {
		cout <<arr[i] << "\t";
	}
	cout << endl;

	cout << "容量: " << arr.getCapacity() << endl;
	cout<<"大小: "<< arr.getSize() << endl;

}

void test02()
{
	MyArray <int>arr1(5);
	for (int i = 0; i < 5; i++)
	{
		// 利用尾插法向数组中插入数据
		arr1.Push_Back(i);
	}
	printPersonArray(arr1);

	MyArray <int>arr2(arr1);
	printPersonArray(arr2);
	arr2.Pop_Back(); // 尾删
	printPersonArray(arr2);
}


//测试自定义数据类型
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
		cout << "姓名：" << personArr[i].m_Name << " 年龄： " << personArr[i].m_Age << endl;
	}
	cout << "容量: " << personArr.getCapacity() << endl;
	cout << "大小: " << personArr.getSize() << endl;
}

void test03()
{
	MyArray<Person> arr(10);
	Person p1("孙悟空", 30);
	Person p2("韩信", 20);
	Person p3("妲己", 18);
	Person p4("王昭君", 15);
	Person p5("赵云", 24);
	//插入数据
	arr.Push_Back(p1);
	arr.Push_Back(p2);
	arr.Push_Back(p3);
	arr.Push_Back(p4);
	arr.Push_Back(p5);

	printPersonArray(arr);


}
//void test02()
//{
//	//创建数组
//	MyArray<Person> pArray(10);
//	Person p1("孙悟空", 30);
//	Person p2("韩信", 20);
//	Person p3("妲己", 18);
//	Person p4("王昭君", 15);
//	Person p5("赵云", 24);
//
//	//插入数据
//	pArray.Push_back(p1);
//	pArray.Push_back(p2);
//	pArray.Push_back(p3);
//	pArray.Push_back(p4);
//	pArray.Push_back(p5);
//
//	printPersonArray(pArray);
//
//	cout << "pArray的大小：" << pArray.getSize() << endl;
//	cout << "pArray的容量：" << pArray.getCapacity() << endl;
//
//}

int main() {

	test03();

	//system("pause");

	return 0;
}