#include "constants.h"
#include "spriteManager.h"
#include <iostream>
#include <vector>

enum class EntityType {
    NONE,
    BUILDER,
    FIGHTER,
    GOBLIN
};

struct Entity {
    EntityType type;
    std::string name;
    int row;
    int col;
};

class EntityManager {
public:
    EntityManager(SpriteManager& spriteManager);

    void update();
    void draw();

private:
    SpriteManager& m_spriteManager;

    void addEntity(EntityType type, const std::string& name, int row, int col);

    std::vector<Entity> m_entities;
    EntityType m_typeGrid[MAP_HEIGHT][MAP_WIDTH] = { EntityType::NONE };
};