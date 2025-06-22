#include "spriteManager.h"
#include "config.h"
#include <fstream>
#include <iostream>
#include <json.hpp>

using json = nlohmann::json;

SpriteManager::SpriteManager(Config& config)
    : m_config(config)
{
    std::string path = "../sprites.json";
    std::ifstream f(path);

    json data = json::parse(f);
    for (auto& [name, pos] : data.items()) {
        m_sprites.emplace(name, Vector2 { pos["x"], pos["y"] });
    }
}

Vector2 SpriteManager::getPosition(const std::string& name)
{
    auto it = m_sprites.find(name);
    if (it != m_sprites.end()) {
        return it->second;
    }

    std::cerr << name << " not found" << std::endl;

    // default to builder
    return { 0, 0 };
}

void SpriteManager::loadSheet(const std::string& path)
{
    m_sheet = LoadTexture(path.c_str());
}

void SpriteManager::draw(const std::string& name, int x, int y)
{
    Vector2 pos = getPosition(name);
    Rectangle src = {
        pos.x,
        pos.y,
        m_config.cellSize,
        m_config.cellSize
    };

    Rectangle dst = {
        x,
        y,
        m_config.cellSize,
        m_config.cellSize
    };

    DrawTexturePro(m_sheet, src, dst, { 0.f, 0.f }, 0.f, WHITE);
}
