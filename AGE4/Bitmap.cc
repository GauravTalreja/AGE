#include "Bitmap.h"

#include <utility>

AGE4Character::AGE4Character(int X, int Y, char C) : X{X}, Y{Y}, C{C} {}

AGE4Bitmap::AGE4Bitmap(char C) { theBitmap.emplace_back(0, 0, C); }

AGE4Bitmap::AGE4Bitmap(int lengthX, int heightY, char C) {
  for (int i = 0; i < lengthX; ++i) {
    for (int j = 0; j < heightY; ++j) {
      theBitmap.emplace_back(i, j, C);
    }
  }
}

AGE4Bitmap::AGE4Bitmap(std::vector<AGE4Character> bitmap)
    : theBitmap{std::move(bitmap)} {}

AGE4Bitmap::AGE4Bitmap(std::string s) {
  int i = 0;
  for (char c : s) {
    theBitmap.emplace_back(i++, 0, c);
  }
}

AGE4Bitmap::iterator AGE4Bitmap::begin() { return theBitmap.begin(); }

AGE4Bitmap::iterator AGE4Bitmap::end() { return theBitmap.end(); }

AGE4Bitmap::const_iterator AGE4Bitmap::begin() const {
  return theBitmap.begin();
}
AGE4Bitmap::const_iterator AGE4Bitmap::end() const {
  return theBitmap.end();
}
