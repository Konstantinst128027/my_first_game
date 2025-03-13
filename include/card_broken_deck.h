/* Berezkin Konstantin Evgenievich
./main st128027@student.spbu.ru*/
#ifndef CARD_BROKEN_DECK_H
#define CARD_BROKEN_DECK_H
#include "additional_card.h"
class Card_Broken_Deck: public Additional_Card
{
public:
    Card_Broken_Deck();
    void Card_Capability() override;
    bool The_Card_Broken_Deck(std::string& input, std::vector <std::unique_ptr<Card>>& Hand, std::vector <std::unique_ptr<Card>>& Broken_Deck);
};
#endif
