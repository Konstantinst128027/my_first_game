/* Berezkin Konstantin Evgenievich
./main st128027@student.spbu.ru*/
#include <gtest/gtest.h>
#include "player.h"

TEST(Get_Health_Test, Player_Test)
{
    Player player("Konst");
    EXPECT_EQ(player.Get_Health(), 25);
}
TEST(Get_Manna_Test, Player_Test)
{
    Player player("Konst");
    EXPECT_EQ(player.Get_Manna(), 10);
}
TEST(Get_Name_Test, Player_Test)
{
    Player player("Konst");
    EXPECT_EQ(player.Get_Name(), "Konst");
}

