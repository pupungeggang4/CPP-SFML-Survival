#include "ui/button.hpp"
#include "asset.hpp"
#include "game.hpp"

Button::Button(std::array<float, 6> r) {
    rect = {{r[0], r[1]}, {r[2], r[3]}};
}

bool Button::contains(sf::Vector2f pos) {
    return rect.contains(pos);
}

void Button::render(Game& game) {
}

ButtonColor::ButtonColor(std::array<float, 6> r, sf::Color color, sf::String str, int size) : Button(r) {
    bg = sf::RectangleShape({r[2], r[3]});
    bg.setPosition({r[0], r[1]});
    bg.setFillColor(color);
    text.emplace(*Asset::neodgm, str, size);
    text->setPosition({r[0] + 20, r[1] + 20});
    text->setFillColor(sf::Color::Black);
}

void ButtonColor::render(Game& game) {
    game.window.draw(bg);
    game.window.draw(*text);
}

ButtonTexture::ButtonTexture(std::array<float, 6> r, sf::Texture* texture, sf::String str, int size) : Button(r) {
    bg = sf::RectangleShape({r[2], r[3]});
    bg.setPosition({r[0], r[1]});
    bg.setTexture(texture);

    text.emplace(*Asset::neodgm, str, size);
    text->setPosition({r[0] + 20, r[1] + 20});
    text->setFillColor(sf::Color::Black);
}

void ButtonTexture::render(Game& game) {
    game.window.draw(bg);
    game.window.draw(*text);
}
