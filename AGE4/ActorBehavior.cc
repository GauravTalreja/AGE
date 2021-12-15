#include "ActorBehavior.h"
#include "Actor.h"
#include <cmath>

#define PI 3.14159

AGE4ActorBehavior::AGE4ActorBehavior(AGE4ActorBody &body) : body{body} {}

bool AGE4ActorBehaviorBase::hasPlayerControlledBehavior() { return false; }

void AGE4ActorBehaviorBase::doBehavior(AGE4InputAction) {}

void AGE4ActorBehaviorBase::bounce(Axis) {}

AGE4ActorBehaviorBase::AGE4ActorBehaviorBase(AGE4ActorBody &body)
    : AGE4ActorBehavior(body) {}

bool AGE4ActorBehaviorDecorator::hasPlayerControlledBehavior() {
  return requiredInputAction != AGE4InputAction::null ||
         next->hasPlayerControlledBehavior();
}

AGE4ActorBehaviorDecorator::AGE4ActorBehaviorDecorator(
    std::unique_ptr<AGE4ActorBehavior> next, AGE4InputAction gate)
    : AGE4ActorBehavior{*next}, next{std::move(next)}, requiredInputAction{
                                                           gate} {}

void Velocity::doBehavior(AGE4InputAction inputAction) {
  angle = static_cast<float>(static_cast<int>(angle) % 360);
  if (requiredInputAction == AGE4InputAction::null ||
      requiredInputAction == inputAction) {
    body.posX += static_cast<float>(std::sin(angle * PI / 180)) * magnitude;
    body.posY -= static_cast<float>(std::cos(angle * PI / 180)) * magnitude;
  }
  next->doBehavior(inputAction);
}

void Velocity::bounce(Axis a) {
  angle = static_cast<float>(static_cast<int>(angle) % 360);
  if (a == horizontal) {
    angle = 360 - angle;
  }
  if (a == vertical) {
    angle = 180 - angle;
  }
}

Velocity::Velocity(std::unique_ptr<AGE4ActorBehavior> component, float dist,
                   float angle,
                   AGE4InputAction requiredInputAction = AGE4InputAction::null)
    : AGE4ActorBehaviorDecorator{std::move(component), requiredInputAction},
      magnitude{dist}, angle{angle} {}

void PhaseShift::doBehavior(AGE4InputAction inputAction) {
  if (requiredInputAction == AGE4InputAction::null ||
      requiredInputAction == inputAction) {
    activeIndex = (activeIndex + 1) % phases.size();
    body.bitmap = phases[activeIndex];
  }
  next->doBehavior(inputAction);
}

void PhaseShift::bounce(Axis a) { next->bounce(a); }

PhaseShift::PhaseShift(std::unique_ptr<AGE4ActorBehavior> component,
                       std::vector<AGE4Bitmap *> phases,
                       AGE4InputAction inputAction = AGE4InputAction::null)
    : AGE4ActorBehaviorDecorator{std::move(component), inputAction},
      activeIndex{0}, phases{std::move(phases)} {}
