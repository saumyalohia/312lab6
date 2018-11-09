//
// Created by Saumya Lohia on 11/2/18.
//

// FILE:  player.h
// written by Roger Priebe
// 1/22/08 (revised 9/2/08)
// This class represents a player in a card game that takes "tricks"
// The "Books" represent a container for holding tricks

#include <iostream>
#include <string>
#include <vector>
#include "card.h"
#include "player.h"

using namespace std;

Player::Player()
{
    myName = " ";
}


void Player::addCard(Card c)
{
    myHand.push_back(c);
}


void Player::bookCards(Card c1, Card c2)
{
    myBook.push_back(c1);
    myBook.push_back(c2);

    removeCardFromHand(c1);
    removeCardFromHand(c2);
}

//OPTIONAL
// comment out if you decide to not use it
//this function will check a players hand for a pair.
//If a pair is found, it returns true and populates the two variables with the cards tha make the pair.

//bool Player::checkHandForBook(Card &c1, Card &c2)
//{
//
//}

//OPTIONAL
// comment out if you decide to not use it
//Does the player have a card with the same rank as c in her hand?
//bool Player::rankInHand(Card c) const
//{
//
//}


//uses some strategy to choose one card from the player's
//hand so they can say "Do you have a 4?"
Card Player::chooseCardFromHand() const
{
    //unsigned int currentTime = (unsigned)time(0);
    unsigned int currentTime = 8;
    srand(currentTime);

    int card = (rand() % myHand.size());
    return myHand[card];
}


//Does the player have the card c in her hand?
bool Player::cardInHand(Card c) const
{
    int myHandSize = getHandSize();

    for(int i=0; i<myHandSize; i++)
    {
        if(myHand[i] == c)
        {
            return true;
        }
    }
    return false;
}



//Remove the card c from the hand and return it to the caller
Card Player::removeCardFromHand(Card c)
{
    vector<Card>::iterator iter;
    for(iter = myHand.begin(); iter != myHand.end(); iter++)
    {
        if(*iter == c)
        {
            myHand.erase(iter);
            return c;
        }
    }

}



string Player::showHand() const
{
    int myHandSize = myHand.size();

    string str;

    for(int i=0; i<myHandSize; i++)
    {
        str += " " + myHand[i].toString();
    }

    return str;
}


string Player::showBooks() const {
    string str;

    int myBookSize = myBook.size();

    for (int i = 0; i<myBookSize; i++)
    {
        str += myBook[i].toString() + " ";
    }
    return str;
}



int Player::getHandSize() const
{
    return myHand.size();
}


int Player::getBookSize() const
{
    return myBook.size() / 2;
}

//OPTIONAL
// comment out if you decide to not use it
//this function will check a players hand for a pair.
//If a pair is found, it returns true and populates the two variables with the cards tha make the pair.

bool Player::checkHandForPair(Card &c1, Card &c2)
{
    int myHandSize = myHand.size();

    for (int i = 0; i < myHandSize-1; i++)
    {
        for (int j = i+1; j < myHandSize; j++)
        {
            if (myHand[i].getRank() == myHand[j].getRank())
            {
                return true;
            }
        }
    }
    return false;
}


//OPTIONAL
// comment out if you decide to not use it
//Does the player have a card with the same rank as c in her hand?
//e.g. will return true if the player has a 7d and the parameter is 7c

bool Player::sameRankInHand(Card c) const
{
    int myHandSize = myHand.size();

    for (int i = 0; i < myHandSize; i++)
    {
        if (myHand[i].getRank() == c.getRank())
        {
            return true;
        }
    }
    return false;
}