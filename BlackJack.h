#ifndef BLACKJACK_H
#define BLACKJACK_H

#include "Deck.h"
#include "Player.h"
#include <vector>

class BlackJack {
private:
    Deck* deck;
    Player* dealer;
    std::vector<Player*> players;
    int numPlayers;
    int currentPlayerIndex;
public:
    BlackJack(int numPlayers);
    ~BlackJack();
    void startGame();
    void dealInitialCards();
    void playerTurn(Player* player);
    void dealerTurn();
    void determineWinner();
};

#endif
