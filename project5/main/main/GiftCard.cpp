#include <iostream>
#include <string>
#include "GiftCard.h"
using namespace std; 

GiftCard::GiftCard(string retailer, double amount)
{
	setAmount(amount);
	mRetailer = retailer; //sets the user input to the private data members 
}

void GiftCard::setAmount(double amount)
{
	mAmount = amount;
}
double GiftCard::getAmount()
{
	return(mAmount);
}
string GiftCard::getRetailer()
{
	return(mRetailer);
}
void GiftCard::empty()
{
	setAmount(0);//sets amount to zero is essentially emptying the card 
}
bool GiftCard::isEmpty()
{
	bool empty = false; 
	if (getAmount() <= 0)
	{ 
		empty = true; 
	}
	return empty; 
}
bool GiftCard::canBeUsedToPurchase(double amount)
{
	bool purchase = true;
	if (amount > getAmount() || amount <= 0)//checks that the cost is not greater than the gift card amou nt as well as the amount being greater than zero 
	{
		purchase = false; 
	}
	return purchase; 
}