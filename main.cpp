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
        printf("%d•bŠÔ‘Ò‹@\n", second);
        Sleep(second * 1000);

        return x % 2;
    };

    getRand = fx(getRand, 3);


    //“–‚½‚Á‚Ä‚é‚©‚Ç‚¤‚©
    std::function<void(int, int)>fortune = [](int playerSelect, int random) {

        playerSelect == random ? printf("‘å“–‚½‚è") : printf("c”OA‚Í‚¸‚ê");
    };

    fortune(player, getRand);

    //’·•l‚É‹³‚¦‚½‚ç‚»‚Ì‚Ü‚Üg‚í‚ê‚½...
    return 0;
}