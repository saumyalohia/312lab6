// FILE: card_demo.cpp
// This is a small demonstration program showing how the Card and Deck classes are used.
#include <iostream>    // Provides cout and cin
#include <cstdlib>     // Provides EXIT_SUCCESS
#include <vector>
#include "card.h"
#include "player.h"
#include "deck.h"

using namespace std;


// PROTOTYPES for functions used by this demonstration program:
void dealHand(Deck &d, Player &p, int numCards);




int main( )
{
    //FOR DEBUGGING CARD
    //Card a;
    Card::Suit c = Card::clubs;
    Card::Suit s = Card::spades;
    Card a(11, s);
    Card b(1, s);
    Card e(11, c);
    cout << a.toString() << endl;
    cout << b.toString() << endl;
    cout << e.toString() << endl;

    bool result = a.sameSuitAs(e);
    cout << result << endl;


    bool blah = (a == e);
    cout << blah << endl;

    cout << a << endl;

    //FOR DEBUGGING DECK
    Deck d;  //create a deck of cards

    cout << d.size() << endl;

    //cout << d.dealCard() << endl;
    //cout << d.dealCard() << endl;


    //DEBUGGING FOR PLAYERS

//    int numCards = 5;
//    Player p1("Joe");
//    Player p2("Jane");
//    dealHand(d, p1, numCards);
//    dealHand(d, p2, numCards);
//
//    cout << p1.getName() <<" has : " << p1.showHand() << endl;
//    cout << p2.getName() <<" has : " << p2.showHand() << endl;
//
//    return EXIT_SUCCESS;
}


//
//void dealHand(Deck &d, Player &p, int numCards)
//{
//    for (int i=0; i < numCards; i++)
//        p.addCard(d.dealCard());
//}



