/* Berezkin Konstantin Evgenievich
./main st128027@student.spbu.ru*/
#include "player.h"

Player::Player(std::string Name, int Manna, int Health) : Name(Name), Manna(Manna), Health(Health) {}

int Player::Get_Manna()
{
    return Manna;
}

int Player::Get_Health()
{
    return Health;
}

std::string Player::Get_Name()
{
    return Name;
}

Player::~Player() {}

