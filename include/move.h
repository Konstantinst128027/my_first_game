/* Berezkin Konstantin Evgenievich
./main st128027@student.spbu.ru*/
#ifndef MOVE_H
#define MOVE_H
#include "deck.h"
#include <optional>
class Move
{
public:
    Move();
    std::string Making_Move(std::string& Name_1, int& Manna_Player_1, int& Health_1, std::vector <std::unique_ptr<Card>>& Hand_1, std::string& Name_2, int& Health_2, std::vector<std::unique_ptr<Card>>& Hand_2, std::vector<std::unique_ptr<Card>>& Broken_Deck);
    std::optional<bool> Choosing_Card(std::string& input, std::string& situation, std::string& Name_1, int& Manna_1, int& Manna_Player_1, int& Health_1, std::vector <std::unique_ptr<Card>>& Hand_1, std::string& Name_2, int& Health_2,  std::vector<std::unique_ptr<Card>>& Hand_2, std::vector<std::unique_ptr<Card>>& Broken_Deck);
    std::optional<bool> The_Choosing_Move(std::string& input, std::string& Name_1, std::string& Name_2);
    ~Move();
};
#endif
