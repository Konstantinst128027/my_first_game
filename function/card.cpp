/* Berezkin Konstantin Evgenievich
./main st128027@student.spbu.ru*/
#include "card.h"
Card::Card(std::string name, int manna) : name(name), manna(manna) {}
void Card::The_Card()
{
    std::cout << Get_Name() << " (manna = " << Get_Manna() << ") ";
}

std::string Card::Get_Name()
{
    return name;
}

int Card::Get_Manna()
{
    return manna;
}

Card::~Card() {}
