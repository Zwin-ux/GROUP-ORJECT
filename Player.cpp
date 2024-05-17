#include "Player.h"
#include <iostream>

Player::Player(std::string name) {
    this->name = name;
}

Player::~Player() {
    for (auto card : hand) {
        delete card;
    }
}

void Player::addToHand(Card* card) {
    hand.push_back(card);
}

void Player::displayHand() {
     for (auto card : hand) {
        card->display();
        std::cout << ", ";
    }
    std::cout << std::endl;
}

const std::list<Card*>& Player::getHand() const {
    return hand;
}

int Player::calculateTotal() {
    int total = 0;
    int numAces = 0;

    for (auto card : hand) {
        int value = card->getValue();

        if (value == 1) {
            // Ace found
            numAces++;
            total += 11; // Assume ace as 11 initially
        } else if (value >= 10) {
            // Face card or 10
            total += 10;
        } else {
            // Number card
            total += value;
        }
    }

    // Adjust the value of aces if needed to prevent busting
    while (total > 21 && numAces > 0) {
        total -= 10; // Change ace value from 11 to 1
        numAces--;
    }

    return total;
}

std::string Player::getName() const {
    return name;
}
