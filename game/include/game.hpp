#ifndef GAME_HPP
#define GAME_HPP

#include "includes.hpp"

class Scene;
class SceneTitle;
class SceneSelect;
class SceneBattle;

class Game {
    public:
        // System
        sf::RenderWindow window; float aspRatio = 16.0f / 9.0f; unsigned int width, height;
        sf::View viewUI, viewCamera;
        sf::Clock clock; float dt;

        // Game System
        int state;
        std::unordered_map<int, shared_ptr<Scene>> scenes;
        shared_ptr<Scene> scene;

        // Functions
        Game();
        void loop();
        void handleInput();
};

#endif
