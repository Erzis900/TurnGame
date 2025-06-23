#include "inputManager.h"
#include <iostream>

InputManager::InputManager(Config& config, EntityManager& entityManager)
    : m_config(config)
    , m_entityManager(entityManager)
{
}

void InputManager::update()
{
    updateSelector();
}

void InputManager::draw()
{
    drawSelector();
}

void InputManager::updateSelector()
{
    if (IsKeyPressed(KEY_DOWN)) {
        m_selectorRow++;
    } else if (IsKeyPressed(KEY_UP)) {
        m_selectorRow--;
    } else if (IsKeyPressed(KEY_LEFT)) {
        m_selectorCol--;
    } else if (IsKeyPressed(KEY_RIGHT)) {
        m_selectorCol++;
    }

    if (IsKeyPressed(KEY_SPACE)) {
        auto& entities = m_entityManager.getEntities();

        if (m_selectedEntity == -1) {
            for (int i = 0; i < entities.size(); i++) {
                
                if (m_selectorRow == entities[i].row && m_selectorCol == entities[i].col) {
                    m_selectedEntity = i;
                }
            }
        } else {
            entities[m_selectedEntity].row = m_selectorRow;
            entities[m_selectedEntity].col = m_selectorCol;
            m_selectedEntity = -1;
        }
    }
}

void InputManager::drawSelector()
{
    DrawRectangleLines(m_selectorCol * m_config.cellSize, m_selectorRow * m_config.cellSize, m_config.cellSize, m_config.cellSize, GREEN);
}
