//#include<iostream>
//using namespace std;
//#include<string>
//
//// ������
//class Building
//{
//    // goodguyȫ�ֺ�����Building�����ѣ����Է���Building��˽������
//    friend void goodguy(Building* building);  // ȫ�ֺ�������
//public:
//    // ���캯��
//    Building()
//    {
//        m_SittingRoom = "����";
//        m_BedRoom = "����";
//    }
//public:
//    string m_SittingRoom;
//private:
//    string m_BedRoom;
//};
//
//// ȫ�ֺ��� building ����ָ��ʹ��
//void goodguy(Building *building) //ָ�����
//{
//    cout << "�û���ȫ�ֺ��� ���ڷ��ʣ�" << building->m_SittingRoom << endl;
//
//    cout << "�û���ȫ�ֺ��� ���ڷ��ʣ�" << building->m_BedRoom << endl;
//}
//void test01()
//{
//    Building building;
//    goodguy(&building); // �����ַ
//}
//
//
//int main()
//{
//    test01();
//    return 0;
//}