//
// Created by GT on 2021-12-17.
//

#ifndef DESPAIR_P_H
#define DESPAIR_P_H
#include "AGE4.h"

class P : public AGE4Actor {
  void collide(AGE4Actor* other) override;
  static AGE4Bitmap p;
public:
  explicit P(AGE4Scene *parent);
  void collide(Border border) override;
};

#endif // DESPAIR_P_H
