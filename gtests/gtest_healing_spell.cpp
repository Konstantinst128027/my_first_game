/* Berezkin Konstantin Evgenievich
./main st128027@student.spbu.ru*/
#include <gtest/gtest.h>
#include "healing_spell.h"

TEST(Get_Damage_Test, Healing_Spell_Test)
{
    Healing_Spell healing_spell;
    EXPECT_EQ(healing_spell.Get_Damage(), 0);
}
TEST(Get_Healing_Test, Healing_Spell_Test)
{
    Healing_Spell healing_spell;
    EXPECT_EQ(healing_spell.Get_Healing(), 3);
}
TEST(Get_Manna_Test, Healing_Spell_Test)
{
    Healing_Spell healing_spell;
    EXPECT_EQ(healing_spell.Get_Manna(), 1);
}
TEST(Get_Name_Test, Healing_Spell_Test)
{
    Healing_Spell healing_spell;
    EXPECT_EQ(healing_spell.Get_Name(), "Healing_Spell");
}
TEST(Healing_Spell_Play_Test, Healing_Spell_Test)
{
    Healing_Spell healing_spell;
    int Manna = 10;
    int My_Health = 10;
    int Health_opponent = 10;
    healing_spell.Game_Card_Play(Manna, My_Health, Health_opponent);
    EXPECT_EQ(Manna, 9);
    EXPECT_EQ(My_Health, 13);
    EXPECT_EQ(Health_opponent, 10);
}
