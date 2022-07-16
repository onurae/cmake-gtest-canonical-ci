#include <gtest/gtest.h>
#include "Calculator.hpp"

TEST(SquareTest, SquarePositiveInput)
{
    Calculator calc;
    int i{ 9 };
    int r = calc.Square(i);
    EXPECT_EQ(i * i, r);
}

TEST(SquareTest, SquareZeroInput)
{
    Calculator calc;
    int i{ 0 };
    int r = calc.Square(i);
    EXPECT_EQ(0, r);
}

TEST(SquareTest, SquareNegativeInput)
{
    Calculator calc;
    int i{ -2 };
    int r = calc.Square(i);
    EXPECT_EQ(i * i, r);
}