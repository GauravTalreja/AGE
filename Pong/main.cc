#include <AGE4.h>
#include "Ball.h"

int main () {
  AGE4Game pong;
  AGE4Scene mainLevel;
  mainLevel.isBorderRigid = true;
  mainLevel.newActor(std::make_unique<Ball>(&mainLevel));
}