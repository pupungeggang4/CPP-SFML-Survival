#include "scene.hpp"

#include "asset.hpp"
#include "ui/ui.hpp"
#include "ui/button.hpp"

#include "game.hpp"

Menu::Menu() {

}

void Menu::render(Game& game) {
}

void Menu::keyDown(Game& game, sf::Keyboard::Scan scan) {
    using Scan = sf::Keyboard::Scan;

    if (scan == Scan::Up || scan == Scan::W) selected = (selected + 2) % 3;
    else if (scan == Scan::Down || scan == Scan::S) selected = (selected + 1) % 3;
    else if (scan == Scan::Enter) {
        if (selected == 0) game.menu = false;
        else if (selected == 1) {
            game.menu = false;
            game.changeSceneTo(TITLE);
        } else if (selected == 2) {
            game.close.window();
        }
    }
}

void Menu::mouseUp(Game& game, sf::Vector2f pos, sf::Mouse::Button button) {
    if (button == sf::Mouse::Button::Left) {
        
    }
}
