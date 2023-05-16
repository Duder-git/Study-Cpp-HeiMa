//#include<iostream>
//using namespace std;
//#include<string>
//// 分别利用普通写法和多态技术实现
//
//
//// 普通写法
//class Calculator
//{
//public:
//	int getResult(string oper)
//	{
//		if (oper == "+")
//			return m_Num1 + m_Num2;
//		else if (oper == "-")
//			return m_Num1 - m_Num2;
//		else if (oper == "*")
//			return m_Num1 * m_Num2;
//		else if (oper == "/")
//			return m_Num1 / m_Num2;
//	}
//	// 如果扩展新功能，需要修改源码
//	// 开闭原则
//
//	int m_Num1;
//	int m_Num2;
//};
//
//void test01()
//{
//	Calculator c;
//	c.m_Num1 = 20;
//	c.m_Num2 = 10;
//
//	cout << c.m_Num1 << "+" << c.m_Num2 << "=" << c.getResult("+") << endl;
//	cout << c.m_Num1 << "-" << c.m_Num2 << "=" << c.getResult("-") << endl;
//	cout << c.m_Num1 << "*" << c.m_Num2 << "=" << c.getResult("*") << endl;
//	cout << c.m_Num1 << "/" << c.m_Num2 << "=" << c.getResult("/") << endl;
//}
//
//// 利用计算器抽象
//class AbstractCaculator
//{
//public:
//
//	virtual int getResult()
//	{
//		return 0;
//	}
//
//	int m_Num1;
//	int m_Num2;
//};
//// 加法计算器类
//class AddCalculator : public AbstractCaculator
//{
//public:
//	virtual int getResult() // virtual 可带可不带
//	{
//		return m_Num1 + m_Num2;
//	}
//};
//// 乘法计算器类
//class MulCalculator : public AbstractCaculator
//{
//public:
//	virtual int getResult() // virtual 可带可不带
//	{
//		return m_Num1 * m_Num2;
//	}
//};
//// 减法运算类
//class SubCalculator : public AbstractCaculator
//{
//public:
//	virtual int getResult() // virtual 可带可不带
//	{
//		return m_Num1 - m_Num2;
//	}
//};
//
//void test02()
//{
//	// 多态使用条件
//	// 父类指针或者引用指向子类对象
//
//	// 加法运算
//	//AbstractCaculator* abc = new AddCalculator;
//	AbstractCaculator* abc = new MulCalculator;
//	abc->m_Num1 = 40;
//	abc->m_Num2 = 20;
//
//	//cout << abc->m_Num1 << "+" << abc->m_Num2 << "=" << abc->getResult() << endl;
//	//cout << abc->m_Num1 << "-" << abc->m_Num2 << "=" << abc->getResult() << endl;
//	cout << abc->m_Num1 << "*" << abc->m_Num2 << "=" << abc->getResult() << endl;
//	// 堆区数据，用完销毁
//	delete abc;
//}
//
//int main() {
//	test02();
//
//	return 0;
//}