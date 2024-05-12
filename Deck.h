// Deck.h
#ifndef DECK_H
#define DECK_H

#include "card.h"
#include <vector>

class Deck {
public:
    Deck();

    void shuffle();
    Card dealCard();

private:
    std::vector<Card> cards;
};

#endif // DECK_H
