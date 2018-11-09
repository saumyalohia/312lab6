//
// Created by Saumya Lohia on 11/2/18.
//


#include <iostream>
#include <string>
#include <cstdlib>
#include "card.h"
#include <cstdio>
#include <sstream>
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
    string r; string s;
    r = rankString(myRank);
    s = suitString(mySuit);
    return r+s;
}


bool Card::sameSuitAs(const Card &c) const {
    return (mySuit == c.mySuit);
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
    std::string rank;
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
            rank = std::to_string(r);
    }
    return rank;
}


bool Card::operator == (const Card& rhs) const {
    return ((myRank == rhs.myRank) && (mySuit == rhs.mySuit));
}


bool Card::operator != (const Card& rhs) const {
    return !((myRank == rhs.myRank) && (mySuit == rhs.mySuit));
}


//ostream& Card::operator << (ostream& out, const Card& c)
ostream& operator << (ostream& out, const Card& c)
{
    out << c.toString() << endl;
    return out;
}
