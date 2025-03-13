/* Berezkin Konstantin Evgenievich
./main st128027@student.spbu.ru*/
#include "manna_card.h"
Manna_Card::Manna_Card(int Plus_Manna) : Additional_Card("Manna_Card", 0), Plus_Manna(Plus_Manna) {}

void Manna_Card::Card_Capability()
{
    std::cout << "Card " << Get_Name() << " adds 5 manna to your manna supply (Manna = " << Get_Manna() << ")" << std::endl;
}

int Manna_Card::Get_Plus_Manna()
{
    return Plus_Manna;
}
//his function adds 5 mana
void Manna_Card::The_Manna_Card(int& Manna)
{
    Manna += Get_Plus_Manna();
    The_Card();
    std::cout << "was used" << std::endl;
}

