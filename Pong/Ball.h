#ifndef PONG_BALL_H
#define PONG_BALL_H

#include <AGE4.h>

class Scoreboard;

class Ball : public AGE4Actor {
  static AGE4Bitmap ballMap;
  Scoreboard* scoreboard;

 public:
  void collide(Border border) override;
  Ball(AGE4Scene*, Scoreboard*);
  void collide(AGE4Actor *other) override;
};

#endif  // PONG_BALL_H
