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

   do {
        std::cout << "Enter the number of players (maximum 4): ";
        std::cin >> numPlayers;
        if (numPlayers <= 0 || numPlayers > 4) {
            std::cout << "Invalid number of players. Please enter a number between 1 and 4.\n";
        }
    } while (numPlayers <= 0 || numPlayers > 4);

    // Create players
    for (int i = 0; i < numPlayers; ++i) {
        std::string playerName;
        std::cout << "Enter name for Player " << i + 1 << ": ";
        std::cin >> playerName;
        players.push_back(new Player(playerName));
    }

    // Deal initial cards
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


void BlackJack::dealInitialCards() {
  
}

void BlackJack::playerTurn(Player* player) {
    
}

void BlackJack::dealerTurn() {
   
}

void BlackJack::determineWinner() {
   
}
