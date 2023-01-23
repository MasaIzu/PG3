#pragma once
#include "IShape.h"
class Rectangle :public IShape
{
public:
	~Rectangle()override;
	void Draw()override;
	void Size()override;
private:
	int sizeX = 5, sizeY = 5;
};