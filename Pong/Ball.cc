//
// Created by GT on 15-Dec-21.
//

#include "Ball.h"

unique_ptr<AGE4Bitmap> Ball::ballMap{std::make_unique<AGE4Bitmap>("o")};

Ball::Ball(AGE4Scene* parent)
    : AGE4Actor{parent, AGE4ActorBody{40, 10, 40, 10, 0, ballMap.get()}} {
  behaviors = std::move(std::unique_ptr<AGE4ActorBehavior>{
      new Velocity{std::move(behaviors), 1, 45, AGE4InputAction::null}});
}
