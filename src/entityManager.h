#pragma once
#include "spriteManager.h"
#include <iostream>
#include <vector>

struct Entity {
    std::string name;
    int row;
    int col;
};

class EntityManager {
public:
    EntityManager(SpriteManager& spriteManager);

    void update();
    void draw();

    std::vector<Entity>& getEntities()
    {
        return m_entities;
    }

private:
    SpriteManager& m_spriteManager;

    void addEntity(const std::string& name, int row, int col);

    std::vector<Entity> m_entities;
};