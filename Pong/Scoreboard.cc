//
// Created by GT on 2021-12-16.
//

#include "Scoreboard.h"

Scoreboard::Scoreboard(AGE4Scene *scene) : AGE4Actor{scene} {}

void Scoreboard::doTick(AGE4InputAction inputAction) {
  parent->status[1] = "                                   " +
                      std::to_string(left) + "     -     " +
                      std::to_string(right);
  if (left >= 11) {
    parent->status[0] = "PLAYER 1 WINS!";
    left = 0;
    right = 0;
  } else  if (right >= 11) {
    parent->status[0] = "PLAYER 2 WINS!";
    left = 0;
    right = 0;
  }
}
