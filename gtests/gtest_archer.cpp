/* Berezkin Konstantin Evgenievich
./main st128027@student.spbu.ru*/
#include <gtest/gtest.h>
#include "archer.h"

TEST(Get_Damage_Test, Archer_Test)
{
    Archer archer;
    EXPECT_EQ(archer.Get_Damage(), 5);
}
TEST(Get_Healing_Test, Archer_Test)
{
    Archer archer;
    EXPECT_EQ(archer.Get_Healing(), 1);
}
TEST(Get_Manna_Test, Archer_Test)
{
    Archer archer;
    EXPECT_EQ(archer.Get_Manna(), 4);
}
TEST(Get_Name_Test, Archer_Test)
{
    Archer archer;
    EXPECT_EQ(archer.Get_Name(), "Archer");
}
TEST(Archer_Play_Test, Archer_Test)
{
    Archer archer;
    int Manna = 10;
    int My_Health = 10;
    int Health_opponent = 10;
    archer.Game_Card_Play(Manna, My_Health, Health_opponent);
    EXPECT_EQ(Manna, 6);
    EXPECT_EQ(My_Health, 11);
    EXPECT_EQ(Health_opponent, 5);
}
