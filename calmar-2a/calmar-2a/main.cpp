//Matthew Martinico
// this is the main file for flip card
// it includes the main fucntion
#include "pch.h"
#include"calmar-2a.h"
void playFlip()
{
	deck d1;
	deck d2;
	deck d3;
	cout << d1<<endl;
	//deck *firstShuffle;
	//deck *shuffleddeck = d1.shuffle();
	//deck secondShuffle;
	//deck thirdShuffle;
	cout << "please wait while the cards are being shuffled" << endl;
	deck *firstShuffle = d1.shuffle();
	d2 = *firstShuffle;
	//deck secondShuffle = firstShuffle.shuffle(firstShuffle);
	deck *secondShuffle = d2.shuffle();
	d3 = *secondShuffle;
	deck *thirdshuffle = d3.shuffle();


	//thirdShuffle = secondShuffle.shuffle(secondShuffle);
	//delete &firstShuffle;
	//delete &secondShuffle;
	cout << "the shuffled deck is"<< endl;
	//cout << thirdShuffle;
	cout << *thirdshuffle << endl << endl;
	cout << "please wait while you are dealt 24 cards" << endl;
	vector<int> cardsdealtVal;
	vector<string> carddealtSuit;
	for (int i = 0; i < 24; i++)
	{
		card dealt = thirdshuffle->deal();
		//card dealt = thirdShuffle.deal();
		// add the cards to a vector as they are dealt up to 24
		cardsdealtVal.push_back(dealt.getValue());
		carddealtSuit.push_back(dealt.getSuit());
		// with vector allow user to pick
	}
	cout << "your hand is" << endl;
	for (int z = 0; z < 24; z++)
	{
		cout << cardsdealtVal[z] << " of " << carddealtSuit[z] << endl;
	}
	//cout << "the remaining cards in the deck are" << thirdShuffle;
	cout << "the remaining cards in the deck are" << endl << *thirdshuffle;
	int x=0;
	int numberofpoints = 0;
	while (true)
	{

		cout << "please enter a number from 0-23 to pick a card" << endl;
		cout << " please enter the number 100 to end game" << endl;
		cin >> x;
		if (x == 100)
		{
			break;
		}
		cout << "the card you have selected is" << cardsdealtVal[x] << "  of  " << carddealtSuit[x];
		if (cardsdealtVal[x] = 1)
		{
			numberofpoints = numberofpoints + 10;
		}
		else if (cardsdealtVal[x] = 13 || 12 || 11)
		{
			numberofpoints = numberofpoints + 5;
		}
		else if (cardsdealtVal[x] = 8 || 9 || 10)
		{
			numberofpoints = numberofpoints;
		}
		else if (cardsdealtVal[x] = 7)
		{
			numberofpoints = numberofpoints / 2;
		}
		else
		{
			numberofpoints = 0;
		}
		if (carddealtSuit[x] == "hearts")
		{
			numberofpoints = numberofpoints + 1;
		}
	}

	cout << "the total number of points you have accumulated is equal to" << " " << numberofpoints << endl;

}
int main()
{
	playFlip();

	

}