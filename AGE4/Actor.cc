#include "Actor.h"
#include "Scene.h"

using std::make_unique;

std::strong_ordering
AGE4ActorBody::operator<=>(const AGE4ActorBody &other) const {
  if (auto cmp = static_cast<int>(posX) <=> static_cast<int>(other.posX);
      cmp != nullptr) {
    return cmp;
  }
  if (auto cmp = static_cast<int>(posY) <=> static_cast<int>(other.posY);
      cmp != nullptr) {
    return cmp;
  }
  if (auto cmp = height <=> other.height; cmp != nullptr) {
    return cmp;
  }
  return *bitmap <=> *other.bitmap;
}

bool AGE4Actor::isPlayerControlled() {
  if (behaviors) {
    return behaviors->hasPlayerControlledBehavior();
  }
  return false;
}

void AGE4Actor::Tick(AGE4InputAction inputAction) {
  prevBody = body;
  doTick(inputAction);
  if (behaviors) {
    behaviors->doBehavior(inputAction);
  }
  if (false) {
    ++invisibleTicks;
  } else {
    invisibleTicks = 0;
  }
  if (invisibleTicks >= 5) {
    canBeDestructed = true;
  }
}


AGE4Actor::AGE4Actor(AGE4Scene *parent, AGE4ActorBody actorBody)
    : invisibleTicks{0}, parent{parent}, body{actorBody},
      behaviors{make_unique<AGE4ActorBehaviorBase>(actorBody)},
      canBeDestructed{false} {}

const AGE4ActorBody &AGE4Actor::getBody() const { return body; }

void AGE4Actor::setBody(const AGE4ActorBody &body) { AGE4Actor::body = body; }

AGE4ActorBody &AGE4Actor::getPrevActorBody() { return prevBody; }

AGE4Actor::~AGE4Actor() = default;