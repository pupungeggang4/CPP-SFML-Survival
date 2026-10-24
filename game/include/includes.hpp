#ifndef INCLUDES_HPP
#define INCLUDES_HPP

#include <iostream>
#include <sstream>
#include <fstream>

#include <string>
#include <unordered_map>
#include <vector>
#include <array>

#include <memory>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

enum SceneName {TITLE, SELECT, BATTLE};
enum State {NORMAL, REWARD};

using std::shared_ptr;
using std::make_shared;

#endif
