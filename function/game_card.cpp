/* Berezkin Konstantin Evgenievich
./main st128027@student.spbu.ru*/
#include "game_card.h"
Game_Card::Game_Card(int Damage, int Healing) : Card(), Damage(Damage), Healing(Healing) {}
Game_Card::Game_Card(std::string Name, int Manna, int Damage, int Healing) : Card(Name, Manna), Damage(Damage), Healing(Healing) {}
void Game_Card:: The_Card()
{
    std::cout << Get_Name() << " (damage = " << Get_Damage() << ", healing = " << Get_Healing() << ", manna = " << Get_Manna() << ") ";
}
int Game_Card::Get_Damage()
{
    return Damage;
}
int Game_Card::Get_Healing()
{
    return Healing;
}
//this function deducts as much mana as the card is worth, as much damage as the card is worth and adds as much health as the card has.
void Game_Card::Game_Card_Play(int& Manna, int& Health_1, int& Health_2)
{
    Manna -= Get_Manna();
    Health_1 += Get_Healing();
    Health_2 -= Get_Damage();
    The_Card();
    std::cout << "was used" << std::endl;
}
