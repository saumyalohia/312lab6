//
// Created by Saumya Lohia on 11/2/18.
//


#include <iostream>
#include <string>
#include "card.h"
using namespace std;

Card::Card(){}

Card::Card(int rank, Card::Suit s) {}


string Card::toString() const {}


bool Card::sameSuitAs(const Card &c) const {}


int  Card::getRank() const {}


string Card::suitString(Suit s) const {}


string Card::rankString(int r) const {}


bool Card::operator == (const Card& rhs) const {}


bool Card::operator != (const Card& rhs) const {}


//ostream& Card::operator << (ostream& out, const Card& c) {}
