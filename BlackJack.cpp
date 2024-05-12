#include "BlackJack.h"
using namespace std;
#include <iostream> // Ensure <iostream> is included

Blackjack::Blackjack(int numPlayers) : numPlayers(numPlayers) {
    for (int i = 0; i < numPlayers; ++i) {
        players.push_back(Player());
    }
}

void Blackjack::play() {
    Deck deck;
    for (int i = 0; i < 2; ++i) {
        for (Player& player : players) {
            player.addCard(deck.dealCard());
        }
    }

    for (Player& player : players) {
        std::cout << "Player " << (&player - &players[0] + 1) << " hand:" << std::endl;
        player.displayHand();
        std::cout << std::endl;
    }
}
