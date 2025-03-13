/* Berezkin Konstantin Evgenievich
./main st128027@student.spbu.ru*/
#ifndef GAME_CARD_H
#define GAME_CARD_H
#include "card.h"
class Game_Card: public Card
{
private:
    int Damage;
    int Healing;
public:
    Game_Card(int Damage = 0, int Healing = 0);
    Game_Card(std::string Name, int Manna, int Damage = 0, int Healing = 0);
    void The_Card() override;
    int Get_Damage();
    int Get_Healing();
    void Game_Card_Play(int& Manna, int& Health_1, int& Health_2);
};
#endif
