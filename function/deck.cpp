/* Berezkin Konstantin Evgenievich
./main st128027@student.spbu.ru*/
#include "deck.h"
Deck::Deck() {}
//This function fills the deck with cards.
void Deck::Filling_Deck(std::vector<std::unique_ptr<Card>>& Deck)
{
    for(int i = 0; i < 2; i++)
    {
        Deck.push_back(std::make_unique<Manna_Card>());
        Deck.push_back(std::make_unique<Swap_My_Card>());
        Deck.push_back(std::make_unique<Card_Broken_Deck>());
    }
    for(int i = 0; i < 6; i++)
    {
        Deck.push_back(std::make_unique<Healing_Spell>());
        Deck.push_back(std::make_unique<Healer>());
        Deck.push_back(std::make_unique<Magician>());
    }
    for(int i = 0; i < 4; i++)
    {
        Deck.push_back(std::make_unique<Attacking_Spell>());
        Deck.push_back(std::make_unique<Thief>());
        Deck.push_back(std::make_unique<Archer>());
        Deck.push_back(std::make_unique<Knight>());
        Deck.push_back(std::make_unique<Berserker>());

    }
    std::cout << "The deck was full" << std::endl;
}
//This function shuffles the deck.
void Deck::Shuffling_Deck(std::vector<std::unique_ptr<Card>>& Deck)
{
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine rng(seed);
    std::shuffle(Deck.begin(), Deck.end(), rng);
    std::cout << "Deck was shuffled" << std::endl;
}
//This function makes the deck complete if it runs out. That is, she shuffles the broken deck and makes it a deck, and in turn makes the broken deck empty.
void Deck::Filling_Empty_Deck(std::vector<std::unique_ptr<Card>>& Deck, std::vector<std::unique_ptr<Card>>& Broken_Deck)
{
    if (Deck.empty())
    {
        for (size_t i = 0; i < Broken_Deck.size(); i++)
        {
            Deck.push_back(std::move(Broken_Deck[i]));
        }
        Broken_Deck.clear();
        Shuffling_Deck(Deck);
        std::cout << "The deck is refilled" << std::endl;
    }
}

Deck::~Deck() {}
