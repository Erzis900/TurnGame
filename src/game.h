#include "config.h"
#include "spriteManager.h"
#include <raylib.h>

class Game {
public:
    Game(Config& config);
    ~Game();
    void loop();

private:
    void update();
    void draw();
    void updateRenderRec();
    void drawGrid(int rows, int cols);

    Config& m_config;
    SpriteManager m_spriteManager;

    RenderTexture2D m_renderTexture;
    Rectangle m_renderRec;
    float m_scale;
};