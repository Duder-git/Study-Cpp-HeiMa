//#include <map>
//#include <iostream>
//#include <string>
//using namespace std;
//
//class MyCompare {
//public:
//	bool operator()(int v1, int v2) const{
//		return v1 < v2;
//	}
//};
//
//void test01()
//{
//	//默认从小到大排序
//	//利用仿函数实现从大到小排序
//	map<int, string, MyCompare> m;
//	string nameseed = "ABCDEFG";
//	string name;
//	for (int i = 0; i < 5; i++)
//	{
//		name = "name";
//		name += nameseed[i];
//		m.insert(make_pair(i, name));
//	}
//
//	for (map<int, string, MyCompare>::iterator it = m.begin(); it != m.end(); it++) {
//		cout << "key:" << it->first << " value:" << it->second << endl;
//	}
//}
//int main() {
//
//	test01();
//
//	system("pause");
//
//	return 0;
//}