#include "Rectangle.h"
#include <stdio.h>
Rectangle::~Rectangle()
{
	printf("�l�p��������\n");
}

void Rectangle::Draw()
{
	printf("�l�p���ł���\n");
}

void Rectangle::Size()
{
	int result = sizeX * sizeY;
	printf("�ʐ�:%d\n", result);
}