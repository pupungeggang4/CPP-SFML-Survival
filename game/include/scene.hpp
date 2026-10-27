#ifndef SCENE_HPP
#define SCENE_HPP

#include "includes.hpp"

class Game;
class ButtonColor;
class ButtonTexture;

class Scene {
    public:
        Scene();
        virtual void ready(Game&);
        virtual void update(Game&);
        virtual void render(Game&);
        virtual void keyDown(Game&, sf::Keyboard::Scan);
        virtual void mouseUp(Game&, sf::Vector2f, sf::Mouse::Button);
};

class SceneTitle : public Scene {
    public:
        std::optional<sf::Text> textTitle;
        shared_ptr<ButtonColor> buttonStart, buttonCollection, buttonQuit;

        SceneTitle();
        void ready(Game&) override;
        void update(Game&) override;
        void render(Game&) override;
        void keyDown(Game&, sf::Keyboard::Scan) override;
        void mouseUp(Game&, sf::Vector2f, sf::Mouse::Button) override;
};

class SceneSelect : public Scene {
    public:
        shared_ptr<ButtonTexture> buttonBack;

        SceneSelect();
        void ready(Game&) override;
        void update(Game&) override;
        void render(Game&) override;
        void keyDown(Game&, sf::Keyboard::Scan) override;
        void mouseUp(Game&, sf::Vector2f, sf::Mouse::Button) override;
};

class SceneBattle : public Scene {
    public:
        SceneBattle();
        void ready(Game&) override;
        void update(Game&) override;
        void render(Game&) override;
        void keyDown(Game&, sf::Keyboard::Scan) override;
        void mouseUp(Game&, sf::Vector2f, sf::Mouse::Button) override;
};

class SceneCollection : public Scene {
    public:
        SceneCollection();
        void ready(Game&) override;
        void update(Game&) override;
        void render(Game&) override;
        void keyDown(Game&, sf::Keyboard::Scan) override;
        void mouseUp(Game&, sf::Vector2f, sf::Mouse::Button) override;
};

#endif
