#include "Ball.h"
#include "Paddle.h"
#include "Scoreboard.h"
#include <AGE4.h>

int main() {
  AGE4Game pong;
  AGE4Scene mainLevel;
  mainLevel.isBorderRigid = true;
  auto score = dynamic_cast<Scoreboard *>(
      mainLevel.newActor(std::make_unique<Scoreboard>(&mainLevel)));
  auto ball = mainLevel.newActor(std::make_unique<Ball>(&mainLevel, score));
  auto left = mainLevel.newActor(std::make_unique<Paddle>(
      &mainLevel, AGE4InputAction::w, AGE4InputAction::s, 5, 8));
  auto right = mainLevel.newActor(std::make_unique<Paddle>(
      &mainLevel, AGE4InputAction::up, AGE4InputAction::down, 74, 8));
  pong.scene = &mainLevel;
  pong.go();
}
