#include <gtest/gtest.h>
#include <inc/equal.h>

TEST(TestEqual, equal_true)
{
    // arrange
    const int a = 1;
    const int b = 1;

    // act
    const bool res = equal(a, b);

    // assert
    EXPECT_TRUE(res);
}

TEST(TestEqual, equal_false)
{
    // arrange
    const int a = 1;
    const int b = 2;

    // act
    const bool res = equal(a, b);

    // assert
    EXPECT_FALSE(res);
}
