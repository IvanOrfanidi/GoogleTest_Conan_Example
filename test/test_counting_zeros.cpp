#include <gtest/gtest.h>
#include <list>
#include <stddef.h>
#include <stdio.h>
#include <vector>

#include <inc/counting_zeros.h>

template <class T>
class FXCountingZeros : public ::testing::TestWithParam<T> {
};

TYPED_TEST_CASE_P(FXCountingZeros);
TYPED_TEST_P(FXCountingZeros, CountingZeros)
{
    // arrange
    TypeParam TestItem;

    // act
    const size_t res = counting_zeros(TestItem.data);

    // assert
    EXPECT_EQ(res, TestItem.zeros);
}

REGISTER_TYPED_TEST_CASE_P(FXCountingZeros, CountingZeros);

template <class T>
struct vectorIntTestItem {
    const std::vector<T> data = { 1, 0, -2, 0, 5, -1 };

    const size_t zeros = 2;
};

template <class T>
struct vectorFloatingPointTestItem {
    const std::vector<T> data = { 1.01, 0, -2, 0, 5, 0, -1.002 };

    const size_t zeros = 3;
};

template <class T>
struct listIntTestItem {
    const std::list<T> data = { 1, 0, -2, 0, 5, -1 };

    const size_t zeros = 2;
};

template <class T>
struct listFloatingPointTestItem {
    const std::list<T> data = { 1.01, 0, -2, 0, 5, 0, -1.002 };

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
    CountingZerosTypesT;

INSTANTIATE_TYPED_TEST_CASE_P(CountingZeros, FXCountingZeros, CountingZerosTypesT);