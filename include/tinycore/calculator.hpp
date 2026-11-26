
#pragma once

namespace tinycore {

class Calculator {
public:
  [[nodiscard]] double add(double a, double b) const;
  [[nodiscard]] double subtract(double a, double b) const;
  [[nodiscard]] double multiply(double a, double b) const;
  [[nodiscard]] double divide(double a, double b) const;
};

} // namespace tinycore
