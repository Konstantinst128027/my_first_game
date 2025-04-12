/* Berezkin Konstantin Evgenievich
./main st128027@student.spbu.ru*/
#include "AI.h"

AI::AI() {}
//this function returns a vector of the Healing_Card indexes in descending order of their Healng (that is, the index of the card with the most Healing goes first)
std::vector <size_t> AI::Choosing_Healing_Card(std::vector <std::unique_ptr<Card>>& Hand)
{

    std::vector <size_t> Choosing_Healing_Cards;
    for (size_t i = 0; i < Hand.size(); i++)
    {

        auto* GameCard = dynamic_cast<Game_Card*>(Hand[i].get());

        if (GameCard)
        {

            if (GameCard->Get_Healing() > 0)
            {
                Choosing_Healing_Cards.push_back(i);
            }
        }

        else
        {

            continue;

        }
    }
    sort(Choosing_Healing_Cards.begin(), Choosing_Healing_Cards.end(), [&Hand](size_t a, size_t b)
    {

        auto* cardA = dynamic_cast<Game_Card*>(Hand[a].get());
        auto* cardB = dynamic_cast<Game_Card*>(Hand[b].get());
        return cardA->Get_Healing() > cardB->Get_Healing();

    });

    return Choosing_Healing_Cards;
}

//this function returns a vector of the Damage_Card indexes in descending order of their Damage (that is, the index of the card with the most Damage goes first)
std::vector <size_t> AI::Choosing_Damage_Card(std::vector <std::unique_ptr<Card>>& Hand)
{

    std::vector <size_t> Choosing_Damage_Cards;
    for (size_t i = 0; i < Hand.size(); i++)
    {

        auto* GameCard = dynamic_cast<Game_Card*>(Hand[i].get());

        if (GameCard)
        {

            if (GameCard->Get_Damage() > 0)
            {
                Choosing_Damage_Cards.push_back(i);
            }
        }

        else
        {

            continue;

        }
    }

    sort(Choosing_Damage_Cards.begin(), Choosing_Damage_Cards.end(), [&Hand](size_t a, size_t b)
    {

        auto* cardA = dynamic_cast<Game_Card*>(Hand[a].get());
        auto* cardB = dynamic_cast<Game_Card*>(Hand[b].get());
        return cardA->Get_Damage() > cardB->Get_Damage();

    });

    return Choosing_Damage_Cards;
}
//this function returns a vector of the Manna_Card indexes.
std::vector <size_t> AI::Choosing_Manna_Card(std::vector <std::unique_ptr<Card>>& Hand)
{

    std::vector <size_t> Choosing_Manna_Cards;
    for (size_t i = 0; i < Hand.size(); i++)
    {

        auto* Manna = dynamic_cast<Manna_Card*>(Hand[i].get());

        if (Manna)
        {
            Choosing_Manna_Cards.push_back(i);
        }

        else
        {

            continue;

        }
    }

    return Choosing_Manna_Cards;
}
//this function returns a vector of the Additional_Card indexes (without Manna_Card)
std::vector <size_t> AI::Choosing_Additional_Card(std::vector <std::unique_ptr<Card>>& Hand)
{

    std::vector <size_t> Choosing_Additional_Cards;
    for (size_t i = 0; i < Hand.size(); i++)
    {

        auto* AdditionalCards = dynamic_cast<Additional_Card*>(Hand[i].get());

        if (AdditionalCards and AdditionalCards->Get_Manna() > 0)
        {

            Choosing_Additional_Cards.push_back(i);
        }

        else
        {

            continue;

        }
    }

    return Choosing_Additional_Cards;
}
//this function shows how Swap_My_Card works For AI. Its implementation shows a smart card selection.
void AI::The_Swap_My_Card_AI(std::vector <std::unique_ptr<Card>>& Hand_1, std::vector <std::unique_ptr<Card>>& Hand_2, std::vector <size_t>& HealingCards, std::vector <size_t>& DamageCards, std::vector <size_t>& MannaCards, std::vector <size_t>& AdditionalCards, int& Health_1)
{

    size_t index_of_card;

    std::vector <size_t> HealingsCards = Choosing_Healing_Card(Hand_2);
    std::vector <size_t> DamagesCards = Choosing_Damage_Card(Hand_2);
    std::vector <size_t> MannasCards = Choosing_Manna_Card(Hand_2);
    std::vector <size_t> AdditionalsCards = Choosing_Additional_Card(Hand_2);

    if (!MannasCards.empty())
    {
        index_of_card = MannasCards[0];
        MannaCards.push_back(Hand_1.size());
    }

    else if (Health_1 < 15 and !HealingsCards.empty())
    {
        index_of_card = HealingsCards[0];
        HealingCards.push_back(Hand_1.size());
    }

    else if (!DamagesCards.empty())
    {
        index_of_card = DamagesCards[0];
        DamageCards.push_back(Hand_1.size());
    }

    else if (!AdditionalsCards.empty())
    {
        index_of_card = AdditionalsCards[0];
        AdditionalCards.push_back(Hand_1.size());
    }
    else if (Health_1 > 15 and !HealingsCards.empty())
    {
        index_of_card = HealingsCards[0];
        HealingCards.push_back(Hand_1.size());
    }

    Hand_1.push_back(std::move(Hand_2[index_of_card]));

    Hand_2.erase(Hand_2.begin() + index_of_card);

    std::cout << "Card was used!" << std::endl;

}
//this function shows how Card_Broken_Deck works For AI. Its implementation shows a smart card selection.
void AI::The_Card_Broken_Deck_AI(std::vector <std::unique_ptr<Card>>& Hand, std::vector <std::unique_ptr<Card>>& Broken_Deck, std::vector <size_t>& HealingCards, std::vector <size_t>& DamageCards, std::vector <size_t>& MannaCards, std::vector <size_t>& AdditionalCards, int& Health_1)
{

    size_t index_of_card;

    std::vector <size_t> HealingsCards = Choosing_Healing_Card(Broken_Deck);
    std::vector <size_t> DamagesCards = Choosing_Damage_Card(Broken_Deck);
    std::vector <size_t> MannasCards = Choosing_Manna_Card(Broken_Deck);
    std::vector <size_t> AdditionalsCards = Choosing_Additional_Card(Broken_Deck);

    if (!MannasCards.empty())
    {
        index_of_card = MannasCards[0];
        MannaCards.push_back(Hand.size());
    }

    else if (Health_1 < 15 and !HealingsCards.empty())
    {
        index_of_card = HealingsCards[0];
        HealingCards.push_back(Hand.size());
    }

    else if (!DamagesCards.empty())
    {
        index_of_card = DamagesCards[0];
        DamageCards.push_back(Hand.size());
    }

    else if (!AdditionalsCards.empty())
    {
        index_of_card = AdditionalsCards[0];
        AdditionalCards.push_back(Hand.size());
    }
    else if (Health_1 > 15 and !HealingsCards.empty())
    {
        index_of_card = HealingsCards[0];
        HealingCards.push_back(Hand.size());
    }

    Hand.push_back(std::move(Broken_Deck[index_of_card]));

    Broken_Deck.erase(Broken_Deck.begin() + index_of_card);

    std::cout << "Card was used!" << std::endl;
}
//This function adjusts the indexes of the maps after using one of them
void AI::Corrected_Index(std::vector <size_t>& HealingCards, std::vector <size_t>& DamageCards, std::vector <size_t>& MannaCards, std::vector <size_t>& AdditionalCards, std::vector <size_t>& ThenAdditionalHealingCards, std::vector <size_t>& ThenAdditionalDamageCards, size_t& Index_Of_Card)
{

    for (size_t i = 0; i < MannaCards.size(); i++)
    {
        if (MannaCards[i] > Index_Of_Card)
        {
            MannaCards[i] -= 1;
        }
    }

    for (size_t i = 0; i < AdditionalCards.size(); i++)
    {
        if (AdditionalCards[i] > Index_Of_Card)
        {
            AdditionalCards[i] -= 1;
        }
    }

    for (size_t i = 0; i < HealingCards.size(); i++)
    {
        if (HealingCards[i] > Index_Of_Card)
        {
            HealingCards[i] -= 1;
        }
    }

    for (size_t i = 0; i < DamageCards.size(); i++)
    {
        if (DamageCards[i] > Index_Of_Card)
        {
            DamageCards[i] -= 1;
        }
    }

    for (size_t i = 0; i < ThenAdditionalHealingCards.size(); i++)
    {
        if (ThenAdditionalHealingCards[i] > Index_Of_Card)
        {
            ThenAdditionalHealingCards[i] -= 1;
        }
    }

    for (size_t i = 0; i < ThenAdditionalDamageCards.size(); i++)
    {
        if (ThenAdditionalDamageCards[i] > Index_Of_Card)
        {
            ThenAdditionalDamageCards[i] -= 1;
        }
    }


}
//this function makes the AI move. Here I consider all cases so that there are no uncertainties.
std::string AI::Making_AI_Move(std::string& Name_1, int& Manna_AI, int& Health_1, std::vector <std::unique_ptr<Card>>& Hand_1, std::string& Name_2, int& Health_2,  std::vector<std::unique_ptr<Card>>& Hand_2, std::vector<std::unique_ptr<Card>>& Broken_Deck)
{

    std::cout << "The " << Name_1 << " player is walking" <<std::endl;

    int Manna_1 = Manna_AI;

    std::string situation = "all_right";

    std::vector <size_t> HealingCards = Choosing_Healing_Card(Hand_1);
    std::vector <size_t> DamageCards = Choosing_Damage_Card(Hand_1);
    std::vector <size_t> MannaCards = Choosing_Manna_Card(Hand_1);
    std::vector <size_t> AdditionalCards = Choosing_Additional_Card(Hand_1);
    std::vector <size_t> ThenAdditionalHealingCards;//I am creating this vector in case if there was not enough mana for this card before using additional cards, then maybe there will be enough mana for it after using it.
    std::vector <size_t> ThenAdditionalDamageCards;//I am creating this vector in case if there was not enough mana for this card before using additional cards, then maybe there will be enough mana for it after using it.
    std::vector <size_t> ThenAdditionalCards;//I created this vector in case if Broken_Deck is empty, then the Card_Broken_Deck card cannot be used.


    while (Manna_1 >= 0 and (!HealingCards.empty() or !DamageCards.empty() or !MannaCards.empty() or !AdditionalCards.empty() or !ThenAdditionalDamageCards.empty() or !ThenAdditionalHealingCards.empty()))
    {

        size_t index_of_card;

        if (!MannaCards.empty())
        {

            index_of_card = MannaCards[0];

            MannaCards.erase(MannaCards.begin());

            Corrected_Index(HealingCards, DamageCards, MannaCards, AdditionalCards, ThenAdditionalHealingCards, ThenAdditionalDamageCards, index_of_card);

            if ((Manna_1 - Hand_1[index_of_card]->Get_Manna()) >= 0)
            {

                auto* MannaCard = dynamic_cast<Manna_Card*>(Hand_1[index_of_card].get());

                if (MannaCard)
                {

                    MannaCard->Card_Capability();

                    MannaCard->The_Manna_Card(Manna_1);

                    MannaCard->Additional_Card_Play(Manna_1);

                    std::cout << Name_1 << " manna: " << Manna_1 << ", ";

                    std::cout << Name_1 << " health: " << Health_1 << ", ";

                    std::cout << Name_2 << " health: " << Health_2 << std::endl;

                    Manna_AI += MannaCard->Get_Plus_Manna();

                    Broken_Deck.push_back(std::move(Hand_1[index_of_card]));

                    Hand_1.erase(Hand_1.begin() + index_of_card);
                }
            }
        }

        else if (Health_1 < 15 and !HealingCards.empty())
        {

            index_of_card = HealingCards[0];

            if ((Manna_1 - Hand_1[index_of_card]->Get_Manna()) >= 0)
            {

                HealingCards.erase(HealingCards.begin());

                auto it = std::find(DamageCards.begin(), DamageCards.end(), index_of_card);//

                if (it != DamageCards.end())
                {

                    DamageCards.erase(it);
                }

                Corrected_Index(HealingCards, DamageCards, MannaCards, AdditionalCards, ThenAdditionalHealingCards, ThenAdditionalDamageCards, index_of_card);

                auto* GameCard = dynamic_cast<Game_Card*>(Hand_1[index_of_card].get());//by doing this, I find the card that is in both DamageCards and HealingCars, and when using it, I delete it from both DamageCards and HealingCars so that there are no uncertainties. I do the same in subsequent cases.

                if (GameCard)
                {
                    if ((Health_2 - GameCard->Get_Damage()) > 0)
                    {

                        GameCard->Game_Card_Play(Manna_1, Health_1, Health_2);

                        std::cout << Name_1 << " manna: " << Manna_1 << ", ";

                        std::cout << Name_1 << " health: " << Health_1 << ", ";

                        std::cout << Name_2 << " health: " << Health_2 << std::endl;

                        Broken_Deck.push_back(std::move(Hand_1[index_of_card]));

                        Hand_1.erase(Hand_1.begin() + index_of_card);
                    }

                    else
                    {
                        GameCard->Game_Card_Play(Manna_1, Health_1, Health_2);

                        std::cout << Name_1 << " manna: " << Manna_1 << ", ";

                        std::cout << Name_1 << " health: " << Health_1 << ", ";

                        std::cout << Name_2 << " health: " << Health_2 << std::endl;

                        Broken_Deck.push_back(std::move(Hand_1[index_of_card]));

                        Hand_1.erase(Hand_1.begin() + index_of_card);

                        situation = "Player " + Name_1 + " win!";

                        break;

                    }
                }
            }
            else
            {

                ThenAdditionalHealingCards.push_back(index_of_card);

                HealingCards.erase(HealingCards.begin());
            }
        }

        else if (!DamageCards.empty())
        {

            index_of_card = DamageCards[0];

            if ((Manna_1 - Hand_1[index_of_card]->Get_Manna()) >= 0)
            {

                DamageCards.erase(DamageCards.begin());

                auto it = std::find(HealingCards.begin(), HealingCards.end(), index_of_card);

                if (it != HealingCards.end())
                {

                    HealingCards.erase(it);
                }

                Corrected_Index(HealingCards, DamageCards, MannaCards, AdditionalCards, ThenAdditionalHealingCards, ThenAdditionalDamageCards, index_of_card);

                auto* GameCard = dynamic_cast<Game_Card*>(Hand_1[index_of_card].get());

                if (GameCard)
                {

                    if ((Health_2 - GameCard->Get_Damage()) > 0)
                    {

                        GameCard->Game_Card_Play(Manna_1, Health_1, Health_2);

                        std::cout << Name_1 << " manna: " << Manna_1 << ", ";

                        std::cout << Name_1 << " health: " << Health_1 << ", ";

                        std::cout << Name_2 << " health: " << Health_2 << std::endl;

                        Broken_Deck.push_back(std::move(Hand_1[index_of_card]));

                        Hand_1.erase(Hand_1.begin() + index_of_card);

                    }
                    else
                    {
                        GameCard->Game_Card_Play(Manna_1, Health_1, Health_2);

                        std::cout << Name_1 << " manna: " << Manna_1 << ", ";

                        std::cout << Name_1 << " health: " << Health_1 << ", ";

                        std::cout << Name_2 << " health: " << Health_2 << std::endl;

                        Broken_Deck.push_back(std::move(Hand_1[index_of_card]));

                        Hand_1.erase(Hand_1.begin() + index_of_card);

                        situation = "Player " + Name_1 + " win!";

                        break;

                    }
                }
            }

            else
            {

                DamageCards.erase(DamageCards.begin());

                ThenAdditionalDamageCards.push_back(index_of_card);

            }
        }

        else if (!AdditionalCards.empty())
        {

            index_of_card = AdditionalCards[0];

            AdditionalCards.erase(AdditionalCards.begin());


            if ((Manna_1 - Hand_1[index_of_card]->Get_Manna()) >= 0)
            {


                auto* AdditionalCard = dynamic_cast<Additional_Card*>(Hand_1[index_of_card].get());

                if (AdditionalCard->Get_Name() == "Card_Broken_Deck")
                {

                    if (!Broken_Deck.empty())
                    {

                        AdditionalCards.insert(AdditionalCards.begin(), ThenAdditionalCards.begin(), ThenAdditionalCards.end());

                        AdditionalCard->Card_Capability();

                        The_Card_Broken_Deck_AI(Hand_1, Broken_Deck, HealingCards, DamageCards, MannaCards, AdditionalCards, Health_1);

                        AdditionalCard->Additional_Card_Play(Manna_1);

                        std::cout << Name_1 << " manna: " << Manna_1 << ", ";

                        std::cout << Name_1 << " health: " << Health_1 << ", ";

                        std::cout << Name_2 << " health: " << Health_2 << std::endl;

                        Broken_Deck.push_back(std::move(Hand_1[index_of_card]));

                        Hand_1.erase(Hand_1.begin() + index_of_card);

                        Corrected_Index(HealingCards, DamageCards, MannaCards, AdditionalCards, ThenAdditionalHealingCards, ThenAdditionalDamageCards, index_of_card);
                    }
                    else
                    {
                        ThenAdditionalCards.push_back(index_of_card);
                    }
                }
                else if (AdditionalCard->Get_Name() == "Swap_My_Card")
                {

                    AdditionalCard->Card_Capability();

                    The_Swap_My_Card_AI(Hand_1, Hand_2, HealingCards, DamageCards, MannaCards, AdditionalCards, Health_1);

                    AdditionalCard->Additional_Card_Play(Manna_1);

                    std::cout << Name_1 << " manna: " << Manna_1 << ", ";

                    std::cout << Name_1 << " health: " << Health_1 << ", ";

                    std::cout << Name_2 << " health: " << Health_2 << std::endl;

                    Broken_Deck.push_back(std::move(Hand_1[index_of_card]));

                    Hand_1.erase(Hand_1.begin() + index_of_card);

                    Corrected_Index(HealingCards, DamageCards, MannaCards, AdditionalCards, ThenAdditionalHealingCards, ThenAdditionalDamageCards, index_of_card);


                }
            }
        }
        else if (Health_1 < 15 and !ThenAdditionalHealingCards.empty())
        {

            index_of_card = ThenAdditionalHealingCards[0];

            ThenAdditionalHealingCards.erase(ThenAdditionalHealingCards.begin());

            Corrected_Index(HealingCards, DamageCards, MannaCards, AdditionalCards, ThenAdditionalHealingCards, ThenAdditionalDamageCards, index_of_card);

            auto it = std::find(ThenAdditionalDamageCards.begin(), ThenAdditionalDamageCards.end(), index_of_card);

            if (it != ThenAdditionalDamageCards.end())
            {

                ThenAdditionalDamageCards.erase(it);
            }

            if ((Manna_1 - Hand_1[index_of_card]->Get_Manna()) >= 0)
            {

                auto it = std::find(ThenAdditionalDamageCards.begin(), ThenAdditionalDamageCards.end(), index_of_card);

                if (it != ThenAdditionalDamageCards.end())
                {

                    ThenAdditionalDamageCards.erase(it);
                }

                auto* GameCard = dynamic_cast<Game_Card*>(Hand_1[index_of_card].get());

                if (GameCard)
                {

                    if ((Health_2 - GameCard->Get_Damage()) > 0)
                    {

                        GameCard->Game_Card_Play(Manna_1, Health_1, Health_2);

                        std::cout << Name_1 << " manna: " << Manna_1 << ", ";

                        std::cout << Name_1 << " health: " << Health_1 << ", ";

                        std::cout << Name_2 << " health: " << Health_2 << std::endl;

                        Broken_Deck.push_back(std::move(Hand_1[index_of_card]));

                        Hand_1.erase(Hand_1.begin() + index_of_card);
                    }

                    else
                    {
                        GameCard->Game_Card_Play(Manna_1, Health_1, Health_2);

                        std::cout << Name_1 << " manna: " << Manna_1 << ", ";

                        std::cout << Name_1 << " health: " << Health_1 << ", ";

                        std::cout << Name_2 << " health: " << Health_2 << std::endl;

                        Broken_Deck.push_back(std::move(Hand_1[index_of_card]));

                        Hand_1.erase(Hand_1.begin() + index_of_card);

                        situation = "Player " + Name_1 + " win!";

                        break;
                    }
                }
            }
        }
        else if (!ThenAdditionalDamageCards.empty())
        {

            index_of_card = ThenAdditionalDamageCards[0];

            ThenAdditionalDamageCards.erase(ThenAdditionalDamageCards.begin());

            auto it = std::find(ThenAdditionalHealingCards.begin(), ThenAdditionalHealingCards.end(), index_of_card);

            if (it != ThenAdditionalHealingCards.end())
            {

                ThenAdditionalHealingCards.erase(it);
            }

            auto it_2 = std::find(HealingCards.begin(), HealingCards.end(), index_of_card);

            if (it_2 != HealingCards.end())
            {

                HealingCards.erase(it_2);
            }

            if ((Manna_1 - Hand_1[index_of_card]->Get_Manna()) >= 0)
            {

                Corrected_Index(HealingCards, DamageCards, MannaCards, AdditionalCards, ThenAdditionalHealingCards, ThenAdditionalDamageCards, index_of_card);

                auto* GameCard = dynamic_cast<Game_Card*>(Hand_1[index_of_card].get());

                if (GameCard)
                {
                    if ((Health_2 - GameCard->Get_Damage()) > 0)
                    {

                        GameCard->Game_Card_Play(Manna_1, Health_1, Health_2);

                        std::cout << Name_1 << " manna: " << Manna_1 << ", ";

                        std::cout << Name_1 << " health: " << Health_1 << ", ";

                        std::cout << Name_2 << " health: " << Health_2 << std::endl;

                        Broken_Deck.push_back(std::move(Hand_1[index_of_card]));

                        Hand_1.erase(Hand_1.begin() + index_of_card);
                    }

                    else
                    {
                        GameCard->Game_Card_Play(Manna_1, Health_1, Health_2);

                        std::cout << Name_1 << " manna: " << Manna_1 << ", ";

                        std::cout << Name_1 << " health: " << Health_1 << ", ";

                        std::cout << Name_2 << " health: " << Health_2 << std::endl;

                        Broken_Deck.push_back(std::move(Hand_1[index_of_card]));

                        Hand_1.erase(Hand_1.begin() + index_of_card);

                        situation = "Player " + Name_1 + " win!";
                        break;
                    }
                }
            }
        }

        else if (!HealingCards.empty()) //I'm only doing this cycle because it might happen that all the cards improve your health and you need to spend mana, so I'm doing this cycle. The HealingCards vector consists of those elements that do not fall into the condition Health < 15
        {

            index_of_card = HealingCards[0];

            HealingCards.erase(HealingCards.begin());

            if ((Manna_1 - Hand_1[index_of_card]->Get_Manna()) >= 0)
            {

                Corrected_Index(HealingCards, DamageCards, MannaCards, AdditionalCards, ThenAdditionalHealingCards, ThenAdditionalDamageCards, index_of_card);


                auto* GameCard = dynamic_cast<Game_Card*>(Hand_1[index_of_card].get());

                if (GameCard)
                {
                    if ((Health_2 - GameCard->Get_Damage()) > 0)
                    {

                        GameCard->Game_Card_Play(Manna_1, Health_1, Health_2);

                        std::cout << Name_1 << " manna: " << Manna_1 << ", ";

                        std::cout << Name_1 << " health: " << Health_1 << ", ";

                        std::cout << Name_2 << " health: " << Health_2 << std::endl;

                        Broken_Deck.push_back(std::move(Hand_1[index_of_card]));

                        Hand_1.erase(Hand_1.begin() + index_of_card);
                    }
                    else
                    {
                        GameCard->Game_Card_Play(Manna_1, Health_1, Health_2);

                        std::cout << Name_1 << " manna: " << Manna_1 << ", ";

                        std::cout << Name_1 << " health: " << Health_1 << ", ";

                        std::cout << Name_2 << " health: " << Health_2 << std::endl;

                        Broken_Deck.push_back(std::move(Hand_1[index_of_card]));

                        Hand_1.erase(Hand_1.begin() + index_of_card);

                        situation = "Player " + Name_1 + " win!";

                        break;
                    }
                }
            }
        }
    }
    std::cout << "AI turn is complete!" << std::endl;
    return situation;
}

AI::~AI() {}
