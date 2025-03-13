/* Berezkin Konstantin Evgenievich
./main st128027@student.spbu.ru*/
#include <gtest/gtest.h>
#include "card.h"

TEST(Get_name_Test, card_Test)
{
    Card card;
    EXPECT_EQ(card.Get_Name(), "null");
}
TEST(take_manna_Test, card_Test)
{
    Card card;
    EXPECT_EQ(card.Get_Manna(), 0);
}
