#include "scene.hpp"
#include "asset.hpp"
#include "ui/ui.hpp"
#include "ui/button.hpp"

#include "game.hpp"

SceneSelect::SceneSelect() {
    buttonBack = make_shared<ButtonTexture>(UI::UISelect["button_back"], "", Asset::texture["button_menu"]);
}

void SceneSelect::ready(Game& game) {

}

void SceneSelect::update(Game& game) {

}

void SceneSelect::render(Game& game) {
    buttonBack->render(game);
}

void SceneSelect::keyDown(Game& game, sf::Keyboard::Scan scan) {

}

void SceneSelect::mouseUp(Game& game, sf::Vector2f pos, sf::Mouse::Button button) {
    if (buttonBack->contains(pos)) {
        game.changeSceneTo(TITLE);
    }
}
