/* Berezkin Konstantin Evgenievich
./main st128027@student.spbu.ru*/
#include "move.h"
Move::Move() {}
//this function processes Input and returns true if this card can be used or false if it cannot be used. In this function, I am using two mana Manna_1 and Manna_Player_1 only because I will not be able to increase the total mana (which is used in each turn)
std::optional<bool> Move::Choosing_Card(std::string& input, std::string& situation, std::string& Name_1, int& Manna_1, int& Manna_Player_1, int& Health_1, std::vector <std::unique_ptr<Card>>& Hand_1, std::string& Name_2, int& Health_2,  std::vector<std::unique_ptr<Card>>& Hand_2, std::vector<std::unique_ptr<Card>>& Broken_Deck)
{

    bool is_valid = true;

    for (char ch : input)
    {
        if (!std::isdigit(ch))
        {
            is_valid = false;
        }
    }

    if (!is_valid)
    {
        std::cout << "Invalid input! Please enter a number." << std::endl;
        return is_valid;
    }

    int Number_Of_Card = std::stoi(input);

    if (Number_Of_Card < 0 or Number_Of_Card > static_cast<int>(Hand_1.size()))
    {
        std::cout << "Invalid index! Please enter a number between 1 and " << Hand_1.size() << "." << std::endl;
        is_valid = false;
        return is_valid;
    }

    if (Number_Of_Card == 0)
    {
        std::cout << Name_1 << " health: " << Health_1 << ", ";
        std::cout << Name_2 << " health: " << Health_2 << std::endl;
        return std::nullopt;
    }
    else
    {
        size_t corrected_index = static_cast<size_t>(Number_Of_Card - 1);
        if ((Manna_1 - Hand_1[corrected_index]->Get_Manna()) >= 0)
        {
            if (Hand_1[corrected_index]->Get_Name() == "Card_Broken_Deck")
            {
                auto* BrokenDeckCard = dynamic_cast<Card_Broken_Deck*>(Hand_1[corrected_index].get());

                if (Broken_Deck.empty())
                {
                    std::cout << "This card cannot be used" << std::endl;
                    is_valid = false;
                    return is_valid;
                }
                else
                {
                    BrokenDeckCard->Card_Capability();

                    BrokenDeckCard->Additional_Card_Play(Manna_1);

                    bool Can_To_Use = false;

                    std::cout << "Select the number of card from list you want to take:" << std::endl;

                    for (size_t i = 0; i < Broken_Deck.size(); i++)
                    {
                        std::cout << (i+1) << ": " << Broken_Deck[i]->Get_Name();
                        if ((i+1) < Broken_Deck.size())
                        {
                            std::cout << ", ";
                        }
                    }

                    std::cout << std::endl;

                    while (!Can_To_Use)
                    {
                        std::cout << "Enter the number: ";
                        std::string input;
                        std::cin >> input;
                        Can_To_Use = BrokenDeckCard->The_Card_Broken_Deck(input, Hand_1, Broken_Deck);

                    }

                    Broken_Deck.push_back(std::move(Hand_1[corrected_index]));

                    Hand_1.erase(Hand_1.begin() + corrected_index);

                    return is_valid;
                }
            }

            else if (Hand_1[corrected_index]->Get_Name() == "Manna_Card")
            {

                auto* MannaCard = dynamic_cast<Manna_Card*>(Hand_1[corrected_index].get());

                MannaCard->Card_Capability();

                MannaCard->Additional_Card_Play(Manna_1);

                MannaCard->The_Manna_Card(Manna_1);

                Manna_Player_1 += MannaCard->Get_Plus_Manna();

                Broken_Deck.push_back(std::move(Hand_1[corrected_index]));

                Hand_1.erase(Hand_1.begin() + corrected_index);

                return is_valid;
            }

            else if (Hand_1[corrected_index]->Get_Name() == "Swap_My_Card")
            {

                auto* SwapMyCard = dynamic_cast<Swap_My_Card*>(Hand_1[corrected_index].get());

                SwapMyCard->Card_Capability();

                SwapMyCard->Additional_Card_Play(Manna_1);

                bool Can_To_Use = false;

                std::cout << "Select the number of card from list you want to take:" << std::endl;

                for (size_t i = 0; i < Hand_2.size(); i++)
                {
                    std::cout << (i+1) << ": " << Hand_2[i]->Get_Name();
                    if ((i+1) < Hand_2.size())
                    {
                        std::cout << ", ";
                    }
                }

                std::cout << std::endl;

                while (!Can_To_Use)
                {
                    std::cout << "Enter the number: ";
                    std::string input;
                    std::cin >> input;
                    Can_To_Use = SwapMyCard->The_Swap_My_Card(input, Hand_1, Hand_2);

                }

                Broken_Deck.push_back(std::move(Hand_1[corrected_index]));

                Hand_1.erase(Hand_1.begin() + corrected_index);

                return is_valid;

            }

            else
            {

                auto* GameCard = dynamic_cast<Game_Card*>(Hand_1[corrected_index].get());
                if ((Health_2 - GameCard->Get_Damage()) > 0)
                {

                    GameCard->Game_Card_Play(Manna_1, Health_1, Health_2);

                    Broken_Deck.push_back(std::move(Hand_1[corrected_index]));

                    Hand_1.erase(Hand_1.begin() + corrected_index);

                    return is_valid;
                }
                else
                {
                    GameCard->Game_Card_Play(Manna_1, Health_1, Health_2);

                    Broken_Deck.push_back(std::move(Hand_1[corrected_index]));

                    Hand_1.erase(Hand_1.begin() + corrected_index);

                    situation = "Player " + Name_1 + " win!";

                    return is_valid;
                }
            }
        }
        else
        {
            std::cout << "You don't have enough manna" << std::endl;
            is_valid = false;
            return is_valid;
        }
    }
}
//This function reproduces the player's turn.
std::string Move::Making_Move(std::string& Name_1, int& Manna_Player_1, int& Health_1, std::vector <std::unique_ptr<Card>>& Hand_1, std::string& Name_2, int& Health_2,  std::vector<std::unique_ptr<Card>>& Hand_2, std::vector<std::unique_ptr<Card>>& Broken_Deck)
{
    int Manna_1 = Manna_Player_1;

    std::cout << "The " << Name_1 << " player is walking" << std::endl;

    std::string situation = "all_right";

    while (Manna_1 >= 0 and !Hand_1.empty() and Health_2 > 0)
    {
        std::cout << Name_1 << " health: " << Health_1 << ", ";
        std::cout << Name_1 << " Manna: " << Manna_1 << ", ";
        std::cout << Name_2 << " health: " << Health_2 << "." << std::endl;
        std::cout << "Your Hand: " << std::endl;

        for (size_t i = 0; i < Hand_1.size(); i++)
        {
            std::cout << (i + 1) << ": " << Hand_1[i]->Get_Name();
            if ((i + 1) < Hand_1.size())
            {
                std::cout << ", ";
            }
        }
        std::cout << std::endl;

        bool Can_To_Move = false;
        while (!Can_To_Move)
        {
            std::cout << "select the number of the card you want to use (to complete the turn, enter 0): ";
            std::string input;
            std::cin >> input;

            auto result = Choosing_Card(input, situation, Name_1, Manna_1, Manna_Player_1, Health_1, Hand_1, Name_2, Health_2, Hand_2, Broken_Deck);

            if (result.has_value())
            {
                Can_To_Move = result.value();
            }
            else
            {
                std::cout << Name_1 << " turn is complete!" << std::endl;
                return situation;
            }
        }
    }
    std::cout << Name_1 << " health: " << Health_1 << ", ";
    std::cout << Name_1 << " Manna: " << Manna_1 << ", ";
    std::cout << Name_2 << " health: " << Health_2 << "." << std::endl;
    std::cout << Name_1 << " turn is complete!" << std::endl;
    return situation;
}
//this function returns true if you chose to go first, returns false if you chose your opponent to go first, and returns std::nullopt if the input is incorrect.
std::optional<bool> Move::The_Choosing_Move(std::string& input, std::string& Name_1, std::string& Name_2)
{

    bool Who_Is_Walking = true;

    for (char ch : input)
    {
        if (!std::isdigit(ch))
        {
            Who_Is_Walking = false;
        }
    }

    if (!Who_Is_Walking)
    {
        std::cout << "Invalid input! Please enter a number." << std::endl;
        return std::nullopt;
    }

    int choosing_a_move = std::stoi(input);

    if (choosing_a_move <= 0 or choosing_a_move > 3)
    {
        std::cout << "Invalid index! Please enter a number between 1 and 3." << std::endl;
        return std::nullopt;
    }
    if (choosing_a_move == 1)
    {
        std::cout << "the player goes first " << Name_1 << std::endl;
        return Who_Is_Walking;

    }
    else if (choosing_a_move == 2)
    {
        Who_Is_Walking = false;
        std::cout << "the player goes first " << Name_2 << std::endl;
        return Who_Is_Walking;
    }
    else if (choosing_a_move == 3)
    {
        std::srand(std::time(0));
        int random_number = std::rand() % 2 + 1;
        if (random_number == 1)
        {
            std::cout << "the player goes first " << Name_1 << std::endl;
            return Who_Is_Walking;
        }
        else if (random_number == 2)
        {
            Who_Is_Walking = false;
            std::cout << "the player goes first " << Name_2 << std::endl;
            return Who_Is_Walking;
        }
    }
    return std::nullopt;
}

Move::~Move() {}
