#include "scene.hpp"

#include "asset.hpp"
#include "ui/ui.hpp"
#include "ui/button.hpp"

#include "game.hpp"

SceneTitle::SceneTitle() {
    textTitle.emplace(*Asset::neodgm, "Planterguy Survival", 32);
    textTitle->setFillColor(sf::Color::Black);
    textTitle->setPosition({UI::UITitle["text_title"][0], UI::UITitle["text_title"][1]});
    buttonStart = make_shared<ButtonColor>(UI::UITitle["button_start"], "Start Game", sf::Color::Yellow);
    buttonCollection = make_shared<ButtonColor>(UI::UITitle["button_collection"], "Collection", sf::Color::Cyan);
    buttonQuit = make_shared<ButtonColor>(UI::UITitle["button_quit"], "Quit Game", sf::Color::Yellow);
}

void SceneTitle::ready(Game& game) {

}

void SceneTitle::update(Game& game) {

}

void SceneTitle::render(Game& game) {
    game.window.setView(game.viewUI);
    game.window.draw(*textTitle);
    buttonStart->render(game);
    buttonCollection->render(game);
    buttonQuit->render(game);
}

void SceneTitle::keyDown(Game& game, sf::Keyboard::Scan scan) {
    using Scan = sf::Keyboard::Scan;
    if (scan == Scan::Escape) {
        game.window.close();
    }
}

void SceneTitle::mouseUp(Game& game, sf::Vector2f pos, sf::Mouse::Button button) {
    if (button == sf::Mouse::Button::Left) {
        if (buttonQuit->contains(pos)) {
            game.window.close();
        }
    }
}
