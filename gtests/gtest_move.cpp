/* Berezkin Konstantin Evgenievich
./main st128027@student.spbu.ru*/
#include <gtest/gtest.h>
#include "move.h"
#include "player.h"
TEST(The_Choosing_Move, Move_Test_1)
{

    Move move;
    std::string Name_1 = "Konst";
    std::string Name_2 = "Kirill";
    std::string input = "1";

    std::optional<bool> Choosing_Move = move.The_Choosing_Move(input, Name_1, Name_2);

    EXPECT_EQ(Choosing_Move.has_value(), true);
    EXPECT_EQ(Choosing_Move, true);
}

TEST(The_Choosing_Move, Move_Test_2)
{

    Move move;
    std::string Name_1 = "Konst";
    std::string Name_2 = "Kirill";
    std::string input = "2";

    std::optional<bool> Choosing_Move = move.The_Choosing_Move(input, Name_1, Name_2);

    EXPECT_EQ(Choosing_Move.has_value(), true);
    EXPECT_EQ(Choosing_Move, false);
}

TEST(The_Choosing_Move, Move_Test_3)
{

    Move move;
    std::string Name_1 = "Konst";
    std::string Name_2 = "Kirill";
    std::string input = "4";

    std::optional<bool> Choosing_Move = move.The_Choosing_Move(input, Name_1, Name_2);

    EXPECT_EQ(Choosing_Move.has_value(), false);
}

TEST(The_Choosing_Move, Move_Test_4)
{

    Move move;
    std::string Name_1 = "Konst";
    std::string Name_2 = "Kirill";
    std::string input = "vector";

    std::optional<bool> Choosing_Move = move.The_Choosing_Move(input, Name_1, Name_2);

    EXPECT_EQ(Choosing_Move.has_value(), false);
}

TEST(Choosing_Card, Move_Test_1)
{

    std::vector <std::unique_ptr <Card>> Broken_Deck;

    std::string Name_1 = "Konst";
    Player player_1(Name_1);
    int Manna_Player_1 = player_1.Get_Manna();
    int Health_1 = player_1.Get_Health();

    int Manna_1 = Manna_Player_1;
    std::vector <std::unique_ptr <Card>> Hand_1;
    Hand_1.push_back(std::make_unique<Healer>());

    std::string Name_2 = "Kirill";
    Player player_2(Name_2);
    int Health_2 = player_2.Get_Health();

    std::vector <std::unique_ptr <Card>> Hand_2;
    std::string situation = "all_right";

    Move move;

    std::string input = "1";
    std::optional<bool> The_Choosing_Card = move.Choosing_Card(input, situation, Name_1, Manna_1, Manna_Player_1, Health_1, Hand_1, Name_2, Health_2, Hand_2, Broken_Deck);
    EXPECT_EQ(The_Choosing_Card, true);
    EXPECT_EQ(Manna_Player_1, 10);
    EXPECT_EQ(Manna_1, 6);
    EXPECT_EQ(Health_1, 30);
    EXPECT_EQ(Health_2, 24);
    EXPECT_EQ(Hand_1.size(), 0);
    EXPECT_EQ(situation, "all_right");
}

TEST(Choosing_Card, Move_Test_2)
{

    std::vector <std::unique_ptr <Card>> Broken_Deck;

    std::string Name_1 = "Konst";
    Player player_1(Name_1);
    int Manna_Player_1 = player_1.Get_Manna();
    int Health_1 = player_1.Get_Health();

    int Manna_1 = Manna_Player_1;
    std::vector <std::unique_ptr <Card>> Hand_1;
    Hand_1.push_back(std::make_unique<Healer>());

    std::string Name_2 = "Kirill";
    Player player_2(Name_2);
    int Health_2 = player_2.Get_Health();

    std::vector <std::unique_ptr <Card>> Hand_2;
    std::string situation = "all_right";

    Move move;

    std::string input = "2";
    std::optional<bool> The_Choosing_Card = move.Choosing_Card(input, situation, Name_1, Manna_1, Manna_Player_1, Health_1, Hand_1, Name_2, Health_2, Hand_2, Broken_Deck);
    EXPECT_EQ(The_Choosing_Card, false);
    EXPECT_EQ(Manna_Player_1, 10);
    EXPECT_EQ(Manna_1, 10);
    EXPECT_EQ(Health_1, 25);
    EXPECT_EQ(Health_2, 25);
    EXPECT_EQ(Hand_1.size(), 1);
    EXPECT_EQ(situation, "all_right");
}

TEST(Choosing_Card, Move_Test_3)
{

    std::vector <std::unique_ptr <Card>> Broken_Deck;

    std::string Name_1 = "Konst";
    Player player_1(Name_1);
    int Manna_Player_1 = player_1.Get_Manna();
    int Health_1 = player_1.Get_Health();

    int Manna_1 = Manna_Player_1;
    std::vector <std::unique_ptr <Card>> Hand_1;
    Hand_1.push_back(std::make_unique<Healer>());

    std::string Name_2 = "Kirill";
    Player player_2(Name_2);
    int Health_2 = player_2.Get_Health();

    std::vector <std::unique_ptr <Card>> Hand_2;
    std::string situation = "all_right";

    Move move;

    std::string input = "vector";
    std::optional<bool> The_Choosing_Card = move.Choosing_Card(input, situation, Name_1, Manna_1, Manna_Player_1, Health_1, Hand_1, Name_2, Health_2, Hand_2, Broken_Deck);
    EXPECT_EQ(The_Choosing_Card, false);
    EXPECT_EQ(Manna_Player_1, 10);
    EXPECT_EQ(Manna_1, 10);
    EXPECT_EQ(Health_1, 25);
    EXPECT_EQ(Health_2, 25);
    EXPECT_EQ(Hand_1.size(), 1);
    EXPECT_EQ(situation, "all_right");
}

TEST(Choosing_Card, Move_Test_4)
{

    std::vector <std::unique_ptr <Card>> Broken_Deck;

    std::string Name_1 = "Konst";
    Player player_1(Name_1);
    int Manna_Player_1 = player_1.Get_Manna();
    int Health_1 = player_1.Get_Health();

    int Manna_1 = Manna_Player_1;
    std::vector <std::unique_ptr <Card>> Hand_1;
    Hand_1.push_back(std::make_unique<Healer>());

    std::string Name_2 = "Kirill";
    Player player_2(Name_2);
    int Health_2 = 1;

    std::vector <std::unique_ptr <Card>> Hand_2;
    std::string situation = "all_right";

    Move move;

    std::string input = "1";
    std::optional<bool> The_Choosing_Card = move.Choosing_Card(input, situation, Name_1, Manna_1, Manna_Player_1, Health_1, Hand_1, Name_2, Health_2, Hand_2, Broken_Deck);
    EXPECT_EQ(The_Choosing_Card, true);
    EXPECT_EQ(Manna_Player_1, 10);
    EXPECT_EQ(Manna_1, 6);
    EXPECT_EQ(Health_1, 30);
    EXPECT_EQ(Health_2, 0);
    EXPECT_EQ(Hand_1.size(), 0);
    EXPECT_EQ(situation, "Player " + Name_1 + " win!");
}

TEST(Choosing_Card, Move_Test_5)
{

    std::vector <std::unique_ptr <Card>> Broken_Deck;

    std::string Name_1 = "Konst";
    Player player_1(Name_1);
    int Manna_Player_1 = player_1.Get_Manna();
    int Health_1 = player_1.Get_Health();

    int Manna_1 = 3;
    std::vector <std::unique_ptr <Card>> Hand_1;
    Hand_1.push_back(std::make_unique<Healer>());

    std::string Name_2 = "Kirill";
    Player player_2(Name_2);
    int Health_2 = player_2.Get_Health();

    std::vector <std::unique_ptr <Card>> Hand_2;
    std::string situation = "all_right";

    Move move;

    std::string input = "1";
    std::optional<bool> The_Choosing_Card = move.Choosing_Card(input, situation, Name_1, Manna_1, Manna_Player_1, Health_1, Hand_1, Name_2, Health_2, Hand_2, Broken_Deck);
    EXPECT_EQ(The_Choosing_Card, false);
    EXPECT_EQ(Manna_Player_1, 10);
    EXPECT_EQ(Manna_1, 3);
    EXPECT_EQ(Health_1, 25);
    EXPECT_EQ(Health_2, 25);
    EXPECT_EQ(Hand_1.size(), 1);
    EXPECT_EQ(situation, "all_right");
}

TEST(Choosing_Card, Move_Test_6)
{

    std::vector <std::unique_ptr <Card>> Broken_Deck;

    std::string Name_1 = "Konst";
    Player player_1(Name_1);
    int Manna_Player_1 = player_1.Get_Manna();
    int Health_1 = player_1.Get_Health();

    int Manna_1 = Manna_Player_1;
    std::vector <std::unique_ptr <Card>> Hand_1;
    Hand_1.push_back(std::make_unique<Manna_Card>());

    std::string Name_2 = "Kirill";
    Player player_2(Name_2);
    int Health_2 = player_2.Get_Health();

    std::vector <std::unique_ptr <Card>> Hand_2;
    std::string situation = "all_right";

    Move move;

    std::string input = "1";
    std::optional<bool> The_Choosing_Card = move.Choosing_Card(input, situation, Name_1, Manna_1, Manna_Player_1, Health_1, Hand_1, Name_2, Health_2, Hand_2, Broken_Deck);
    EXPECT_EQ(The_Choosing_Card, true);
    EXPECT_EQ(Manna_Player_1, 15);
    EXPECT_EQ(Manna_1, 15);
    EXPECT_EQ(Health_1, 25);
    EXPECT_EQ(Health_2, 25);
    EXPECT_EQ(Hand_1.size(), 0);
    EXPECT_EQ(situation, "all_right");
}

TEST(Choosing_Card, Move_Test_7)
{

    std::vector <std::unique_ptr <Card>> Broken_Deck;

    std::string Name_1 = "Konst";
    Player player_1(Name_1);
    int Manna_Player_1 = player_1.Get_Manna();
    int Health_1 = player_1.Get_Health();

    int Manna_1 = Manna_Player_1;
    std::vector <std::unique_ptr <Card>> Hand_1;
    Hand_1.push_back(std::make_unique<Healer>());

    std::string Name_2 = "Kirill";
    Player player_2(Name_2);
    int Health_2 = player_2.Get_Health();

    std::vector <std::unique_ptr <Card>> Hand_2;
    std::string situation = "all_right";

    Move move;

    std::string input = "0";
    std::optional<bool> The_Choosing_Card = move.Choosing_Card(input, situation, Name_1, Manna_1, Manna_Player_1, Health_1, Hand_1, Name_2, Health_2, Hand_2, Broken_Deck);
    EXPECT_EQ(The_Choosing_Card.has_value(), false);
    EXPECT_EQ(Manna_Player_1, 10);
    EXPECT_EQ(Manna_1, 10);
    EXPECT_EQ(Health_1, 25);
    EXPECT_EQ(Health_2, 25);
    EXPECT_EQ(Hand_1.size(), 1);
    EXPECT_EQ(situation, "all_right");
}
