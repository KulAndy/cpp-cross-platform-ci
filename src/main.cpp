
#include "tinycore/calculator.hpp"

#include <exception>
#include <iostream>

int main() {
  const tinycore::Calculator calculator;

  try {
    std::cout << "TinyCore Calculator\n";
    std::cout << "-------------------\n";

    std::cout << "10 + 5 = " << calculator.add(10, 5) << '\n';

    std::cout << "10 - 5 = " << calculator.subtract(10, 5) << '\n';

    std::cout << "10 * 5 = " << calculator.multiply(10, 5) << '\n';

    std::cout << "10 / 5 = " << calculator.divide(10, 5) << '\n';

  } catch (const std::exception &error) {
    std::cerr << "Error: " << error.what() << '\n';
    return 1;
  }

  return 0;
}
