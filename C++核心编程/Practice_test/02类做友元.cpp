//#include<iostream>
//using namespace std;
//#include<string>
//
//// ������Ԫ
//class Building;
//class GoodGuy
//{
//public:
//    GoodGuy();
//
//    void visit();  // �ιۺ��� ������Building�е�����
//    Building* building;
//};
//
//class Building
//{
//    // GoodGuy �Ǳ���ĺ�����
//    friend class GoodGuy;
//public:
//    // ���캯��
//    Building();
//
//public:
//    string m_SittingRoom;
//private:
//    string m_BedRoom;
//};
//
//
//// ����д��Ա����
//GoodGuy::GoodGuy()
//{
//    // �������������
//    building = new Building;
//}
//
//void GoodGuy::visit()
//{
//    cout << "�û������ڷ��ʣ�" << building->m_SittingRoom << endl;
//    cout << "�û������ڷ��ʣ�" << building->m_BedRoom << endl;
//}
//
//Building::Building()
//{
//    m_SittingRoom = "����";
//    m_BedRoom = "����";
//}
//
//// ��������
//void test01()
//{
//    GoodGuy gg;
//    gg.visit();
//}
//
//
//int main()
//{
//    test01();
//    return 0;
//}