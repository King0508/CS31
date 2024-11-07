

#include <iostream>
#include <string>
using namespace std; 

int main()
{
	//establish all useful variables for this program 
	double cost = 0; 
	string planIn, planDiscountIn, everydayAccessIn, facilitiesAccessIn, autopayDisIn, paperDisIn; 
	string plan1 = "Executive";
	string plan2 = "Basic";
	string adultPlan = "Adult";
	string childPlan = "Child";
	string seniorPlan = "Senior";
	string oddDay = "Odd";
	string evenDay = "Even";
	string everyDay = "Everyday";
	string oneAccess = "Just One";
	string regionalAccess = "Regional";
	string nationalAccess = "National"; 
	string autopay1 = "Yes";
	string autopay2 = "No";
	string paperlessBill1 = "Yes";
	string paperlessBill2 = "No";
	//get membership input from user 
	cout << "What kind of gym membership plan do you want to buy";
	getline(cin, planIn);
	if (planIn == plan1)
	{
		cost += 100; 
	}
	if (planIn == plan2)
	{
		cost += 50; 
	}
	//get type of plan discount input from user
	cout << "What type of gym membership do you want to buy?";
	getline(cin, planDiscountIn);
	//get everyday access input from user 
	cout << "Which days do you want to workout?";
	getline(cin, everydayAccessIn); 
	if (everydayAccessIn == oddDay)
	{
		cost = cost; 
	}
	if (everydayAccessIn == evenDay)
	{
		cost = cost;
	}
	if (everydayAccessIn == everyDay)
	{
		cost += 25; 
	}
	//get facilities access from user
	cout << "Which facilities do you want to access to?";
	getline(cin, facilitiesAccessIn);
	if (facilitiesAccessIn == oneAccess)
	{
		cost = cost; 
	}
	if (facilitiesAccessIn == regionalAccess)
	{
		cost += 30;
	}
	if (facilitiesAccessIn == nationalAccess)
	{
		cost += 50;
	}
	//compute plan discount from earlier
	if (planDiscountIn == adultPlan)
	{
		cost = cost; 
	}
	if (planDiscountIn == childPlan)
	{
		cost *= 0.5;
	}
	if (planDiscountIn == seniorPlan)
	{
		cost *= 0.75;
	}
	//get payment input from user
	cout << "Are you on autopay";
	getline(cin, autopayDisIn);
	if (autopayDisIn == autopay1)
	{
		cost -= 2; 
	}
	if (autopayDisIn == autopay2)
	{
		cost = cost; 
	}
	cout << "Are you on paperless billing?";
	getline(cin, paperDisIn);
	if (paperDisIn == paperlessBill1)
	{
		cost -= 3;
	}
	if (paperDisIn == paperlessBill2)
	{
		cost = cost;
	}
	if (planIn != plan1 && planIn != plan2)
	{
		cout << "Your kind of membership plan is not valid!";
	}
	else if (planDiscountIn != childPlan && planDiscountIn != adultPlan && planDiscountIn != seniorPlan)
	{
		cout << "Your type of membership is not valid!";
	}
	else if (everydayAccessIn != oddDay && everydayAccessIn != evenDay && everydayAccessIn != everyDay)
	{
		cout << "Your membership days are not valid!";
	}
	else if (facilitiesAccessIn != oneAccess && facilitiesAccessIn != regionalAccess && facilitiesAccessIn != nationalAccess)
	{
		cout << "Your facilities choice is not valid!";
	}
	else if (autopayDisIn != autopay1 && autopayDisIn != autopay2)
	{
		cout << "Your autopay is not valid!";
	}
	else if (paperDisIn != paperlessBill1 && paperDisIn != paperlessBill2)
	{
		cout << "Your paperless billing is not valid!";
	}
	else
	{
		cout.setf(ios::showpoint);
		cout.setf(ios::fixed);
		cout.precision(2);
		cout << "Your " + planIn + " gym membership costs $";
		cout << cost << endl;
	}
	return(0);
}


