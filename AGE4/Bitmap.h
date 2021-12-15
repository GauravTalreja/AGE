#ifndef AGE4_BITMAP_H
#define AGE4_BITMAP_H

#include <string>
#include <vector>
#include <compare>

struct AGE4Character {
  int X;
  int Y;
  char C;

  // Constructor for a Character.
  AGE4Character(int X, int Y, char C);
};

// A Bitmap is responsible for the visual representation of an Actor
struct AGE4Bitmap {
  std::vector<AGE4Character> theBitmap;

  // Constructor for a single character (assumed to be printable ASCII)
  explicit AGE4Bitmap(char C);

  // Constructor for a rectangle, made up of a single character, repeated
  AGE4Bitmap(int lengthX, int heightY, char C);

  // Explicit constructor from a vector of Character triples
  explicit AGE4Bitmap(std::vector<AGE4Character> bitmap);

  // Constructor for horizontal text
  explicit AGE4Bitmap(std::string s);

  // Comparison of bitmaps
  std::strong_ordering operator<=>(const AGE4Bitmap& other) const = default;
  ~AGE4Bitmap() = default;

  // iterator pattern
  typedef std::vector<AGE4Character>::iterator iterator;
  typedef std::vector<AGE4Character>::const_iterator const_iterator;
  iterator begin();
  iterator end();
  const_iterator begin() const;
  const_iterator end() const;
};

#endif // AGE4_BITMAP_H