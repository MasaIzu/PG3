#include<functional>
#include<stdio.h>
#include<windows.h>
#include<stdlib.h>
#include<time.h>


int main() {

    srand(time(nullptr));
    int getRand = rand() % 2;
    int player = 0;
    scanf_s("%d", &player);

   
    //�������Ă邩�ǂ���
    std::function<void(int, int)>fortune = [](int playerSelect, int random) {

        playerSelect == random ? printf("�哖����") : printf("�c�O�A�͂���");
    };

    std::function<void(std::function<void(int, int)>, int)>fx = [=](std::function<void(int, int)> x, int second) {
        printf("%d�b�ԑҋ@\n", second);
        Sleep(second * 1000);

        x(player, getRand);
    };

    fx(fortune, 3);

    return 0;
}
