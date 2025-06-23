#include "inputManager.h"
#include <iostream>

InputManager::InputManager(Config& config)
    : m_config(config)
    , m_selectorCoord({ 0.f, 0.f })
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
        m_selectorCoord.y++;
    } else if (IsKeyPressed(KEY_UP)) {
        m_selectorCoord.y--;
    } else if (IsKeyPressed(KEY_LEFT)) {
        m_selectorCoord.x--;
    } else if (IsKeyPressed(KEY_RIGHT)) {
        m_selectorCoord.x++;
    }
}

void InputManager::drawSelector()
{
    DrawRectangleLines(m_selectorCoord.x * m_config.cellSize, m_selectorCoord.y * m_config.cellSize, m_config.cellSize, m_config.cellSize, GREEN);
}
