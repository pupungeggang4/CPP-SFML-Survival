#include "game.hpp"
#include "scene.hpp"

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
    viewUI = sf::View({640, 360}, {1280, 720});
    viewCamera = sf::View({0, 0}, {1280, 720});
    clock = sf::Clock();

    scenes = std::unordered_map<int, shared_ptr<Scene>>({
        {TITLE, make_shared<SceneTitle>()}
    });
    scene = scenes[TITLE];
    scene->ready(*this);
}

void Game::loop() {
    while (window.isOpen()) {
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
}

void Game::handleInput() {
    using Scan = sf::Keyboard::Scan;
    while (const std::optional event = window.pollEvent()) {
        if (event->is<sf::Event::Closed>()) {
            window.close();
        }
        if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>()) {
            if (keyPressed->scancode == sf::Keyboard::Scan::Escape) {
                std::cout << "the escape key was pressed" << std::endl;
                std::cout << "scancode: " << static_cast<int>(keyPressed->scancode) << std::endl;
                std::cout << "code: " << static_cast<int>(keyPressed->code) << std::endl;
                std::cout << "control: " << keyPressed->control << std::endl;
                std::cout << "alt: " << keyPressed->alt << std::endl;
                std::cout << "shift: " << keyPressed->shift << std::endl;
                std::cout << "system: " << keyPressed->system << std::endl;
                std::cout << "description: " << sf::Keyboard::getDescription(keyPressed->scancode).toAnsiString() << std::endl;
                std::cout << "localize: " << static_cast<int>(sf::Keyboard::localize(keyPressed->scancode)) << std::endl;
                std::cout << "delocalize: " << static_cast<int>(sf::Keyboard::delocalize(keyPressed->code)) << std::endl;
            }
        }
    }
}
