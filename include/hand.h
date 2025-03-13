/* Berezkin Konstantin Evgenievich
./main st128027@student.spbu.ru*/
#ifndef HAND_H
#define HAND_H
#include "deck.h"
class Hand
{
public:
    Hand();
    void Refilling_Hand(std::string& Name, std::vector<std::unique_ptr<Card>>& Hand, std::vector<std::unique_ptr<Card>>& Deck, std::vector<std::unique_ptr<Card>>& Broken_Deck);
    virtual ~Hand();
};
#endif
