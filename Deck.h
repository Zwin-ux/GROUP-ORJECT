#ifndef DECK_H
#define DECK_H

#include "card.h" // Assuming the correct filename is "Card.h"
#include <list>

class Deck {
private:
    std::list<Card*> cards;
public:
    Deck();
    ~Deck();
    void initialize();
    void shuffle();
    Card* dealCard();
    int cardsLeft();
};

#endif
