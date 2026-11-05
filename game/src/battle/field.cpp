#include "field.hpp"

#include "asset.hpp"
#include "ui/ui.hpp"
#include "ui/uielement.hpp"

#include "game.hpp"

Entity::Entity() {
    sprite.emplace(Asset::texture["placeholder"]);
    sprite->setScale({4, 4});
}

void Entity::render(Game& game) {
    sprite->setPosition(rect.position);
    game.window.draw(*sprite);
}

void Entity::update(Game& game) {
}

Player::Player() {
}

void Player::update(Game& game) {
    if (game.keyPressed[LEFT]) rect.position.x -= 320 * game.dt;
    if (game.keyPressed[RIGHT]) rect.position.x += 320 * game.dt;
    if (game.keyPressed[UP]) rect.position.y -= 320 * game.dt;
    if (game.keyPressed[DOWN]) rect.position.y += 320 * game.dt;

}

Field::Field() {    
}

void Field::update(Game& game) {
    player.update(game);
}

void Field::render(Game& game) {
    player.render(game);
}
