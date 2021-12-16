#ifndef PONG_BALL_H
#define PONG_BALL_H

#include <AGE4.h>

class Scoreboard;

class Ball : public AGE4Actor {
  static unique_ptr<AGE4Bitmap> ballMap;
  Scoreboard* scoreboard;

 public:
  void collide(Border border) override;
  Ball(AGE4Scene*, Scoreboard*);
};

#endif  // PONG_BALL_H
