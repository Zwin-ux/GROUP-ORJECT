#include <iostream>
#include "BlackJack.h"

int main() {
    std::cout << "Welcome to Blackjack!" << std::endl;

    // Get the number of players from the user
    int numPlayers;
    std::cout << "Enter the number of players (including yourself): ";
    std::cin >> numPlayers;

    // Create an instance of the Blackjack game
    BlackJack game(numPlayers);

    // Start the game
    game.startGame();

    return 0;
}
