//
// Created by Saumya Lohia on 11/2/18.
//


#include <iostream>
#include <string>
#include <cstdlib>
#include "card.h"
#include <stdio.h>
#include <stdlib.h>
using namespace std;

Card::Card() {
    myRank = 1;
    mySuit = spades;
}

Card::Card(int rank, Card::Suit s) {
    myRank = rank;
    mySuit = s;
}


string Card::toString() const {
    string blah = "a";
    return blah;
}


bool Card::sameSuitAs(const Card &c) const {
    return true;
}


int  Card::getRank() const {
    return myRank;
}


string Card::suitString(Suit s) const {
    string suit;
    switch (s) {
        case spades:
            suit = 's';
            break;
        case clubs:
            suit = 'c';
            break;
        case diamonds:
            suit = 'd';
            break;
        case hearts:
            suit = 'h';
            break;
    }
    return suit;
}


string Card::rankString(int r) const {
    string rank;
    switch (r) {
        case 1:
            rank = 'A';
            break;
        case 11:
            rank = 'J';
            break;
        case 12:
            rank = 'Q';
            break;
        case 13:
            rank = 'K';
            break;
        default:
            rank = to_string(r);
    }
    return rank;
}


bool Card::operator == (const Card& rhs) const {
    return true;
}


bool Card::operator != (const Card& rhs) const {
    return true;
}


//ostream& Card::operator << (ostream& out, const Card& c) {}
