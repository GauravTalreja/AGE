//
// Created by GT on 2021-12-17.
//

#include "Paddle.h"

AGE4Bitmap Paddle::paddle{2, 4, ':'};

void Paddle::collide(Border border) { body = prevBody; }

Paddle::Paddle(AGE4Scene *parent, AGE4InputAction down, AGE4InputAction up,
               int xPos, int yPos)
    : AGE4Actor{parent, AGE4ActorBody{
                            static_cast<float>(xPos - 2), static_cast<float>(yPos),
                            static_cast<float>(xPos + 2),
                            static_cast<float>(yPos + 4), 0, &paddle}} {
  behaviors = std::make_unique<Velocity>(
      std::make_unique<Velocity>(std::make_unique<AGE4ActorBehaviorBase>(), 1,
                                 0, down),
      1, 180, up);
}
