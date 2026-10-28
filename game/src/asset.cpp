#include "asset.hpp"

std::optional<sf::Font> Asset::neodgm;
std::unordered_map<std::string, sf::Texture> Asset::texture;

void Asset::loadAsset() {
    neodgm.emplace();
    neodgm->openFromFile("asset/font/neodgm.ttf");
    texture = std::unordered_map<std::string, sf::Texture>({
        {"button_menu", sf::Texture("asset/image/back.png")},
        {"arrow", sf::Texture("asset/image/arrow.png")},
    });
}

void Asset::disposeAsset() {
    texture.clear();
    neodgm.reset();
}
