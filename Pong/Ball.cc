#include "Ball.h"
#include "Paddle.h"
#include "Scoreboard.h"

AGE4Bitmap Ball::ballMap{"o"};

Ball::Ball(AGE4Scene *parent, Scoreboard *scoreboard)
    : AGE4Actor{parent, AGE4ActorBody{40, 10, 40, 10, 0, &Ball::ballMap}},
      scoreboard{scoreboard} {
  behaviors = std::move(std::unique_ptr<AGE4ActorBehavior>{
      new Velocity{std::move(behaviors), -3, 270}});
}

void Ball::collide(Border border) {
  switch (border) {
  case Border::up:
    behaviors->bounce(Axis::vertical);
    behaviors->doBehavior(body, AGE4InputAction::empty);
    break;
  case Border::down:
    behaviors->bounce(Axis::vertical);
    behaviors->doBehavior(body, AGE4InputAction::empty);
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

void Ball::collide(AGE4Actor *other) {
  if (auto paddle = dynamic_cast<Paddle *>(other)) {
    behaviors = std::make_unique<Velocity>(
        std::make_unique<AGE4ActorBehaviorBase>(), 5,
        (body.getPosY() - paddle->getBody().getPosY()) / 7 * 60 + 60 +
            ((body.getPosX() < 40) ? 0 : 180));
  }
}
