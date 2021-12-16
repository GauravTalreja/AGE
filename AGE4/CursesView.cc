#include "CursesView.h"
#include <ncurses.h>
#include <algorithm>
#include <cmath>
#include "Config.h"
#include "Game.h"

CursesView::CursesView(AGE4Game& g) : g{g} {
  initscr();
  noecho();
  raw();
  curs_set(0);
  keypad(stdscr, TRUE);
  nodelay(stdscr, TRUE);
}

void CursesView::print() {
  erase();
  printBorders();
  printStatus();
  printEntities();
  refresh();
}

void CursesView::printBorders() const {
  mvprintw(0, 0, boardTop.c_str());
  for (int i = 1; i < borderRows; i++) {
    mvaddch(i, 0, '|');
    mvaddch(i, borderColumns - 1, '|');
  }
  mvprintw(borderRows, 0, boardTop.c_str());
}

void CursesView::printStatus() const {
  mvprintw(borderRows + 1, 0, g.scene->status[0].c_str());
  mvprintw(borderRows + 2, 0, g.scene->status[1].c_str());
  mvprintw(borderRows + 3, 0, g.scene->status[2].c_str());
}

struct height_compare {
  inline bool operator()(const AGE4Actor* a, const AGE4Actor* b) {
    if (a->getBody().height == b->getBody().height) {
      return (a < b);
    }
    return (a->getBody().height < b->getBody().height);
  }
};

void CursesView::printEntities() const {
  std::vector<AGE4Actor*> actors;
  for (auto& actor : g.scene->getActors()) {
    actors.push_back(actor.get());
  }
  std::sort(actors.begin(), actors.end(), height_compare());
  for (auto& actor : actors) {
    auto posX = lround(actor->getBody().posX);
    auto posY = lround(actor->getBody().posY);
    if (auto bmp = actor->getBody().bitmap) {
      for (auto c : *bmp) {
        auto outX = posX + c.X;
        auto outY = posY + c.Y;
        if (outX >= 0 && outX < borderColumns - 1 && outY >= 0 &&
            outY < borderRows - 1) {
          mvaddch(1 + outY, 1 + outX, c.C);
        }
      }
    }
  }
}

CursesView::~CursesView() {
  endwin();
}
