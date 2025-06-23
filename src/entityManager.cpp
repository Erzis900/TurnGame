#include "entityManager.h"

EntityManager::EntityManager(SpriteManager& spriteManager)
    : m_spriteManager(spriteManager)
{
    addEntity(EntityType::BUILDER, "builder", 2, 2);
    addEntity(EntityType::FIGHTER, "fighter", 3, 2);
}

void EntityManager::addEntity(EntityType type, const std::string& name, int row, int col)
{
    m_typeGrid[row][col] = type;

    Entity ent;
    ent.type = type;
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