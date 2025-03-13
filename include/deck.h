/* Berezkin Konstantin Evgenievich
./main st128027@student.spbu.ru*/
#ifndef DECK_H
#define DECK_H
#include "archer.h"
#include "healer.h"
#include "attacking_spell.h"
#include "healing_spell.h"
#include "card_broken_deck.h"
#include "knight.h"
#include "magician.h"
#include "manna_card.h"
#include "swap_my_card.h"
#include "thief.h"
#include "berserker.h"

class Deck
{
public:
    Deck();
    void Filling_Deck(std::vector<std::unique_ptr<Card>>& Deck);
    void Shuffling_Deck(std::vector<std::unique_ptr<Card>>& Deck);
    void Filling_Empty_Deck(std::vector<std::unique_ptr<Card>>& Deck, std::vector<std::unique_ptr<Card>>& Broken_Deck);
    virtual ~Deck();
};
#endif
