#include "scene.hpp"

#include "asset.hpp"
#include "ui/ui.hpp"
#include "ui/uielement.hpp"

#include "game.hpp"

SceneCollection::SceneCollection() {
    buttonBack = make_shared<ButtonTexture>(UI::UISelect["button_back"], &Asset::texture["button_back"], "");
}

void SceneCollection::ready(Game& game) {

}

void SceneCollection::update(Game& game) {

}

void SceneCollection::render(Game& game) {
    game.window.setView(game.viewUI);
    buttonBack->render(game);
}

void SceneCollection::keyDown(Game& game, sf::Keyboard::Scan scan) {
    using Scan = sf::Keyboard::Scan;

    if (scan == Scan::Escape) {
        game.changeSceneTo(TITLE);
    }
}

void SceneCollection::mouseUp(Game& game, sf::Vector2f pos, sf::Mouse::Button button) {
    if (button == sf::Mouse::Button::Left) {
        if (buttonBack->contains(pos)) {
            game.changeSceneTo(TITLE);
        }
    }
}
