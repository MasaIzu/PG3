#include "Circle.h"
#include <stdio.h>
Circle::~Circle()
{
	printf("まるが消えた\n");
}

void Circle::Draw()
{
	printf("まるがうまれた\n");
}

void Circle::Size()
{
	float result = radius * radius * PI;
	printf("面積:%f\n", result);
}