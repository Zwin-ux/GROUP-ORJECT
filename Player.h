#ifndef PLAYER_H
#define PLAYER_H

#include <list>
#include "card.h"

class Player {
private:
    std::string name;
    std::list<Card*> hand;
public:
    Player(std::string name);
    ~Player();
    void addToHand(Card* card);
    void displayHand();
    int calculateTotal();
    std::string getName() const; // Declaration

};

#endif
