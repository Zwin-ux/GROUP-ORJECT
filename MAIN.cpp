#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>
using namespace std;

class Card {
public:
    enum Suit {HEARTS, DIAMONDS, CLUBS, SPADES};
    enum Rank {ACE = 1, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING};
//MAKE IT POSSIBLY SHOW IN THE TERMINAL
    Card(Suit s, Rank r) : suit(s), rank(r) {}

    int getValue() const {
        if (rank >= TWO && rank <= TEN)
            return rank;
        else if (rank >= JACK && rank <= KING)
            return 10;
        else // ACE
            return 11; // For simplicity, we'll treat Ace as 11
    }

    void display() const {
        std::cout << rank << " of ";
        switch (suit) {
            case HEARTS: std::cout << "Hearts"; break;
            case DIAMONDS: std::cout << "Diamonds"; break;
            case CLUBS: std::cout << "Clubs"; break;
            case SPADES: std::cout << "Spades"; break;
        }
    }

private:
    Suit suit;
    Rank rank;
};

class Deck {
public:
    Deck() {
        for (int s = Card::HEARTS; s <= Card::SPADES; ++s) {
            for (int r = Card::ACE; r <= Card::KING; ++r) {
                cards.push_back(Card(static_cast<Card::Suit>(s), static_cast<Card::Rank>(r)));
            }
        }
        shuffle();
    }

    void shuffle() {
        //std::random_shuffle(cards.begin(), cards.end());
    }

    Card dealCard() {
        Card card = cards.back();
        cards.pop_back();
        return card;
    }

private:
    std::vector<Card> cards;
};

class Player {
public:
    Player() : totalScore(0) {}

    void addCard(const Card& card) {
        hand.push_back(card);
        totalScore += card.getValue();
    }

    void displayHand() const {
        for (const Card& card : hand) {
            card.display();
            std::cout << std::endl;
        }
        std::cout << "Total Score: " << totalScore << std::endl;
    }

    int getTotalScore() const {
        return totalScore;
    }

protected:
    std::vector<Card> hand;
    int totalScore;
};

class BlackjackGame {
public:
    BlackjackGame(int numPlayers) : numPlayers(numPlayers) {
        for (int i = 0; i < numPlayers; ++i) {
            players.push_back(Player());
        }
    }

    void play() {
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

private:
    int numPlayers;
    std::vector<Player> players;
};

int main() {
    int numPlayers;
    std::cout << "Enter number of players (2-4): ";
    std::cin >> numPlayers;

    if (numPlayers < 2 || numPlayers > 4) {
        std::cerr << "Invalid number of players!" << std::endl;
        return 1;
    }

    BlackjackGame game(numPlayers);
    game.play();

    return 0;
}
