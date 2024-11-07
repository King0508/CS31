#ifndef RETAILER_H//makes sure the headers file only gets read once
#define RETAILER_H
#include <iostream>
#include <string>
#include "GiftCard.h"
using namespace std; 

class Retailer
{
public: 
	Retailer(string name);//setting a one string parameter contructor of class Retailer 
	//declaring public methods 
	string getName(); 
	bool purchaseItem(string item, double cost, GiftCard& card);
	bool purchaseItem(string item, double cost, GiftCard& card1, GiftCard& card2);
	bool returnItem(string item, double cost, GiftCard& card);
private: 
	string mName;//private data members
};



#endif