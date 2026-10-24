#ifndef BUTTON_HPP
#define BUTTON_HPP

#include "includes.hpp"

class Game;

class Button {
    public:
        Button(std::vector<float>);
        sf::FloatRect rect;
        virtual bool contains(sf::Vector2f);
        virtual void render(Game&);
};

class ButtonColor : public Button {
    public:
        std::optional<sf::Text> text;

        ButtonColor(std::vector<float>, sf::String, sf::Color);
        sf::RectangleShape bg;
        void render(Game&) override;
};

#endif
