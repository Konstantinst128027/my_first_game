/* Berezkin Konstantin Evgenievich
./main st128027@student.spbu.ru*/
#include <gtest/gtest.h>
#include "knight.h"

TEST(Get_Damage_Test, Knight_Test)
{
    Knight knight;
    EXPECT_EQ(knight.Get_Damage(), 7);
}
TEST(Get_Healing_Test, Knight_Test)
{
    Knight knight;
    EXPECT_EQ(knight.Get_Healing(), 0);
}
TEST(Get_Manna_Test, Knight_Test)
{
    Knight knight;
    EXPECT_EQ(knight.Get_Manna(), 5);
}
TEST(Get_Name_Test, Knight_Test)
{
    Knight knight;
    EXPECT_EQ(knight.Get_Name(), "Knight");
}
TEST(Knight_Play_Test, Knight_Test)
{
    Knight knight;
    int Manna = 10;
    int My_Health = 10;
    int Health_opponent = 10;
    knight.Game_Card_Play(Manna, My_Health, Health_opponent);
    EXPECT_EQ(Manna, 5);
    EXPECT_EQ(My_Health, 10);
    EXPECT_EQ(Health_opponent, 3);
}
