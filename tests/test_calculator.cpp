
#include "tinycore/calculator.hpp"

#include <gtest/gtest.h>

#include <stdexcept>

namespace {

const tinycore::Calculator calculator;

TEST(CalculatorTests, Add) { EXPECT_DOUBLE_EQ(calculator.add(2.0, 3.0), 5.0); }

TEST(CalculatorTests, Subtract) {
  EXPECT_DOUBLE_EQ(calculator.subtract(5.0, 3.0), 2.0);
}

TEST(CalculatorTests, Multiply) {
  EXPECT_DOUBLE_EQ(calculator.multiply(4.0, 3.0), 12.0);
}

TEST(CalculatorTests, Divide) {
  EXPECT_DOUBLE_EQ(calculator.divide(10.0, 2.0), 5.0);
}

TEST(CalculatorTests, DivideByZero) {
  EXPECT_THROW(calculator.divide(10.0, 0.0), std::invalid_argument);
}

} // namespace
