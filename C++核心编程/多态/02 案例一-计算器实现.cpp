//#include<iostream>
//using namespace std;
//#include<string>
//// �ֱ�������ͨд���Ͷ�̬����ʵ��
//
//
//// ��ͨд��
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
//	// �����չ�¹��ܣ���Ҫ�޸�Դ��
//	// ����ԭ��
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
//// ���ü���������
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
//// �ӷ���������
//class AddCalculator : public AbstractCaculator
//{
//public:
//	virtual int getResult() // virtual �ɴ��ɲ���
//	{
//		return m_Num1 + m_Num2;
//	}
//};
//// �˷���������
//class MulCalculator : public AbstractCaculator
//{
//public:
//	virtual int getResult() // virtual �ɴ��ɲ���
//	{
//		return m_Num1 * m_Num2;
//	}
//};
//// ����������
//class SubCalculator : public AbstractCaculator
//{
//public:
//	virtual int getResult() // virtual �ɴ��ɲ���
//	{
//		return m_Num1 - m_Num2;
//	}
//};
//
//void test02()
//{
//	// ��̬ʹ������
//	// ����ָ���������ָ���������
//
//	// �ӷ�����
//	//AbstractCaculator* abc = new AddCalculator;
//	AbstractCaculator* abc = new MulCalculator;
//	abc->m_Num1 = 40;
//	abc->m_Num2 = 20;
//
//	//cout << abc->m_Num1 << "+" << abc->m_Num2 << "=" << abc->getResult() << endl;
//	//cout << abc->m_Num1 << "-" << abc->m_Num2 << "=" << abc->getResult() << endl;
//	cout << abc->m_Num1 << "*" << abc->m_Num2 << "=" << abc->getResult() << endl;
//	// �������ݣ���������
//	delete abc;
//}
//
//int main() {
//	test02();
//
//	return 0;
//}