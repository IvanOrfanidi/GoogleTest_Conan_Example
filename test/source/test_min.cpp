#include <gtest/gtest.h>
#include <include/min.h>

template <class T>
class FXTestMin : public ::testing::TestWithParam<T> {
};

TYPED_TEST_CASE_P(FXTestMin);
TYPED_TEST_P(FXTestMin, MIN)
{
    // arrange
    TypeParam TestItem;

    // act
    const auto res = min(TestItem.a, TestItem.b);

    // assert
    EXPECT_EQ(res, TestItem.min);
}

REGISTER_TYPED_TEST_CASE_P(FXTestMin, MIN);

template <class T>
struct U8TestItem {
    const T a = 1;
    const T b = 254;

    const T min = 1;
};

template <class T>
struct U16TestItem {
    const T a = 10000;
    const T b = 1;

    const T min = 1;
};

typedef ::testing::Types<
    U8TestItem<uint8_t>,
    U16TestItem<uint16_t>>
    MinTypesT;

INSTANTIATE_TYPED_TEST_CASE_P(MIN, FXTestMin, MinTypesT);