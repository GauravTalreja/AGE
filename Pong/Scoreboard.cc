//
// Created by GT on 2021-12-16.
//

#include "Scoreboard.h"

Scoreboard::Scoreboard(AGE4Scene *scene): AGE4Actor{scene} {}

void Scoreboard::doTick(AGE4InputAction inputAction) {
  parent->status[0] = std::to_string(left);
  parent->status[1] = std::to_string(right);
}
