/* Berezkin Konstantin Evgenievich
./main st128027@student.spbu.ru*/
#include <gtest/gtest.h>
#include "healer.h"

TEST(Get_Damage_Test, Healer_Test)
{
    Healer healer;
    EXPECT_EQ(healer.Get_Damage(), 1);
}
TEST(Get_Healing_Test, Healer_Test)
{
    Healer healer;
    EXPECT_EQ(healer.Get_Healing(), 5);
}
TEST(Get_Manna_Test, Healer_Test)
{
    Healer healer;
    EXPECT_EQ(healer.Get_Manna(), 4);
}
TEST(Get_Name_Test, Healer_Test)
{
    Healer healer;
    EXPECT_EQ(healer.Get_Name(), "Healer");
}
TEST(Healer_Play_Test, Healer_Test)
{
    Healer healer;
    int Manna = 10;
    int My_Health = 10;
    int Health_opponent = 10;
    healer.Game_Card_Play(Manna, My_Health, Health_opponent);
    EXPECT_EQ(Manna, 6);
    EXPECT_EQ(My_Health, 15);
    EXPECT_EQ(Health_opponent, 9);
}
