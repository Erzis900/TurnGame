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
    DrawText(TextFormat("Turn: %d", m_turn), 0, m_config.virtualHeight - m_config.cellSize, 1, WHITE);
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

        for (int i = 0; i < entities.size(); i++) {
            // if entity not selected
            if (m_selectedEntity == -1) {
                if (m_selectorRow == entities[i].row && m_selectorCol == entities[i].col) {
                    m_selectedEntity = i;
                    m_selectorColor = GREEN;
                    break;
                }
            } else {
                if (m_entityManager.isOccupied(m_selectorRow, m_selectorCol)) {
                    continue;
                }

                m_selectorColor = GREEN;
                entities[m_selectedEntity].dstRow = m_selectorRow;
                entities[m_selectedEntity].dstCol = m_selectorCol;
                m_selectedEntity = -1;
                m_selectorColor = GRAY;
            }
        }
    }

    if (IsKeyPressed(KEY_ENTER)) {
        auto& entities = m_entityManager.getEntities();

        for (int i = 0; i < entities.size(); i++) {
            if (entities[i].dstRow == -1 || entities[i].dstCol == -1)
                continue;

            entities[i].row = entities[i].dstRow;
            entities[i].col = entities[i].dstCol;
            entities[i].dstRow = -1;
            entities[i].dstCol = -1;
        }

        m_turn++;
    }
}

void InputManager::drawSelector()
{
    DrawRectangleLines(m_selectorCol * m_config.cellSize, m_selectorRow * m_config.cellSize, m_config.cellSize, m_config.cellSize, m_selectorColor);
}
