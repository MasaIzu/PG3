#include "Circle.h"
#include <stdio.h>
Circle::~Circle()
{
	printf("�܂邪������\n");
}

void Circle::Draw()
{
	printf("�܂邪���܂ꂽ\n");
}

void Circle::Size()
{
	float result = radius * radius * PI;
	printf("�ʐ�:%f\n", result);
}