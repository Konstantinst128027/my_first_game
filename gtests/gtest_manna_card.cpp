/* Berezkin Konstantin Evgenievich
./main st128027@student.spbu.ru*/
#include <gtest/gtest.h>
#include "manna_card.h"

TEST(Get_Plus_Manna_Test, Manna_Card_Test)
{
    Manna_Card manna_card;
    EXPECT_EQ(manna_card.Get_Plus_Manna(), 5);
}
TEST(Get_Name_Test, Manna_Card_Test)
{
    Manna_Card manna_card;
    EXPECT_EQ(manna_card.Get_Name(), "Manna_Card");
}
TEST(Manna_Card_Play_Test, Manna_Card_Test)
{
    Manna_Card manna_card;
    int Manna = 10;
    manna_card.The_Manna_Card(Manna);
    EXPECT_EQ(Manna, 15);
}
