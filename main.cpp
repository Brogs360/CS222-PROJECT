#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include "Cards.h"
int Lines(std::string path){
    std::ifstream stream;
    stream.open(path);

    int line_num = 0;

    std::string line;
    while(std::getline(stream,line)){
        line_num++;
    }

    stream.close();
    return line_num;
}

Card** Card_Input(std::string path, int card_nums){
    Card** cardlist = new Card * [card_nums];
    std::ifstream stream;
    stream.open(path);

    std::string line;
    std::getline(stream,line);
    for (int i = 0; i <card_nums;i++){
        std::getline(stream,line);
        std::stringstream ss(line);

        std::string substr;
        std::getline(ss, substr,',');
        int suit = std::stoi(substr);

        std::getline(ss, substr,',');
        int card_num = std::stoi(substr);

        cardlist[i] = new Card(suit,card_num);
    }
    stream.close();
    return cardlist;
}


void user_card(std::vector<Card>& Usercards, int length){
    int Suit, Number;
    for (int i = 0; i< length; i++) {
        std::cout << "Enter your Card Suit and Card Number: ";
        std::cin >> Suit >> Number;
        if (Suit >= 1 && Suit <= 4 && Number >= 1 && Number <= 13){
            Card New_card(Suit,Number);
            Usercards.push_back(New_card);}
        else{std::cout<<"Invalid input!";
            exit(1);}
    }


}
int main() {
    std::string path = "Data/CardList.csv";
    const int max = 7;
    int card_num = Lines(path)-1;
    Card** cards = Card_Input(path,card_num);
    std::vector<Card> UserCards;
    user_card(UserCards,2);
    for (int i = 0; i < max;i++){
        UserCards[i].print();
    }
    user_card(UserCards,3);
    for (int i = 0; i < max;i++){
        UserCards[i].print();
    }
    delete[] cards;
    return 0;
}
