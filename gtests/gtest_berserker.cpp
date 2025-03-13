/* Berezkin Konstantin Evgenievich
./main st128027@student.spbu.ru*/
#include <gtest/gtest.h>
#include "berserker.h"

TEST(Get_Damage_Test, Berserker_Test)
{
    Berserker berserker;
    EXPECT_EQ(berserker.Get_Damage(), 6);
}
TEST(Get_Healing_Test, Berserker_Test)
{
    Berserker berserker;
    EXPECT_EQ(berserker.Get_Healing(), 0);
}
TEST(Get_Manna_Test, Berserker_Test)
{
    Berserker berserker;
    EXPECT_EQ(berserker.Get_Manna(), 3);
}
TEST(Get_Name_Test, Berserker_Test)
{
    Berserker berserker;
    EXPECT_EQ(berserker.Get_Name(), "Berserker");
}
TEST(Berserker_Play_Test, Berserker_Test)
{
    Berserker berserker;
    int Manna = 10;
    int My_Health = 10;
    int Health_opponent = 10;
    berserker.Game_Card_Play(Manna, My_Health, Health_opponent);
    EXPECT_EQ(Manna, 7);
    EXPECT_EQ(My_Health, 10);
    EXPECT_EQ(Health_opponent, 4);
}
