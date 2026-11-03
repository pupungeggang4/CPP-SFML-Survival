#include "scene.hpp"

#include "asset.hpp"
#include "ui/ui.hpp"
#include "ui/uielement.hpp"

#include "game.hpp"

WindowReward::WindowReward() {
    textTitle = make_shared<Label>(UI::UIReward["text_title"], sf::Color::Black, "Select");
}

void WindowReward::ready(Game& game) {
    selected = 0;
}

void WindowReward::render(Game& game) {

}

void WindowReward::keyDown(Game& game, sf::Keyboard::Scan scan) {

}

void WindowReward::mouseUp(Game& game, sf::Vector2f pos, sf::Mouse::Button button) {

}
