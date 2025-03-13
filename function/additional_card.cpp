/* Berezkin Konstantin Evgenievich
./main st128027@student.spbu.ru*/
#include "additional_card.h"
Additional_Card::Additional_Card() : Card()  {}
Additional_Card::Additional_Card(std::string name, int manna) : Card(name, manna)  {}
void Additional_Card::Card_Capability()
{
    std::cout << "Card " << Get_Name() << " doesn`t do anything" << std::endl;
}

void Additional_Card::The_Card()
{
    std::cout << Get_Name() << " (manna = " << Get_Manna() << ") ";
}
//this function deducts as much mana as the card is worth.
void Additional_Card::Additional_Card_Play(int& Manna)
{
    Manna -= Get_Manna();
}
