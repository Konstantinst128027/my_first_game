/* Berezkin Konstantin Evgenievich
./main st128027@student.spbu.ru*/
#ifndef SWAP_MY_CARD_H
#define SWAP_MY_CARD_H
#include "additional_card.h"
class Swap_My_Card: public Additional_Card
{
public:
    Swap_My_Card();
    void Card_Capability() override;
    bool The_Swap_My_Card(std::string& opponent_input, std::vector<std::unique_ptr<Card>>& My_Hand, std::vector<std::unique_ptr<Card>>& Opponent_Hand);
};
#endif
