#include <iostream>
using namespace std;
#include "workerManager.h"

#include "test.h" // ����ͷ�ļ�


void doSystem()
{
	WorkerManager wm;

	int choice = 0;
	while (true)
	{
		wm.Show_Menu();
		cout << "����������ѡ��:" << endl;
		cin >> choice;

		switch (choice)
		{
		case 0: //�˳�ϵͳ
			wm.exitSystem();
			break;
		case 1: //���ְ��
			wm.Add_Emp();
			break;
		case 2: //��ʾְ��
			wm.show_Emp();
			break;
		case 3: //ɾ��ְ��
			wm.Del_Emp();
			break;
		case 4: //�޸�ְ��
			wm.Mod_Emp();
			break;
		case 5: //����ְ��
			wm.Find_Emp();
			break;
		case 6: //����ְ��
			wm.Sort_Emp();
			break;
		case 7: //����ļ�
			wm.Clean_File();
			break;
		default:
			system("cls");
			break;
		}
	}
}
int main()
{
	// ����
	//test01();

	// ����ϵͳ
	doSystem();

	return 0;
}