// ���������
// 1. ������������
// 2. �������
// 3. �����Ϊ ��ȡ��������������
// 4. ����ȫ�ֺ����ж������������Ƿ����
// 5. ���ó�Ա�����ж������������Ƿ����

#include <iostream>
using namespace std;

#include "Cube.h"

int main() 
{
	Cube c1{};
	c1.setLength(10);
	c1.setWidth(10);
	c1.setHeight(10);
	cout << "c1�����Ϊ: " << c1.calCubeS() << endl;
	cout << "c1�����Ϊ: " << c1.calCubeV() << endl;

	// �����ڶ���������
	Cube c2{};
	c2.setLength(10);
	c2.setWidth(10);
	c2.setHeight(11);

	// ����ȫ�ֺ����ж�
	bool ret = isSame(c1, c2);
	cout << "ȫ�ֺ����ж�:";
	if (ret)
		cout << "c1 �� c2 ����ȵ�" << endl;
	else
		cout << "c1 �� c2 �ǲ���ȵ�" << endl;
	
	// ���ó�Ա�����ж�
	ret = c1.isSameByClass(c2);
	cout << "��Ա�����ж�:";
	if (ret)
		cout << "c1 �� c2 ����ȵ�" << endl;
	else
		cout << "c1 �� c2 �ǲ���ȵ�" << endl;
	
	//system("pause");
	return 0;
}