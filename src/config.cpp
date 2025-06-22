#include "config.h"
#include <fstream>
#include <json.hpp>

using json = nlohmann::json;

void loadConfig(const std::string& path, Config& config)
{
    std::ifstream f(path);
    json data = json::parse(f);

    config.screenWidth = data["screen_width"];
    config.screenHeight = data["screen_height"];
    config.virtualWidth = data["virtual_width"];
    config.virtualHeight = data["virtual_height"];
    config.maxFps = data["max_fps"];
    config.cellSize = data["cell_size"];
}