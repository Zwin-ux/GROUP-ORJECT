#include "BlackJack.h"
#include <iostream>

BlackJack::BlackJack(int numPlayers) {
    deck = new Deck();
    dealer = new Player("Dealer");
    this->numPlayers = numPlayers;
    currentPlayerIndex = 0;
}

BlackJack::~BlackJack() {
    delete deck;
    delete dealer;
    for (auto player : players) {
        delete player;
    }
}

void BlackJack::startGame() {
    // Implement the startGame function
}

void BlackJack::dealInitialCards() {
    // Implement the dealInitialCards function
}

void BlackJack::playerTurn(Player* player) {
    // Implement the playerTurn function
}

void BlackJack::dealerTurn() {
    // Implement the dealerTurn function
}

void BlackJack::determineWinner() {
    // Implement the determineWinner function
}
