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
        printf("%d秒間待機\n", second);
        Sleep(second * 1000);

        return x % 2;
    };

    getRand = fx(getRand, 3);


    //当たってるかどうか
    std::function<void(int, int)>fortune = [](int playerSelect, int random) {

        playerSelect == random ? printf("大当たり") : printf("残念、はずれ");
    };

    fortune(player, getRand);

    //長浜に教えたらそのまま使われた...
    return 0;
}