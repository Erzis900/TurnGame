#include "config.h"
#include <raylib.h>

class InputManager {
public:
    InputManager(Config& config);

    void update();
    void draw();

private:
    void updateSelector();
    void drawSelector();

    Config& m_config;

    Vector2 m_selectorCoord;
};
