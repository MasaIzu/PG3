#include "Circle.h"
#include <stdio.h>
Circle::~Circle()
{
	printf("‚Ü‚é‚ªÁ‚¦‚½\n");
}

void Circle::Draw()
{
	printf("‚Ü‚é‚ª‚¤‚Ü‚ê‚½\n");
}

void Circle::Size()
{
	float result = radius * radius * PI;
	printf("–ÊÏ:%f\n", result);
}