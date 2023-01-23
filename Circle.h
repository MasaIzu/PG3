#pragma once
#include "IShape.h"
class Circle :public IShape
{
public:
	~Circle()override;
	void Draw()override;
	void Size()override;
private:
	float PI = 3.14;
	int radius = 5;
};