/* Berezkin Konstantin Evgenievich
./main st128027@student.spbu.ru*/
#include <gtest/gtest.h>
#include "II.h"
#include "player.h"
TEST(Choosing_Healing_Card, II_Test)
{

    std::vector <std::unique_ptr <Card>> My_Hand;

    My_Hand.push_back(std::make_unique<Manna_Card>());//0 (index)
    My_Hand.push_back(std::make_unique<Swap_My_Card>());//1 (index)
    My_Hand.push_back(std::make_unique<Card_Broken_Deck>());//2 (index)
    My_Hand.push_back(std::make_unique<Healing_Spell>());//3 (index)
    My_Hand.push_back(std::make_unique<Healer>());//4 (index)
    My_Hand.push_back(std::make_unique<Attacking_Spell>());//5 (index)

    II ii;
    std::vector <size_t> result = {4, 3};
    EXPECT_EQ(ii.Choosing_Healing_Card(My_Hand), result);
}

TEST(Choosing_Damage_Card, II_Test)
{

    std::vector <std::unique_ptr <Card>> My_Hand;

    My_Hand.push_back(std::make_unique<Manna_Card>());//0 (index)
    My_Hand.push_back(std::make_unique<Swap_My_Card>());//1 (index)
    My_Hand.push_back(std::make_unique<Card_Broken_Deck>());//2 (index)
    My_Hand.push_back(std::make_unique<Healing_Spell>());//3 (index)
    My_Hand.push_back(std::make_unique<Healer>());//4 (index)
    My_Hand.push_back(std::make_unique<Attacking_Spell>());//5 (index)

    II ii;
    std::vector <size_t> result = {5, 4};
    EXPECT_EQ(ii.Choosing_Damage_Card(My_Hand), result);
}

TEST(Choosing_Manna_Card, II_Test)
{

    std::vector <std::unique_ptr <Card>> My_Hand;

    My_Hand.push_back(std::make_unique<Manna_Card>());//0 (index)
    My_Hand.push_back(std::make_unique<Swap_My_Card>());//1 (index)
    My_Hand.push_back(std::make_unique<Card_Broken_Deck>());//2 (index)
    My_Hand.push_back(std::make_unique<Healing_Spell>());//3 (index)
    My_Hand.push_back(std::make_unique<Healer>());//4 (index)
    My_Hand.push_back(std::make_unique<Attacking_Spell>());//5 (index)

    II ii;
    std::vector <size_t> result = {0};
    EXPECT_EQ(ii.Choosing_Manna_Card(My_Hand), result);
}

TEST(Choosing_Additional_Card, II_Test)
{

    std::vector <std::unique_ptr <Card>> My_Hand;

    My_Hand.push_back(std::make_unique<Manna_Card>());//0 (index)
    My_Hand.push_back(std::make_unique<Swap_My_Card>());//1 (index)
    My_Hand.push_back(std::make_unique<Card_Broken_Deck>());//2 (index)
    My_Hand.push_back(std::make_unique<Healing_Spell>());//3 (index)
    My_Hand.push_back(std::make_unique<Healer>());//4 (index)
    My_Hand.push_back(std::make_unique<Attacking_Spell>());//5 (index)

    II ii;
    std::vector <size_t> result = {1, 2};
    EXPECT_EQ(ii.Choosing_Additional_Card(My_Hand), result);
}

TEST(The_Swap_My_Card_II, II_Test_1)
{

    std::vector <std::unique_ptr <Card>> Opponent_Hand;

    Opponent_Hand.push_back(std::make_unique<Manna_Card>());//0 (index)
    Opponent_Hand.push_back(std::make_unique<Swap_My_Card>());//1 (index)
    Opponent_Hand.push_back(std::make_unique<Card_Broken_Deck>());//2 (index)
    Opponent_Hand.push_back(std::make_unique<Healing_Spell>());//3 (index)
    Opponent_Hand.push_back(std::make_unique<Healer>());//4 (index)
    Opponent_Hand.push_back(std::make_unique<Attacking_Spell>());//5 (index)

    Player player("II");
    int Health_1 = player.Get_Health();

    II ii;
    std::vector <std::unique_ptr <Card>> My_Hand;
    std::vector <size_t> HealingCards = ii.Choosing_Healing_Card(My_Hand);
    std::vector <size_t> DamageCards =  ii.Choosing_Damage_Card(My_Hand);
    std::vector <size_t> MannaCards = ii.Choosing_Manna_Card(My_Hand);
    std::vector <size_t> AdditionalCards = ii.Choosing_Additional_Card(My_Hand);

    ii.The_Swap_My_Card_II(My_Hand, Opponent_Hand, HealingCards, DamageCards, MannaCards, AdditionalCards, Health_1);

    std::vector <size_t> result = {0};

    EXPECT_EQ(My_Hand.size(), 1);
    EXPECT_EQ(My_Hand[0]->Get_Name(), "Manna_Card");
    EXPECT_EQ(Opponent_Hand.size(), 5);
    EXPECT_EQ(MannaCards, result);

}

TEST(The_Swap_My_Card_II, II_Test_2)
{

    std::vector <std::unique_ptr <Card>> Opponent_Hand;

    Opponent_Hand.push_back(std::make_unique<Swap_My_Card>());//0 (index)
    Opponent_Hand.push_back(std::make_unique<Card_Broken_Deck>());//1 (index)
    Opponent_Hand.push_back(std::make_unique<Healing_Spell>());//2 (index)
    Opponent_Hand.push_back(std::make_unique<Healer>());//3 (index)
    Opponent_Hand.push_back(std::make_unique<Attacking_Spell>());//4 (index)

    Player player("II");
    int Health_1 = player.Get_Health();

    II ii;
    std::vector <std::unique_ptr <Card>> My_Hand;
    std::vector <size_t> HealingCards = ii.Choosing_Healing_Card(My_Hand);
    std::vector <size_t> DamageCards =  ii.Choosing_Damage_Card(My_Hand);
    std::vector <size_t> MannaCards = ii.Choosing_Manna_Card(My_Hand);
    std::vector <size_t> AdditionalCards = ii.Choosing_Additional_Card(My_Hand);

    ii.The_Swap_My_Card_II(My_Hand, Opponent_Hand, HealingCards, DamageCards, MannaCards, AdditionalCards, Health_1);

    std::vector <size_t> result = {0};

    EXPECT_EQ(My_Hand.size(), 1);
    EXPECT_EQ(My_Hand[0]->Get_Name(), "Attacking_Spell");
    EXPECT_EQ(Opponent_Hand.size(), 4);
    EXPECT_EQ(DamageCards, result);

}

TEST(The_Swap_My_Card_II, II_Test_3)
{

    std::vector <std::unique_ptr <Card>> Opponent_Hand;

    Opponent_Hand.push_back(std::make_unique<Swap_My_Card>());//0 (index)
    Opponent_Hand.push_back(std::make_unique<Card_Broken_Deck>());//1 (index)
    Opponent_Hand.push_back(std::make_unique<Healing_Spell>());//2 (index)

    Player player("II");
    int Health_1 = player.Get_Health();

    II ii;
    std::vector <std::unique_ptr <Card>> My_Hand;
    std::vector <size_t> HealingCards = ii.Choosing_Healing_Card(My_Hand);
    std::vector <size_t> DamageCards =  ii.Choosing_Damage_Card(My_Hand);
    std::vector <size_t> MannaCards = ii.Choosing_Manna_Card(My_Hand);
    std::vector <size_t> AdditionalCards = ii.Choosing_Additional_Card(My_Hand);

    ii.The_Swap_My_Card_II(My_Hand, Opponent_Hand, HealingCards, DamageCards, MannaCards, AdditionalCards, Health_1);

    std::vector <size_t> result = {0};

    EXPECT_EQ(My_Hand.size(), 1);
    EXPECT_EQ(My_Hand[0]->Get_Name(), "Swap_My_Card");
    EXPECT_EQ(Opponent_Hand.size(), 2);
    EXPECT_EQ(AdditionalCards, result);
}

TEST(The_Swap_My_Card_II, II_Test_4)
{

    std::vector <std::unique_ptr <Card>> Opponent_Hand;

    Opponent_Hand.push_back(std::make_unique<Healing_Spell>());//0 (index)

    Player player("II");
    int Health_1 = player.Get_Health();// > 15

    II ii;
    std::vector <std::unique_ptr <Card>> My_Hand;
    std::vector <size_t> HealingCards = ii.Choosing_Healing_Card(My_Hand);
    std::vector <size_t> DamageCards =  ii.Choosing_Damage_Card(My_Hand);
    std::vector <size_t> MannaCards = ii.Choosing_Manna_Card(My_Hand);
    std::vector <size_t> AdditionalCards = ii.Choosing_Additional_Card(My_Hand);

    ii.The_Swap_My_Card_II(My_Hand, Opponent_Hand, HealingCards, DamageCards, MannaCards, AdditionalCards, Health_1);

    std::vector <size_t> result = {0};

    EXPECT_EQ(My_Hand.size(), 1);
    EXPECT_EQ(My_Hand[0]->Get_Name(), "Healing_Spell");
    EXPECT_EQ(Opponent_Hand.size(), 0);
    EXPECT_EQ(HealingCards, result);
}

TEST(The_Swap_My_Card_II, II_Test_5)
{

    std::vector <std::unique_ptr <Card>> Opponent_Hand;

    Opponent_Hand.push_back(std::make_unique<Swap_My_Card>());//0 (index)
    Opponent_Hand.push_back(std::make_unique<Card_Broken_Deck>());//1 (index)
    Opponent_Hand.push_back(std::make_unique<Healing_Spell>());//2 (index)
    Opponent_Hand.push_back(std::make_unique<Healer>());//3 (index)
    Opponent_Hand.push_back(std::make_unique<Attacking_Spell>());//4 (index)

    int Health_1 = 14;

    II ii;
    std::vector <std::unique_ptr <Card>> My_Hand;
    std::vector <size_t> HealingCards = ii.Choosing_Healing_Card(My_Hand);
    std::vector <size_t> DamageCards =  ii.Choosing_Damage_Card(My_Hand);
    std::vector <size_t> MannaCards = ii.Choosing_Manna_Card(My_Hand);
    std::vector <size_t> AdditionalCards = ii.Choosing_Additional_Card(My_Hand);

    ii.The_Swap_My_Card_II(My_Hand, Opponent_Hand, HealingCards, DamageCards, MannaCards, AdditionalCards, Health_1);

    std::vector <size_t> result = {0};

    EXPECT_EQ(My_Hand.size(), 1);
    EXPECT_EQ(My_Hand[0]->Get_Name(), "Healer");
    EXPECT_EQ(Opponent_Hand.size(), 4);
    EXPECT_EQ(HealingCards, result);

}
TEST(The_Card_Broken_Deck_II, II_Test_1)
{

    std::vector <std::unique_ptr <Card>> Broken_Deck;

    Broken_Deck.push_back(std::make_unique<Manna_Card>());//0 (index)
    Broken_Deck.push_back(std::make_unique<Swap_My_Card>());//1 (index)
    Broken_Deck.push_back(std::make_unique<Card_Broken_Deck>());//2 (index)
    Broken_Deck.push_back(std::make_unique<Healing_Spell>());//3 (index)
    Broken_Deck.push_back(std::make_unique<Healer>());//4 (index)
    Broken_Deck.push_back(std::make_unique<Attacking_Spell>());//5 (index)

    Player player("II");
    int Health_1 = player.Get_Health();

    II ii;
    std::vector <std::unique_ptr <Card>> My_Hand;
    std::vector <size_t> HealingCards = ii.Choosing_Healing_Card(My_Hand);
    std::vector <size_t> DamageCards =  ii.Choosing_Damage_Card(My_Hand);
    std::vector <size_t> MannaCards = ii.Choosing_Manna_Card(My_Hand);
    std::vector <size_t> AdditionalCards = ii.Choosing_Additional_Card(My_Hand);

    ii.The_Card_Broken_Deck_II(My_Hand, Broken_Deck, HealingCards, DamageCards, MannaCards, AdditionalCards, Health_1);

    std::vector <size_t> result = {0};

    EXPECT_EQ(My_Hand.size(), 1);
    EXPECT_EQ(My_Hand[0]->Get_Name(), "Manna_Card");
    EXPECT_EQ(Broken_Deck.size(), 5);
    EXPECT_EQ(MannaCards, result);

}

TEST(The_Card_Broken_Deck_II, II_Test_2)
{

    std::vector <std::unique_ptr <Card>> Broken_Deck;

    Broken_Deck.push_back(std::make_unique<Swap_My_Card>());//0 (index)
    Broken_Deck.push_back(std::make_unique<Card_Broken_Deck>());//1 (index)
    Broken_Deck.push_back(std::make_unique<Healing_Spell>());//2 (index)
    Broken_Deck.push_back(std::make_unique<Healer>());//3 (index)
    Broken_Deck.push_back(std::make_unique<Attacking_Spell>());//4 (index)

    Player player("II");
    int Health_1 = player.Get_Health();

    II ii;
    std::vector <std::unique_ptr <Card>> My_Hand;
    std::vector <size_t> HealingCards = ii.Choosing_Healing_Card(My_Hand);
    std::vector <size_t> DamageCards =  ii.Choosing_Damage_Card(My_Hand);
    std::vector <size_t> MannaCards = ii.Choosing_Manna_Card(My_Hand);
    std::vector <size_t> AdditionalCards = ii.Choosing_Additional_Card(My_Hand);

    ii.The_Card_Broken_Deck_II(My_Hand, Broken_Deck, HealingCards, DamageCards, MannaCards, AdditionalCards, Health_1);

    std::vector <size_t> result = {0};

    EXPECT_EQ(My_Hand.size(), 1);
    EXPECT_EQ(My_Hand[0]->Get_Name(), "Attacking_Spell");
    EXPECT_EQ(Broken_Deck.size(), 4);
    EXPECT_EQ(DamageCards, result);

}

TEST(The_Card_Broken_Deck_II, II_Test_3)
{

    std::vector <std::unique_ptr <Card>> Broken_Deck;

    Broken_Deck.push_back(std::make_unique<Swap_My_Card>());//0 (index)
    Broken_Deck.push_back(std::make_unique<Card_Broken_Deck>());//1 (index)
    Broken_Deck.push_back(std::make_unique<Healing_Spell>());//2 (index)

    Player player("II");
    int Health_1 = player.Get_Health();

    II ii;
    std::vector <std::unique_ptr <Card>> My_Hand;
    std::vector <size_t> HealingCards = ii.Choosing_Healing_Card(My_Hand);
    std::vector <size_t> DamageCards =  ii.Choosing_Damage_Card(My_Hand);
    std::vector <size_t> MannaCards = ii.Choosing_Manna_Card(My_Hand);
    std::vector <size_t> AdditionalCards = ii.Choosing_Additional_Card(My_Hand);

    ii.The_Card_Broken_Deck_II(My_Hand, Broken_Deck, HealingCards, DamageCards, MannaCards, AdditionalCards, Health_1);

    std::vector <size_t> result = {0};

    EXPECT_EQ(My_Hand.size(), 1);
    EXPECT_EQ(My_Hand[0]->Get_Name(), "Swap_My_Card");
    EXPECT_EQ(Broken_Deck.size(), 2);
    EXPECT_EQ(AdditionalCards, result);
}

TEST(The_Card_Broken_Deck_II, II_Test_4)
{

    std::vector <std::unique_ptr <Card>> Broken_Deck;

    Broken_Deck.push_back(std::make_unique<Healing_Spell>());//0 (index)

    Player player("II");
    int Health_1 = player.Get_Health();// > 15

    II ii;
    std::vector <std::unique_ptr <Card>> My_Hand;
    std::vector <size_t> HealingCards = ii.Choosing_Healing_Card(My_Hand);
    std::vector <size_t> DamageCards =  ii.Choosing_Damage_Card(My_Hand);
    std::vector <size_t> MannaCards = ii.Choosing_Manna_Card(My_Hand);
    std::vector <size_t> AdditionalCards = ii.Choosing_Additional_Card(My_Hand);

    ii.The_Card_Broken_Deck_II(My_Hand, Broken_Deck, HealingCards, DamageCards, MannaCards, AdditionalCards, Health_1);

    std::vector <size_t> result = {0};

    EXPECT_EQ(My_Hand.size(), 1);
    EXPECT_EQ(My_Hand[0]->Get_Name(), "Healing_Spell");
    EXPECT_EQ(Broken_Deck.size(), 0);
    EXPECT_EQ(HealingCards, result);
}

TEST(The_Card_Broken_Deck_II, II_Test_5)
{

    std::vector <std::unique_ptr <Card>> Broken_Deck;

    Broken_Deck.push_back(std::make_unique<Swap_My_Card>());//0 (index)
    Broken_Deck.push_back(std::make_unique<Card_Broken_Deck>());//1 (index)
    Broken_Deck.push_back(std::make_unique<Healing_Spell>());//2 (index)
    Broken_Deck.push_back(std::make_unique<Healer>());//3 (index)
    Broken_Deck.push_back(std::make_unique<Attacking_Spell>());//4 (index)

    int Health_1 = 14;

    II ii;
    std::vector <std::unique_ptr <Card>> My_Hand;
    std::vector <size_t> HealingCards = ii.Choosing_Healing_Card(My_Hand);
    std::vector <size_t> DamageCards =  ii.Choosing_Damage_Card(My_Hand);
    std::vector <size_t> MannaCards = ii.Choosing_Manna_Card(My_Hand);
    std::vector <size_t> AdditionalCards = ii.Choosing_Additional_Card(My_Hand);

    ii.The_Card_Broken_Deck_II(My_Hand, Broken_Deck, HealingCards, DamageCards, MannaCards, AdditionalCards, Health_1);

    std::vector <size_t> result = {0};

    EXPECT_EQ(My_Hand.size(), 1);
    EXPECT_EQ(My_Hand[0]->Get_Name(), "Healer");
    EXPECT_EQ(Broken_Deck.size(), 4);
    EXPECT_EQ(HealingCards, result);
}
TEST(Corrected_Index, II_Test)
{

    std::vector <std::unique_ptr <Card>> Hand;

    Hand.push_back(std::make_unique<Manna_Card>());//0 (index)
    Hand.push_back(std::make_unique<Swap_My_Card>());//1 (index)
    Hand.push_back(std::make_unique<Card_Broken_Deck>());//2 (index)
    Hand.push_back(std::make_unique<Healing_Spell>());//3 (index)
    Hand.push_back(std::make_unique<Healer>());//4 (index)
    Hand.push_back(std::make_unique<Attacking_Spell>());//5 (index)

    II ii;

    std::vector <size_t> HealingCards = ii.Choosing_Healing_Card(Hand);
    std::vector <size_t> DamageCards =  ii.Choosing_Damage_Card(Hand);
    std::vector <size_t> MannaCards = ii.Choosing_Manna_Card(Hand);
    std::vector <size_t> AdditionalCards = ii.Choosing_Additional_Card(Hand);
    std::vector <size_t> ThenAdditionalHealingCards;
    std::vector <size_t> ThenAdditionalDamageCards;
    size_t Index_Of_Card = 0;
    Hand.erase(Hand.begin());
    MannaCards.erase(MannaCards.begin());
    ii.Corrected_Index(HealingCards, DamageCards, MannaCards, AdditionalCards, ThenAdditionalHealingCards, ThenAdditionalDamageCards, Index_Of_Card);

    std::vector <size_t> Healing_result = {3, 2};
    EXPECT_EQ(HealingCards, Healing_result);

    std::vector <size_t> Damage_result = {4, 3};
    EXPECT_EQ(DamageCards, Damage_result);

    std::vector <size_t> Manna_result = {};
    EXPECT_EQ(MannaCards, Manna_result);

    std::vector <size_t> Additional_result = {0, 1};
    EXPECT_EQ(AdditionalCards, Additional_result);
}

TEST(Making_II_Move, II_Test_1)
{

    Player player_II("II");
    std::string Name_II = player_II.Get_Name();
    int Manna_II = player_II.Get_Manna();
    int Health_II = player_II.Get_Health();
    std::vector <std::unique_ptr <Card>> II_Hand;

    II_Hand.push_back(std::make_unique<Manna_Card>());//0 (index)

    Player player("Konst");
    std::string Name_Player = player.Get_Name();
    int Health_Player = player.Get_Health();
    std::vector <std::unique_ptr <Card>> Player_Hand;

    std::vector <std::unique_ptr <Card>> Broken_Deck;

    II ii;

    EXPECT_EQ(ii.Making_II_Move(Name_II, Manna_II, Health_II, II_Hand, Name_Player, Health_Player, Player_Hand, Broken_Deck), "all_right");
    EXPECT_EQ(Manna_II, 15);
    EXPECT_EQ(Health_II, 25);
    EXPECT_EQ(Health_Player, 25);
    EXPECT_EQ(II_Hand.size(), 0);
    EXPECT_EQ(Broken_Deck.size(), 1);
}

TEST(Making_II_Move, II_Test_2)
{

    Player player_II("II");
    std::string Name_II = player_II.Get_Name();
    int Manna_II = player_II.Get_Manna();
    int Health_II = player_II.Get_Health();
    std::vector <std::unique_ptr <Card>> II_Hand;

    II_Hand.push_back(std::make_unique<Card_Broken_Deck>());//0 (index)

    Player player("Konst");
    std::string Name_Player = player.Get_Name();
    int Health_Player = player.Get_Health();
    std::vector <std::unique_ptr <Card>> Player_Hand;

    std::vector <std::unique_ptr <Card>> Broken_Deck;

    II ii;

    EXPECT_EQ(ii.Making_II_Move(Name_II, Manna_II, Health_II, II_Hand, Name_Player, Health_Player, Player_Hand, Broken_Deck), "all_right");
    EXPECT_EQ(Health_II, 25);
    EXPECT_EQ(Health_Player, 25);
    EXPECT_EQ(II_Hand.size(), 1);
    EXPECT_EQ(Broken_Deck.size(), 0);
}

TEST(Making_II_Move, II_Test_3)
{

    Player player_II("II");
    std::string Name_II = player_II.Get_Name();
    int Manna_II = player_II.Get_Manna();
    int Health_II = player_II.Get_Health();
    std::vector <std::unique_ptr <Card>> II_Hand;

    II_Hand.push_back(std::make_unique<Card_Broken_Deck>());//0 (index)

    Player player("Konst");
    std::string Name_Player = player.Get_Name();
    int Health_Player = player.Get_Health();
    std::vector <std::unique_ptr <Card>> Player_Hand;

    std::vector <std::unique_ptr <Card>> Broken_Deck;
    Broken_Deck.push_back(std::make_unique<Healer>());//0 (index)

    II ii;

    EXPECT_EQ(ii.Making_II_Move(Name_II, Manna_II, Health_II, II_Hand, Name_Player, Health_Player, Player_Hand, Broken_Deck), "all_right");
    EXPECT_EQ(Health_II, 30);
    EXPECT_EQ(Health_Player, 24);
    EXPECT_EQ(II_Hand.size(), 0);
    EXPECT_EQ(Broken_Deck.size(), 2);
}

TEST(Making_II_Move, II_Test_4)
{

    Player player_II("II");
    std::string Name_II = player_II.Get_Name();
    int Manna_II = player_II.Get_Manna();
    int Health_II = player_II.Get_Health();

    std::vector <std::unique_ptr <Card>> II_Hand;

    II_Hand.push_back(std::make_unique<Swap_My_Card>());//0 (index)

    Player player("Konst");
    std::string Name_Player = player.Get_Name();
    int Health_Player = player.Get_Health();
    std::vector <std::unique_ptr <Card>> Player_Hand;
    Player_Hand.push_back(std::make_unique<Attacking_Spell>());//0 (index)

    std::vector <std::unique_ptr <Card>> Broken_Deck;

    II ii;

    EXPECT_EQ(ii.Making_II_Move(Name_II, Manna_II, Health_II, II_Hand, Name_Player, Health_Player, Player_Hand, Broken_Deck), "all_right");
    EXPECT_EQ(Health_II, 25);
    EXPECT_EQ(Health_Player, 22);
    EXPECT_EQ(II_Hand.size(), 0);
    EXPECT_EQ(Broken_Deck.size(), 2);
}
TEST(Making_II_Move, II_Test_5)
{

    Player player_II("II");
    std::string Name_II = player_II.Get_Name();
    int Manna_II = 4;
    int Health_II = player_II.Get_Health();

    std::vector <std::unique_ptr <Card>> II_Hand;

    II_Hand.push_back(std::make_unique<Card_Broken_Deck>());//0 (index)
    II_Hand.push_back(std::make_unique<Knight>());//0 (index)

    Player player("Konst");
    std::string Name_Player = player.Get_Name();
    int Health_Player = player.Get_Health();
    std::vector <std::unique_ptr <Card>> Player_Hand;

    std::vector <std::unique_ptr <Card>> Broken_Deck;
    Broken_Deck.push_back(std::make_unique<Manna_Card>());//0 (index)

    II ii;

    EXPECT_EQ(ii.Making_II_Move(Name_II, Manna_II, Health_II, II_Hand, Name_Player, Health_Player, Player_Hand, Broken_Deck), "all_right");
    EXPECT_EQ(Health_II, 25);
    EXPECT_EQ(Health_Player, 18);
    EXPECT_EQ(II_Hand.size(), 0);
    EXPECT_EQ(Broken_Deck.size(), 3);
}

TEST(Making_II_Move, II_Test_6)
{

    Player player_II("II");
    std::string Name_II = player_II.Get_Name();
    int Manna_II = player_II.Get_Manna();
    int Health_II = player_II.Get_Health();

    std::vector <std::unique_ptr <Card>> II_Hand;

    II_Hand.push_back(std::make_unique<Knight>());//0 (index)

    Player player("Konst");
    std::string Name_Player = player.Get_Name();
    int Health_Player = 7;
    std::vector <std::unique_ptr <Card>> Player_Hand;

    std::vector <std::unique_ptr <Card>> Broken_Deck;

    II ii;

    EXPECT_EQ(ii.Making_II_Move(Name_II, Manna_II, Health_II, II_Hand, Name_Player, Health_Player, Player_Hand, Broken_Deck), "Player " + Name_II + " win!");
    EXPECT_EQ(Health_II, 25);
    EXPECT_EQ(Health_Player, 0);
    EXPECT_EQ(II_Hand.size(), 0);
    EXPECT_EQ(Broken_Deck.size(), 1);
}
//example
TEST(Making_II_Move, II_Test_7)
{

    Player player_II("II");
    std::string Name_II = player_II.Get_Name();
    int Manna_II = player_II.Get_Manna();
    int Health_II = player_II.Get_Health();

    std::vector <std::unique_ptr <Card>> II_Hand;

    II_Hand.push_back(std::make_unique<Swap_My_Card>());//0 (index)
    II_Hand.push_back(std::make_unique<Manna_Card>());//1 (index)
    II_Hand.push_back(std::make_unique<Manna_Card>());//2 (index)
    II_Hand.push_back(std::make_unique<Knight>());//3 (index)
    II_Hand.push_back(std::make_unique<Knight>());//4 (index)
    II_Hand.push_back(std::make_unique<Healing_Spell>());//5 (index)
    Player player("Konst");
    std::string Name_Player = player.Get_Name();
    int Health_Player = player.Get_Health();
    std::vector <std::unique_ptr <Card>> Player_Hand;

    Player_Hand.push_back(std::make_unique<Knight>());//0 (index)

    std::vector <std::unique_ptr <Card>> Broken_Deck;

    II ii;

    EXPECT_EQ(ii.Making_II_Move(Name_II, Manna_II, Health_II, II_Hand, Name_Player, Health_Player, Player_Hand, Broken_Deck), "all_right");
    EXPECT_EQ(Manna_II, 20);
    EXPECT_EQ(Health_II, 28);
    EXPECT_EQ(Health_Player, 4);
    EXPECT_EQ(II_Hand.size(), 0);
    EXPECT_EQ(Broken_Deck.size(), 7);
}

