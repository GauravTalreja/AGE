//
// Created by GT on 2021-12-17.
//

#include "P.h"
#include "X.h"

AGE4Bitmap P::p{"P"};

void P::collide(Border border) { body = prevBody; }

void P::collide(AGE4Actor *other) {
  if (dynamic_cast<X *>(other)) {
    parent->status[0] = "GAME OVER";
    parent->status[1] = "YOU SHOULD NOT HAVE EVEN TRIED";
    parent->status[2] = "THERE IS NO ESCAPE";
    behaviors = std::make_unique<AGE4ActorBehaviorBase>();
  }
}

P::P(AGE4Scene *parent)
    : AGE4Actor(parent, AGE4ActorBody{76, 19, 76, 19, 0, &p}) {
  behaviors = std::make_unique<Velocity>(
      std::make_unique<Velocity>(
          std::make_unique<Velocity>(
              std::make_unique<Velocity>(
                  std::make_unique<AGE4ActorBehaviorBase>(), 1, 0,
                  AGE4InputAction::down),
              1, 180, AGE4InputAction::up),
          1, 90, AGE4InputAction::left),
      1, 360, AGE4InputAction::right);
}
