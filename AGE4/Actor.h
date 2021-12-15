#ifndef AGE4_ACTOR_H
#define AGE4_ACTOR_H

#include "Bitmap.h"
#include "Borders.h"
#include "InputActions.h"
#include "ActorBehavior.h"
#include <memory>
#include <string>
#include <compare>

using std::unique_ptr;
using std::string;

class AGE4Scene;

/*
 * An Actor's body consists of its:
 * * Bitmap
 * * Position in the 2D plane
 * * Height
 * */
struct AGE4ActorBody {
  // top left position, primary position of the entity
  float posX = 0, posY = 0;

  // bottom right, used for AABB collision calculations
  float botRightX = posX, botRightY = posY;

  int height = 0;
  AGE4Bitmap* bitmap;

  // Comparison of bodies
  std::strong_ordering operator<=>(const AGE4ActorBody& other) const;
};

// Superclass of all Actors added to Levels in AGE4.
class AGE4Actor {
  // For garbage collection
  unsigned int invisibleTicks;

protected:
  // Access parent level's interface
  AGE4Scene *parent;

  // doTick is called every Tick
  virtual void doTick(AGE4InputAction a) {}

  // behaviors
  unique_ptr<AGE4ActorBehavior> behaviors;

  // body
  AGE4ActorBody body;
  AGE4ActorBody prevBody;

public:
  bool canBeDestructed;

  // Checks if Actor hasPlayerControlledBehavior
  bool isPlayerControlled();

  virtual void collide(AGE4Actor *other) {}

  virtual void collide(Border border) {}

  void Tick(AGE4InputAction inputAction);

  AGE4ActorBody &getPrevActorBody();

  [[nodiscard]] const AGE4ActorBody &getBody() const;

  void setBody(const AGE4ActorBody &body);

  /*
   * parent should always refer to the Scene that owns this Actor
   */
  AGE4Actor(AGE4Scene *parent, AGE4ActorBody actorBody);

  virtual ~AGE4Actor() = 0;
};

#endif // AGE4_ACTOR_H