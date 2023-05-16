//#include<iostream>
//using namespace std;
//#include<string>
//
//// 类做友元
//class Building;
//class GoodGuy
//{
//public:
//    GoodGuy();
//
//    void visit();  // 参观函数 ，访问Building中的属性
//    Building* building;
//};
//
//class Building
//{
//    // GoodGuy 是本类的好朋友
//    friend class GoodGuy;
//public:
//    // 构造函数
//    Building();
//
//public:
//    string m_SittingRoom;
//private:
//    string m_BedRoom;
//};
//
//
//// 类外写成员函数
//GoodGuy::GoodGuy()
//{
//    // 创建建筑物对象
//    building = new Building;
//}
//
//void GoodGuy::visit()
//{
//    cout << "好基友正在访问：" << building->m_SittingRoom << endl;
//    cout << "好基友正在访问：" << building->m_BedRoom << endl;
//}
//
//Building::Building()
//{
//    m_SittingRoom = "客厅";
//    m_BedRoom = "卧室";
//}
//
//// 测试用例
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