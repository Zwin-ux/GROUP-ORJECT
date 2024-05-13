#include "Deck.h"
#include <algorithm>
#include <ctime>
#include <cstdlib>

Deck::Deck() : nextCardIndex(0) {
    initialize();
}

Deck::~Deck() {
    for (auto card : cards) {
        delete card;
    }
}

void Deck::initialize() {
 // Generate a standard deck of 52 cards
    std::vector<std::string> suits = {"Hearts", "Diamonds", "Clubs", "Spades"};
    std::vector<std::string> ranks = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King", "Ace"};

    for (const auto& suit : suits) {
        for (const auto& rank : ranks) {
            cards.push_back(new Card(suit, rank));
        }
    }
}

void Deck::shuffle() {
    // Shuffle the deck using Fisher-Yates algorithm
    std::srand(static_cast<unsigned int>(std::time(0)));
    for (int i = cards.size() - 1; i > 0; --i) {
        int j = std::rand() % (i + 1);
        std::swap(cards[i], cards[j]);
    }
}

Card* Deck::dealCard() {
    // Deal a card from the deck
    if (nextCardIndex >= cards.size()) {
        return nullptr; // No cards left in the deck
    }
    return cards[nextCardIndex++];
}

int Deck::cardsLeft() const {
    // Return the number of cards left in the deck
    return cards.size() - nextCardIndex;
}
