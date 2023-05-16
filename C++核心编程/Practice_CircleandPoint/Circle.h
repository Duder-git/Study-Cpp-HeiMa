#pragma once
#include <iostream>
using namespace std;
#include "Point.h"

// ‘≤¿‡
class Circle
{
public:
	void setR(int R);
	int getR();
	void setCenter(Point center);
	Point getCenter();
private:
	int m_R;
	Point m_Center;
};