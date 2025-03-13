/* Berezkin Konstantin Evgenievich
./main st128027@student.spbu.ru*/
#ifndef MANNA_CARD_H
#define MANNA_CARD_H
#include "additional_card.h"
class Manna_Card : public Additional_Card
{
private:
    int Plus_Manna;
public:
    Manna_Card(int Plus_Manna = 5);
    void Card_Capability() override;
    int Get_Plus_Manna();
    void The_Manna_Card(int& Manna);
};

#endif
