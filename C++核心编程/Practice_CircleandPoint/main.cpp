#include <iostream>
using namespace std;

#include "Point.h"
#include "Circle.h"
// ���Բ�Ĺ�ϵ ����
// ����
//class Point
//{
//public:
//	void setPoint(int x, int y)
//	{
//		m_x = x;
//		m_y = y;
//	}
//	int getX()
//	{
//		return m_x;
//	}
//	int getY()
//	{
//		return m_y;
//	}
//private:
//	int m_x;
//	int m_y;
//};

// Բ��
//class Circle
//{
//public:
//	void setR(int R)
//	{
//		m_R = R;
//	}
//	int getR()
//	{
//		return m_R;
//	}
//	void setCenter(Point center)
//	{
//		m_Center = center;
//	}
//	Point getCenter()
//	{
//		return m_Center;
//	}
//
//private:
//	int m_R;
//	Point m_Center;
//};
void isInCircle(Circle& c, Point& p);

void isInCircle(Circle& c, Point& p)
{
	// �뾶ƽ��
	double distance = (c.getCenter().getX() - p.getX()) * (c.getCenter().getX() - p.getX())
		+ (c.getCenter().getY() - p.getY()) * (c.getCenter().getY() - p.getY());

	// ����ƽ��
	int rDistance = c.getR() * c.getR();
	
	if (distance == rDistance)
		cout << "����Բ��" << endl;
	else if (distance > rDistance)
		cout << "����Բ��" << endl;
	else
		cout << "����Բ��" << endl;
}

int main()
{
	Point center{};
	center.setPoint(10, 0);

	Circle c{};
	c.setCenter(center);
	c.setR(10);
	
	Point p1{};
	p1.setPoint(0, 0);

	Point p2{};
	p2.setPoint(0, 1);

	Point p3{};
	p3.setPoint(1, 0);
	isInCircle(c, p3);

	return 0;
}