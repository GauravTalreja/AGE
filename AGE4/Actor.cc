#include "Actor.h"
#include "Scene.h"

using std::make_unique;

AGE4ActorBody::AGE4ActorBody()
    : posX{0},
      posY{0},
      botRightX{0},
      botRightY{0},
      height{0},
      bitmap{nullptr} {}

AGE4ActorBody::AGE4ActorBody(float posX,
                             float posY,
                             float botRightX,
                             float botRightY,
                             int height,
                             AGE4Bitmap* bmp)
    : posX{posX},
      posY{posY},
      botRightX{botRightX},
      botRightY{botRightY},
      height{height},
      bitmap{bmp} {}

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

AGE4Actor::AGE4Actor(AGE4Scene* parent, AGE4ActorBody actorBody)
    : invisibleTicks{0},
      parent{parent},
      body{actorBody},
      behaviors{make_unique<AGE4ActorBehaviorBase>(actorBody)},
      canBeDestructed{false} {}

const AGE4ActorBody& AGE4Actor::getBody() const {
  return body;
}

void AGE4Actor::setBody(const AGE4ActorBody& body) {
  AGE4Actor::body = body;
}

AGE4ActorBody& AGE4Actor::getPrevActorBody() {
  return prevBody;
}

AGE4Actor::~AGE4Actor(){};
