#include "ui/ui.hpp"

std::unordered_map<std::string, std::array<float, 6>> UI::UITitle = {
    {"text_title", {20, 20}},
    {"button_start", {160, 160, 960, 80}},
    {"button_collection", {160, 240, 960, 80}},
    {"button_quit", {160, 320, 960, 80}},
    {"arrow", {80, 160, 0, 80}},
};

std::unordered_map<std::string, std::array<float, 6>> UI::UISelect = {
    {"text_title", {20, 20}},
    {"button_back", {1180, 20, 80, 80}},
};
