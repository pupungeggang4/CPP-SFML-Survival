#include "scene.hpp"

#include "asset.hpp"
#include "ui/ui.hpp"
#include "ui/button.hpp"

#include "game.hpp"

SceneBattle::SceneBattle() {
    menu = make_shared<Menu>(); 
}

void SceneBattle::ready(Game& game) {
    game.menu = false;
}

void SceneBattle::update(Game& game) {

}

void SceneBattle::render(Game& game) {
    if (game.menu == true) {
        menu->render(game);
    }
}

void SceneBattle::keyDown(Game& game, sf::Keyboard::Scan scan) {
    using Scan = sf::Keyboard::Scan;

    if (game.menu) {
        if (scan == Scan::Escape) {
            game.menu = false;
        }

        menu->keyDown(game, scan);
    } else {
        if (scan == Scan::Escape) {
            game.menu = true;
        }
    }
}

void SceneBattle::mouseUp(Game& game, sf::Vector2f pos, sf::Mouse::Button button) {

}
