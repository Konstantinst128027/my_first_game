/* Berezkin Konstantin Evgenievich
./assignment4 st128027@student.spbu.ru*/
#include <gtest/gtest.h>
#include "example_function.h"

TEST(AddTest, HandlesPositiveNumbers) {
    EXPECT_EQ(add(2, 3), 5);
}

TEST(AddTest, HandlesNegativeNumbers) {
    EXPECT_EQ(add(-1, -1), -2);
}

int main() {
    ::testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}
