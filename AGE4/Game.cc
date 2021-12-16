#include "Game.h"
#include <thread>
#include "Config.h"

void AGE4Game::tick(AGE4InputAction inputAction) {
  scene->Tick(inputAction);
}

void AGE4Game::go() {
  AGE4InputAction inputAction;
  while (inputAction != AGE4InputAction::zero) {
    auto startTime = std::chrono::high_resolution_clock::now();
    inputAction = CursesController::getNextInputAction();
    tick(inputAction);
    view.print();
    auto stopTime = std::chrono::high_resolution_clock::now();

    if (stopTime - startTime <
        std::chrono::milliseconds(minTickDurationMilliseconds)) {
      std::this_thread::sleep_for(
          std::chrono::milliseconds(minTickDurationMilliseconds) -
          (stopTime - startTime));
    }
  }
}

AGE4Game::AGE4Game() : view{CursesView{*this}}, controller{} {}
