#include <iostream>
using namespace std;

class Cube
{
public:
	// ��Ϊ
		// ���ó����
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
	// ��ȡ�����
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

	// ��ȡ���������
	double calCubeS()
	{
		return 2 * m_Length * m_Width + 2 * m_Width * m_Height + 2 * m_Length * m_Width;
	}
	// ��ȡ���������
	double calCubeV()
	{
		return m_Length * m_Width * m_Height;
	}
	// ���ó�Ա�����ж��Ƿ����
	bool isSameByClass(Cube& c)
	{
		if (m_Length == c.getLength() && m_Width == c.getWidth() && m_Height == c.getHeight())
			return true;

		return false;
	}


private:
	// ����
	double m_Length;
	double m_Width;
	double m_Height;
};

// ʹ��ȫ�ֺ����ж������������Ƿ����
bool isSame(Cube& c1, Cube& c2); // ���ô���