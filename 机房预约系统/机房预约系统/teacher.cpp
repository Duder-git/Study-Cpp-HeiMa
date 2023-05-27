#include "teacher.h"
#include "orderFile.h"
#include<vector>

//����
Teacher::Teacher()
{

}

// �вι���
Teacher::Teacher(int id, string name, string pwd)
{
	m_EmpId = id;
	m_Name = name;
	m_Pwd = pwd;
}

//�˵�����
void Teacher::operMenu()
{
	cout << "��ӭ��ʦ��" << this->m_Name << "��¼��" << endl;
	cout << "\t\t ---------------------------------- \n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          1.�鿴����ԤԼ          |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          2.���ԤԼ              |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          0.ע����¼              |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t ---------------------------------- \n";
	cout << "��ѡ�����Ĳ����� " << endl;
}

//�鿴����ԤԼ
void Teacher::showAllOrder()
{
	OrderFile of;
	of.showAllOrder();
}

//���ԤԼ
void Teacher::validOrder()
{
	OrderFile of;
	if (of.m_Size == 0)
	{
		cout << "��ԤԼ��¼" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "����˵�ԤԼ��¼���£�" << endl;

	vector<int>v;
	int index = 1;

	// չʾԤԼ��¼
	map<string, string> m;
	for (map<int, map<string, string>>::iterator it = of.m_orderData.begin(); it != of.m_orderData.end(); it++)
	{
		m = (*it).second;
		if (m["status"] != "0")
		{
			v.push_back((*it).first);
			cout << index++ << "��";
			printOrder((*it).second);
		}

	}

	cout << "��������˵�ԤԼ��¼,0������" << endl;
	int select = 0;

	while (true)
	{
		cin >> select;
		if (select == 0)
		{
			break;
		}

		if (select > 0 && select <= v.size())
		{
			cout << "��������˽��" << endl;
			cout << "1��ͨ��" << endl;
			cout << "2����ͨ��" << endl;
			int ret = 0;
			cin >> ret;

			if (ret == 1)
			{
				// ͨ��
				of.m_orderData[v[select - 1]]["status"] = "2";
			}
			else
			{
				// ���δͨ��
				of.m_orderData[v[select - 1]]["status"] = "-1";
			}

			of.updateOrder();

			cout << "�����ϣ�" << endl;
			break;
		}
		cout << "������������������" << endl;
	}

	system("pause");
	system("cls");
}



// ���
void Teacher::showMassage()
{
	cout << "ְ���ţ�" << m_EmpId << "\t������" << m_Name << endl;
}

// �˵�����
void Teacher::showMenu()
{
	while (true)
	{
		// ��ʦ�˵�
		operMenu();

		int select = 0;

		cin >> select;

		if (select == 1)
		{
			cout << "�鿴����ԤԼ" << endl;
			showAllOrder();
		}
		else if (select == 2)
		{
			cout << "���ԤԼ" << endl;
			validOrder();
		}
		else
		{
			cout << "ע���ɹ�" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}

