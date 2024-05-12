#ifndef PLAYER_H
#define PLAYER_H

#include "card.h"
#include <vector>

class Player {
public:
    Player();

    void addCard(const Card& card);
    void displayHand() const;
    int getTotalScore() const;

private:
    std::vector<Card> hand;
    int totalScore;
};

#endif // PLAYER_H
