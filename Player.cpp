#include "Player.h"
#include <iostream>

Player::Player() : totalScore(0) {}

void Player::addCard(const Card& card) {
    hand.push_back(card);
    totalScore += card.getValue();
}

void Player::displayHand() const {
    for (const Card& card : hand) {
        card.display();
        std::cout << std::endl;
    }
    std::cout << "Total Score: " << totalScore << std::endl;
}

int Player::getTotalScore() const {
    return totalScore;
}
