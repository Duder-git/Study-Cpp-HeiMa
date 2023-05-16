#include "test.h"


void test01()
{
	Worker* worker = NULL;
	worker = new Employee(1, "张三", 1,1);
	worker->showInfo();
	delete worker;

	worker = new Manager(2, "李四", 2,2);
	worker->showInfo();
	delete worker;

	worker = new Boss(3, "王五", 3,3);
	worker->showInfo();
	delete worker;
}