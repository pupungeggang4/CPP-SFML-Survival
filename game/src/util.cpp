#include "util.hpp"

bool pointInsideRectUI(sf::Vector2f pos, std::vector<float> rect) {
    return pos.x > rect[0] && pos.x < rect[0] + rect[2] && pos.y > rect[1] && pos.y < rect[1] + rect[3];
}
