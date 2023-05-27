#include "system.h"



int main()
{
	int select = 0;
	while (true)
	{

		cout << "======================  ��ӭ�������ǲ��ͻ���ԤԼϵͳ  ====================="
			<< endl;
		cout << endl << "�������������" << endl;
		cout << "\t\t -------------------------------\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          1.ѧ������           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          2.��    ʦ           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          3.�� �� Ա           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          0.��    ��           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t -------------------------------\n";
		cout << "��������ѡ��: ";

		cin >> select;
		switch (select)
		{
		case 1: // ѧ��
			LonginIn("student.txt", 1);
			break;

		case 2: // ��ʦ
			LonginIn(TEACHER_FILE, 2);
			break;

		case 3: // ����Ա
			LonginIn(ADMIN_FILE, 3);
			break;

		case 0: // �˳�
			cout << "��ӭ�´�ʹ��" << endl;
			system("pause");
			return 0;
			break;

		default:
			cout << "��������������ѡ��" << endl;
			system("pause");
			system("cls");
			break;
		}

	}
	system("pause");

	return 0;
}

void LonginIn(string filename, int type)
{
	//Identify* person = NULL;

	ifstream ifs;
	ifs.open(filename, ios::in);

	// �ļ�������
	if (!ifs.is_open())
	{
		cout << "�ļ�������" << endl;
		ifs.close();
		return;
	}

	int id = 0;
	string name;
	string pwd;

	if (type == 1) // ѧ����¼
	{
		cout << "���������ѧ��" << endl;
		cin >> id;
	}
	else if (type == 2) // ��ʦ��¼
	{
		cout << "������ְ����" << endl;
		cin >> id;
	}
	cout << "�������û�����" << endl;
	cin >> name;

	cout << "���������룺 " << endl;
	cin >> pwd;

	if (type == 1)
	{
		//ѧ����¼��֤
		int fId;
		string fName;
		string fPwd;
		while (ifs >> fId && ifs >> fName && ifs >> fPwd)
		{
			//cout << fId << " " << fName << " " << fPwd <<endl;
			if (id = fId && name == fName && pwd == fPwd)
			{
				cout << "ѧ����֤��¼�ɹ���" << endl;
				system("pause");
				system("cls");
				Student student(id, name, pwd);
				// ����ѧ���˵�
				student.showMenu();
				return;
			}
		}

	}
	else if (type == 2)
	{
		//��ʦ��¼��֤
		int fId;
		string fName;
		string fPwd;
		while (ifs >> fId && ifs >> fName && ifs >> fPwd)
		{
			//cout << fId << " " << fName << " " << fPwd <<endl;
			if (id = fId && name == fName && pwd == fPwd)
			{
				cout << "��ʦ��֤��¼�ɹ���" << endl;
				system("pause");
				system("cls");
				Teacher teacher(id, name, pwd);
				// ������ʦ�˵�
				teacher.showMenu();
				return;
			}
		}
	}
	else if (type == 3)
	{
		//����Ա��¼��֤
		string fName;
		string fPwd;
		while (ifs >> fName && ifs >> fPwd)
		{
			//cout << fId << " " << fName << " " << fPwd <<endl;
			if (name == fName && pwd == fPwd)
			{
				cout << "����Ա��֤��¼�ɹ���" << endl;
				system("pause");
				system("cls");
				// ��������Ա����
				//person = new Manager(name, pwd);
				Manager manager(name, pwd);
				// �������Ա�˵�
				manager.showMenu();
				return;
			}
		}
	}

	cout << "��֤��¼ʧ��!" << endl;

	system("pause");
	system("cls");
	return;
}

