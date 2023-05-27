#include "student.h"


//����
Student::Student()
{

}

// �вι���
Student::Student(int id, string name, string pwd)
{
	m_Id = id;
	m_Name = name;
	m_Pwd = pwd;

	initVector();
}


//�˵�����
void Student::operMenu()
{
	cout << "��ӭѧ������" << m_Name << "��¼��" << endl;
	cout << "\t\t ---------------------------------- \n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          1.����ԤԼ              |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          2.�鿴�ҵ�ԤԼ          |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          3.�鿴����ԤԼ          |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          4.ȡ��ԤԼ              |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          0.ע����¼              |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t ---------------------------------- \n";
	cout << "��ѡ�����Ĳ�����" << endl;
}

//����ԤԼ
void Student::applyOrder()
{
	cout << "��������ʱ��Ϊ��һ�����壡" << endl;
	cout << "����������ԤԼ��ʱ�䣺" << endl;
	cout << "1����һ" << endl;
	cout << "2���ܶ�" << endl;
	cout << "3������" << endl;
	cout << "4������" << endl;
	cout << "5������" << endl;


	int date = 0;		// �ܼ�
	int interval = 0;	// ������
	int room = 0;		// ���Ż���

	while (true)
	{
		cin >> date;
		if (date >= 1 && date <= 5)
		{
			break;
		}
		cout << "������������������" << endl;
	}


	cout << "����������ԤԼ��ʱ��Σ�" << endl;
	cout << "1������" << endl;
	cout << "2������" << endl;
	cout << "3������" << endl;

	while (true)
	{
		cin >> interval;
		if (interval >= 1 && interval <= 3)
		{
			break;
		}
		cout << "������������������" << endl;
	}


	cout << "�����ź��������£�" << endl;
	for (vector<ComputerRoom>::iterator it = vCom.begin(); it != vCom.end(); it++)
	{
		(*it).showMassage();
	}
	cout << "��ѡ�������" << endl;
	while (true)
	{
		cin >> room;
		if (room >= 1 && room <= 3)
		{
			break;
		}
		cout << "������������������" << endl;
	}

	// д��ԤԼ�ļ�
	writeMassage(date, interval, room, 1);


	cout << "ԤԼ�ɹ��������" << endl;

	system("pause");
	system("cls");
}

//�鿴�ҵ�ԤԼ
void Student::showMyOrder()
{
	OrderFile of;
	if (of.m_Size == 0)
	{
		cout << "��ԤԼ��¼" << endl;
		system("pause");
		system("cls");
		return;
	}
	map<string, string> m;
	for (map<int, map<string, string>>::iterator it = of.m_orderData.begin(); it != of.m_orderData.end(); it++)
	{
		m = (*it).second;
		if (atoi(m["stuId"].c_str()) == m_Id)// stringתcharתint
		{
			printOrder(m);
		}
	}
	system("pause");
	system("cls");
}

void Student::showAllOrder()
{
	OrderFile of;
	of.showAllOrder();
}


//ȡ��ԤԼ
void Student::cancelOrder()
{
	OrderFile of;
	if (of.m_Size == 0)
	{
		cout << "��ԤԼ��¼" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "����л�ԤԼ�ɹ��ļ�¼���£�" << endl;

	vector<int>v; // �����Ҫ�޸ĵļ�¼
	int index = 1;

	map<string, string> m;
	for (map<int, map<string, string>>::iterator it = of.m_orderData.begin(); it != of.m_orderData.end(); it++)
	{
		m = (*it).second;
		if (atoi(m["stuId"].c_str()) == m_Id)
		{
			if (m["status"] == "1" || m["status"] == "2")
			{
				v.push_back((*it).first);
				cout << index++ << "��";
				printOrder(m);
			}
		}
	}

	cout << "������ȡ���ļ�¼, 0 ����" << endl;
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
			of.m_orderData[v[select - 1]]["status"] = "0";

			of.updateOrder();

			cout << "��ȡ��ԤԼ" << endl;
			break;
		}
		cout << "������������������" << endl;
	}

	system("pause");
	system("cls");
}

// ���
void Student::showMassage()
{
	cout << "ѧ�ţ�" << m_Id << "\t������" << m_Name << endl;
}


// �˵�����
void Student::showMenu()
{
	while (true)
	{
		// ѧ���˵�
		operMenu();
		OrderFile of;

		int select = 0;
		cin >> select;

		if (select == 1)  //����ԤԼ
		{
			cout << "����ԤԼ" << endl;
			applyOrder();
		}
		else if (select == 2) //�鿴����ԤԼ
		{
			cout << "�鿴����ԤԼ" << endl;
			showMyOrder();
		}
		else if (select == 3) //�鿴����
		{
			cout << "�鿴����ԤԼ" << endl;
			showAllOrder();

		}
		else if (select == 4) //ȡ��ԤԼ
		{
			cout << "ȡ��ԤԼ" << endl;
			cancelOrder();
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

void Student::initVector()
{
	// ��ȡ������Ϣ
	ifstream ifs;
	ifs.open(COMPUTER_FILE, ios::in);
	vCom.clear();
	ComputerRoom c;
	while (ifs >> c.m_ComId && ifs >> c.m_MaxNum)
	{
		vCom.push_back(c);
	}
	//cout << "��ǰ��������Ϊ��" << vCom.size() << endl;

	ifs.close();
}

// д��order�ļ� һ��
void Student::writeMassage(int date, int interval, int room, bool status)
{
	ofstream ofs(ORDER_FILE, ios::app);
	ofs << "date:" << date << "\t";
	ofs << "interval:" << interval << "\t";
	ofs << "stuId:" << m_Id << "\t";
	ofs << "stuName:" << m_Name << "\t";
	ofs << "roomId:" << room << "\t";
	ofs << "status:" << status << endl;
	ofs.close();
}

