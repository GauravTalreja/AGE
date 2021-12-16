#include "Scene.h"
#include "Config.h"

void AGE4Scene::tickActors(AGE4InputAction inputAction) {
  for (size_t i = 0; i < actors.size(); ++i) {
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
  for (auto& a : actors) {
    checkAndResolveEdgeCollision(a.get());
    for (auto& b : actors) {
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

const std::vector<unique_ptr<AGE4Actor>>& AGE4Scene::getActors() const {
  return actors;
}

AGE4Actor* AGE4Scene::newActor(unique_ptr<AGE4Actor>&& actor) {
  actors.push_back(std::move(actor));
  return actors[actors.size() - 1].get();
}
void AGE4Scene::checkAndResolveCollision(AGE4Actor* a, AGE4Actor* b) {
  auto bodyA = a->getBody(), bodyB = b->getBody();
  if (bodyA.height == bodyB.height &&
      !(bodyA.botRightX < bodyB.posX || bodyB.botRightX < bodyA.posX ||
        bodyA.botRightY < bodyB.posY || bodyB.botRightY < bodyA.posY)) {
    a->collide(b);
    b->collide(a);
  }
}

void AGE4Scene::checkAndResolveEdgeCollision(AGE4Actor* actor) const {
  const auto& body = actor->getBody();
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
