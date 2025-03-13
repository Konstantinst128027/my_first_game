/* Berezkin Konstantin Evgenievich
./main st128027@student.spbu.ru*/
#include <gtest/gtest.h>
#include "game_card.h"

TEST(Get_Damage_Test, Game_Card_Test)
{
    Game_Card game_card;
    EXPECT_EQ(game_card.Get_Damage(), 0);
}
TEST(Get_Healing_Test, Game_Card_Test)
{
    Game_Card game_card;
    EXPECT_EQ(game_card.Get_Healing(), 0);
}
TEST(Get_Name_Test, Game_Card_Test)
{
    Game_Card game_card;
    EXPECT_EQ(game_card.Get_Name(), "null");
}
TEST(Game_Card_Play_Test, Game_Card_Test)
{
    Game_Card game_card;
    int Manna = 10;
    int My_Health = 10;
    int Health_opponent = 10;
    game_card.Game_Card_Play(Manna, My_Health, Health_opponent);
    EXPECT_EQ(Manna, 10);
    EXPECT_EQ(My_Health, 10);
    EXPECT_EQ(Health_opponent, 10);
}
