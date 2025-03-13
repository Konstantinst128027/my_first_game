/* Berezkin Konstantin Evgenievich
./main st128027@student.spbu.ru*/
#include <gtest/gtest.h>
#include "hand.h"
TEST(Refilling_Hand, Hand_Test_1)
{

    Deck deck;

    std::vector <std::unique_ptr <Card>> The_Deck;
    deck.Filling_Deck(The_Deck);
    EXPECT_EQ(The_Deck.size(), 44);

    Hand hand;
    std::vector <std::unique_ptr <Card>> My_Hand;
    EXPECT_EQ(My_Hand.size(), 0);

    std::vector <std::unique_ptr <Card>> Broken_Deck;

    std::string Name = "Konst";
    hand.Refilling_Hand(Name, My_Hand, The_Deck, Broken_Deck);
    EXPECT_EQ(The_Deck.size(), 38);
    EXPECT_EQ(My_Hand.size(), 6);
}

TEST(Refilling_Hand, Hand_Test_2)
{

    Deck deck;

    std::vector <std::unique_ptr <Card>> The_Deck;
    deck.Filling_Deck(The_Deck);
    EXPECT_EQ(The_Deck.size(), 44);

    Hand hand;
    std::vector <std::unique_ptr <Card>> My_Hand;
    for (int i = 0; i < 3; i++)
    {
        My_Hand.push_back(std::make_unique<Manna_Card>());
    }
    EXPECT_EQ(My_Hand.size(), 3);
    std::vector <std::unique_ptr <Card>> Broken_Deck;

    std::string Name = "Konst";
    hand.Refilling_Hand(Name, My_Hand, The_Deck, Broken_Deck);
    EXPECT_EQ(The_Deck.size(), 41);
    EXPECT_EQ(My_Hand.size(), 6);
}

TEST(Refilling_Hand, Hand_Test_3)
{

    Deck deck;

    std::vector <std::unique_ptr <Card>> The_Deck;
    EXPECT_EQ(The_Deck.size(), 0);

    Hand hand;
    std::vector <std::unique_ptr <Card>> My_Hand;
    for (int i = 0; i < 3; i++)
    {
        My_Hand.push_back(std::make_unique<Manna_Card>());
    }
    EXPECT_EQ(My_Hand.size(), 3);

    std::vector <std::unique_ptr <Card>> Broken_Deck;
    deck.Filling_Deck(Broken_Deck);
    EXPECT_EQ(Broken_Deck.size(), 44);

    std::string Name = "Konst";
    hand.Refilling_Hand(Name, My_Hand, The_Deck, Broken_Deck);
    EXPECT_EQ(The_Deck.size(), 41);
    EXPECT_EQ(Broken_Deck.size(), 0);
    EXPECT_EQ(My_Hand.size(), 6);
}
