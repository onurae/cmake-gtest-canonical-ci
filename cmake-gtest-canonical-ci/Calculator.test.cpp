#include <gtest/gtest.h>
#include "Calculator.hpp"

TEST(SquareTest, PositiveInput)
{
    Calculator calc;
    int i{ 9 };
    int r = calc.Square(i);
    EXPECT_EQ(i * i, r);
}

TEST(SquareTest, ZeroInput)
{
    Calculator calc;
    int i{ 0 };
    int r = calc.Square(i);
    EXPECT_EQ(0, r);
}

TEST(SquareTest, NegativeInput)
{
    Calculator calc;
    int i{ -2 };
    int r = calc.Square(i);
    EXPECT_EQ(i * i, r);
}
