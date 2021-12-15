#ifndef CURSES_CONTROLLER_H
#define CURSES_CONTROLLER_H

#include "InputActions.h"
#include <unordered_map>

class CursesController {
  static std::unordered_map<int, AGE4InputAction> keyMappings;

public:
  static AGE4InputAction getNextInputAction();

};
#endif // CURSES_CONTROLLER_H
