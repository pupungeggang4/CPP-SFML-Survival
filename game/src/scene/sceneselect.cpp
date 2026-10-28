#include "scene.hpp"
#include "asset.hpp"
#include "ui/ui.hpp"
#include "ui/button.hpp"

#include "game.hpp"

SceneSelect::SceneSelect() {
    textTitle.emplace(*Asset::neodgm, "Select Character", 32);
    textTitle->setPosition({UI::UITitle["text_title"][0], UI::UITitle["text_title"][1]});
    textTitle->setFillColor(sf::Color::Black);

    buttonBack = make_shared<ButtonTexture>(UI::UISelect["button_back"], &Asset::texture["button_back"], "");
    for (int i = 0; i < 8; i++) {
        int col = i % 3;
        int row = (i - col) / 3;
        std::array<float, 6> rect = {
            UI::UISelect["button_character"][0] + UI::UISelect["button_character"][2] * col,
            UI::UISelect["button_character"][1] + UI::UISelect["button_character"][3] * row,
            UI::UISelect["button_character"][4], UI::UISelect["button_character"][5]
        };
        buttonCharacter[i] = make_shared<ButtonColor>(rect, sf::Color::Yellow, std::to_string(i + 1));
    }
    buttonStart = make_shared<ButtonColor>(UI::UISelect["button_start"], sf::Color::Yellow, "Start");

    descriptionArea = sf::RectangleShape({UI::UISelect["description_area"][2], UI::UISelect["description_area"][3]});
    descriptionArea.setPosition({UI::UISelect["description_area"][0], UI::UISelect["description_area"][1]});
    descriptionArea.setFillColor(sf::Color::Yellow);
}

void SceneSelect::ready(Game& game) {

}

void SceneSelect::update(Game& game) {

}

void SceneSelect::render(Game& game) {
    game.window.draw(*textTitle);
    buttonBack->render(game);

    for (int i = 0; i < 8; i++) {
        buttonCharacter[i]->render(game);
    }
    buttonStart->render(game);

    game.window.draw(descriptionArea);
}

void SceneSelect::keyDown(Game& game, sf::Keyboard::Scan scan) {
    using Scan = sf::Keyboard::Scan;

    if (scan == Scan::Escape) {
        game.changeSceneTo(TITLE);
    }
}

void SceneSelect::mouseUp(Game& game, sf::Vector2f pos, sf::Mouse::Button button) {
    if (buttonBack->contains(pos)) {
        game.changeSceneTo(TITLE);
    }
}
