/* Berezkin Konstantin Evgenievich
./main st128027@student.spbu.ru*/
#include <gtest/gtest.h>
#include "thief.h"

TEST(Get_Damage_Test, Thief_Test)
{
    Thief thief;
    EXPECT_EQ(thief.Get_Damage(), 4);
}
TEST(Get_Healing_Test, MThief_Test)
{
    Thief thief;
    EXPECT_EQ(thief.Get_Healing(), 2);
}
TEST(Get_Manna_Test, Thief_Test)
{
    Thief thief;
    EXPECT_EQ(thief.Get_Manna(), 3);
}
TEST(Get_Name_Test, Thief_Test)
{
    Thief thief;
    EXPECT_EQ(thief.Get_Name(), "Thief");
}
TEST(Thief_Play_Test, Thief_Test)
{
    Thief thief;
    int Manna = 10;
    int My_Health = 10;
    int Health_opponent = 10;
    thief.Game_Card_Play(Manna, My_Health, Health_opponent);
    EXPECT_EQ(Manna, 7);
    EXPECT_EQ(My_Health, 12);
    EXPECT_EQ(Health_opponent, 6);
}
