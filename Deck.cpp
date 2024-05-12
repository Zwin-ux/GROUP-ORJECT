// Deck.cpp
#include "Deck.h"
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <__algorithm/shuffle.h>
using namespace std;
Deck::Deck() {
    for (int s = Card::HEARTS; s <= Card::SPADES; ++s) {
        for (int r = Card::ACE; r <= Card::KING; ++r) {
            cards.push_back(Card(static_cast<Card::Suit>(s), static_cast<Card::Rank>(r)));
        }
    }
    shuffle();
}

void Deck::shuffle() {
    //std::random_shuffle(cards.begin(), cards.end());
}

Card Deck::dealCard() {
    Card card = cards.back();
    cards.pop_back();
    return card;
}
