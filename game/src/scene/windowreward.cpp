#include "scene.hpp"

#include "asset.hpp"
#include "ui/ui.hpp"
#include "ui/uielement.hpp"

#include "game.hpp"

WindowReward::WindowReward() {
    textTitle = make_shared<Label>(UI::UIReward["text_title"], sf::Color::Black, "Select");
    bg = make_shared<RectColor>(UI::UIReward["rect"], sf::Color::Yellow);
    cursor = make_shared<RectTexture>(UI::UIReward["cursor"], &Asset::texture["cursor"]);
    buttonOk = make_shared<ButtonColor>(UI::UIReward["button_ok"], sf::Color::Cyan, "Start");

    for (int i = 0; i < 3; i++) {
        std::array<float, 6> rect = {
            UI::UIReward["button_select"][0] + UI::UIReward["button_select"][2] * i,
            UI::UIReward["button_select"][1],
            UI::UIReward["button_select"][4], UI::UIReward["button_select"][5]
        };
        buttonSelect[i] = make_shared<ButtonTexture>(rect, nullptr, "");
    }

    cursor->bg.setPosition({UI::UIReward["cursor"][0], UI::UIReward["cursor"][1]});
}

void WindowReward::ready(Game& game) {
    selected = 0;
}

void WindowReward::render(Game& game) {
    bg->render(game);
    textTitle->render(game);

    for (int i = 0; i < 3; i++) {
        buttonSelect[i]->render(game);
    }

    cursor->bg.setPosition({UI::UIReward["button_select"][0] + UI::UIReward["button_select"][2] * selected, UI::UIReward["button_select"][1]});
    cursor->render(game);
    buttonOk->render(game);
}

void WindowReward::keyDown(Game& game, sf::Keyboard::Scan scan) {

}

void WindowReward::mouseUp(Game& game, sf::Vector2f pos, sf::Mouse::Button button) {

}
