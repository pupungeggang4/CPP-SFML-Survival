#include "scene.hpp"

#include "asset.hpp"
#include "ui/ui.hpp"
#include "ui/button.hpp"

#include "game.hpp"

Menu::Menu() {
    textPaused.emplace(*Asset::neodgm, "Paused", 32);
    textPaused->setFillColor(sf::Color::Black);
    textPaused->setPosition({UI::UIMenu["text_paused"][0], UI::UIMenu["text_paused"][1]});
    arrow = sf::RectangleShape({UI::UIMenu["arrow"][4], UI::UIMenu["arrow"][5]});
    arrow.setTexture(&Asset::texture["arrow"]);
    bg = sf::RectangleShape({UI::UIMenu["rect"][2], UI::UIMenu["rect"][3]});
    bg.setPosition({UI::UIMenu["rect"][0], UI::UIMenu["rect"][1]});
    bg.setFillColor(sf::Color::Green);
    buttonResume = make_shared<ButtonColor>(UI::UIMenu["button_resume"], sf::Color::Yellow, "Resume", 32);
    buttonExit = make_shared<ButtonColor>(UI::UIMenu["button_exit"], sf::Color::Cyan, "Exit", 32);
    buttonQuit = make_shared<ButtonColor>(UI::UIMenu["button_quit"], sf::Color::Yellow, "Quit", 32);
}

void Menu::render(Game& game) {
    game.window.draw(*textPaused);
    arrow.setPosition({
        UI::UIMenu["arrow"][0] + UI::UIMenu["arrow"][2], UI::UIMenu["arrow"][1] + UI::UIMenu["arrow"][3] * selected
    });
    game.window.draw(arrow);
    game.window.draw(bg);
    game.window.draw(*textPaused);
    buttonResume->render(game);
    buttonExit->render(game);
    buttonQuit->render(game);
}

void Menu::keyDown(Game& game, sf::Keyboard::Scan scan) {
    using Scan = sf::Keyboard::Scan;

    if (scan == Scan::Up || scan == Scan::W) selected = (selected + 2) % 3;
    else if (scan == Scan::Down || scan == Scan::S) selected = (selected + 1) % 3;
    else if (scan == Scan::Enter) {
        if (selected == 0) game.menu = false;
        else if (selected == 1) {
            game.menu = false;
            game.changeSceneTo(TITLE);
        } else if (selected == 2) {
            game.window.close();
        }
    }
}

void Menu::mouseUp(Game& game, sf::Vector2f pos, sf::Mouse::Button button) {
    if (button == sf::Mouse::Button::Left) {
        
    }
}
