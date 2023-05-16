// �Լ���ͨ�õ�������
#pragma once
#include <iostream>
using namespace std;

template<class T>
class MyArray
{
public:
	// ���캯�� �вι���
	MyArray(int capacity)
	{
		//cout << "MyArray ���вι���" << endl;
		m_Capacity = capacity;
		m_Size = 0;
		pAddress = new T[m_Capacity];
	}

	// �������캯��
	MyArray(const MyArray& arr)
	{
		//cout << "MyArray �Ŀ�������" << endl;
		m_Capacity = arr.m_Capacity;
		m_Size = arr.m_Size;
		// ���
		pAddress = new T[arr.m_Capacity];
		// ��arr�����ݿ���
		for (int i = 0; i < m_Size; i++)
		{
			pAddress[i] = arr.pAddress[i];
		}
	}

	// ����=
	MyArray& operator=(const MyArray& arr)
	{
		//cout << "MyArray ��operator=����" << endl;
		// �ж�ԭ���������Ƿ������ݣ������ͷ�
		if (this->pAddress != NULL)
		{
			delete[] pAddress;
			pAddress = NULL;
			m_Capacity = 0;
			m_Size = 0;
		}

		// ���
		m_Capacity = arr.m_Capacity;
		m_Size = arr.m_Size;
		pAddress = new T[arr.m_Capacity];
		// ��arr�����ݿ���
		for (int i = 0; i < m_Size; i++)
		{
			pAddress[i] = arr.pAddress[i];
		}
		return *this;
	}

	// β�巨
	void Push_Back(const T& val)
	{
		// �ж������Ƿ���ڴ�С
		if (m_Capacity == m_Size)
		{
			return;
		}
		pAddress[m_Size] = val; // ����ĩβ��������
		m_Size++; // ���������С
	}

	// βɾ��
	void Pop_Back()
	{
		// �û����ʲ������һ��Ԫ��
		if (m_Size == 0)
		{
			return;
		}
		m_Size--;
	}

	// ͨ���±�Ԫ�ط���
	// ����������

	T& operator[](int index)
	{
		return pAddress[index];
	}

	// ������������
	int getCapacity()
	{
		return m_Capacity;
	}

	// ��������
	int getSize()
	{
		return m_Size;
	}

	// ��������
	~MyArray()
	{
		//cout << "MyArray ����������" << endl;
		if (pAddress != NULL)
		{
			delete[] this->pAddress;
			this->pAddress = NULL;
			this->m_Capacity = 0;
			this->m_Size = 0;
		}
	}

private:
	T* pAddress;	// ָ��ָ��������ٿռ��ַ
	int m_Capacity; // ����
	int m_Size;		// ��С
};