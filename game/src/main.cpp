#include "includes.hpp"
#include "game.hpp"
#include "asset.hpp"

int main (int argc, char** argv) {
    Game game;
    while (game.window.isOpen()) {
        game.loop();
    }
    Asset::disposeAsset();
    return 0;
}
