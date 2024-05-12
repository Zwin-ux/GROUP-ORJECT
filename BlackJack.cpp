#include "BlackJack.h"
#include <iostream>
#include "card.h"

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
    // Shuffle the deck
    deck->shuffle();

    // Create players and deal initial cards
    for (int i = 0; i < 4; ++i) { // Max number of players is set to 4
        if (i >= numPlayers) {
            break;
        }

        std::string playerName;
        std::cout << "Enter name for Player " << i + 1 << ": ";
        std::cin >> playerName;

        players.push_back(new Player(playerName));
    }
     if (numPlayers > 4) {
        std::cout << "Only 4 players can play. Adding more players will be ignored." << std::endl;
    } else {
        dealInitialCards();

        // Player turns
        for (int i = 0; i < numPlayers; ++i) {
            playerTurn(players[i]);
        }

        // Dealer's turn
        dealerTurn();

        // Determine the winner
        determineWinner();
    }
}


void BlackJack::dealInitialCards() {
  
}

void BlackJack::playerTurn(Player* player) {
    
}

void BlackJack::dealerTurn() {
   
}

void BlackJack::determineWinner() {
   
}
