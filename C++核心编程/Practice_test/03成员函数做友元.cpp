#include<iostream>
using namespace std;
#include<string>

// 类做友元
class Building; // 提前声明 不要报错
class GoodGuy
{
public:
    GoodGuy();

    void visit();  // 参观函数 ，访问Building中的私有成员
    void visit2();  //不可以访问Building中的私有成员

    Building* building;
};

class Building
{
    // GoodGuy下的visit是好朋友，可以访问私有成员
    friend void GoodGuy::visit();
public:
    // 构造函数
    Building();

public:
    string m_SittingRoom;
private:
    string m_BedRoom;
};


// 类外写成员函数
GoodGuy::GoodGuy()
{
    // 创建建筑物对象
    building = new Building;
}

void GoodGuy::visit()
{
    cout << "visit正在访问：" << building->m_SittingRoom << endl;
    cout << "visit正在访问：" << building->m_BedRoom << endl;
}

void GoodGuy::visit2()
{
    cout << "visit2正在访问：" << building->m_SittingRoom << endl;
    //cout << "好基友正在访问：" << building->m_BedRoom << endl;
}

Building::Building()
{
    m_SittingRoom = "客厅";
    m_BedRoom = "卧室";
}

// 测试用例
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