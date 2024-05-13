#include "card.h"

Card::Card(std::string suit, std::string rank) {
    this->suit = suit;
    this->rank = rank;
}

void Card::display() {
    // Unicode symbols for card suits
    std::string suitSymbol;
    if (suit == "Hearts") {
        suitSymbol = "\u2665"; // Heart symbol
    } else if (suit == "Diamonds") {
        suitSymbol = "\u2666"; // Diamond symbol
    } else if (suit == "Clubs") {
        suitSymbol = "\u2663"; // Club symbol
    } else if (suit == "Spades") {
        suitSymbol = "\u2660"; // Spade symbol
    } else {
        suitSymbol = "Invalid Suit"; // Handle invalid suit
    }

    std::cout << rank << " of " << suitSymbol << std::endl;
}

int Card::getValue() {
    // For numbered cards (2 through 10), return their face value
    if (rank == "2" || rank == "3" || rank == "4" || rank == "5" || rank == "6" || rank == "7" || rank == "8" || rank == "9" || rank == "10") {
        return std::stoi(rank);
    }
    // For face cards (Jack, Queen, King), return 10
    else if (rank == "Jack" || rank == "Queen" || rank == "King") {
        return 10;
    }
    // For Ace, return 11 if adding 11 doesn't exceed 21, otherwise return 1
    else if (rank == "Ace") {
        return 11; // Assume default value is 11
    }
    // Default case (shouldn't happen in a well-formed deck)
    else {
        return 0;
    }
}
