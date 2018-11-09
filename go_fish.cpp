
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
    //FOR DEBUGGING DECK
    Deck d;  //create a deck of cards
    d.shuffle();
    //DEBUGGING FOR PLAYERS

    int numCards = 5;
    Player p1("Joe");
    Player p2("Jane");
    dealHand(d, p1, numCards);
    dealHand(d, p2, numCards);

    cout << p1.getName() <<" has : " << p1.showHand() << endl;
    cout << p2.getName() <<" has : " << p2.showHand() << endl;

    Card c1 = Card();
    Card c2 = Card();

    while (p1.checkHandForPair(c1, c2)) {
        p1.bookCards(c1, c2);
        p1.removeCardFromHand(c1);
        p1.removeCardFromHand(c2);
    }

    while (p2.checkHandForPair(c1, c2)) {
        p2.bookCards(c1, c2);
        p2.removeCardFromHand(c1);
        p2.removeCardFromHand(c2);
    }

    cout << p1.getName() <<" has : " << p1.showHand() << endl;
    cout << p2.getName() <<" has : " << p2.showHand() << endl;

    //while ((p1.getBookSize() < 14) || (p2.getBookSize() <14)) {
        if (p1.getHandSize() > 0) {
            cout << p1.getName() << "asks: Do you have a " << p1.chooseCardFromHand() << "?" << endl;

        }
        //check if p1 has cards in their hand
            //skip directly to draw card if not
        //p1 chooses a card from their hand
        //p1 asks p2 if they have that card

        //p2 checks their hand for that card
        //if true, then remove card from p2's hand
        //add to p1's hand
        //check for books
        //if false, print go fish
            //check deck size
            //p1 picks up a card from the deck
            //check for books
        //p2's turn

    //}

    //FOR DEBUGGING

    return EXIT_SUCCESS;
}



void dealHand(Deck &d, Player &p, int numCards)
{
    for (int i=0; i < numCards; i++)
        p.addCard(d.dealCard());
}



