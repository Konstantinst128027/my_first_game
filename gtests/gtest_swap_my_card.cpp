/* Berezkin Konstantin Evgenievich
./main st128027@student.spbu.ru*/
#include <gtest/gtest.h>
#include "swap_my_card.h"
#include "knight.h"
TEST(The_Swap_My_Card, Swap_My_Card_Test_1)
{

    Swap_My_Card swap_my_card;

    std::vector <std::unique_ptr <Card>> Opponent_Hard;
    Opponent_Hard.push_back(std::make_unique<Knight>());

    std::vector <std::unique_ptr <Card>> My_Hand;
    std::string input = "1";
    EXPECT_EQ(swap_my_card.The_Swap_My_Card(input, My_Hand, Opponent_Hard), true);
    EXPECT_EQ(My_Hand[0]->Get_Name(), "Knight");
    EXPECT_EQ(My_Hand.size(), 1);
    EXPECT_EQ(Opponent_Hard.size(), 0);
}

TEST(The_Swap_My_Card, Swap_My_Card_Test_2)
{

    Swap_My_Card swap_my_card;

    std::vector <std::unique_ptr <Card>> Opponent_Hard;
    Opponent_Hard.push_back(std::make_unique<Knight>());

    std::vector <std::unique_ptr <Card>> My_Hand;
    std::string input = "vector";
    EXPECT_EQ(swap_my_card.The_Swap_My_Card(input, My_Hand, Opponent_Hard), false);
}

TEST(The_Swap_My_Card, Swap_My_Card_Test_3)
{

    Swap_My_Card swap_my_card;

    std::vector <std::unique_ptr <Card>> Opponent_Hard;
    Opponent_Hard.push_back(std::make_unique<Knight>());

    std::vector <std::unique_ptr <Card>> My_Hand;
    std::string input = "12";
    EXPECT_EQ(swap_my_card.The_Swap_My_Card(input, My_Hand, Opponent_Hard), false);
}
TEST(Get_Manna_Test, Swap_My_Card_Test)
{
    Swap_My_Card swap_my_card;
    EXPECT_EQ(swap_my_card.Get_Manna(), 4);
}

TEST(Get_Name_Test, Swap_My_Card_Test)
{
    Swap_My_Card swap_my_card;
    EXPECT_EQ(swap_my_card.Get_Name(), "Swap_My_Card");
}
