//#include<iostream>
//using namespace std;
//
//// ��̬
//
//// ������
//class Animal
//{
//public:
//	virtual void speak()
//	{
//		cout << "������˵��" << endl;
//	}
//};
//
//
//// è��
//class Cat :public Animal
//{
//public:
//	void speak()
//	{
//		cout << "Сè��˵��" << endl;
//	}
//};
//
//// ����
//class Dog :public Animal
//{
//public:
//	void speak()
//	{
//		cout << "С����˵��" << endl;
//	}
//};
//
//
//
//// ִ��˵���ĺ���
//// ��ַ��� �ڱ���׶�ȷ��������ַ
//// ��ִ��è˵����������ǰ�󶨣�ʵ�ֵ�ַ���
//void doSpeak(Animal &animal)
//{
//	animal.speak();
//}
//
//
//
//void test01()
//{
//	Cat cat;
//	doSpeak(cat);
//
//	Dog dog;
//	doSpeak(dog);
//}
//
//void test02()
//{
//	cout << "Animal�ռ�" << sizeof(Animal) << endl;
//	cout << "һ��ָ��ռ�"<< sizeof(int*) << endl;
//}
//
//int main()
//{
//
//	test01();
//	test02();
//	return 0;
//}