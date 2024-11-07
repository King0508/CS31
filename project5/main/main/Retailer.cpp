#include <iostream>
#include <string>
#include "Retailer.h"
//should include Giftcard.h because giftcard objects are used in this file 
using namespace std; 
Retailer::Retailer(string name)
{
	mName = name;//assigns the user input value with the private data member 
}
string Retailer::getName()
{
	return(mName);
}
bool Retailer::purchaseItem(string item, double cost, GiftCard& card)
{
	bool result = true;
	if (card.getRetailer() != getName() || cost <= 0)
	{
		result = false; 
	}
	else if (card.getAmount() < cost)
	{
		result = false;
	}
	else
	{
		card.setAmount(card.getAmount() - cost); //sets the final amount of the card after the purchase 
	}
	return result;
}
bool Retailer::purchaseItem(string item, double cost, GiftCard& card1, GiftCard& card2)
{
	bool result = true;
	if (card1.getRetailer() != mName || card2.getRetailer() != mName || cost <= 0)
	{
		result = false;
	}
	else if ((card1.getAmount() + card2.getAmount()) < cost)
	{
		result = false; 
	}
	else
	{
		if (cost >= card1.getAmount())
		{
			card2.setAmount(card2.getAmount() - (cost - card1.getAmount())); //subtracts an amount from card 2 before emptying out card 1 
			card1.empty(); 
		}
		else
		{
			card1.setAmount(card1.getAmount() - cost); 
		}
	}
	return result;
}
bool Retailer::returnItem(string item, double cost, GiftCard& card)
{
	bool result = true;
	if (card.getRetailer() != mName || cost <= 0) //checks that the retailer names match and the cost is significant 
	{
		result = false; 
	}
	else
	{
		card.setAmount(card.getAmount() + cost);
	}

	return result; 
}
