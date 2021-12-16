#ifndef AGE4_GAME_H
#define AGE4_GAME_H

#include "CursesController.h"
#include "CursesView.h"
#include "InputActions.h"
#include "Scene.h"

class AGE4Game {
  CursesView view;
  CursesController controller;
  void tick(AGE4InputAction inputAction);

 public:
  AGE4Scene* scene;
  void go();
  AGE4Game();
};

#endif  // AGE4_GAME_H
