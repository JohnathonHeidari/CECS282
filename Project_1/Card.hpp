// Johnathon Heidari
// Class: (CECS 282-05)
// Project: (Prog 1 - Solitare Prime)
// Due Date: (02/11/20)

#ifndef CARD_HPP
#define CARD_HPP

#include <stdio.h>
#include "Card.hpp"
#include <string>

class Card{
    // instance variable
    private:
        char mRank;
        char mSuit;
    public:
        // contrustor
        Card(char,char);
        Card();
        // accessor (getter)
        int getValue();
        // mutator (setter)
        void setCard(char,char);
        // other methoed
        void showCard();
    std::string getCard();
    };


#endif /* CARD_HPP */
