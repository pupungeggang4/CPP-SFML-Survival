#include "asset.hpp"

sf::Font Asset::neodgm;
std::unordered_map<std::string, sf::Texture> Asset::texture;

void Asset::loadAsset() {
    neodgm.openFromFile("asset/font/neodgm.ttf");
    texture = std::unordered_map<std::string, sf::Texture>({
        {"button_menu", sf::Texture("asset/image/back.png")},
    });
}

void Asset::disposeAsset() {
}
