/* Berezkin Konstantin Evgenievich
./main st128027@student.spbu.ru*/
#include "game.h"

Game::Game() {}
//this function returns true if the play against player mode is selected, returns false if the play against II mode is selected, and returns an empty value if the input is incorrect.
std::optional<bool> Game::Choosing_Mode(std::string& input)
{
    int mode;

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
        return std::nullopt;
    }

    mode = std::stoi(input);

    if (mode <= 0 or mode > 2)
    {
        std::cout << "Invalid index! Please enter a number between 1 and 2." << std::endl;
        return std::nullopt;
    }
    if (mode == 1)
    {
        return valid_input;
    }
    else if (mode == 2)
    {
        valid_input = false;
        return valid_input;
    }
    return std::nullopt;
}
//This is a function that produces a single game with everything combined
void Game::Gaming()
{

    std::cout << "Select the mode: 1. Playing against the player. 2. Playing against the II." << std::endl;
    std::optional<bool> mode;
    while (!mode.has_value())
    {
        std::cout << "Enter the number: ";
        std::string input;
        std::cin >> input;
        mode = Choosing_Mode(input);
    }

    if (mode == true)
    {
        Game_Vs_Player();
    }
    else
    {
        Game_Vs_II();
    }
}
//This is a feature that replays the game against AI.
void Game::Game_Vs_II()
{
    std::cout << "Enter the Name: ";
    std::string Name_1;
    std::cin >> Name_1;
    Player player_1(Name_1);
    int Manna_1 = player_1.Get_Manna();
    int Health_1 = player_1.Get_Health();

    std::string Name_II = "II";
    Player player_II(Name_II);
    int Manna_II = player_II.Get_Manna();
    int Health_II = player_II.Get_Health();

    Deck deck;
    std::vector<std::unique_ptr<Card>> The_Deck;
    deck.Filling_Deck(The_Deck);
    deck.Shuffling_Deck(The_Deck);
    std::vector<std::unique_ptr<Card>> Broken_Deck;

    Hand hand;
    std::vector <std::unique_ptr<Card>> Hand_Player_1;
    hand.Refilling_Hand(Name_1, Hand_Player_1, The_Deck, Broken_Deck);

    std::vector <std::unique_ptr<Card>> Hand_II;
    hand.Refilling_Hand(Name_II, Hand_II, The_Deck, Broken_Deck);

    Move move;

    std::optional<bool> Who_Is_Walking;

    std::cout << "choose who walks: ";
    std::cout << "1. Player " << Name_1 << " " << "2. Player " << Name_II << " " << "3. selected randomly" << std::endl;
    while (!Who_Is_Walking.has_value())
    {
        std::cout << "Enter the number: ";
        std::string input;
        std::cin >> input;
        Who_Is_Walking = move.The_Choosing_Move(input, Name_1, Name_II);
    }
    II ii;

    std::string situation = "all_right";

    while (situation != ("Player " + Name_1 + " win!") and situation != ("Player " + Name_II + " win!"))
    {
        if (Who_Is_Walking == true)
        {
            situation = move.Making_Move(Name_1, Manna_1, Health_1, Hand_Player_1, Name_II, Health_II, Hand_II, Broken_Deck);
            if (situation != ("Player " + Name_1 + " win!") and situation != ("Player " + Name_II + " win!"))
            {
                hand.Refilling_Hand(Name_1, Hand_Player_1, The_Deck, Broken_Deck);
                hand.Refilling_Hand(Name_II, Hand_II, The_Deck, Broken_Deck);
                Who_Is_Walking = false;
            }
            else
            {
                continue;
            }

        }
        else
        {
            situation = ii.Making_II_Move(Name_II, Manna_II, Health_II, Hand_II, Name_1, Health_1, Hand_Player_1, Broken_Deck);
            if (situation != ("Player " + Name_1 + " win!") and situation != ("Player " + Name_II + " win!"))
            {
                hand.Refilling_Hand(Name_II, Hand_II, The_Deck, Broken_Deck);
                hand.Refilling_Hand(Name_1, Hand_Player_1, The_Deck, Broken_Deck);
                Who_Is_Walking = true;
            }
            else
            {
                continue;
            }
        }
    }
    std::cout << situation << std::endl;
    std::cout << "The game is over!" << std::endl;
}
//This is a feature that replays the game against other player.
void Game::Game_Vs_Player()
{
    std::cout << "Player_1 enter the Name: ";
    std::string Name_1;
    std::cin >> Name_1;
    Player player_1(Name_1);
    int Manna_1 = player_1.Get_Manna();
    int Health_1 = player_1.Get_Health();

    std::cout << "Player_2 enter the Name: ";
    std::string Name_2;
    std::cin >> Name_2;
    Player player_2(Name_2);
    int Manna_2 = player_2.Get_Manna();
    int Health_2 = player_2.Get_Health();

    Deck deck;
    std::vector<std::unique_ptr<Card>> The_Deck;
    deck.Filling_Deck(The_Deck);
    deck.Shuffling_Deck(The_Deck);
    std::vector<std::unique_ptr<Card>> Broken_Deck;

    Hand hand;
    std::vector <std::unique_ptr<Card>> Hand_Player_1;
    hand.Refilling_Hand(Name_1, Hand_Player_1, The_Deck, Broken_Deck);

    std::vector <std::unique_ptr<Card>> Hand_Player_2;
    hand.Refilling_Hand(Name_2, Hand_Player_2, The_Deck, Broken_Deck);

    Move move;

    std::optional<bool> Who_Is_Walking;

    std::cout << "choose who walks: ";
    std::cout << "1. Player " << Name_1 << " " << "2. Player " << Name_2 << " " << "3. selected randomly" << std::endl;
    while (!Who_Is_Walking.has_value())
    {
        std::cout << "Enter the number: ";
        std::string input;
        std::cin >> input;
        Who_Is_Walking = move.The_Choosing_Move(input, Name_1, Name_2);
    }


    std::string situation = "all_right";

    while (situation != ("Player " + Name_1 + " win!") and situation != ("Player " + Name_2 + " win!"))
    {
        if (Who_Is_Walking == true)
        {
            situation = move.Making_Move(Name_1, Manna_1, Health_1, Hand_Player_1, Name_2, Health_2, Hand_Player_2, Broken_Deck);
            if (situation != ("Player " + Name_1 + " win!") and situation != ("Player " + Name_2 + " win!"))
            {
                hand.Refilling_Hand(Name_1, Hand_Player_1, The_Deck, Broken_Deck);
                hand.Refilling_Hand(Name_2, Hand_Player_2, The_Deck, Broken_Deck);
                Who_Is_Walking = false;
            }
            else
            {
                continue;
            }

        }
        else
        {
            situation = move.Making_Move(Name_2, Manna_2, Health_2, Hand_Player_2, Name_1, Health_1, Hand_Player_1, Broken_Deck);
            if (situation != ("Player " + Name_1 + " win!") and situation != ("Player " + Name_2 + " win!"))
            {
                hand.Refilling_Hand(Name_2, Hand_Player_2, The_Deck, Broken_Deck);
                hand.Refilling_Hand(Name_1, Hand_Player_1, The_Deck, Broken_Deck);
                Who_Is_Walking = true;
            }
            else
            {
                continue;
            }
        }
    }
    std::cout << situation << std::endl;
    std::cout << "The game is over!" << std::endl;

}
//this function returns true if the player wants to play more, returns false if the player does not want to play anymore, and returns std::nullopt if the input is incorrect.
std::optional<bool> Game::The_Play_Or_Not_Play(std::string& input)
{
    int Play_Or_Not_Play;

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
        return std::nullopt;
    }

    Play_Or_Not_Play = std::stoi(input);

    if (Play_Or_Not_Play < 0 or Play_Or_Not_Play > 1)
    {
        std::cout << "Invalid index! Please enter a number between 0 and 1." << std::endl;
        return std::nullopt;
    }
    if (Play_Or_Not_Play == 1)
    {
        return valid_input;
    }
    else if (Play_Or_Not_Play == 0)
    {
        valid_input = false;
        return valid_input;
    }
    return std::nullopt;

}
//This feature replays the full game.
void Game::All_Game()
{
    std::cout << "Welcome to my game! You will find a lot of interesting and mysterious things here!" << std::endl;

    int Play_NotPlay;
    std::optional <bool> Play_Or_Not_Play;

    while (!Play_Or_Not_Play.has_value())
    {
        std::cout << "if you want to play, then enter 1 (to exit the game, enter 0): ";
        std::string input;
        std::cin >> input;
        Play_Or_Not_Play = The_Play_Or_Not_Play(input);
    }
    Play_NotPlay = Play_Or_Not_Play.value();

    while (Play_NotPlay == 1)
    {
        Gaming();
        std::optional <bool> Play_Or_Not_Play;

        while (!Play_Or_Not_Play.has_value())
        {
            std::cout << "If you want to play again, enter 1 (if you want to exit the game, enter 0): ";
            std::string input;
            std::cin >> input;
            Play_Or_Not_Play = The_Play_Or_Not_Play(input);
        }
        Play_NotPlay = Play_Or_Not_Play.value();
    }
    std::cout << "You're out of the game, thanks for playing it." << std::endl;
}
Game::~Game() {}
