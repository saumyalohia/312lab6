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

Card::Card(){}

Card::Card(int rank, Card::Suit s) {}


string Card::toString() const {}


bool Card::sameSuitAs(const Card &c) const {}


int  Card::getRank() const {
    return myRank;
}


string Card::suitString(Suit s) const {}


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


bool Card::operator == (const Card& rhs) const {}


bool Card::operator != (const Card& rhs) const {}


//ostream& Card::operator << (ostream& out, const Card& c) {}
