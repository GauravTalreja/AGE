#include "ActorBehavior.h"
#include "Actor.h"
#include <cmath>

#define PI 3.14159

bool AGE4ActorBehaviorBase::hasPlayerControlledBehavior() { return false; }

void AGE4ActorBehaviorBase::doBehavior(AGE4ActorBody&, AGE4InputAction) {}

void AGE4ActorBehaviorBase::bounce(Axis) {}

bool AGE4ActorBehaviorDecorator::hasPlayerControlledBehavior() {
  return requiredInputAction != AGE4InputAction::null ||
         next->hasPlayerControlledBehavior();
}

AGE4ActorBehaviorDecorator::AGE4ActorBehaviorDecorator(
    unique_ptr<AGE4ActorBehavior> &&next, AGE4InputAction inputAction)
    : AGE4ActorBehavior{*next}, next{std::move(next)}, requiredInputAction{
                                                           inputAction} {}

void Velocity::doBehavior(AGE4ActorBody& body, AGE4InputAction inputAction) {
  angle = static_cast<float>(static_cast<int>(angle) % 360);
  if (requiredInputAction == AGE4InputAction::null ||
      requiredInputAction == inputAction) {
    body.posX += static_cast<float>(std::sin(angle * PI / 180)) * magnitude;
    body.posY -= static_cast<float>(std::cos(angle * PI / 180)) * magnitude;
  }
  next->doBehavior(body, inputAction);
}

void Velocity::bounce(Axis a) {
  angle = static_cast<float>(static_cast<int>(angle) % 360);
  if (a == Axis::horizontal) {
    angle = 360 - angle;
  }
  if (a == Axis::vertical) {
    angle = 180 - angle;
  }
}

Velocity::Velocity(std::unique_ptr<AGE4ActorBehavior> &&component, float dist,
                   float angle, AGE4InputAction requiredInputAction)
    : AGE4ActorBehaviorDecorator{std::move(component), requiredInputAction},
      magnitude{dist}, angle{angle} {}

void PhaseShift::doBehavior(AGE4ActorBody& body, AGE4InputAction inputAction) {
  if (requiredInputAction == AGE4InputAction::null ||
      requiredInputAction == inputAction) {
    activeIndex = (activeIndex + 1) % phases.size();
    body.bitmap = phases[activeIndex];
  }
  next->doBehavior(body, inputAction);
}

void PhaseShift::bounce(Axis a) { next->bounce(a); }

PhaseShift::PhaseShift(unique_ptr<AGE4ActorBehavior> &&component,
                       std::vector<AGE4Bitmap *> phases,
                       AGE4InputAction inputAction = AGE4InputAction::null)
    : AGE4ActorBehaviorDecorator{std::move(component), inputAction},
      activeIndex{0}, phases{std::move(phases)} {}
