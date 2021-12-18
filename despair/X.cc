//
// Created by GT on 2021-12-17.
//
#include "X.h"
#include <random>

static std::random_device rd; // only used once to initialise (seed) engine
static std::mt19937
    rng(rd()); // random-number engine used (Mersenne-Twister in this case)
static std::uniform_int_distribution<int> uni(1, 4); // guaranteed unbiased

std::vector<AGE4Bitmap> X::map = {AGE4Bitmap{"X"}, AGE4Bitmap{"x"}};

void X::doTick(AGE4InputAction a) {
  if (a != AGE4InputAction::null) {
    int random = uni(rng);
    switch (random) {
    case 1:
      parent->newActor(
          std::make_unique<X>(parent, body.getPosX() - 1, body.getPosY()));
      break;
    case 2:
      parent->newActor(
          std::make_unique<X>(parent, body.getPosX() - 1, body.getPosY() - 1));
      break;
    case 3:
      parent->newActor(
          std::make_unique<X>(parent, body.getPosX(), body.getPosY() - 1));
      break;
    default:
      parent->newActor(
          std::make_unique<X>(parent, body.getPosX() - 1, body.getPosY() - 1));
      break;
    }
  }
}

X::X(AGE4Scene *parent, int xPos, int yPos)
    : AGE4Actor{parent, AGE4ActorBody{
                            static_cast<float>(xPos), static_cast<float>(yPos),
                            static_cast<float>(xPos), static_cast<float>(yPos),
                            0, &map[uni(rng) % 2]}} {
  behaviors =
      std::make_unique<PhaseShift>(std::make_unique<AGE4ActorBehaviorBase>(),
                                   std::vector<AGE4Bitmap *>{&map[0], &map[1]});
}
