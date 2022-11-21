#include<functional>
#include<stdio.h>
#include<windows.h>
#include<stdlib.h>
#include<time.h>


int main() {

    printf("0になるか1になるか予想して入力してください\n");
    srand(time(nullptr));
    int playerSelect = 0;
    scanf_s("%d", &playerSelect);

   
    //当たってるかどうか
    std::function<void()>fortune = [=]() {

        playerSelect == rand() % 2 ? printf("大当たり ") : printf("残念、はずれ ");
    };

	//タイムアウト
    std::function<void(std::function<void()>, int)>setTimeout = [=](std::function<void()> d, int second) {
        Sleep(second * 1000);
        d();
    };

    setTimeout(fortune, 3);

    system("pause");
    return 0;
}
