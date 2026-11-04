#include "scene.hpp"

#include "asset.hpp"
#include "ui/ui.hpp"
#include "ui/uielement.hpp"

#include "game.hpp"

SceneBattle::SceneBattle() {
    menu = make_shared<Menu>();
    windowReward = make_shared<WindowReward>();
    buttonMenu = make_shared<ButtonTexture>(UI::UIBattle["button_menu"], &Asset::texture["button_menu"], "");
}

void SceneBattle::ready(Game& game) {
    game.menu = false;
}

void SceneBattle::update(Game& game) {
    if (game.menu == false) {
        if (game.state == NORMAL) {
        }
    }
}

void SceneBattle::render(Game& game) {
    game.window.setView(game.viewUI);
    buttonMenu->render(game);

    if (game.state == REWARD) {
        windowReward->render(game);
    }

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

        if (game.state == REWARD) {
            windowReward->keyDown(game, scan);
        }
    }
}

void SceneBattle::mouseUp(Game& game, sf::Vector2f pos, sf::Mouse::Button button) {
    if (button == sf::Mouse::Button::Left) {
        if (game.menu) {
            if (buttonMenu->contains(pos)) {
                game.menu = false;
            }
            menu->mouseUp(game, pos, button);
        } else {
            if (buttonMenu->contains(pos)) {
                game.menu = true;
            }

            if (game.state == REWARD) {
                windowReward->mouseUp(game, pos, button);
            }
        }
    }
}
