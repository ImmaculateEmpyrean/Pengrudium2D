#include "stdafx.h"

#include "gtest/gtest.h"

char squigly(char a)
{
    return a;
}

TEST(charFunctions, squiglyTestPositive)
{
    EXPECT_EQ('a', squigly('a'));
    EXPECT_EQ('b', squigly('b'));
    EXPECT_EQ('c', squigly('c'));
}

TEST(computationFunctions, squiglyTestZero)
{
    EXPECT_EQ('d', squigly('d'));
}

TEST(charFunctions, squiglyTestNegative)
{
    /*EXPECT_EQ(4, squigly(-2));
    EXPECT_EQ(9, squigly(-3));
    EXPECT_EQ(16,squigly(-4));

    EXPECT_EQ(160, squigly(-4)) << "hoho";*/
}




int square(int n)
{
    return n * n;
}

TEST(computationFunctions, squareTestPositive)
{
    EXPECT_EQ(4, square(2));
    EXPECT_EQ(9, square(3));
    EXPECT_EQ(16, square(4));
}

TEST(computationFunctions, squareTestZero)
{
    EXPECT_EQ(0, square(0));
}

TEST(computationFunctions, squareTestNegative)
{
    EXPECT_EQ(4, square(-2));
    EXPECT_EQ(9, square(-3));
    EXPECT_EQ(16, square(-4));

    EXPECT_EQ(160, square(-4)) << "hoho";
}