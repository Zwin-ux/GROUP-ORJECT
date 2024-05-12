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
    // Shuffle the deck
    deck->shuffle();
    
    // Deal initial cards to each player including the dealer
    dealInitialCards();
    
    // Players take turns
    for (int i = 0; i < numPlayers; ++i) {
        playerTurn(players[i]);
    }
    
    // Dealer's turn
    dealerTurn();
    
    // Determine the winner
    determineWinner();
}

void BlackJack::dealInitialCards() {
    // Deal 2 cards to each player including the dealer
    for (int i = 0; i < 2; ++i) {
        for (auto player : players) {
            player->addToHand(deck->dealCard());
        }
        dealer->addToHand(deck->dealCard());
    }
}

void BlackJack::playerTurn(Player* player) {
    std::cout << player->getName() << "'s turn:" << std::endl;
    bool hasPokerMove = true;

    while (true) {
        player->displayHand();
        int choice;
        std::cout << "Choose your move:" << std::endl;
        std::cout << "1. Hit" << std::endl;
        std::cout << "2. Stand" << std::endl;
        std::cout << "3. Surrender" << std::endl; // Added option for surrender
        std::cin >> choice;

        switch (choice) {
            case 1:
                player->addToHand(deck->dealCard());
                break;
            case 2:
                return; // Player chooses to stand
            case 3:
                // Player chooses to surrender
                std::cout << player->getName() << " surrenders!" << std::endl;
                // Forfeit half of the bet and end the round
                // Implement logic to handle surrender here
                return;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
        }

        // Check if the player's hand total exceeds 21
        if (player->calculateTotal() > 21) {
            std::cout << player->getName() << " busts!" << std::endl;
            return;
        }

        // Check if the player has made a poker move
        if (hasPokerMove) {
            std::cout << player->getName() << " made a poker move!" << std::endl;
            return;
        }
    }
}

void BlackJack::dealerTurn() {
    std::cout << "Dealer's turn:" << std::endl;
    dealer->displayHand();

    while (dealer->calculateTotal() < 17) {
        dealer->addToHand(deck->dealCard());
        dealer->displayHand();
    }

    if (dealer->calculateTotal() > 21) {
        std::cout << "Dealer busts!" << std::endl;
    }
}

void BlackJack::determineWinner() {
    int dealerTotal = dealer->calculateTotal();

    for (auto player : players) {
        int playerTotal = player->calculateTotal();

        if (playerTotal > 21) {
            std::cout << player->getName() << " busts! Dealer wins." << std::endl;
        } else if (dealerTotal > 21 || playerTotal > dealerTotal) {
            std::cout << player->getName() << " wins!" << std::endl;
        } else if (playerTotal < dealerTotal) {
            std::cout << "Dealer wins." << std::endl;
        } else {
            std::cout << "It's a tie!" << std::endl;
        }
    }
}
