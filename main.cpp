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

   
    //“–‚½‚Á‚Ä‚é‚©‚Ç‚¤‚©
    std::function<void(int, int)>fortune = [](int playerSelect, int random) {

        playerSelect == random ? printf("‘å“–‚½‚è") : printf("c”OA‚Í‚¸‚ê");
    };

    std::function<void(std::function<void(int, int)>, int)>fx = [=](std::function<void(int, int)> x, int second) {
        printf("%d•bŠÔ‘Ò‹@\n", second);
        Sleep(second * 1000);

        x(player, getRand);
    };

    fx(fortune, 3);

    return 0;
}
