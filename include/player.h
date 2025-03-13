/* Berezkin Konstantin Evgenievich
./main st128027@student.spbu.ru*/
#ifndef PLAYER_H
#define PLAYER_H
#include "card.h"
class Player
{
private:
    std::string Name;
    int Manna;
    int Health;
public:
    Player(std::string Name, int Manna = 10, int Health = 25);
    int Get_Manna();
    int Get_Health();
    std::string Get_Name();
    virtual ~Player();
};
#endif
