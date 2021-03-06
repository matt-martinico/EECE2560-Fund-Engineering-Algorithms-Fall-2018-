// Matthew Martinico project 2a calmar
// this is the .cpp file that contains all function implementations
// the functions are part of the deck and card class

#include "pch.h"
#include "calmar-2a.h"
#include <iostream>
using namespace std;


ostream & operator<<(ostream & ostr, const card & c)
//this function is the overloaded operator for the card class
// it is passed a card
//it allows us to cout a card object by dispalying its suit and value
{
	ostr << "the cards Value is " << c.value << " the cards suit is " << c.suit << endl;
	return ostr;
}

ostream & operator<<(ostream & ostr, deck& d)
// this is the overloaded ostr operator for the deck class
// it is passed a deck
// it allows us to cout a deck object
// the object displays the value of the card and the suit of the card
{
	node<card> *current;
	current = d.firstCard;
	while (current != NULL)
	{
		ostr << current->nodeValue.getValue() << " " << current->nodeValue.getSuit() << endl;
		current = current->next;

	}
	return ostr;
}

void card::setValue(int CardValue)
// this function allows us to set the value of the card
// it is passed a card value
{
	value = CardValue;
}

void card::setSuit(string CardSuit)
//this function allows us to set the suit of the card
// it is passed a card suit
{
	suit = CardSuit;
}

int card::getValue()
// this functions al;lows us to get the value of the card
{
	return value;
}

string card::getSuit()
// this function allows us to get the suit of the card
{
	return suit;
}

card card::operator=(const card & rhs)
// this is an overloaded = operator for card class
// it is passed a card and returns a card
{
	value = rhs.value;
	suit = rhs.suit;

	return rhs;
}

card::card(const card & acard)
// this is a card copy constructor
{
	suit = acard.suit;
	value = acard.value;
}

deck::deck()
// this is the deck constructor
// our implementation adds nodes at the front
// please note after each addition of a node the firstcard pointer is updated
{
	int SizeOfDeck = 0;
	int numberOFDifferent = 13;
	int NUmberofSuites = 4;
	firstCard = NULL;

	for (int s = numberOFDifferent; s > 0; s--)
		// this for loop adds the Spades to the deck
	{
		card newSpade(s, "Spades");
		newNode = new node<card>(newSpade, firstCard);
		firstCard = newNode;
	}

	for (int h = numberOFDifferent; h > 0; h--)
		// this for loop adds the hearts to the deck
	{
		card newHeart(h, "Hearts");
		newNode = new node<card>(newHeart, firstCard);
		firstCard = newNode;


	}
	for (int d = numberOFDifferent; d > 0; d--)
		//this for loop adds the diamonds to the deck
	{
		card newDiamond(d, "diamonds");
		newNode = new node<card>(newDiamond, firstCard);
		firstCard = newNode;


	}
	for (int c = numberOFDifferent; c > 0; c--)
		// this loop adds the clubs to the deck
	{
		card newClub(c, "clubs");
		newNode = new node<card>(newClub, firstCard);
		firstCard = newNode;
	}


}
void deck::swap(node<card> *first, node<card> *second)
// this function takes two node pointers
// this function takes two nodes and swaps them
{
	if (first && second)
	{
		card temp = first->nodeValue;
		first->nodeValue = second->nodeValue;
		second->nodeValue = temp;
	}
}
deck* deck::copy()
// this function allows us to copy a deck

{
	deck *result = new deck();
	//dynamically allocates a new deck
	result->firstCard = nullptr;
	node<card> *current = this->firstCard;
	// creates new pointer node pointer and sets it equal to firstcard
	while (current)
	// while there is a current node
	{
	// copies nodes to new deck
		node<card> * newNode = new node<card>(current->nodeValue, result->firstCard);
		result->firstCard = newNode;
		current = current->next;
	}
	return result;
}
deck *deck::shuffle()
// this is the shuffle function
// 
{
	deck *result = this->copy();
	for (int i = 0; i < 500; ++i)
	{
		node<card> *f = nullptr;
		node<card> *s = nullptr;
		int firstIndex = rand() % this->total;
		int secondIndex = rand() % this->total;
		node<card> *c = result->firstCard;
		int counter = 0;
		while (c && c->next)
		{
			if (counter == firstIndex)
			{
				f = c;
			}
			else if (counter == secondIndex)
			{
				s = c;
				swap(f, s);
				break;
			}
			c = c->next;
			counter = counter +1;
		}
	}
	return result;
}

void deck::replace(card cardToReplace)
{

	node<card> *ptr = this->firstCard;
	while (ptr->next != NULL)
	{
		ptr = ptr->next;
	}
	newNode = new node<card>(cardToReplace, ptr);
}
card deck::deal()
//this is a deal function
// it returns a card
{
	if (this->firstCard == nullptr)
	// if there is no firstcard in the deck return a blank card
	{
		return card();
	}
	card result = this->firstCard->nodeValue;
	// makes a new card that is equal to the node at firstcard
	node<card> *next = this->firstCard->next;
	// create next pointer
	delete this->firstCard;
	// deletes top card
	this->firstCard = next;
	//moves firstcard pointer to next card
	return result;
	//returns the top card being dealt
}


deck::~deck()
// this is a deck destructor it will destory all the cards in a deck
// uses while loop to keep destorying until NULL
{
	node<card> *CurrDestroy = firstCard;
	node<card> * nextToDestroy = nullptr;
	while (CurrDestroy != NULL)
	{
		nextToDestroy = CurrDestroy->next;
		delete CurrDestroy;
		CurrDestroy = nextToDestroy;
	}
}






