#include "BlackJack.h"
#include <iostream>

int main() {
    int numPlayers;
    std::cout << "Enter number of players (2-4): ";
    std::cin >> numPlayers;

    if (numPlayers < 2 || numPlayers > 4) {
        std::cerr << "Invalid number of players!" << std::endl;
        return 1;
    }

    Blackjack game(numPlayers);
    game.play();

    return 0;
}
