#pragma once
#include "config.h"
#include "spriteManager.h"
#include <iostream>
#include <vector>

struct Entity {
    std::string name;
    int row;
    int col;
    int dstRow;
    int dstCol;
};

class EntityManager {
public:
    EntityManager(Config& config, SpriteManager& spriteManager);

    void update();
    void draw();

    std::vector<Entity>& getEntities()
    {
        return m_entities;
    }

    bool isOccupied(int row, int col);

private:
    SpriteManager& m_spriteManager;
    Config& m_config;

    void addEntity(const std::string& name, int row, int col);

    std::vector<Entity> m_entities;
};