// Johnathon Heidari
// Class: (CECS 282-05)
// Project: (Prog 1 - Solitare Prime)
// Due Date: (02/11/20)

#include <iostream>
#include <stdio.h>
#include <string>
#include "Card.hpp"
#include "Deck.hpp"
using namespace std;

    // contrustor
    Card::Card(){}
    Card::Card(char r, char s){
         mRank = r;
         mSuit = s;
    }
    
    // accessor (getter)
     int Card::getValue(){
        switch(mRank) {
            case '2':
                return 2;
            case '3':
                return 3;
            case '4':
                return 4;
            case '5':
                return 5;
            case '6':
                return 6;
            case '7':
                return 7;
            case '8':
                return 8;
            case '9':
                return 9;
            case 'A':
                return 1;
            // Jack, King, and Queen will be 10
            case '0':
                return 10;
            case 'K':
                return 10;
            case 'Q':
                return 10;
            case 'J':
                return 10;
            // invalid option
            default:
                return -1;
        }
     };

    // mutator (setter)
    void Card:: setCard(char r, char s){
        mRank = r;
        mSuit = s;
    };

    // other methods
    void Card::showCard(){
        string showcard;
        //cout<<mRank<<" "<<mSuit<<endl;
        if (mRank == 'A') {
            showcard = "A";
        }
        else if (mRank == '2'){
            showcard = "2";
        }
        else if (mRank == '3'){
            showcard = "3";
        }
        else if (mRank == '4'){
            showcard = "4";
        }
        else if (mRank == '5'){
            showcard = "5";
        }
        else if (mRank == '6'){
            showcard = "6";
        }
        else if (mRank == '7'){
            showcard = "7";
        }
        else if (mRank == '8'){
            showcard = "8";
        }
        else if (mRank == '9'){
            showcard = "9";
        }
        else if (mRank == '0'){
            showcard = "10";
        }
        else if (mRank == 'Q'){
            showcard = "Q";
        }
        else if (mRank == 'K'){
            showcard = "K";
        }
        else if (mRank == 'J'){
            showcard = "J";
        }
        
        if (mSuit == 'S') {
            showcard += "S";
        }
        else if (mSuit == 'H'){
            showcard += "H";
        }
        else if (mSuit == 'D'){
            showcard += "D";
        }
        else if (mSuit == 'C'){
            showcard += "C";
        }
        cout<<showcard<<endl;
    };
    
string Card:: getCard(){
    string showcard;
    if(mRank == '0'){
        //TEN
        showcard += "10";
    }
    else{
        showcard += mRank;
    }
    return showcard + mSuit;
}

