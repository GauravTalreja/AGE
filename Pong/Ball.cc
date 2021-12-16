#include "Ball.h"
#include "Scoreboard.h"

unique_ptr<AGE4Bitmap> Ball::ballMap{std::make_unique<AGE4Bitmap>("o")};

Ball::Ball(AGE4Scene *parent, Scoreboard *scoreboard)
    : AGE4Actor{parent, AGE4ActorBody{40, 10, 40, 10, 0, ballMap.get()}},
      scoreboard{scoreboard} {
  behaviors = std::move(std::unique_ptr<AGE4ActorBehavior>{
      new Velocity{std::move(behaviors), 3, 270}});
}

void Ball::collide(Border border) {
  switch (border) {
  case Border::up:
    behaviors->bounce(Axis::vertical);
    behaviors->doBehavior(AGE4InputAction::empty);
    break;
  case Border::down:
    behaviors->bounce(Axis::vertical);
    behaviors->doBehavior(AGE4InputAction::empty);
    break;
  case Border::left:
    scoreboard->right++;
    canBeDestructed = true;
    parent->newActor(std::unique_ptr<AGE4Actor>(new Ball{parent, scoreboard}));
    break;
  case Border::right:
    scoreboard->left++;
    canBeDestructed = true;
    parent->newActor(std::unique_ptr<AGE4Actor>(new Ball{parent, scoreboard}));
    break;
  }
}
