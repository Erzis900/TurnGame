#include "config.h"
#include "entityManager.h"
#include "inputManager.h"
#include "map.h"
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

    Config& m_config;
    SpriteManager m_spriteManager;
    Map m_map;
    InputManager m_inputManager;
    EntityManager m_entityManager;

    RenderTexture2D m_renderTexture;
    RenderTexture2D m_mapRenderTexture;
    Rectangle m_renderRec;
    float m_scale;
};