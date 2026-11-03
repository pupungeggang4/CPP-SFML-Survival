#include "scene.hpp"

#include "asset.hpp"
#include "ui/ui.hpp"
#include "ui/uielement.hpp"

#include "game.hpp"

WindowReward::WindowReward() {
    textTitle = make_shared<Label>(UI::UIReward["text_title"], sf::Color::Black, "Select");
    bg = sf::RectangleShape({UI::UIReward["rect"][2], UI::UIReward["rect"][3]});
    bg.setPosition({UI::UIReward["rect"][0], UI::UIReward["rect"][1]});
    bg.setFillColor(sf::Color::Yellow);
}

void WindowReward::ready(Game& game) {
    selected = 0;
}

void WindowReward::render(Game& game) {
    game.window.draw(bg);
}

void WindowReward::keyDown(Game& game, sf::Keyboard::Scan scan) {

}

void WindowReward::mouseUp(Game& game, sf::Vector2f pos, sf::Mouse::Button button) {

}
