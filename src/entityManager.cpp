#include "entityManager.h"

EntityManager::EntityManager(SpriteManager& spriteManager)
    : m_spriteManager(spriteManager)
{
    addEntity("builder", 2, 2);
    addEntity("fighter", 3, 2);
}

void EntityManager::addEntity(const std::string& name, int row, int col)
{
    Entity ent;
    ent.name = name;
    ent.row = row;
    ent.col = col;

    m_entities.push_back(ent);
}

void EntityManager::draw()
{
    for (auto& ent : m_entities) {
        m_spriteManager.draw(ent.name, ent.row, ent.col);
    }
}