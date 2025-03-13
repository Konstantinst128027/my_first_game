/* Berezkin Konstantin Evgenievich
./main st128027@student.spbu.ru*/
#include "swap_my_card.h"
Swap_My_Card::Swap_My_Card() : Additional_Card("Swap_My_Card", 4) {}

void Swap_My_Card::Card_Capability()
{
    std::cout << "Card " << Get_Name() << " gives you the opportunity to swap this cards for any one of your opponent's cards (Manna = " << Get_Manna() << ")" << std::endl;
}
//this function reproduces the Swap_My_Card action for the player. If you entered an incorrect value, it returns false, but if the input is correct, it returns true
bool Swap_My_Card::The_Swap_My_Card(std::string& opponent_input, std::vector<std::unique_ptr<Card>>& My_Hand, std::vector<std::unique_ptr<Card>>& Opponent_Hand)
{
    int index_of_opponent_card;
    bool valid_opponent_input = true;

    for (char ch : opponent_input)
    {
        if (!std::isdigit(ch))
        {
            valid_opponent_input = false;
        }
    }

    if (!valid_opponent_input)
    {
        std::cout << "Invalid input! Please enter a number." << std::endl;
        return valid_opponent_input;
    }

    index_of_opponent_card = std::stoi(opponent_input);

    if (index_of_opponent_card <= 0 or index_of_opponent_card > static_cast<int>(Opponent_Hand.size()))
    {
        std::cout << "Invalid index! Please enter a number between 1 and " << Opponent_Hand.size() << "." << std::endl;
        valid_opponent_input = false;
        return valid_opponent_input;
    }

    size_t corrected_opponent_index = static_cast<size_t>(index_of_opponent_card - 1);

    My_Hand.push_back(std::move(Opponent_Hand[corrected_opponent_index]));

    Opponent_Hand.erase(Opponent_Hand.begin() + corrected_opponent_index);

    std::cout << "Card was used" << std::endl;

    return valid_opponent_input;
}
