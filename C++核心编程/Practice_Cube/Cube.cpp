#include "Cube.h"

// 使用全局函数判断两个立方体是否相等
bool isSame(Cube& c1, Cube& c2) // 引用传递
{
	if (c1.getLength() == c2.getLength() && c1.getWidth() == c2.getWidth() && c1.getHeight() == c2.getHeight())
		return true;

	return false;
}