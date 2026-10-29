#ifndef SCENE_HPP
#define SCENE_HPP

#include "includes.hpp"

class Game;
class Label;
class ButtonColor;
class ButtonTexture;
class Menu;

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
        int selected = 0;

        sf::RectangleShape arrow;
        shared_ptr<Label> textTitle;
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
        int selected = 0;

        shared_ptr<Label> textTitle;
        shared_ptr<ButtonTexture> buttonBack;
        std::array<shared_ptr<ButtonColor>, 10> buttonCharacter;
        shared_ptr<ButtonColor> buttonStart;
        sf::RectangleShape descriptionArea;
        sf::RectangleShape cursor;

        SceneSelect();
        void ready(Game&) override;
        void update(Game&) override;
        void render(Game&) override;
        void keyDown(Game&, sf::Keyboard::Scan) override;
        void mouseUp(Game&, sf::Vector2f, sf::Mouse::Button) override;
};

class SceneBattle : public Scene {
    public:
        shared_ptr<Menu> menu;
        shared_ptr<ButtonTexture> buttonMenu;

        SceneBattle();
        void ready(Game&) override;
        void update(Game&) override;
        void render(Game&) override;
        void keyDown(Game&, sf::Keyboard::Scan) override;
        void mouseUp(Game&, sf::Vector2f, sf::Mouse::Button) override;
};

class SceneCollection : public Scene {
    public:
        shared_ptr<ButtonTexture> buttonBack;

        SceneCollection();
        void ready(Game&) override;
        void update(Game&) override;
        void render(Game&) override;
        void keyDown(Game&, sf::Keyboard::Scan) override;
        void mouseUp(Game&, sf::Vector2f, sf::Mouse::Button) override;
};

class Menu : public Scene {
    public:
        int selected = 0;
        shared_ptr<Label> textPaused;
        sf::RectangleShape bg, arrow;
        shared_ptr<ButtonColor> buttonResume, buttonExit, buttonQuit;

        Menu();
        void render(Game&) override;
        void keyDown(Game&, sf::Keyboard::Scan) override;
        void mouseUp(Game&, sf::Vector2f, sf::Mouse::Button) override;
};

#endif
