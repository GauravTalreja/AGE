#ifndef AGE4_MOVEMENT_H
#define AGE4_MOVEMENT_H

struct AGE4ActorBody;
class AGE4Bitmap;

#include "Axes.h"
#include "InputActions.h"
#include <memory>
#include <vector>

class AGE4ActorBehaviorDecorator;

class AGE4ActorBehavior {
public:
  virtual void doBehavior(AGE4ActorBody &body, AGE4InputAction) = 0;

  virtual bool hasPlayerControlledBehavior() = 0;

  virtual void bounce(Axis a) = 0;

  virtual ~AGE4ActorBehavior() = default;
};

class AGE4ActorBehaviorBase : public AGE4ActorBehavior {
public:
  void doBehavior(AGE4ActorBody &body, AGE4InputAction inputAction) override;
  void bounce(Axis) override;
  bool hasPlayerControlledBehavior() override;
};

class AGE4ActorBehaviorDecorator : public AGE4ActorBehavior {
protected:
  std::unique_ptr<AGE4ActorBehavior> next;
  AGE4InputAction requiredInputAction;

public:
  ~AGE4ActorBehaviorDecorator() override = default;
  bool hasPlayerControlledBehavior() override;
  AGE4ActorBehaviorDecorator(std::unique_ptr<AGE4ActorBehavior> &&next,
                             AGE4InputAction inputAction);
};

class Velocity : public AGE4ActorBehaviorDecorator {
public:
  float magnitude, angle;
  void doBehavior(AGE4ActorBody &body, AGE4InputAction inputAction) override;
  void bounce(Axis a) override;
  Velocity(std::unique_ptr<AGE4ActorBehavior> &&component, float dist,
           float angle,
           AGE4InputAction requiredInputAction = AGE4InputAction::null);
};

class PhaseShift : public AGE4ActorBehaviorDecorator {
  size_t activeIndex;

public:
  std::vector<AGE4Bitmap *> phases;
  void doBehavior(AGE4ActorBody &body, AGE4InputAction inputAction) override;
  void bounce(Axis a) override;
  PhaseShift(std::unique_ptr<AGE4ActorBehavior> &&component,
             std::vector<AGE4Bitmap *> phases,
             AGE4InputAction inputAction = AGE4InputAction::null);
};

#endif // AGE4_MOVEMENT_H
