#include "Cube.h"

// ʹ��ȫ�ֺ����ж������������Ƿ����
bool isSame(Cube& c1, Cube& c2) // ���ô���
{
	if (c1.getLength() == c2.getLength() && c1.getWidth() == c2.getWidth() && c1.getHeight() == c2.getHeight())
		return true;

	return false;
}