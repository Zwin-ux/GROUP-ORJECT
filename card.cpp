
// Card.cpp
#include "card.h"
#include <iostream>

Card::Card(Suit s, Rank r) : suit(s), rank(r) {}

int Card::getValue() const {
    if (rank >= TWO && rank <= TEN)
        return rank;
    else if (rank >= JACK && rank <= KING)
        return 10;
    else // ACE
        return 11;
}

void Card::display() const {
    std::cout << rank << " of ";
    switch (suit) {
        case HEARTS: std::cout << "Hearts"; break;
        case DIAMONDS: std::cout << "Diamonds"; break;
        case CLUBS: std::cout << "Clubs"; break;
        case SPADES: std::cout << "Spades"; break;
    }
}
