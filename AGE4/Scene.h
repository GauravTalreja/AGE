#ifndef AGE4_SCENE_H
#define AGE4_SCENE_H

#include "Actor.h"
#include "InputActions.h"
#include "Status.h"

#include <string>
#include <vector>

class AGE4Scene {
  std::vector<unique_ptr<AGE4Actor>> actors;

private:
  void tickEntities(AGE4InputAction inputAction);
  void handleCollisions();
  static void checkAndResolveCollision(AGE4Actor *a, AGE4Actor *b);
  void checkAndResolveEdgeCollision(AGE4Actor* actor) const;
  void destructGarbage();
  virtual void doTick(AGE4InputAction inputAction) {}

public:
  Status status;
  bool isBorderRigid;

  [[nodiscard]] const std::vector<unique_ptr<AGE4Actor>> &getActors() const;
  void Tick(AGE4InputAction inputAction);
  AGE4Actor *newActor(unique_ptr<AGE4Actor> &&actor);
};
#endif
