/* Berezkin Konstantin Evgenievich
./main st128027@student.spbu.ru*/
#include "card_broken_deck.h"
Card_Broken_Deck::Card_Broken_Deck() : Additional_Card("Card_Broken_Deck", 4) {}

void Card_Broken_Deck::Card_Capability()
{
    std::cout << "Card " << Get_Name() << " allows you to draw one card from a broken deck (Manna = "<< Get_Manna() << ")" << std::endl;
}
//this function accepts a text value, a hand vector, and a Broken_Deck vector as input, and it returns false if the input is incorrect and true if it was used.
bool Card_Broken_Deck::The_Card_Broken_Deck(std::string& input, std::vector <std::unique_ptr<Card>>& Hand, std::vector <std::unique_ptr<Card>>& Broken_Deck)
{

    int index_of_card;

    bool valid_input = true;
    for (char ch : input)
    {
        if (!std::isdigit(ch))
        {
            valid_input = false;

        }
    }

    if (!valid_input)
    {
        std::cout << "Invalid input! Please enter a number." << std::endl;
        return valid_input;
    }

    index_of_card = std::stoi(input);

    if (index_of_card <= 0 or index_of_card > static_cast<int>(Broken_Deck.size()))
    {
        std::cout << "Invalid index! Please enter a number between 1 and " << Broken_Deck.size() << "." << std::endl;
        valid_input = false;
        return valid_input;
    }

    size_t corrected_index = static_cast<size_t>(index_of_card - 1);

    Hand.push_back(std::move(Broken_Deck[corrected_index]));

    Broken_Deck.erase(Broken_Deck.begin() + corrected_index);

    std::cout << "Card was used!" << std::endl;

    return valid_input;
}

