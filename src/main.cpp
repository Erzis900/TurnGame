#include "config.h"
#include "game.h"
#include <iostream>
#include <raylib.h>

int main()
{
    Config config;
    loadConfig("../config.json", config);

    Game game(config);
    game.loop();

    return 0;
}