#ifndef FIELD_HPP
#define FIELD_HPP

#include "includes.hpp"

class Game;

class Entity {
    public:
        sf::FloatRect rect = {{0, 0}, {80, 80}};
        std::optional<sf::Sprite> sprite;

        Entity();
        virtual void update(Game&);
        virtual void render(Game&);
};

class Player : public Entity {
    public:
        Player();

        void update(Game&) override;
};

class Field {
    public:
        Player player;
        Field();

        void update(Game&);
        void render(Game&);
};

#endif
