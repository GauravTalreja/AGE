//
// Created by GT on 2021-12-16.
//

#ifndef FINAL_SCOREBOARD_H
#define FINAL_SCOREBOARD_H

#include <AGE4.h>

struct Scoreboard : AGE4Actor {
  int left = 0, right = 0;

  void doTick(AGE4InputAction inputAction) override;

public:
  explicit Scoreboard(AGE4Scene* scene);
};

#endif // FINAL_SCOREBOARD_H
