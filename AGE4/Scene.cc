#include "Scene.h"
#include "Config.h"

void AGE4Scene::tickActors(AGE4InputAction inputAction) {
  auto end = actors.size();
  for (size_t i = 0; i < end; ++i) {
    actors[i]->Tick(inputAction);
  }
}

void AGE4Scene::Tick(AGE4InputAction inputAction) {
  tickActors(inputAction);
  doTick(inputAction);
  handleCollisions();
  destructGarbage();
}

void AGE4Scene::handleCollisions() {
  for (size_t i = 0; i < actors.size(); ++i) {
    checkAndResolveEdgeCollision(actors[i].get());
    for (size_t j = 0; j < actors.size(); ++j) {
      if (i != j) {
        checkAndResolveCollision(actors[i].get(), actors[j].get());
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

AGE4Actor *AGE4Scene::newActor(unique_ptr<AGE4Actor> &&actor) {
  actors.push_back(std::move(actor));
  return actors[actors.size() - 1].get();
}

void AGE4Scene::checkAndResolveCollision(AGE4Actor *a, AGE4Actor *b) {
  auto bodyA = a->getBody(), bodyB = b->getBody();
  if (bodyA.height == bodyB.height &&
      !(bodyA.getBotRightX() < bodyB.getPosX() ||
        bodyB.getBotRightX() < bodyA.getPosX() ||
        bodyA.getBotRightY() < bodyB.getPosY() ||
        bodyB.getBotRightY() < bodyA.getPosY())) {
    a->collide(b);
    b->collide(a);
  }
}

void AGE4Scene::checkAndResolveEdgeCollision(AGE4Actor *actor) const {
  const auto &body = actor->getBody();
  if (actor->isPlayerControlled() || isBorderRigid) {
    if (body.getPosX() <= 0) {
      actor->collide(Border::left);
    } else if (body.getBotRightX() >= borderColumns - 1) {
      actor->collide(Border::right);
    } else if (body.getPosY() <= 0) {
      actor->collide(Border::up);
    } else if (body.getBotRightY() >= borderRows - 1) {
      actor->collide(Border::down);
    }
  }
}
