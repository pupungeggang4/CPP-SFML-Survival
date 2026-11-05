#ifndef GAME_HPP
#define GAME_HPP

#include "includes.hpp"

class Field;
class Scene;
class SceneTitle;
class SceneSelect;
class SceneBattle;

class Game {
    public:
        // System
        sf::RenderWindow window; float aspRatio = 16.0f / 9.0f; unsigned int width, height; float scale;
        sf::View viewUI, viewCamera;
        sf::Clock clock; float dt;
        std::array<bool, 4> keyPressed = {0};

        // Game System
        int state; bool menu;
        std::unordered_map<int, shared_ptr<Scene>> scenes;
        shared_ptr<Scene> scene;

        // Game var
        shared_ptr<Field> field;

        // Functions
        Game();
        void loop();
        void handleInput();
        void changeSceneTo(int);
};

#endif
