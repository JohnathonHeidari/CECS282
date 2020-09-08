// Johnathon Heidari
// Class: (CECS 282-05)
// Project: (Prog 1 - Solitare Prime)
// Due Date: (02/11/20)

#ifndef DECK_HPP
#define DECK_HPP
#include "Deck.hpp"
#include "Card.hpp"
#include <iostream>
#include <stdio.h>
class Deck{
private:
    Card storage[52];
    int top = 0;
public:
    // contrustor
    Deck();
    // other methoed
    void refreshDeck();
    Card deal();
    void shuffle();
    int cardsLeft();
    void showDeck();
};
#endif /* DECK_HPP */
