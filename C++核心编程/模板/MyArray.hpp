// 自己的通用的数组类
#pragma once
#include <iostream>
using namespace std;

template<class T>
class MyArray
{
public:
	// 构造函数 有参构造
	MyArray(int capacity)
	{
		//cout << "MyArray 的有参构造" << endl;
		m_Capacity = capacity;
		m_Size = 0;
		pAddress = new T[m_Capacity];
	}

	// 拷贝构造函数
	MyArray(const MyArray& arr)
	{
		//cout << "MyArray 的拷贝构造" << endl;
		m_Capacity = arr.m_Capacity;
		m_Size = arr.m_Size;
		// 深拷贝
		pAddress = new T[arr.m_Capacity];
		// 将arr中数据拷贝
		for (int i = 0; i < m_Size; i++)
		{
			pAddress[i] = arr.pAddress[i];
		}
	}

	// 重载=
	MyArray& operator=(const MyArray& arr)
	{
		//cout << "MyArray 的operator=调用" << endl;
		// 判断原来堆区中是否有数据，有先释放
		if (this->pAddress != NULL)
		{
			delete[] pAddress;
			pAddress = NULL;
			m_Capacity = 0;
			m_Size = 0;
		}

		// 深拷贝
		m_Capacity = arr.m_Capacity;
		m_Size = arr.m_Size;
		pAddress = new T[arr.m_Capacity];
		// 将arr中数据拷贝
		for (int i = 0; i < m_Size; i++)
		{
			pAddress[i] = arr.pAddress[i];
		}
		return *this;
	}

	// 尾插法
	void Push_Back(const T& val)
	{
		// 判断容量是否等于大小
		if (m_Capacity == m_Size)
		{
			return;
		}
		pAddress[m_Size] = val; // 数据末尾插入数据
		m_Size++; // 更新数组大小
	}

	// 尾删法
	void Pop_Back()
	{
		// 用户访问不到最后一个元素
		if (m_Size == 0)
		{
			return;
		}
		m_Size--;
	}

	// 通过下标元素访问
	// 重载中括号

	T& operator[](int index)
	{
		return pAddress[index];
	}

	// 返回数组容量
	int getCapacity()
	{
		return m_Capacity;
	}

	// 返回容量
	int getSize()
	{
		return m_Size;
	}

	// 析构函数
	~MyArray()
	{
		//cout << "MyArray 的析构函数" << endl;
		if (pAddress != NULL)
		{
			delete[] this->pAddress;
			this->pAddress = NULL;
			this->m_Capacity = 0;
			this->m_Size = 0;
		}
	}

private:
	T* pAddress;	// 指针指向堆区开辟空间地址
	int m_Capacity; // 容量
	int m_Size;		// 大小
};