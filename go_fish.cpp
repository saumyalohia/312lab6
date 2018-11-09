
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

    int numCards = 7;
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

    cout << "--------START GAME---------" << endl;

    while (((p1.getBookSize() <= 13) && (p2.getBookSize() <= 13)) || ((p1.getBookSize()+p2.getBookSize()) == 26)) {
    //check if p1 has cards in their hand
    //skip directly to draw card if not
    //****************JOE'S TURN

        Card card1;
        if (p1.getHandSize() > 0) {
            card1 = p1.chooseCardFromHand();
            //p1 chooses a card from their hand
            //p1 asks p2 if they have that card
            cout << p1.getName() << " asks: Do you have a " << card1.rankString(card1.getRank()) << "?" << endl;
        } else {
            if (d.size() > 0) {
                p1.addCard(d.dealCard());
                if (p1.checkHandForPair(c1, c2)) {
                    p1.bookCards(c1, c2);
                }
            }
            cout << p1.getName() <<" has : " << p1.showHand() << endl;
            cout << p1.getName() <<" has : " << p1.showHand() << endl;
        }

        //p2 checks their hand for that card
        if (p2.sameRankInHand(card1)) {
            cout << p2.getName() << " has " << card1.rankString(card1.getRank()) << endl;
            //if true, then remove card from p2's hand
            //p2.removeCardFromHand(card1);
            //add to p1's hand
            p1.addCard(p2.removeCardFromHand(card1));
            //check for books
            if (p1.checkHandForPair(c1, c2)) {
                    //check for books
                if (p1.checkHandForPair(c1, c2)) {
                    p1.bookCards(c1, c2);
                }
            }
            cout << p1.getName() <<" has : " << p1.showHand() << endl;
            cout << p2.getName() <<" has : " << p2.showHand() << endl;
            cout << p1.getName() <<" has books: " << p1.showBooks() << endl;
            cout << p2.getName() <<" has books: " << p2.showBooks() << endl;
            cout << p1.getName() <<"'s book size is: " << p1.getBookSize() << endl;
            cout << p2.getName() <<"'s book size is: " << p2.getBookSize() << endl << endl;
        } else {
            //if false, print go fish
            cout << p2.getName() << " says: Go Fish" << endl;
            if (d.size() > 0) {
                p1.addCard(d.dealCard());
                if (p1.checkHandForPair(c1, c2)) {
                    p1.bookCards(c1, c2);
                }
            }
            cout << p1.getName() <<" has : " << p1.showHand() << endl;
            cout << p2.getName() <<" has : " << p2.showHand() << endl;
            cout << p1.getName() <<" has books: " << p1.showBooks() << endl;
            cout << p2.getName() <<" has books: " << p2.showBooks() << endl;
            cout << p1.getName() <<"'s book size is: " << p1.getBookSize() << endl;
            cout << p2.getName() <<"'s book size is: " << p2.getBookSize() << endl << endl;
        }


        //**************JANE'S TURN

        Card card2;
        if (p2.getHandSize() > 0) {
            card2 = p2.chooseCardFromHand();
            cout << p2.getName() << " asks: Do you have a " << card2.rankString(card2.getRank()) << "?" << endl;
        } else {
            if (d.size() > 0) {
                p2.addCard(d.dealCard());
                if (p2.checkHandForPair(c1, c2)) {
                    p2.bookCards(c1, c2);
                }
            }
            cout << p2.getName() <<" has : " << p2.showHand() << endl;
            cout << p2.getName() <<" has : " << p2.showHand() << endl;
        }

        if (p1.sameRankInHand(card2)) {
            cout << p1.getName() << " has " << card2.rankString(card2.getRank()) << endl;
            p2.addCard(p1.removeCardFromHand(card2));
            //check for books
            if (p2.checkHandForPair(c1, c2)) {
                //check for books
                if (p2.checkHandForPair(c1, c2)) {
                    p2.bookCards(c1, c2);
                }
            }
            cout << p1.getName() <<" has : " << p1.showHand() << endl;
            cout << p2.getName() <<" has : " << p2.showHand() << endl;
            cout << p1.getName() <<" has books: " << p1.showBooks() << endl;
            cout << p2.getName() <<" has books: " << p2.showBooks() << endl;
            cout << p1.getName() <<"'s book size is: " << p1.getBookSize() << endl;
            cout << p2.getName() <<"'s book size is: " << p2.getBookSize() << endl << endl;
        } else {
            //if false, print go fish
            cout << p1.getName() << " says: Go Fish" << endl;
            if (d.size() > 0) {
                p2.addCard(d.dealCard());
                if (p2.checkHandForPair(c1, c2)) {
                    p2.bookCards(c1, c2);
                }
            }
            cout << p1.getName() <<" has : " << p1.showHand() << endl;
            cout << p2.getName() <<" has : " << p2.showHand() << endl;
            cout << p1.getName() <<" has books: " << p1.showBooks() << endl;
            cout << p2.getName() <<" has books: " << p2.showBooks() << endl;
            cout << p1.getName() <<"'s book size is: " << p1.getBookSize() << endl;
            cout << p2.getName() <<"'s book size is: " << p2.getBookSize() << endl << endl;
        }

    }

    cout << "--------------END GAME-------------" << endl;



    return EXIT_SUCCESS;
}



void dealHand(Deck &d, Player &p, int numCards)
{
    for (int i=0; i < numCards; i++)
        p.addCard(d.dealCard());
}



