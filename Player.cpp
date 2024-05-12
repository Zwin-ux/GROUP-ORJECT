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
    std::cout << name << "'s hand: ";
    for (auto card : hand) {
        card->display();
        std::cout << ", ";
    }
    std::cout << std::endl;
}

int Player::calculateTotal() {
    // Calculate the total value of the player's hand
    return 0;
}
std::string Player::getName() const {
    return name;
}
