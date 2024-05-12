#include "Deck.h"
#include <algorithm>
#include <ctime>
#include <cstdlib>

Deck::Deck() {
    initialize();
}

Deck::~Deck() {
    for (auto card : cards) {
        delete card;
    }
}

void Deck::initialize() {
    // Create and add cards to the deck
    // Add logic to create all 52 cards
}

void Deck::shuffle() {
    // Shuffle the deck
    std::srand(std::time(0));
    //std::random_shuffle(cards.begin(), cards.end());
}

Card* Deck::dealCard() {
    // Remove and return a card from the deck
    // Remove it from the linked list and return
    return nullptr;
}

int Deck::cardsLeft() {
    // Return the number of cards left in the deck
    return cards.size();
}
