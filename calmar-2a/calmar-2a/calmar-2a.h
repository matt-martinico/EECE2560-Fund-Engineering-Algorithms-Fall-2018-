// Matthew Maertnico project 2a calmar
// this is the header file for flip card
// it includes the given node class and the declarations for the card and deck class
#include "pch.h""
#include<iostream> 
#include<string>
#include<vector>
using namespace std;

// linked list node
template <typename T>
class node
{
public:
	T nodeValue;      // data held by the node
	node<T> *next;    // next node in the list

	// default constructor with no initial value
	node() : next(NULL)
	{}

	// constructor. initialize nodeValue and next
	node(const T& item, node<T> *nextNode = NULL) :
		nodeValue(item), next(nextNode)
	{}
};

class card
{
private:
	int value;
	string suit;
public:
	card(int v = 0, string s = " ")
	{
		value = v;
		suit = s;
	}
	void setValue(int CardValue);
	void setSuit(string CardSuit);
	int getValue();
	string getSuit();
	friend ostream & operator<<(ostream & ostr, const card & c);
	card operator= (const card& rhs);
	card(const card& acard);

};

class deck
{
private:
	node<card> *firstCard;
	node<card> *newNode;
	int numberOFDifferent = 13;
	int numberOfSuites = 4;
	int total = numberOFDifferent * numberOfSuites;
	void swap(node<card> *first, node<card> *second);
	
	


public:
	deck();
	friend ostream & operator<<(ostream & ostr, deck &d);
	~deck();
	card deal();
	void replace(card cardToReplace);
	deck *shuffle();
	deck *copy();
};
