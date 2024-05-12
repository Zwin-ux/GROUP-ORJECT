// Card.h
#ifndef CARD_H
#define CARD_H

class Card {
public:
    enum Suit {HEARTS, DIAMONDS, CLUBS, SPADES};
    enum Rank {ACE = 1, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING};

    Card(Suit s, Rank r);

    int getValue() const;
    void display() const;

private:
    Suit suit;
    Rank rank;
};

#endif // CARD_H
