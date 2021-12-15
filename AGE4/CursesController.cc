#include "CursesController.h"
#include <ncurses.h>

std::unordered_map<int, AGE4InputAction> CursesController::keyMappings = {
    {ERR, AGE4InputAction::null},
    {'0', AGE4InputAction::zero},
    {'1', AGE4InputAction::one},
    {'2', AGE4InputAction::two},
    {'3', AGE4InputAction::three},
    {'4', AGE4InputAction::four},
    {'5', AGE4InputAction::five},
    {'6', AGE4InputAction::six},
    {'7', AGE4InputAction::seven},
    {'8', AGE4InputAction::eight},
    {'9', AGE4InputAction::nine},
    {KEY_UP, AGE4InputAction::up},
    {KEY_LEFT, AGE4InputAction::left},
    {KEY_DOWN, AGE4InputAction::down},
    {KEY_RIGHT, AGE4InputAction::right},
    {'a', AGE4InputAction::a},
    {'b', AGE4InputAction::b},
    {'c', AGE4InputAction::c},
    {'d', AGE4InputAction::d},
    {'e', AGE4InputAction::e},
    {'f', AGE4InputAction::f},
    {'g', AGE4InputAction::g},
    {'h', AGE4InputAction::h},
    {'i', AGE4InputAction::i},
    {'j', AGE4InputAction::j},
    {'k', AGE4InputAction::k},
    {'l', AGE4InputAction::l},
    {'m', AGE4InputAction::m},
    {'n', AGE4InputAction::n},
    {'o', AGE4InputAction::o},
    {'p', AGE4InputAction::p},
    {'q', AGE4InputAction::q},
    {'r', AGE4InputAction::r},
    {'s', AGE4InputAction::s},
    {'t', AGE4InputAction::t},
    {'u', AGE4InputAction::u},
    {'v', AGE4InputAction::v},
    {'w', AGE4InputAction::w},
    {'x', AGE4InputAction::x},
    {'y', AGE4InputAction::y},
    {'z', AGE4InputAction::z},
};

AGE4InputAction CursesController::getNextInputAction() {
  int rawInput = getch();
  flushinp();
  return keyMappings[rawInput];
}
