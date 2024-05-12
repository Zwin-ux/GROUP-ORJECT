#ifndef BLACKJACK_H
#define BLACKJACK_H

#include "card.h"
#include "Deck.h"
#include "Player.h"
#include <vector>

class Blackjack {
public:
    Blackjack(int numPlayers);

    void play();

private:
    int numPlayers;
    std::vector<Player> players;
};

#endif // BLACKJACK_H
