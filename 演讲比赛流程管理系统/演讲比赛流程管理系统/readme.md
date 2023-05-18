# 演讲比赛管理系统

## 1. 管理系统需求

### 1 .1 比赛规则

* 学校举行一场演讲比赛，共有**12个人**参加。**比赛共两轮**，第一轮为淘汰赛，第二轮为决赛。
* 比赛方式：**分组比赛，每组6个人**；选手每次要随机分组，进行比赛
* 每名选手都有对应的**编号**，如 10001 ~ 10012 
* 第一轮分为两个小组，每组6个人。 整体按照选手编号进行**抽签**后顺序演讲。
* 当小组演讲完后，淘汰组内排名最后的三个选手，**前三名晋级**，进入下一轮的比赛。
* 第二轮为决赛，**前三名胜出**
* 每轮比赛过后需要**显示晋级选手的信息**

### 1.2 程序功能

* 开始演讲比赛：完成整届比赛的流程，每个比赛阶段需要给用户一个提示，用户按任意键后继续下一个阶段
* 查看往届记录：查看之前比赛前三名结果，每次比赛都会记录到文件中，文件用.csv后缀名保存
* 清空比赛记录：将文件中数据清空
* 退出比赛程序：可以退出当前程序

### 1.3 演讲比赛功能

比赛流程分析：
抽签 → 开始演讲比赛 → 显示第一轮比赛结果 → 
抽签 → 开始演讲比赛 → 显示前三名结果 → 保存分数



## 2. 程序开发

### 2.1 开发环境

* Windows SDK版本：win10
* 平台工具集：visual Studio 2022(v143)
* C++语言标准：ISO C++14 标准



### 2.2 菜单功能

功能描述：与用户的沟通界面

#### 菜单界面

```c++
void SpeechManager::show_Menu()
{
	cout << "********************************************" << endl;
	cout << "************* 欢迎参加演讲比赛  *************" << endl;
	cout << "*************  1.开始演讲比赛  *************" << endl;
	cout << "*************  2.查看往届记录  *************" << endl;
	cout << "*************  3.清空比赛记录  *************" << endl;
	cout << "*************  0.退出比赛程序  *************" << endl;
	cout << "********************************************" << endl;
	cout << endl;
}
```

#### 功能接口

```c++
int main() {

	SpeechManager sm;

	int choice = 0; //用来存储用户的选项

	while (true)
	{
		sm.show_Menu();

		cout << "请输入您的选择： " << endl;
		cin >> choice; // 接受用户的选项

		switch (choice)
		{
		case 1:  //开始比赛
			break;
		case 2:  //查看记录
			break;
		case 3:  //清空记录
			break;
		case 0:  //退出系统
			break;
		default:
			system("cls"); //清屏
			break;
		}
	}

	system("pause");

	return 0;
}
```



#### 退出功能

```
void SpeechManager::exitSystem()
{
	cout << "欢迎下次使用" << endl;
	system("pause");
	exit(0);
}
```





## 3. 创建管理类

**功能描述：**

- 提供菜单界面与用户交互
- 对演讲比赛流程进行控制
- 与文件的读写交互



### 功能定义

speechManager.h

```c++
#pragma once
#include<iostream>
using namespace std;

//演讲管理类
class SpeechManager
{
public:

	//构造函数
	SpeechManager();


	//析构函数
	~SpeechManager();
};
```



### 功能实现

speechManager.cpp

```c++
#include "speechManager.h"

SpeechManager::SpeechManager()
{
}

SpeechManager::~SpeechManager()
{
}
```







## 3. 演讲比赛功能

比赛流程分析：

抽签 → 开始演讲比赛 → 显示第一轮比赛结果 → 

抽签 → 开始演讲比赛 → 显示前三名结果 → 保存分数



### 创建选手类

* 选手类中的属性包含：选手姓名、分数
* 头文件中创建 speaker.h文件，并添加代码：

```C++
#pragma once
#include<iostream>
using namespace std;

class Speaker
{
public:
	string m_Name;  //姓名
	double m_Score[2]; //分数  最多有两轮得分
};
```





