#include<iostream>
using namespace std;
#include<string>

// ������Ԫ
class Building; // ��ǰ���� ��Ҫ����
class GoodGuy
{
public:
    GoodGuy();

    void visit();  // �ιۺ��� ������Building�е�˽�г�Ա
    void visit2();  //�����Է���Building�е�˽�г�Ա

    Building* building;
};

class Building
{
    // GoodGuy�µ�visit�Ǻ����ѣ����Է���˽�г�Ա
    friend void GoodGuy::visit();
public:
    // ���캯��
    Building();

public:
    string m_SittingRoom;
private:
    string m_BedRoom;
};


// ����д��Ա����
GoodGuy::GoodGuy()
{
    // �������������
    building = new Building;
}

void GoodGuy::visit()
{
    cout << "visit���ڷ��ʣ�" << building->m_SittingRoom << endl;
    cout << "visit���ڷ��ʣ�" << building->m_BedRoom << endl;
}

void GoodGuy::visit2()
{
    cout << "visit2���ڷ��ʣ�" << building->m_SittingRoom << endl;
    //cout << "�û������ڷ��ʣ�" << building->m_BedRoom << endl;
}

Building::Building()
{
    m_SittingRoom = "����";
    m_BedRoom = "����";
}

// ��������
void test01()
{
    GoodGuy gg;
    gg.visit();
    gg.visit2();
}


int main()
{
    test01();
    return 0;
}