#include "config.h"
#include "entityManager.h"
#include <raylib.h>

class InputManager {
public:
    InputManager(Config& config, EntityManager& entityManager);

    void update();
    void draw();

private:
    void updateSelector();
    void drawSelector();

    Config& m_config;
    EntityManager& m_entityManager;

    int m_selectorRow { 0 };
    int m_selectorCol { 0 };
    Color m_selectorColor { GRAY };

    int m_dstRow { 0 };
    int m_dstCol { 0 };

    int m_selectedEntity { -1 };

    int m_turn { 0 };
};
