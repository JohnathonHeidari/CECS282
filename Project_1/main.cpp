// Johnathon Heidari
// Class: (CECS 282-05)
// Project: (Prog 1 - Solitare Prime)
// Due Date: (02/11/20)

#include "Card.hpp"
#include <stdio.h>
#include "Deck.hpp"
#include <iostream>
using namespace std;

//Header methods
int menu();
bool isPrime(int);

int main() {
    // Declaration variables
    int x = 0;
    Deck myDeck;
    
    while(x!=5){
        cout<<endl;
        x = menu();
        if(x == 1){
            myDeck = Deck();
            cout<<"New Deck Created"<<endl;
        }
        else if(x == 2){
            myDeck.showDeck();
        }
        else if (x == 3){
            cout<<"Successfully Shuffle"<<endl;
            myDeck.shuffle();
        }
        else if (x == 4){
            int pile = 0;
            int numofpiles = 0;
    
            while(myDeck.cardsLeft() != 0){
                Card c1 = myDeck.deal();
                pile = c1.getValue();
                cout<<c1.getCard()<<", ";
                
                    while(!isPrime(pile) && myDeck.cardsLeft() != 0){
                        c1 = myDeck.deal();
                        cout<<c1.getCard()<<", ";
                        pile += c1.getValue();
                    }
                
                if(isPrime(pile)){
                    cout<<" Prime: "<<pile<<endl;
                    numofpiles += 1;
                }
            }
            if(isPrime(pile)){
                cout<<"Winner in "<<numofpiles<<" piles!"<<endl;
            }
            else if (pile == 0)
                cout<<"Error: Empty cards"<<endl;
            else{
                cout<<"Loser"<<endl;
            }
        }
        else if (x == 5){
            cout<<"Thanks for playing!"<<endl;
            break;
        }
        else{
            cout<<"Invalid Opition"<<endl;
        }
        
    }
    return 0;
}


bool isPrime(int pile){
    if (pile == 0 || pile == 1) {
        return false;
    }
    int i = 2;
    while (i < pile) {
        if (pile%i == 0){
               return false;
        }
    i++;
    }
    return true;
};


int menu(){
    cout<< "Welcome to Solitaire Prime!"<<endl;
    cout<< "1) New Deck"<<endl;
    cout<< "2) Display Deck"<<endl;
    cout<< "3) Shuffle Deck"<<endl;
    cout<< "4) Play Solitaire Prime!"<<endl;
    cout<< "5) Exit"<<endl;
    int x;
    cout << "Selection option: "; // Type a number and press enter
    cin>>x;
    cout<<endl;
    return x;
}
