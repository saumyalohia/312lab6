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

Deck::Deck() {
    unsigned int n = 52;
    vector<Card> deck(n);

    for (int i = 0; i < n; i++) {
        for (int suit = 0; suit < 4; suit++) {
            for (int rank = 1; rank < 14; rank++) {
                deck[i] = Card(rank, Card::Suit(suit));
            }
        }
    }
}

//void Deck::shuffle() {}   // shuffle the deck, all 52 cards present
//Card Deck::dealCard() {
//    return Card
//}   // get a card, after 52 are dealt, fail

//int Deck::size() const {
//
//}
