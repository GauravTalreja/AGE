#include "Ball.h"
#include "Scoreboard.h"
#include <AGE4.h>

int main() {
  AGE4Game pong;
  AGE4Scene mainLevel;
  mainLevel.isBorderRigid = true;
  auto score = dynamic_cast<Scoreboard *>(
      mainLevel.newActor(std::make_unique<Scoreboard>(&mainLevel)));
  auto ball = mainLevel.newActor(std::make_unique<Ball>(&mainLevel, score));
  pong.scene = &mainLevel;
  pong.go();
}
