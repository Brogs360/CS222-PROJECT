#include <iostream>
#include <string>
#include "hands.h"


hands::hands(Card c1, Card c2) {
	cardvaluenum1 = c1.get_num(); 
	cardsuitnum1 = c1.get_suit(); 
	cardvaluenum2 = c2.get_num(); 
	cardsuitnum2 = c2.get_suit(); 
	readcards(); 
}

void hands::readcards() {
	switch (cardvaluenum1) {
	case 1: cardvalue1 = "Ace"; break;
	case 2: cardvalue1 = "Two"; break;
	case 3: cardvalue1 = "Three"; break;
	case 4: cardvalue1 = "Four"; break;
	case 5: cardvalue1 = "Five"; break;
	case 6: cardvalue1 = "Six"; break;
	case 7: cardvalue1 = "Seven"; break;
	case 8: cardvalue1 = "Eight"; break;
	case 9: cardvalue1 = "Nine"; break;
	case 10: cardvalue1 = "Ten"; break;
	case 11: cardvalue1 = "Jack"; break;
	case 12: cardvalue1 = "Queen"; break;
	case 13: cardvalue1 = "King"; break;
	default: std::cout << "Error processing card." << std::endl; 
	}
	switch (cardsuitnum1) {
	case 1: cardsuit1 = "Hearts"; break; 
	case 2: cardsuit1 = "Diamonds"; break; 
	case 3: cardsuit1 = "Clubs"; break; 
	case 4: cardsuit1 = "Spades"; break; 
	default: std::cout << "Error processing card." << std::endl;
	}

	switch (cardvaluenum2) {
	case 1: cardvalue2 = "Ace"; break;
	case 2: cardvalue2 = "Two"; break;
	case 3: cardvalue2 = "Three"; break;
	case 4: cardvalue2 = "Four"; break;
	case 5: cardvalue2 = "Five"; break;
	case 6: cardvalue2 = "Six"; break;
	case 7: cardvalue2 = "Seven"; break;
	case 8: cardvalue2 = "Eight"; break;
	case 9: cardvalue2 = "Nine"; break;
	case 10: cardvalue2 = "Ten"; break;
	case 11: cardvalue2 = "Jack"; break;
	case 12: cardvalue2 = "Queen"; break;
	case 13: cardvalue2 = "King"; break;
	default: std::cout << "Error processing card." << std::endl;
	}
	switch (cardsuitnum2) {
	case 1: cardsuit2 = "Hearts"; break; 
	case 2: cardsuit2 = "Diamonds"; break; 
	case 3: cardsuit2 = "Clubs"; break; 
	case 4: cardsuit2 = "Spades"; break; 
	default: std::cout << "Error processing card." << std::endl;
	}
}

void hands::checkhands() {
	if (cardsuit1 == cardsuit2) {
		samesuite = true; 
	}
	if (cardvaluenum1 == (cardvaluenum2 - 1) || cardvaluenum1 == (cardvaluenum2 + 1)) {
		sequence = true; 
	}
	if (cardvaluenum1 == 1 || cardvaluenum2 == 1) {
		isace = true; 
	}

	if (samesuite == true && sequence == true && (cardvaluenum1 >= 10 || cardvaluenum2 >= 10 || isace == true)) {
		royalflush = true;
	}
	if (samesuite == true && sequence == true) {
		straightflush = true;
	}
	if (cardvalue1 == cardvalue2) {
		fourofakind = true; 
		fullhouse = true;
		threeofakind = true; 
		twopair = true; 
		onepair = true; 
	}
	if (sequence == true) {
		straight = true; 
	}
	if (samesuite == true) {
		flush = true;
	}
	highcard = true; 
	printhands(); 
}

void hands::printcards() {
	std::cout << "Card 1 is the " << cardvalue1 << " of " << cardsuit1 <<"." << std::endl;
	std::cout << "Card 2 is the " << cardvalue2 << " of " << cardsuit2 << "." << std::endl;
}


void hands::printhands() {
	std::cout << "Royal Flush: " << royalflush << std::endl; 
	std::cout << "Straight Flush: " << straightflush << std::endl;
	std::cout << "Four of a Kind: " << fourofakind << std::endl;
	std::cout << "Full House: " << fullhouse << std::endl;
	std::cout << "Flush: " << flush << std::endl;
	std::cout << "Straight: " << straight << std::endl;
	std::cout << "Three of a Kind: " << threeofakind << std::endl;
	std::cout << "Two Pair: " << twopair << std::endl;
	std::cout << "One Pair:  " << onepair << std::endl;
	std::cout << "High Card: " << highcard << std::endl;
}