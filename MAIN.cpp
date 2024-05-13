#include <iostream>
#include "BlackJack.h"

int main() {
    std::cout << "Welcome to Blackjack 340!" << std::endl;

    // Get the number of players from the user
    int numPlayers;
    // Create an instance of the Blackjack game
    BlackJack game(numPlayers);

    // Start the game
    game.startGame();


    return 0;
}
