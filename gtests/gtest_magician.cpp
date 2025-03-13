/* Berezkin Konstantin Evgenievich
./main st128027@student.spbu.ru*/
#include <gtest/gtest.h>
#include "magician.h"

TEST(Get_Damage_Test, Magician_Test)
{
    Magician magician;
    EXPECT_EQ(magician.Get_Damage(), 3);
}
TEST(Get_Healing_Test, Magician_Test)
{
    Magician magician;
    EXPECT_EQ(magician.Get_Healing(), 3);
}
TEST(Get_Manna_Test, Magician_Test)
{
    Magician magician;
    EXPECT_EQ(magician.Get_Manna(), 5);
}
TEST(Get_Name_Test, Magician_Test)
{
    Magician magician;
    EXPECT_EQ(magician.Get_Name(), "Magician");
}
TEST(Magician_Play_Test, Magician_Test)
{
    Magician magician;
    int Manna = 10;
    int My_Health = 10;
    int Health_opponent = 10;
    magician.Game_Card_Play(Manna, My_Health, Health_opponent);
    EXPECT_EQ(Manna, 5);
    EXPECT_EQ(My_Health, 13);
    EXPECT_EQ(Health_opponent, 7);
}
