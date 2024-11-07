#ifndef GIFTCARD_H
#define GIFTCARD_H
#include <iostream>
#include <string>
using namespace std; 

class GiftCard
{
public: 
	GiftCard(string retailer, double amount);//sets three parameter contructor 
	//declaring public methods 
	void setAmount(double amount);
	double getAmount(); 
	string getRetailer();
	void empty();
	bool isEmpty(); 
	bool canBeUsedToPurchase(double amount); 
	

private: 
	string mRetailer;
	double mAmount; //declares the private data members of this class 
};




#endif //makes sure the file only get read once 