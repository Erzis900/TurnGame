#include "game.h"
#include <cmath>

Game::Game(Config& config)
    : m_config(config)
    , m_spriteManager(config)
{
    SetTraceLogLevel(LOG_ERROR);
    InitWindow(config.screenWidth, config.screenHeight, "Turn game");
    SetTargetFPS(config.maxFps);

    m_renderTexture = LoadRenderTexture(config.virtualWidth, config.virtualHeight);
    SetTextureFilter(m_renderTexture.texture, TEXTURE_FILTER_POINT);

    m_scale = float(config.screenWidth) / config.virtualWidth;
    m_renderRec = { 0.f, 0.f, config.virtualWidth * m_scale, config.virtualHeight * m_scale };

    m_spriteManager.loadSheet("../assets/sprites.png");
}

Game::~Game()
{
    UnloadRenderTexture(m_renderTexture);
    CloseWindow();
}

void Game::update()
{
    float dt = GetFrameTime();
}

void Game::draw()
{
    BeginTextureMode(m_renderTexture);

    ClearBackground(GRAY);
    DrawRectangle(0, 0, 16, 16, PURPLE);
    m_spriteManager.draw("builder", 64, 32);

    EndTextureMode();

    BeginDrawing();
    ClearBackground(BLACK);

    DrawTexturePro(m_renderTexture.texture, { 0.f, 0.f, float(m_config.virtualWidth), float(-m_config.virtualHeight) }, m_renderRec, { 0.f, 0.f }, 0.f, WHITE);
    EndDrawing();
}

void Game::loop()
{
    while (!WindowShouldClose()) {
        if (IsWindowResized()) {
            updateRenderRec();
        }

        update();
        draw();
    }
}

void Game::updateRenderRec()
{
    m_scale = std::min(
        float(GetScreenWidth()) / m_config.virtualWidth,
        float(GetScreenHeight()) / m_config.virtualHeight);
    m_renderRec.width = m_config.virtualWidth * m_scale;
    m_renderRec.height = m_config.virtualHeight * m_scale;
    m_renderRec.x = (GetScreenWidth() - m_renderRec.width) / 2.f;
    m_renderRec.y = (GetScreenHeight() - m_renderRec.height) / 2.f;
}

void Game::drawGrid(int rows, int cols)
{
    Color c = GRAY;
    for (int i = 1; i < cols; i++) {
        DrawLine(i * m_config.cellSize, 0, i * m_config.cellSize, m_config.screenHeight, c);
    }

    for (int j = 1; j < rows; j++) {
        DrawLine(0, j * m_config.cellSize, m_config.screenWidth, j * m_config.cellSize, c);
    }
}
