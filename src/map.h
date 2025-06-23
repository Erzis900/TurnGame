#include "config.h"
#include <json.hpp>
#include <raylib.h>
#include <string>

using json = nlohmann::json;

class Map {
public:
    Map(Config& config);

    void loadSheet(const std::string& path);
    void draw();

private:
    Config& m_config;

    // int m_map[MAP_HEIGHT][MAP_WIDTH];
    Texture2D m_sheet;
    json m_data;
};