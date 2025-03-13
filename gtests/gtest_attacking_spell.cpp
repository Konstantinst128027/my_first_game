/* Berezkin Konstantin Evgenievich
./main st128027@student.spbu.ru*/
#include <gtest/gtest.h>
#include "attacking_spell.h"

TEST(Get_Damage_Test, Attacking_Spell_Test)
{
    Attacking_Spell attacking_spell;
    EXPECT_EQ(attacking_spell.Get_Damage(), 3);
}
TEST(Get_Healing_Test, Attacking_Spell_Test)
{
    Attacking_Spell attacking_spell;
    EXPECT_EQ(attacking_spell.Get_Healing(), 0);
}
TEST(Get_Manna_Test, Attacking_Spell_Test)
{
    Attacking_Spell attacking_spell;
    EXPECT_EQ(attacking_spell.Get_Manna(), 1);
}
TEST(Get_Name_Test, Attacking_Spell_Test)
{
    Attacking_Spell attacking_spell;
    EXPECT_EQ(attacking_spell.Get_Name(), "Attacking_Spell");
}
TEST(Attacking_Spell_Play_Test, Attacking_Spell_Test)
{
    Attacking_Spell attacking_spell;
    int Manna = 10;
    int My_Health = 10;
    int Health_opponent = 10;
    attacking_spell.Game_Card_Play(Manna, My_Health, Health_opponent);
    EXPECT_EQ(Manna, 9);
    EXPECT_EQ(My_Health, 10);
    EXPECT_EQ(Health_opponent, 7);
}
