//
// Created by GT on 15-Dec-21.
//

#include "Ball.h"

unique_ptr<AGE4Bitmap> Ball::ballMap{std::make_unique<AGE4Bitmap>("o")};

Ball::Ball(AGE4Scene *l)
    : AGE4Actor{l, AGE4ActorBody{40, 10, 40, 10, 0, ballMap.get()}} {}
