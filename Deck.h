#ifndef DECK_H
#define DECK_H

#include "Card.h"
#include <vector>

class Deck {
private:
    std::vector<Card*> cards;
    int nextCardIndex;

public:
    Deck();
    ~Deck();
    void initialize();
    void shuffle();
    Card* dealCard();
    int cardsLeft() const;
};

#endif
