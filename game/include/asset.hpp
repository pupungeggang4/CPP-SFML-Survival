#ifndef ASSET_HPP
#define ASSET_HPP

#include "includes.hpp"

class Asset {
    public:
        static std::optional<sf::Font> neodgm;
        static std::unordered_map<std::string, sf::Texture> texture; 

        static void loadAsset();
        static void disposeAsset();
};

#endif
