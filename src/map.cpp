#include "map.h"
#include <fstream>
#include <iostream>
#include <json.hpp>

Map::Map(Config& config)
    : m_config(config)
{
    std::ifstream f("../assets/map/map.json");
    m_data = json::parse(f);
}

void Map::loadSheet(const std::string& path)
{
    m_sheet = LoadTexture(path.c_str());
}

void Map::draw()
{
    for (auto& layer : m_data["layers"]) {
        const json& dataArray = layer["data"];

        for (int row = 0; row < MAP_HEIGHT; row++) {
            for (int col = 0; col < MAP_WIDTH; col++) {
                // m_map[row][col] = dataArray[row * MAP_WIDTH + col];

                int value = dataArray[row * MAP_WIDTH + col];
                if (value == 0)
                    continue;

                Rectangle src = {
                    (value - 1) * m_config.cellSize,
                    0,
                    m_config.cellSize,
                    m_config.cellSize
                };

                Rectangle dst = {
                    col * m_config.cellSize,
                    row * m_config.cellSize,
                    m_config.cellSize,
                    m_config.cellSize
                };

                DrawTexturePro(m_sheet, src, dst, { 0.f, 0.f }, 0.f, WHITE);
            }
        }

        // std::cout << "Map Data:\n";
        // for (int row = 0; row < MAP_HEIGHT; row++) {
        //     for (int col = 0; col < MAP_WIDTH; col++) {
        //         std::cout << map[row][col] << " ";
        //     }
        //     std::cout << std::endl;
        // }
    }
}