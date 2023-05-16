#include "workerManager.h"

WorkerManager::WorkerManager()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	// 1. �ļ����������
	if (!ifs.is_open())
	{
		//cout << "�ļ�������" << endl;
		m_EmpNum = 0;// ��ʼ������Ϊ0
		m_FileIsEmpty = true;
		m_EmpArray = NULL;// ��ʼ��ָ��Ϊ��
		ifs.close();
		return;
	}

	// 2. �ļ�����������Ϊ��
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		//cout << "�ļ�Ϊ�գ�" << endl;
		m_EmpNum = 0;
		m_FileIsEmpty = true;
		m_EmpArray = NULL;
		ifs.close();
		return;
	}

	// 3. �ļ������Ҽ�¼����
	ifs.close();
	int num = get_EmpNum();
	//cout << "��¼ְ��������" << num << endl;
	m_EmpNum = num;

	// ���ٿռ�
	m_EmpArray = new Worker * [m_EmpNum];
	// ���ļ����ݴ�������
	init_Emp();
	// չʾ����
	//show_Emp();
}

WorkerManager::~WorkerManager()
{
	if (m_EmpArray != NULL)
	{
		delete[] m_EmpArray;
		m_EmpArray = NULL;
	}
}


void WorkerManager::Show_Menu()
{
	cout << "********************************************" << endl;
	cout << "*********  ��ӭʹ��ְ������ϵͳ�� **********" << endl;
	cout << "*************  0.�˳��������  *************" << endl;
	cout << "*************  1.����ְ����Ϣ  *************" << endl;
	cout << "*************  2.��ʾְ����Ϣ  *************" << endl;
	cout << "*************  3.ɾ����ְְ��  *************" << endl;
	cout << "*************  4.�޸�ְ����Ϣ  *************" << endl;
	cout << "*************  5.����ְ����Ϣ  *************" << endl;
	cout << "*************  6.���ձ������  *************" << endl;
	cout << "*************  7.��������ĵ�  *************" << endl;
	cout << "********************************************" << endl;
	cout << endl;
}

void WorkerManager::exitSystem()
{
	cout << "��ӭ�´�ʹ��" << endl;
	//system("pause");
	exit(0); // �˳�����
}

// �����ļ�
void WorkerManager::Save()
{
	ofstream ofs;
	ofs.open(FILENAME, ios::out);	// д�ļ�

	// ��ÿ���˵�����д���ļ���
	for (int i = 0; i < m_EmpNum; i++)
	{
		ofs << m_EmpArray[i]->m_ID << "\t"
			<< m_EmpArray[i]->m_Name << "\t"
			<< m_EmpArray[i]->m_DeptID << "\t"
			<< m_EmpArray[i]->m_Post << endl;
	}

	// �ر��ļ�
	ofs.close();
}

// ͳ���ļ�������
int WorkerManager::get_EmpNum()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);	// ���ļ�

	int id;
	string name;
	int dId;
	int post;

	int num = 0;
	while (ifs >> id && ifs >> name && ifs >> dId && ifs >> post)
	{
		// ͳ������
		num++;
	}
	ifs.close();

	return num;
}

void WorkerManager::Add_Emp()
{
	cout << "���������ְ��������" << endl;
	int addNum = 0;
	cin >> addNum;
	if (addNum > 0)
	{
		//���
		// �����¿ռ��С
		int newSize = m_EmpNum + addNum;

		// ���ٿռ�
		Worker** newSpace = new Worker * [newSize];

		// ��ԭ�����ݿ������¿ռ�
		if (m_EmpArray != NULL)
		{
			for (int i = 0; i < m_EmpNum; i++)
			{
				newSpace[i] = m_EmpArray[i];
			}
		}

		// ���������
		for (int i = 0; i < addNum; i++)
		{
			int id;
			string name;
			int deptID;
			int Post;

			cout << "������� " << i + 1 << "����ְ����Ϣ��" << endl;
			cout << "���ID��";
			cin >> id;
			cout << "������";
			cin >> name;
			cout << "����ID��";
			cin >> deptID;
			cout << "��ѡ����ְ����λ��" << endl;
			cout << "1. ��ְͨ��" << endl;
			cout << "2. ����" << endl;
			cout << "3. �ϰ�" << endl;
			cin >> Post;

			Worker* worker = NULL;
			switch (Post)
			{
			case 1:
				worker = new Employee(id, name, deptID, Post);
				break;
			case 2:
				worker = new Manager(id, name, deptID, Post);
				break;
			case 3:
				worker = new Boss(id, name, deptID, Post);
				break;
			default:
				break;
			}
			// ��������ְ�������浽������
			newSpace[m_EmpNum + i] = worker;

		}
		// �ͷſռ�
		delete[] m_EmpArray;
		// �����¿ռ�ָ��
		m_EmpArray = newSpace;

		// ����ְ������
		m_EmpNum = newSize;

		// ����ְ����Ϊ��
		m_FileIsEmpty = false;

		// ��ϵͳ�б��浽�ļ�
		Save();

		// ��ʾ
		cout << "�ɹ����" << addNum << "ְ��" << endl;

	}
	else
	{
		// �������
		cout << "�������" << endl;
	}

	// ������� �����Ļ�����ϼ�
	system("pause");
	system("cls");
}

// ��ʼ��Ա��
void WorkerManager::init_Emp()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int id;
	string name;
	int dId;
	int post;

	int index = 0;
	while (ifs >> id && ifs >> name && ifs >> dId && ifs >> post)
	{
		Worker* worker = NULL;
		if (post == 1)
			worker = new Employee(id, name, dId, post);
		else if (post == 2)
			worker = new Manager(id, name, dId, post);
		else if (post == 3)
			worker = new Boss(id, name, dId, post);

		m_EmpArray[index] = worker;
		index++;
	}
	// �ر��ļ�
	ifs.close();
}

// չʾ���ݿ�����
void WorkerManager::show_Emp()
{
	if (m_FileIsEmpty)
	{
		cout << "�ļ������ڻ���Ϊ��" << endl;
	}
	else
	{
		for (int i = 0; i < m_EmpNum; i++)
		{
			// ���ö�̬���ó���ӿ�
			m_EmpArray[i]->showInfo();
		}
	}
	system("pause");
	system("cls");
	//for (int i = 0; i < m_EmpNum; i++)
	//{
	//	cout << "ְ����ţ�" << m_EmpArray[i]->m_ID << "\t"
	//		<< "ְ��������" << m_EmpArray[i]->m_Name << "\t"
	//		<< "ְ�����ţ�" << m_EmpArray[i]->m_DeptID << "\t"
	//		<< "ְ��ְ��" << m_EmpArray[i]->m_Post << endl;
	//}
}

// ɾ��ְ��
void WorkerManager::Del_Emp()
{
	if (m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ�գ�" << endl;
	}
	else
	{
		//��ְ�����ɾ��
		cout << "��������Ҫɾ����ְ���ţ�" << endl;
		int id = 0;
		cin >> id;

		int index = IsExist(id);

		if (index != -1)  //˵��index��λ��������Ҫɾ��
		{
			for (int i = index; i < m_EmpNum - 1; i++)
			{
				delete m_EmpArray[i];
				m_EmpArray[i] = m_EmpArray[i + 1];
			}
			m_EmpNum--;

			Save(); //ɾ��������ͬ�����ļ���
			cout << "ɾ���ɹ���" << endl;
		}
		else
		{
			cout << "ɾ��ʧ�ܣ�δ�ҵ���ְ��" << endl;
		}
	}
	system("pause");
	system("cls");
}

// �ж�ְ���Ƿ���� ���ڷ���ְ����������λ�� ����Ϊ-1
int WorkerManager::IsExist(int id)
{
	int index = -1;
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		if (m_EmpArray[i]->m_ID == id)
		{
			index = i;
			break;
		}
	}
	return index;
}

// �޸�ְ�� ����ְ����Ŷ�ְ����Ϣ�����޸Ĳ�����
void WorkerManager::Mod_Emp()
{
	if (m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��߼�¼Ϊ�գ�" << endl;
		return;
	}

	cout << "�������޸�ְ���ı�ţ�" << endl;
	int id;
	cin >> id;

	int ret = IsExist(id);
	if (ret == -1)
	{
		cout << "�޸�ʧ�ܣ����޴���" << endl;
		return;
	}

	// �鵽��ŵ�ְ��
	delete m_EmpArray[ret];

	string newName = "";
	int newDeptId = 0;
	int newPost = 0;



	cout << "�ҵ����Ϊ" << id << "��ְ��" << endl;
	cout << "�����������֣�";
	cin >> newName;
	cout << "�������²��ţ�";
	cin >> newDeptId;
	cout << "��������ְλ��";
	cin >> newPost;

	Worker* worker = NULL;
	switch (newPost)
	{
	case 1:
		worker = new Employee(id, newName, newDeptId, newPost);
		break;
	case 2:
		worker = new Manager(id, newName, newDeptId, newPost);
		break;
	case 3:
		worker = new Boss(id, newName, newDeptId, newPost);
		break;
	default:
		break;
	}

	// �������ݵ�������
	m_EmpArray[ret] = worker;
	cout << "�޸ĳɹ���" << endl;

	// ���浽�ļ���
	Save();

	system("pause");
	system("cls");
}

// ����ְ��
void WorkerManager::Find_Emp()
{
	if (m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ�գ�" << endl;
		return;
	}

	cout << "��������ҷ�ʽ" << endl;
	cout << "1. ��ְ����Ų���" << endl;
	cout << "2. ����������" << endl;

	int select = 0;
	cin >> select;

	switch (select)
	{
	case 1:
		_Find_EmpbyID();
		break;
	case 2:
		_Find_EmpbyName();
		break;
	default:
		cout << "��������" << endl;
		break;
	}
	system("pause");
	system("cls");
}

void WorkerManager::_Find_EmpbyID()
{
	int id;
	cout << "���������ְ����ţ�" << endl;
	cin >> id;

	// ����ְ��
	int ret = IsExist(id);
	if (ret != -1)
	{
		cout << "���ҳɹ�����ְ����Ϣ���£�" << endl;
		this->m_EmpArray[ret]->showInfo();
	}
	else
	{
		cout << "����ʧ�ܣ����޴���" << endl;
	}
}

void WorkerManager::_Find_EmpbyName()
{
	string name;
	cout << "���������ְ��������" << endl;
	cin >> name;

	// ����ְ��
	bool flag = false;  //���ҵ��ı�־
	for (int i = 0; i < m_EmpNum; i++)
	{
		if (m_EmpArray[i]->m_Name == name)
		{
			cout << "���ҳɹ�����ְ����Ϣ���£�" << endl;
			m_EmpArray[i]->showInfo();

			flag = true;
		}
	}
	if (flag == false)
	{
		//���޴���
		cout << "����ʧ�ܣ����޴���" << endl;
	}
}


// �����ݿ��������
void WorkerManager::Sort_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ�գ�" << endl;
		return;
	}

	cout << "��ѡ������ʽ�� " << endl;
	cout << "0����ְ���Ž��н���" << endl;
	cout << "1����ְ���Ž�������" << endl;

	bool select = 0;
	cin >> select;

	// ð������
	for (int i = 0; i < m_EmpNum; i++)
	{
		int minOrMax = i;
		for (int j = i + 1; j < m_EmpNum; j++)
		{
			if (select) //����
			{
				if (m_EmpArray[minOrMax]->m_ID > m_EmpArray[j]->m_ID)
				{
					minOrMax = j;
				}
			}
			else //����
			{
				if (m_EmpArray[minOrMax]->m_ID < m_EmpArray[j]->m_ID)
				{
					minOrMax = j;
				}
			}
		}
		// ����λ��
		if (i != minOrMax)
		{
			Worker* temp = m_EmpArray[i];
			m_EmpArray[i] = m_EmpArray[minOrMax];
			m_EmpArray[minOrMax] = temp;
		}
	}

	cout << "����ɹ�,�������Ϊ��" << endl;
	Save();
	show_Emp();
}

// ��պ���ʵ��
void WorkerManager::Clean_File()
{
	cout << "�Ƿ�ȷ��������ݿ⣿" << endl;
	cout << "1. ȷ��" << endl;
	cout << "2. ����" << endl;

	int select = 0;
	cin >> select;

	if (select != 1)
	{
		cout << "δ��������ҳ��" << endl;
		system("pause");
		system("cls");
		return;
	}

	// �������
	//��ģʽ ios::trunc �������ɾ���ļ������´���
	ofstream ofs(FILENAME, ios::trunc);
	ofs.close();

	
	if (m_EmpArray != NULL)
	{
		// ��ɾ��ÿһ���������
		for (int i = 0; i < m_EmpNum; i++)
		{
			if (m_EmpArray[i] != NULL)
			{
				delete m_EmpArray[i];
			}
		}

		// ����������
		m_EmpNum = 0;

		// ɾ��workerָ������
		delete[] m_EmpArray;
		m_EmpArray = NULL;

		// �����ļ���ʶ
		m_FileIsEmpty = true;
	}

	cout << "��ճɹ���" << endl;
	system("pause");
	system("cls");

}