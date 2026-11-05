#include "game.hpp"
#include "asset.hpp"

#include "scene.hpp"
#include "field.hpp"

Game::Game() {
    sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
    if (desktop.size.x / aspRatio > desktop.size.y) {
        height = (unsigned int)(desktop.size.y * 0.8f); width = (unsigned int)(height * aspRatio);
    } else {
        width = (unsigned int)(desktop.size.x * 0.8f); height = (unsigned int)(width / aspRatio);
    } 
    window = sf::RenderWindow(sf::VideoMode({width, height}), "Planterguy's Adventure");
    window.setKeyRepeatEnabled(false);
    window.setVerticalSyncEnabled(true);
    //window.setFramerateLimit(60);

    scale = width / 1280.0f;
    viewUI = sf::View({640, 360}, {1280, 720});
    viewCamera = sf::View({640, 360}, {1280, 720});
    clock = sf::Clock();

    Asset::loadAsset();

    scenes = std::unordered_map<int, shared_ptr<Scene>>({
        {TITLE, make_shared<SceneTitle>()},
        {SELECT, make_shared<SceneSelect>()},
        {BATTLE, make_shared<SceneBattle>()},
        {COLLECTION, make_shared<SceneCollection>()}
    });
    scene = scenes[TITLE];
    scene->ready(*this);

    field = make_shared<Field>();
}

void Game::loop() {
    dt = clock.restart().asSeconds();
    // Handling input
    handleInput();

    // Update
    scene->update(*this);
    // Render
    window.clear(sf::Color::White);
    scene->render(*this);
    window.display();
}

void Game::handleInput() {
    using Scan = sf::Keyboard::Scan;
    while (const std::optional event = window.pollEvent()) {
        if (event->is<sf::Event::Closed>()) {
            window.close();
        }

        if (const auto* e = event->getIf<sf::Event::MouseButtonReleased>()) {
            sf::Vector2f pos = {(float)e->position.x, (float)e->position.y};
            pos /= scale;
            std::cout << pos.x << " " << pos.y << std::endl;
            scene->mouseUp(*this, pos, e->button);
        }

        if (const auto* e = event->getIf<sf::Event::KeyPressed>()) {
            Scan scan = e->scancode;
            
            if (scan == Scan::Left || scan == Scan::W) keyPressed[LEFT] = true;
            else if (scan == Scan::Right || scan == Scan::D) keyPressed[RIGHT] = true;
            else if (scan == Scan::Up || scan == Scan::W) keyPressed[UP] = true;
            else if (scan == Scan::Down || scan == Scan::S) keyPressed[DOWN] = true;

            scene->keyDown(*this, scan);
        }

        if (const auto* e = event->getIf<sf::Event::KeyReleased>()) {
            Scan scan = e->scancode;

            if (scan == Scan::Left || scan == Scan::W) keyPressed[LEFT] = false;
            else if (scan == Scan::Right || scan == Scan::D) keyPressed[RIGHT] = false;
            else if (scan == Scan::Up || scan == Scan::W) keyPressed[UP] = false;
            else if (scan == Scan::Down || scan == Scan::S) keyPressed[DOWN] = false;
        }
    }
}

void Game::changeSceneTo(int target) {
    try {
        scene = scenes[target];
        scene->ready(*this);
    } catch (...) {
        std::cout << "No Scene" << std::endl;
        window.close();
    }
}
