/* Berezkin Konstantin Evgenievich
./main st128027@student.spbu.ru*/
#ifndef ADDITIONAL_CARD_H
#define ADDITIONAL_CARD_H
#include "card.h"

class Additional_Card : public Card
{
public:
    Additional_Card();

    Additional_Card(std::string name, int manna);

    virtual void Card_Capability();

    void The_Card() override;

    void Additional_Card_Play(int& Manna);
};
#endif
