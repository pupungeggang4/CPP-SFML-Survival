#include "scene.hpp"

#include "asset.hpp"
#include "ui/ui.hpp"
#include "ui/uielement.hpp"

#include "game.hpp"

SceneTitle::SceneTitle() {
    textTitle = make_shared<Label>(UI::UITitle["text_title"], sf::Color::Black, "Planterguy Survival");
    buttonStart = make_shared<ButtonColor>(UI::UITitle["button_start"], sf::Color::Yellow, "Start Game");
    buttonCollection = make_shared<ButtonColor>(UI::UITitle["button_collection"], sf::Color::Cyan, "Collection");
    buttonQuit = make_shared<ButtonColor>(UI::UITitle["button_quit"], sf::Color::Yellow, "Quit Game");
    arrow = sf::RectangleShape({UI::UITitle["arrow"][4], UI::UITitle["arrow"][5]});
    arrow.setTexture(&Asset::texture["arrow"]);
}

void SceneTitle::ready(Game& game) {
    selected = 0;
}

void SceneTitle::update(Game& game) {

}

void SceneTitle::render(Game& game) {
    game.window.setView(game.viewUI);
    textTitle->render(game);
    buttonStart->render(game);
    buttonCollection->render(game);
    buttonQuit->render(game);
    arrow.setPosition({
        UI::UITitle["arrow"][0], UI::UITitle["arrow"][1] + UI::UITitle["arrow"][3] * selected
    });
    game.window.draw(arrow);
}

void SceneTitle::keyDown(Game& game, sf::Keyboard::Scan scan) {
    using Scan = sf::Keyboard::Scan;
    if (scan == Scan::Up || scan == Scan::W) {
        selected = (selected + 2) % 3;
    } else if (scan == Scan::Down || scan == Scan::D) {
        selected = (selected + 1) % 3;
    } else if (scan == Scan::Enter) {
        if (selected == 0) game.changeSceneTo(SELECT);
        else if (selected == 1) game.changeSceneTo(COLLECTION);
        else if (selected == 2) game.window.close();
    }
    if (scan == Scan::Grave) {
        game.window.close();
    }
}

void SceneTitle::mouseUp(Game& game, sf::Vector2f pos, sf::Mouse::Button button) {
    if (button == sf::Mouse::Button::Left) {
        if (buttonStart->contains(pos)) {
            game.changeSceneTo(SELECT);
        } else if (buttonCollection->contains(pos)) {
            game.changeSceneTo(COLLECTION);
        } else if (buttonQuit->contains(pos)) {
            game.window.close();
        }
    }
}
