#include<functional>
#include<stdio.h>
#include<windows.h>
#include<stdlib.h>
#include<time.h>


int main() {

    printf("0か1&エンターキーを入力\n");
    srand(time(nullptr));
    int getRand = rand() % 2;
    int player = 0;
    scanf_s("%d", &player);

   
    //当たってるかどうか
    std::function<void(int, int)>fortune = [](int playerSelect, int random) {

        playerSelect == random ? printf("大当たり") : printf("残念、はずれ");
    };

    std::function<void(std::function<void(int, int)>, int)>fx = [=](std::function<void(int, int)> x, int second) {
        printf("%d秒間待機\n", second);
        Sleep(second * 1000);

        x(player, getRand);
    };

    fx(fortune, 3);

    return 0;
}
