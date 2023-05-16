//#include<iostream>
//using namespace std;
//#include<string>
//
//// 建筑物
//class Building
//{
//    // goodguy全局函数是Building好朋友，可以访问Building中私有内容
//    friend void goodguy(Building* building);  // 全局函数声明
//public:
//    // 构造函数
//    Building()
//    {
//        m_SittingRoom = "客厅";
//        m_BedRoom = "卧室";
//    }
//public:
//    string m_SittingRoom;
//private:
//    string m_BedRoom;
//};
//
//// 全局函数 building 当作指针使用
//void goodguy(Building *building) //指针接收
//{
//    cout << "好基友全局函数 正在访问：" << building->m_SittingRoom << endl;
//
//    cout << "好基友全局函数 正在访问：" << building->m_BedRoom << endl;
//}
//void test01()
//{
//    Building building;
//    goodguy(&building); // 传入地址
//}
//
//
//int main()
//{
//    test01();
//    return 0;
//}