#include<stdlib.h>
#include"TestSingleton.h"

int main() {

	//インスタンスを取得して、すぐ使用
	TestSingleton::GetInstance();

	return 0;
}