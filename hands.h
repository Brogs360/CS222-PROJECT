#pragma once
#include <string>
#include "Cards.h"

class hands {
private: 
	std::string cardvalue1;
	std::string cardvalue2;
	int cardvaluenum1; 
	int cardvaluenum2;

	std::string cardsuit1;
	std::string cardsuit2;
	int cardsuitnum1; 
	int cardsuitnum2;
	
	bool samesuite = false; 
	bool sequence = false; 
	bool isace = false; 

	bool royalflush = false; //10 - Ace of the same suite
	bool straightflush = false; //any sequence of the same suite
	bool fourofakind = false; //4 of a kind plus a "kicker" 
	bool fullhouse = false; //3 of a kind and a 2 of a kind
	bool flush = false; //5 cards of the same suite
	bool straight = false; //any sequence
	bool threeofakind = false; //3 of a kind
	bool twopair = false; //2 sets of pairs
	bool onepair = false; //1 pair
	bool highcard = false; //highest value card
public:
	hands(Card, Card); 
	void readcards(); 
	void printcards(); 
	void checkhands(); 
	void printhands(); 
};