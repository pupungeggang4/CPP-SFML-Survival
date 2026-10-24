#ifndef ASSET_HPP
#define ASSET_HPP

#include "includes.hpp"

class Asset {
    public:
        sf::Font neodgm;
        std::unordered_map<std::string, sf::Texture> texture; 

        void loadAsset();
        void disposeAsset();
};

#endif
