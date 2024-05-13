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
    std::cout << player->getName() << "'s turn:" << std::endl;
    while (true) {
        player->displayHand();
        char choice;
        std::cout << "Choose your move (H for Hit, S for Stand): ";
        std::cin >> choice;

        switch (choice) {
            case 'H':
            case 'h':
                player->addToHand(deck->dealCard());
                break;
            case 'S':
            case 's':
                return; // Player chooses to stand
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
        }

        // Check if the player's hand total exceeds 21
        if (player->calculateTotal() > 21) {
            std::cout << player->getName() << " busts!" << std::endl;
            return;
        }
    }
}

    
}

void BlackJack::dealerTurn() {
    // Dealer's turn: Hit until total is at least 17
    while (dealer->calculateTotal() < 17) {
        dealer->addToHand(deck->dealCard());
    }
}

   
}

void BlackJack::determineWinner() {
    int dealerTotal = dealer->calculateTotal();

    std::cout << "Dealer's hand: ";
    dealer->displayHand();

    for (auto player : players) {
        std::cout << player->getName() << "'s hand: ";
        player->displayHand();
        int playerTotal = player->calculateTotal();

        if (playerTotal > 21) {
            std::cout << player->getName() << " busts!" << std::endl;
            continue;
        }

        if (dealerTotal > 21 || playerTotal > dealerTotal) {
            std::cout << player->getName() << " wins!" << std::endl;
        } else if (playerTotal < dealerTotal) {
            std::cout << player->getName() << " loses!" << std::endl;
        } else {
            std::cout << "It's a tie!" << std::endl;
        }
    }
}

   
}
