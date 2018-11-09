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
#include <ctime>

using namespace std;

Deck::Deck()
{
    for (int suit = 0; suit < 4; suit++) {
        for (int rank = 0; rank < 13; rank++) {
            myCards[suit*13+rank] = Card(rank+1, Card::Suit(suit));
            //cout << myCards[suit*13+rank];
        }
    }

    myIndex = 0;
}


void Deck::swapCards(int a, int b)
{
    // Swap cards at indecies a and b
    Card temp = this->myCards[a];
    this->myCards[a] = this->myCards[b];
    this->myCards[b] = temp;
}

void Deck::shuffle()
{
    unsigned int currentTime = (unsigned)time(0);
    //cout << "current Time" << currentTime << endl;
    //unsigned int currentTime = 1;
    srand(currentTime);

    for(int i = 0; i < 2*size(); i++)
    {
        int cardInd1 = (rand() % size());
        int cardInd2 = (rand() % size());
        swapCards(cardInd1, cardInd2);
    }
}


// get a card, after 52 are dealt, fail
Card Deck::dealCard()
{
    Card card;
    if(myIndex != SIZE)
    {
        card = myCards[myIndex];
        myIndex++;
    }
    else
    {
        cout << "No more cards!" << endl;
    }

    return card;
}


int Deck::size() const
{
    return SIZE - myIndex;
}
