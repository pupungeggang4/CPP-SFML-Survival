#ifndef BUTTON_HPP
#define BUTTON_HPP

#include "includes.hpp"

class Game;

class Button {
    public:
        Button(std::array<float, 6>);
        sf::FloatRect rect;
        virtual bool contains(sf::Vector2f);
        virtual void render(Game&);
};

class ButtonColor : public Button {
    public:
        std::optional<sf::Text> text;

        ButtonColor(std::array<float, 6>, sf::Color, sf::String, int size = 32);
        sf::RectangleShape bg;
        void render(Game&) override;
};

class ButtonTexture : public Button {
    public:
        sf::RectangleShape bg;
        std::optional<sf::Text> text;

        ButtonTexture(std::array<float, 6>, sf::Texture*, sf::String, int size = 32);
        void render(Game&) override;
};

#endif
