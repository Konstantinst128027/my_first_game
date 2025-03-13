/* Berezkin Konstantin Evgenievich
./main st128027@student.spbu.ru*/
#include <gtest/gtest.h>
#include "game.h"
TEST(Choosing_Mode, Game_Test_1)
{

    Game game;
    std::string input = "1";

    std::optional<bool> The_Choosing_Mode = game.Choosing_Mode(input);

    EXPECT_EQ(The_Choosing_Mode.has_value(), true);
    EXPECT_EQ(The_Choosing_Mode, true);
}

TEST(Choosing_Mode, Game_Test_2)
{

    Game game;
    std::string input = "2";

    std::optional<bool> The_Choosing_Mode = game.Choosing_Mode(input);

    EXPECT_EQ(The_Choosing_Mode.has_value(), true);
    EXPECT_EQ(The_Choosing_Mode, false);
}

TEST(Choosing_Mode, Game_Test_3)
{

    Game game;
    std::string input = "4";

    std::optional<bool> The_Choosing_Mode = game.Choosing_Mode(input);

    EXPECT_EQ(The_Choosing_Mode.has_value(), false);
}
TEST(Choosing_Mode, Game_Test_4)
{

    Game game;
    std::string input = "vector";

    std::optional<bool> The_Choosing_Mode = game.Choosing_Mode(input);

    EXPECT_EQ(The_Choosing_Mode.has_value(), false);
}
TEST(The_Play_Or_Not_Play, Game_Test_1)
{

    Game game;
    std::string input = "1";

    std::optional<bool> Play_Or_Not_Play = game.The_Play_Or_Not_Play(input);

    EXPECT_EQ(Play_Or_Not_Play.has_value(), true);
    EXPECT_EQ(Play_Or_Not_Play, true);
}

TEST(The_Play_Or_Not_Play, Game_Test_2)
{

    Game game;
    std::string input = "0";

    std::optional<bool> Play_Or_Not_Play = game.The_Play_Or_Not_Play(input);

    EXPECT_EQ(Play_Or_Not_Play.has_value(), true);
    EXPECT_EQ(Play_Or_Not_Play, false);
}

TEST(The_Play_Or_Not_Play, Game_Test_3)
{

    Game game;
    std::string input = "4";

    std::optional<bool> Play_Or_Not_Play = game.The_Play_Or_Not_Play(input);

    EXPECT_EQ(Play_Or_Not_Play.has_value(), false);
}
TEST(The_Play_Or_Not_Play, Game_Test_4)
{

    Game game;
    std::string input = "vector";

    std::optional<bool> Play_Or_Not_Play = game.The_Play_Or_Not_Play(input);

    EXPECT_EQ(Play_Or_Not_Play.has_value(), false);
}
