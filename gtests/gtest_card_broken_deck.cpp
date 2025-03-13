/* Berezkin Konstantin Evgenievich
./main st128027@student.spbu.ru*/
#include <gtest/gtest.h>
#include "card_broken_deck.h"
#include "healer.h"
TEST(The_Card_Broken_Deck, Card_Broken_Deck_Test_1)
{

    Card_Broken_Deck card_broken_deck;

    std::vector <std::unique_ptr <Card>> Broken_Deck;
    Broken_Deck.push_back(std::make_unique<Healer>());

    std::vector <std::unique_ptr <Card>> Hand;
    std::string input = "1";
    EXPECT_EQ(card_broken_deck.The_Card_Broken_Deck(input, Hand, Broken_Deck), true);
    EXPECT_EQ(Hand[0]->Get_Name(), "Healer");
    EXPECT_EQ(Hand.size(), 1);
    EXPECT_EQ(Broken_Deck.size(), 0);
}

TEST(The_Card_Broken_Deck, Card_Broken_Deck_Test_2)
{

    Card_Broken_Deck card_broken_deck;

    std::vector <std::unique_ptr <Card>> Broken_Deck;
    Broken_Deck.push_back(std::make_unique<Healer>());

    std::vector <std::unique_ptr <Card>> Hand;
    std::string input = "vector";
    EXPECT_EQ(card_broken_deck.The_Card_Broken_Deck(input, Hand, Broken_Deck), false);
}

TEST(The_Card_Broken_Deck, Card_Broken_Deck_Test_3)
{

    Card_Broken_Deck card_broken_deck;

    std::vector <std::unique_ptr <Card>> Broken_Deck;
    Broken_Deck.push_back(std::make_unique<Healer>());

    std::vector <std::unique_ptr <Card>> Hand;
    std::string input = "12";
    EXPECT_EQ(card_broken_deck.The_Card_Broken_Deck(input, Hand, Broken_Deck), false);
}
TEST(Get_Manna_Test, Card_Broken_Deck_Test)
{
    Card_Broken_Deck card_broken_deck;
    EXPECT_EQ(card_broken_deck.Get_Manna(), 4);
}
TEST(Get_Name_Test, Card_Broken_Deck_Test)
{
    Card_Broken_Deck card_broken_deck;
    EXPECT_EQ(card_broken_deck.Get_Name(), "Card_Broken_Deck");
}

