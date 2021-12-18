//
// Created by GT on 2021-12-17.
//

#ifndef LEFTRIGHT_X_H
#define LEFTRIGHT_X_H

#include <AGE4.h>

class X : public AGE4Actor {
  static std::vector<AGE4Bitmap> map;

  void doTick(AGE4InputAction a) override;

public:
X(AGE4Scene* parent, int xPos, int yPos);
};

#endif // LEFTRIGHT_X_H
