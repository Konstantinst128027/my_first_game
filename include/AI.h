/* Berezkin Konstantin Evgenievich
./main st128027@student.spbu.ru*/
#ifndef AI_H
#define AI_H

#include "deck.h"


class AI
{
public:
    AI();

    std::vector <size_t> Choosing_Healing_Card(std::vector <std::unique_ptr<Card>>& Hand);

    std::vector <size_t> Choosing_Damage_Card(std::vector <std::unique_ptr<Card>>& Hand);

    std::vector <size_t> Choosing_Manna_Card(std::vector <std::unique_ptr<Card>>& Hand);

    std::vector <size_t> Choosing_Additional_Card(std::vector <std::unique_ptr<Card>>& Hand);

    void The_Swap_My_Card_AI(std::vector <std::unique_ptr<Card>>& Hand_1, std::vector <std::unique_ptr<Card>>& Hand_2, std::vector <size_t>& HealingCards, std::vector <size_t>& DamageCards, std::vector <size_t>& MannaCards, std::vector <size_t>& AdditionalCards, int& Health_1);

    void The_Card_Broken_Deck_AI(std::vector <std::unique_ptr<Card>>& Hand, std::vector <std::unique_ptr<Card>>& Broken_Deck, std::vector <size_t>& HealingCards, std::vector <size_t>& DamageCards, std::vector <size_t>& MannaCards, std::vector <size_t>& AdditionalCards, int& Health_1);

    void Corrected_Index(std::vector <size_t>& HealingCards, std::vector <size_t>& DamageCards, std::vector <size_t>& MannaCards, std::vector <size_t>& AdditionalCards, std::vector <size_t>& ThenAdditionalHealingCards, std::vector <size_t>& ThenAdditionalDamageCards, size_t& Index_Of_Card);

    std::string Making_AI_Move(std::string& Name_1, int& Manna_AI, int& Health_1, std::vector <std::unique_ptr<Card>>& Hand_1, std::string& Name_2, int& Health_2,  std::vector<std::unique_ptr<Card>>& Hand_2, std::vector<std::unique_ptr<Card>>& Broken_Deck);

    ~AI();
};

#endif

