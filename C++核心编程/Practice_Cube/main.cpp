// 立方体设计
// 1. 创建立方体类
// 2. 设计属性
// 3. 设计行为 获取立方体面积和体积
// 4. 利用全局函数判断两个立方体是否相等
// 5. 利用成员函数判断两个立方体是否相等

#include <iostream>
using namespace std;

#include "Cube.h"

int main() 
{
	Cube c1{};
	c1.setLength(10);
	c1.setWidth(10);
	c1.setHeight(10);
	cout << "c1的面积为: " << c1.calCubeS() << endl;
	cout << "c1的体积为: " << c1.calCubeV() << endl;

	// 创建第二个立方体
	Cube c2{};
	c2.setLength(10);
	c2.setWidth(10);
	c2.setHeight(11);

	// 利用全局函数判断
	bool ret = isSame(c1, c2);
	cout << "全局函数判断:";
	if (ret)
		cout << "c1 和 c2 是相等的" << endl;
	else
		cout << "c1 和 c2 是不相等的" << endl;
	
	// 利用成员函数判断
	ret = c1.isSameByClass(c2);
	cout << "成员函数判断:";
	if (ret)
		cout << "c1 和 c2 是相等的" << endl;
	else
		cout << "c1 和 c2 是不相等的" << endl;
	
	//system("pause");
	return 0;
}