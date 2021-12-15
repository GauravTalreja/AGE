#ifndef CURSES_VIEW_H
#define CURSES_VIEW_H

#include <string>

using std::string;

class AGE4Game;

class CursesView {
  string boardTop = "+---------------------------------------------------------"
                    "---------------------+";
  AGE4Game & g;
  void printBorders() const;
  void printStatus() const;
  void printEntities() const;

public:
  ~CursesView();
  explicit CursesView(AGE4Game & g);
  void print();
};
#endif // CURSES_VIEW_H
