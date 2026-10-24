#include "scene.hpp"
#include "ui/button.hpp"

#include "game.hpp"

SceneTitle::SceneTitle() {
    std::vector<float> temp = {160, 320, 960, 80};
    buttonQuit = make_shared<ButtonColor>(temp, "Quit Game", sf::Color::Yellow);
}

void SceneTitle::ready(Game& game) {

}

void SceneTitle::update(Game& game) {

}

void SceneTitle::render(Game& game) {
    game.window.setView(game.viewUI);
    buttonQuit->render(game);
}

void SceneTitle::keyDown(Game& game) {

}

void SceneTitle::mouseUp(Game& game, sf::Vector2f pos, sf::Mouse::Button button) {
    if (button == sf::Mouse::Button::Left) {
        if (buttonQuit->contains(pos)) {
            game.window.close();
        }
    }
}
