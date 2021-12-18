//
// Created by GT on 2021-12-17.
//

#include <AGE4.h>
#include "P.h"
#include "X.h"

int main() {
  AGE4Game despair;
  AGE4Scene mainLevel;
  despair.scene = &mainLevel;
  mainLevel.isBorderRigid = true;
  mainLevel.newActor(std::make_unique<P>(&mainLevel));
  mainLevel.newActor(std::make_unique<X>(&mainLevel, 3, 4));
  despair.go();
}