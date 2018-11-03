// FILE: deck.h
// written by Owen Astrachan and Roger Priebe
// this class respresents a deck of cards
// When a Deck is constructed, it contains 52 cards
// in a "regular" order (aces, twos, threes, ... , kings)
//
// Shuffling a deck makes it consist of 52 cards in a random order
//
// dealCard() returns a card from the deck and decreases the
// number of cards in the deck (returned by size())
// The idea is that after shuffling, calling dealCard() 52 times
// returns each card in the deck after shuffling.
//
// Calling shuffle again replenishes the deck with 52 cards.

#include "deck.h"
#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

Deck::Deck()
{
    vector<Card> deck(SIZE);
//    for (int i = 0; i < SIZE; i++) {
//        for (int suit = 0; suit < 4; suit++) {
//            for (int rank = 1; rank < 14; rank++) {
//                deck[i] = Card(rank, Card::Suit(suit));
//                cout << deck[i];
//            }
//        }
//    }

    // ^prints out 52 decks worth of cards XD

    for (int suit = 0; suit < 4; suit++) {
        for (int rank = 1; rank < 14; rank++) {
            deck[suit+rank] = Card(rank, Card::Suit(suit));
            //cout << deck[suit+rank];
        }
    }

    myIndex = 0;
}


void Deck::shuffle() {

}


//Card Deck::dealCard()
//{
//    Card card;
//    return card;
//}   // get a card, after 52 are dealt, fail


int Deck::size() const
{
    int count = 0;
    int i = myIndex;
    while(i<SIZE)
    {
        if(this->myCards[i].getRank() != 0){ count++; }
        i++;
    }

    return count;
}
