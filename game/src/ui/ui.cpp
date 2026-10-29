#include "ui/ui.hpp"

std::unordered_map<std::string, std::array<float, 6>> UI::UITitle = {
    {"text_title", {20, 20}},
    {"button_start", {160, 160, 960, 80}},
    {"button_collection", {160, 240, 960, 80}},
    {"button_quit", {160, 320, 960, 80}},
    {"arrow", {80, 160, 0, 80, 80, 80}},
};

std::unordered_map<std::string, std::array<float, 6>> UI::UISelect = {
    {"text_title", {20, 20}},
    {"button_back", {1180, 20, 80, 80}},
    {"button_character", {20, 120, 180, 180, 160, 160}},
    {"button_start", {1100, 620, 160, 80}},
    {"description_area", {660, 120, 600, 340}},
};

std::unordered_map<std::string, std::array<float, 6>> UI::UIBattle = {
    {"button_menu", {1180, 20, 80, 80}}
};

std::unordered_map<std::string, std::array<float, 6>> UI::UIMenu = {
    {"rect", {320, 200, 640, 320}},
    {"text_paused", {340, 220}},
    {"button_resume", {320, 280, 640, 80}},
    {"button_exit", {320, 360, 640, 80}},
    {"button_quit", {320, 440, 640, 80}},
    {"arrow", {240, 280, 0, 80, 80, 80}}
};
