#include "entityManager.h"

EntityManager::EntityManager(Config& config, SpriteManager& spriteManager)
    : m_spriteManager(spriteManager)
    , m_config(config)
{
    addEntity("builder", 2, 2);
    addEntity("fighter", 3, 2);
    addEntity("fighter", 4, 4);
    addEntity("fighter", 5, 5);
    addEntity("fighter", 6, 6);
}

bool EntityManager::isOccupied(int row, int col)
{
    for (auto& ent : m_entities) {
        if (ent.row == row && ent.col == col) {
            return true;
        }
    }
    return false;
}

void EntityManager::addEntity(const std::string& name, int row, int col)
{
    Entity ent;
    ent.name = name;
    ent.row = row;
    ent.col = col;

    ent.dstRow = -1;
    ent.dstRow = -1;

    m_entities.push_back(ent);
}

void EntityManager::draw()
{
    for (auto& ent : m_entities) {
        m_spriteManager.draw(ent.name, ent.row, ent.col);

        if (ent.dstRow == -1 || ent.dstCol == -1)
            continue;

        DrawLine(ent.col * m_config.cellSize + m_config.cellSize / 2,
            ent.row * m_config.cellSize + m_config.cellSize / 2,
            ent.dstCol * m_config.cellSize + m_config.cellSize / 2,
            ent.dstRow * m_config.cellSize + m_config.cellSize / 2, ORANGE);
    }
}