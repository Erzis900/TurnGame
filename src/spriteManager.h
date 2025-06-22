#include <raylib.h>
#include <string>
#include <unordered_map>

struct Config;

class SpriteManager {
public:
    SpriteManager(Config& config);

    void loadSheet(const std::string& path);
    void draw(const std::string& name, int x, int y);

private:
    Vector2 getPosition(const std::string& name);

    Texture2D m_sheet;
    std::unordered_map<std::string, Vector2> m_sprites;
    Config& m_config;
};