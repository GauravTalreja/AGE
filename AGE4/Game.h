#ifndef AGE4_GAME_H
#define AGE4_GAME_H

#include "CursesController.h"
#include "CursesView.h"
#include "InputActions.h"
#include "Scene.h"

class AGE4Game {
  CursesView view{*this};
  CursesController controller;
  void tick(AGE4InputAction inputAction);

public:
  std::unique_ptr<AGE4Scene> scene;
  void go();
};

#endif // AGE4_GAME_H
