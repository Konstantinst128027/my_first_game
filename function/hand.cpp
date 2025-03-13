/* Berezkin Konstantin Evgenievich
./main st128027@student.spbu.ru*/
#include "hand.h"
Hand::Hand() {}
//This feature fills your hand with 6 cards or adds up to 6
void Hand::Refilling_Hand(std::string& Name, std::vector<std::unique_ptr<Card>>& Hand, std::vector<std::unique_ptr<Card>>& The_Deck, std::vector<std::unique_ptr<Card>>& Broken_Deck)
{
    size_t n = 0;
    while (Hand.size() >= 0 and Hand.size() < 6)
    {
        if (!The_Deck.empty())
        {
            Hand.push_back(std::move(The_Deck[n]));
            The_Deck.erase(The_Deck.begin() + n);
        }
        else
        {
            Deck deck;
            deck.Filling_Empty_Deck(The_Deck, Broken_Deck);
        }
    }
    std::cout << Name << " hand has been filled with up to 6 cards" << std::endl;
}
Hand::~Hand() {}
