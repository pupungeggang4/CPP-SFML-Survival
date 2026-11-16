#include "scene.hpp"

#include "asset.hpp"
#include "ui/ui.hpp"
#include "ui/uielement.hpp"

#include "field.hpp"
#include "game.hpp"

SceneBattle::SceneBattle() {
    menu = make_shared<Menu>();
    windowReward = make_shared<WindowReward>();
    buttonMenu = make_shared<ButtonTexture>(UI::UIBattle["button_menu"], &Asset::texture["button_menu"], "");
    textHP = make_shared<Label>(UI::UIBattle["text_hp"], "60/60");
    textEnergy = make_shared<Label>(UI::UIBattle["text_energy"], "10/10");
    barHP = make_shared<RectColor>(UI::UIBattle["bar_hp"], sf::Color::Green);
    barEnergy = make_shared<RectColor>(UI::UIBattle["bar_energy"], sf::Color::Cyan);
}

void SceneBattle::ready(Game& game) {
    game.menu = false;
}

void SceneBattle::update(Game& game) {
    if (game.menu == false) {
        if (game.state == NORMAL) {
            game.field->update(game);
        }
    }
}

void SceneBattle::render(Game& game) {
    Player& player = game.field->player;
    game.viewCamera.setCenter(player.rect.position + player.rect.size / 2.0f);
    game.window.setView(game.viewCamera);
    game.field->render(game);

    game.window.setView(game.viewUI);

    textHP->render(game);
    textEnergy->render(game);
    barHP->render(game);
    barEnergy->render(game);
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
