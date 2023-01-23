#include "Rectangle.h"
#include <stdio.h>
Rectangle::~Rectangle()
{
	printf("lŠp‚ªÁ‚¦‚½\n");
}

void Rectangle::Draw()
{
	printf("lŠp‚ª‚Å‚«‚½\n");
}

void Rectangle::Size()
{
	int result = sizeX * sizeY;
	printf("–ÊÏ:%d\n", result);
}