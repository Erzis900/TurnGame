#pragma once
#include <string>

struct Config {
    int screenWidth;
    int screenHeight;
    int virtualWidth;
    int virtualHeight;
    int maxFps;
    int cellSize;
};

void loadConfig(const std::string& path, Config& config);