#include "card.h"

Card::Card(std::string suit, std::string rank) {
    this->suit = suit;
    this->rank = rank;
}

void Card::display() {
    std::cout << rank << " of " << suit;
}

int Card::getValue() {
    // Implement logic to return the value of the card in Blackjack
    return 0;
}
