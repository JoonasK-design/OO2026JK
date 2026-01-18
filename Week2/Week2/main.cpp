#include "game.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    srand(time(0));

    Game game(10);
    game.play();
    return 0;
}
