#ifndef AGE3_STATUS_H
#define AGE3_STATUS_H

#include <array>
#include <string>

class Status {
  std::array<std::string, 3> theStatus;

 public:
  Status() = default;
  std::string& operator[](size_t index);
  [[nodiscard]] const std::array<std::string, 3>& getStatus() const;
  void setStatus(std::string str);
  void setStatus(const std::string& str, size_t line);
};

#endif  // AGE3_STATUS_H
