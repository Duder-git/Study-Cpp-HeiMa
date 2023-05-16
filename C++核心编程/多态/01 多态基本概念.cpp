//#include<iostream>
//using namespace std;
//
//// 多态
//
//// 动物类
//class Animal
//{
//public:
//	virtual void speak()
//	{
//		cout << "动物在说话" << endl;
//	}
//};
//
//
//// 猫类
//class Cat :public Animal
//{
//public:
//	void speak()
//	{
//		cout << "小猫在说话" << endl;
//	}
//};
//
//// 狗类
//class Dog :public Animal
//{
//public:
//	void speak()
//	{
//		cout << "小狗在说话" << endl;
//	}
//};
//
//
//
//// 执行说话的函数
//// 地址早绑定 在编译阶段确定函数地址
//// 想执行猫说话，不能提前绑定，实现地址晚绑定
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
//	cout << "Animal空间" << sizeof(Animal) << endl;
//	cout << "一个指针空间"<< sizeof(int*) << endl;
//}
//
//int main()
//{
//
//	test01();
//	test02();
//	return 0;
//}