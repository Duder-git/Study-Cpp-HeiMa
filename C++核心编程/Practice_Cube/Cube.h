#include <iostream>
using namespace std;

class Cube
{
public:
	// 行为
		// 设置长宽高
	void setLength(double L)
	{
		m_Length = L;
	}
	void setWidth(double W)
	{
		m_Width = W;
	}
	void setHeight(double H)
	{
		m_Height = H;
	}
	// 获取长宽高
	double getLength()
	{
		return m_Length;
	}
	double getWidth()
	{
		return m_Width;
	}
	double getHeight()
	{
		return m_Height;
	}

	// 获取立方体面积
	double calCubeS()
	{
		return 2 * m_Length * m_Width + 2 * m_Width * m_Height + 2 * m_Length * m_Width;
	}
	// 获取立方体体积
	double calCubeV()
	{
		return m_Length * m_Width * m_Height;
	}
	// 利用成员函数判断是否相等
	bool isSameByClass(Cube& c)
	{
		if (m_Length == c.getLength() && m_Width == c.getWidth() && m_Height == c.getHeight())
			return true;

		return false;
	}


private:
	// 属性
	double m_Length;
	double m_Width;
	double m_Height;
};

// 使用全局函数判断两个立方体是否相等
bool isSame(Cube& c1, Cube& c2); // 引用传递