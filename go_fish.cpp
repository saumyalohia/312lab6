
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
    //check if p1 has cards in their hand
    //skip directly to draw card if not
        Card card1 = p1.chooseCardFromHand();
        if (p1.getHandSize() > 0) {
            //p1 chooses a card from their hand
            //p1 asks p2 if they have that card
            cout << p1.getName() << "asks: Do you have a " << card1.rankString(card1.getRank()) << "?" << endl;
        } else {
            p1.addCard(d.dealCard());
            cout << p1.getName() <<" has : " << p1.showHand() << endl;
        }

        //p2 checks their hand for that card
        if (p2.sameRankInHand(card1)) {
            //if true, then remove card from p2's hand
            p2.removeCardFromHand(card1);
            //add to p1's hand
            p1.addCard(card1);
            //check for books
            if (p1.checkHandForPair(c1, c2)) {
                //check deck size
                if (d.size() > 0) {
                    //p1 picks up a card from the deck
                    p1.addCard(d.dealCard());
                    //check for books
                    if (p1.checkHandForPair(c1, c2)) {
                        p1.bookCards(c1, c2);
                    }
                }
            }
            cout << p1.getName() <<" has : " << p1.showHand() << endl;
            cout << p2.getName() <<" has : " << p2.showHand() << endl;
            cout << p1.getName() <<" has books: " << p1.showBooks() << endl;
            cout << p2.getName() <<" has books: " << p2.showBooks() << endl;
        } else {
                //if false, print go fish
            cout << p2.getName() << " says: Go Fish" << endl;
        }


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



