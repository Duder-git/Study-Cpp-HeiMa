#include "manager.h"
#include <fstream>
#include <algorithm>
#include "globalFile.h"


//Ĭ�Ϲ���
Manager::Manager()
{

}

//�вι���
Manager::Manager(string name, string pwd)
{
	m_Name = name;
	m_Pwd = pwd;

	// ��ʼ������
	initVector();
}

//ѡ��˵�
void Manager::operMenu()
{
	cout << "��ӭ����Ա��" << m_Name << "��¼��" << endl;
	cout << "\t\t -------------------------------- \n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          1.����˺�            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          2.�鿴�˺�            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          3.�鿴����            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          4.���ԤԼ            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          0.ע����¼            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t -------------------------------- \n";
	cout << "��ѡ�����Ĳ����� " << endl;
}

//����˺�  
void Manager::addPerson()
{
	cout << "����������˺ŵ�����" << endl;
	cout << "1�����ѧ��" << endl;
	cout << "2�������ʦ" << endl;

	string fileName;
	string tip;
	string errorTip;
	
	int select = 0;
	cin >> select;
	if (select == 1)
	{
		fileName = STUDENT_FILE;
		tip = "������ѧ�ţ� ";
		errorTip = "ѧ���ظ�������������";
	}
	else if(select == 2)
	{
		fileName = TEACHER_FILE;
		tip = "������ְ����ţ�";
		errorTip = "ְ�����ظ�������������";
	}

	int id;
	string name;
	string pwd;

	cout << tip << endl;
	while (true)
	{
		cin >> id;
		bool ret = checkRepeat(id, select);
		if (ret)
			cout << errorTip << endl;
		else
			break;
	}
	cout << "������������ " << endl;
	cin >> name;
	cout << "���������룺 " << endl;
	cin >> pwd;

	ofstream ofs;
	ofs.open(fileName, ios::out | ios::app);
	ofs << id << "\t" << name << "\t" << pwd << endl;
	ofs.close();
		
	cout << "��ӳɹ�" << endl;
	system("pause");
	system("cls");
}

//�鿴�˺�
void Manager::showPerson()
{
	cout << "��ѡ��鿴���ݣ�" << endl;
	cout << "1���鿴����ѧ��" << endl;
	cout << "2���鿴������ʦ" << endl;

	int select = 0;

	cin >> select;

	if (select == 1)
	{
		cout << "����ѧ����Ϣ���£� " << endl;
		for (vector<Student>::iterator it = vStu.begin(); it != vStu.end(); it++)
		{
			(*it).showMassage();
		}
		//for_each(vStu.begin(), vStu.end(), printStudent);
	}
	else
	{
		cout << "������ʦ��Ϣ���£� " << endl;
		for (vector<Teacher>::iterator it = vTea.begin(); it != vTea.end(); it++)
		{
			(*it).showMassage();
		}
		//for_each(vTea.begin(), vTea.end(), printTeacher);
	}
	system("pause");
	system("cls");
}


//�鿴������Ϣ
void Manager::showComputer()
{
	cout << "������Ϣ���£�" << endl;
	for (vector<ComputerRoom>::iterator it = vCom.begin(); it != vCom.end(); it++)
	{
		(*it).showMassage();
	}
	system("pause");
	system("cls");
}

//���ԤԼ��¼
void Manager::cleanFile()
{
	ofstream ofs(ORDER_FILE, ios::trunc); // ���ڣ���ɾ���ٴ���
	ofs.close();

	cout << "��ճɹ���" << endl;
	system("pause");
	system("cls");

}

void Manager::showMenu()
{
	while (true)
	{
		// ����Ա�˵�
		operMenu();

		int select = 0;

		cin >> select;

		if (select == 1)  //����˺�
		{
			cout << "����˺�" << endl;
			addPerson();
		}
		else if (select == 2) //�鿴�˺�
		{
			cout << "�鿴�˺�" << endl;
			showPerson();
		}
		else if (select == 3) //�鿴����
		{
			cout << "�鿴����" << endl;
			showComputer();
		}
		else if (select == 4) //���ԤԼ
		{
			cout << "���ԤԼ" << endl;
			cleanFile();
		}
		else
		{
			//delete manager;
			cout << "ע���ɹ�" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}


void Manager::initVector()
{
	// ��ȡѧ���ļ�����Ϣ
	ifstream ifs;
	ifs.open(STUDENT_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "ѧ���ļ���ȡʧ�ܣ�" << endl;
	}

	vStu.clear();
	Student s;
	while (ifs >> s.m_Id && ifs >> s.m_Name && ifs >> s.m_Pwd)
	{
		vStu.push_back(s);
	}
	cout << "��ǰѧ������Ϊ��" << vStu.size() << endl;
	ifs.close();


	// ��ȡ��ʦ�ļ�����Ϣ
	ifs.open(TEACHER_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "��ʦ�ļ���ȡʧ�ܣ�" << endl;
	}

	vTea.clear();
	Teacher t;
	while (ifs >> t.m_EmpId && ifs >> t.m_Name && ifs >> t.m_Pwd)
	{
		vTea.push_back(t);
	}
	cout << "��ǰ��ʦ����Ϊ��" << vStu.size() << endl;
	ifs.close();

	// ��ȡ������Ϣ
	ifs.open(COMPUTER_FILE, ios::in);
	vCom.clear();
	ComputerRoom c;
	while (ifs >> c.m_ComId && ifs >> c.m_MaxNum)
	{
		vCom.push_back(c);
	}
	cout << "��ǰ��������Ϊ��" << vCom.size() << endl;

	ifs.close();
}



bool Manager::checkRepeat(int id,int type)
{
	if (type == 1)
	{
		for (vector<Student>::iterator it = vStu.begin(); it != vStu.end(); it++)
		{
			if (id == it->m_Id)
			{
				return true;
			}
		}
	}
	else
	{
		for (vector<Teacher>::iterator it = vTea.begin(); it != vTea.end(); it++)
		{
			if (id == it->m_EmpId)
			{
				return true;
			}
		}
	}
	return false;
}

void Manager::showMassage()
{
	cout << "������" << m_Name << "\t���룺" << m_Pwd << endl;
}




void printStudent(Student& s)
{
	cout << "ѧ�ţ�" << s.m_Id << "\t������" << s.m_Name << "\t���룺" << s.m_Pwd << endl;
}

void printTeacher(Teacher& t)
{
	cout << "ְ���ţ�" << t.m_EmpId << "\t������" << t.m_Name << "\t���룺" << t.m_Pwd << endl;
}