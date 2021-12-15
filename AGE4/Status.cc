#include "Status.h"

void Status::setStatus(std::string str) {
    for (auto & line : theStatus) {
      line = str.substr(0, 80);
      str = str.substr(std::min(static_cast<size_t>(80), str.length()));
    }
}

void Status::setStatus(const std::string& str, size_t line) {
  theStatus[line] = str.substr(0, 80);
}
const std::array<std::string, 3>& Status::getStatus() const {
  return theStatus;
}

std::string &Status::operator[](size_t index) { return theStatus[index]; }
