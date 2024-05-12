#ifndef CARD_H
#define CARD_H

#include <iostream>
#include <string>

class Card {
private:
    std::string suit;
    std::string rank;
public:
    Card(std::string suit, std::string rank);
    void display();
    int getValue();
};

#endif
