#include "Rectangle.h"
#include <stdio.h>
Rectangle::~Rectangle()
{
	printf("四角が消えた\n");
}

void Rectangle::Draw()
{
	printf("四角ができた\n");
}

void Rectangle::Size()
{
	int result = sizeX * sizeY;
	printf("面積:%d\n", result);
}