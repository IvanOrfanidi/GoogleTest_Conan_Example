#include <gtest/gtest.h>
#include <list>
#include <stddef.h>
#include <stdio.h>
#include <vector>

#include <inc/less_than_zero.h>

template <class T>
class FXLessThanZero : public ::testing::TestWithParam<T> {
};

TYPED_TEST_CASE_P(FXLessThanZero);
TYPED_TEST_P(FXLessThanZero, LessThanZero)
{
    // arrange
    TypeParam TestItem;

    // act
    const size_t res = less_than_zero(TestItem.data);

    // assert
    EXPECT_EQ(res, TestItem.zeros);
}

REGISTER_TYPED_TEST_CASE_P(FXLessThanZero, LessThanZero);

template <class T>
struct vectorIntTestItem {
    const std::vector<T> data = { 1, 0, -2, 0, 5, -1 };

    const size_t zeros = 2;
};

template <class T>
struct vectorFloatingPointTestItem {
    const std::vector<T> data = { 1.01, 0, -2, -0.5, 5, 0, -1.002 };

    const size_t zeros = 3;
};

template <class T>
struct listIntTestItem {
    const std::list<T> data = { 1, 0, -2, 0, 5, -1 };

    const size_t zeros = 2;
};

template <class T>
struct listFloatingPointTestItem {
    const std::list<T> data = { 1.01, 0, -2, -0.1, 5, 0, -1.002 };

    const size_t zeros = 3;
};

typedef ::testing::Types<
    // Vectors
    vectorIntTestItem<int>,
    vectorFloatingPointTestItem<double>,
    vectorFloatingPointTestItem<float>,
    // Lists
    listIntTestItem<int>,
    listFloatingPointTestItem<double>,
    listFloatingPointTestItem<float>>
    LessThanZeroTypesT;

INSTANTIATE_TYPED_TEST_CASE_P(LessThanZero, FXLessThanZero, LessThanZeroTypesT);