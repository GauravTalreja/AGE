#include "Scene.h"
#include "Config.h"

void AGE4Scene::tickEntities(AGE4InputAction inputAction) {
  for (auto &e : actors) {
    e->Tick(inputAction);
  }
}

void AGE4Scene::Tick(AGE4InputAction inputAction) {
  tickEntities(inputAction);
  doTick(inputAction);
  handleCollisions();
  destructGarbage();
}

void AGE4Scene::handleCollisions() {
  for (auto &a : actors) {
    checkAndResolveEdgeCollision(a.get());
    for (auto &b : actors) {
      if (b != a) {
        checkAndResolveCollision(a.get(), b.get());
      }
    }
  }
}

void AGE4Scene::destructGarbage() {
  auto it = actors.begin();
  while (it != actors.end()) {
    if ((*it)->canBeDestructed) {
      it = actors.erase(it);
    } else {
      ++it;
    }
  }
}

const std::vector<unique_ptr<AGE4Actor>> &AGE4Scene::getActors() const {
  return actors;
}

void AGE4Scene::newActor(unique_ptr<AGE4Actor> &&actor) {
  actors.push_back(actor);
}
void AGE4Scene::checkAndResolveCollision(AGE4Actor *a, AGE4Actor *b) {
  auto bodyA = a->getBody(), bodyB = b->getBody();
  if (bodyA.height == bodyB.height &&
      !(bodyA.botRightX < bodyB.posX || bodyB.botRightX < bodyA.posX ||
        bodyA.botRightY < bodyB.posY || bodyB.botRightY < bodyA.posY)) {
    a->collide(b);
    b->collide(a);
  }
}

void AGE4Scene::checkAndResolveEdgeCollision(AGE4Actor *actor) {
  auto body = actor->getBody();
  if (actor->isPlayerControlled() || isBorderRigid) {
    if (body.posX <= 0) {
      actor->collide(Border::left);
    } else if (body.posY >= borderColumns - 1) {
      actor->collide(Border::right);
    } else if (body.posY <= 0) {
      actor->collide(Border::up);
    } else if (body.posY >= borderRows - 1) {
      actor->collide(Border::down);
    }
  }
}
