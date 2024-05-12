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
    for (int suit = 0; suit < Card::SUITS_COUNT; ++suit) {
        for (int rank = 0; rank < Card::RANKS_COUNT; ++rank) {
            cards.push_back(new Card(Card::SUITS[suit], Card::RANKS[rank]));
        }
    }
}

void Deck::shuffle() {
    // Shuffle the deck
    std::srand(static_cast<unsigned int>(std::time(0)));
    std::random_shuffle(cards.begin(), cards.end());
}

Card* Deck::dealCard() {
    // Remove and return a card from the deck
    if (cards.empty()) {
        return nullptr; // No cards left in the deck
    }
    Card* dealtCard = cards.back();
    cards.pop_back();
    return dealtCard;
}

int Deck::cardsLeft() {
    // Return the number of cards left in the deck
    return cards.size();
}
