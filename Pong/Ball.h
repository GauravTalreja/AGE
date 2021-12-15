//
// Created by GT on 15-Dec-21.
//

#ifndef FINAL_BALL_H
#define FINAL_BALL_H

#include <AGE4.h>

class Ball : public AGE4Actor {
  static unique_ptr<AGE4Bitmap> ballMap;
public:
  Ball(AGE4Scene *);
};

#endif // FINAL_BALL_H
