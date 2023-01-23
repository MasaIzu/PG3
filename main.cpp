#include "Circle.h"
#include "Rectangle.h"
#include "IShape.h"

int main() {
	// サイズ決め
	int size = 2;
	IShape* ishape[] =
	{
		new Circle,
		new Rectangle
	};

	// 描画
	for (int i = 0; i < size; i++)
	{
		ishape[i]->Draw();
		ishape[i]->Size();
	}

	// 消す
	for (int i = 0; i < size; i++)
	{
		ishape[i]->~IShape();
	}


	return 0;
}