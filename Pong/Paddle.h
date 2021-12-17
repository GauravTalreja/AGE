//
// Created by GT on 2021-12-17.
//

#ifndef FINAL_PADDLE_H
#define FINAL_PADDLE_H
#include <AGE4.h>

class Paddle : public AGE4Actor {
  static AGE4Bitmap paddle;
  void collide(Border) override;

public:
  Paddle(AGE4Scene *parent, AGE4InputAction down, AGE4InputAction up, int xPos,
         int yPos);
};

#endif // FINAL_PADDLE_H
