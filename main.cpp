#include<functional>
#include<stdio.h>
#include<windows.h>
#include<stdlib.h>
#include<time.h>


int main() {

    srand(time(nullptr));
    int getRand = rand();
    int player = 0;
    scanf_s("%d", &player);

    std::function<int(int, int)>fx = [](int x, int second) {
        printf("%d�b�ԑҋ@\n", second);
        Sleep(second * 1000);

        return x % 2;
    };

    getRand = fx(getRand, 3);


    //�������Ă邩�ǂ���
    std::function<void(int, int)>fortune = [](int playerSelect, int random) {

        playerSelect == random ? printf("�哖����") : printf("�c�O�A�͂���");
    };

    fortune(player, getRand);

    //���l�ɋ������炻�̂܂܎g��ꂽ...
    return 0;
}