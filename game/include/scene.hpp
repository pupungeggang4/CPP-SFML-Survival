#ifndef SCENE_HPP
#define SCENE_HPP

#include "includes.hpp"

class Game;
class ButtonColor;

class Scene {
    public:
        Scene();
        virtual void ready(Game&);
        virtual void update(Game&);
        virtual void render(Game&);
        virtual void keyDown(Game&);
        virtual void mouseUp(Game&, sf::Vector2f, sf::Mouse::Button);
};

class SceneTitle : public Scene {
    public:
        shared_ptr<ButtonColor> buttonQuit;

        SceneTitle();
        void ready(Game&) override;
        void update(Game&) override;
        void render(Game&) override;
        void keyDown(Game&) override;
        void mouseUp(Game&, sf::Vector2f, sf::Mouse::Button) override;
};

/*
class SceneSelect : public Scene {
};

class SceneBattle : public Scene {
};
*/

#endif
