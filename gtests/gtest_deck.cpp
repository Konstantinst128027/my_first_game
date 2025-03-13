/* Berezkin Konstantin Evgenievich
./main st128027@student.spbu.ru*/
#include <gtest/gtest.h>
#include "deck.h"
TEST(Filling_Deck, Deck_Test)
{

    Deck deck;

    std::vector <std::unique_ptr <Card>> The_Deck;
    deck.Filling_Deck(The_Deck);
    EXPECT_EQ(The_Deck.size(), 44);
}

TEST(Filling_Empty_Deck, Deck_Test)
{

    Deck deck;

    std::vector <std::unique_ptr <Card>> The_Deck;
    std::vector <std::unique_ptr <Card>> Broken_Deck;
    deck.Filling_Deck(Broken_Deck);
    EXPECT_EQ(Broken_Deck.size(), 44);
    EXPECT_EQ(The_Deck.size(), 0);
    deck.Filling_Empty_Deck(The_Deck, Broken_Deck);
    EXPECT_EQ(Broken_Deck.size(), 0);
    EXPECT_EQ(The_Deck.size(), 44);
}

