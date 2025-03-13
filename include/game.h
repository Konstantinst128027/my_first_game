/* Berezkin Konstantin Evgenievich
./main st128027@student.spbu.ru*/
#ifndef GAME_H
#define GAME_H
#include "deck.h"
#include "II.h"
#include "player.h"
#include "move.h"
#include "hand.h"

class Game
{
public:
    Game();
    std::optional<bool> Choosing_Mode(std::string& input);
    void Gaming();
    void Game_Vs_II();
    void Game_Vs_Player();
    std::optional<bool> The_Play_Or_Not_Play(std::string& input);
    void All_Game();
    virtual ~Game();
};
#endif
