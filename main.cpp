#include<functional>
#include<stdio.h>
#include<windows.h>
#include<stdlib.h>
#include<time.h>


int main() {

    printf("0�ɂȂ邩1�ɂȂ邩�\�z���ē��͂��Ă�������\n");
    srand(time(nullptr));
    int playerSelect = 0;
    scanf_s("%d", &playerSelect);

   
    //�������Ă邩�ǂ���
    std::function<void()>fortune = [=]() {

        playerSelect == rand() % 2 ? printf("�哖���� ") : printf("�c�O�A�͂��� ");
    };

	//�^�C���A�E�g
    std::function<void(std::function<void()>, int)>setTimeout = [=](std::function<void()> d, int second) {
        Sleep(second * 1000);
        d();
    };

    setTimeout(fortune, 3);

    system("pause");
    return 0;
}
