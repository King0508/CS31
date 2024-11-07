#include <iostream>
#include <string>
#include <array>
#include "Header.h"
using namespace std;
int locateMinimum(const string array[], int n)
{
	int index = 0; 
	string min = "";
	if (n <= 0)
	{
		index = -1;
		
	}
	else
	{
		min = array[0];
	}
	for (int i = 0; i < n; i++) // maybe I can remove the bool parameter 
	{
		string s = array[i];
		if (s < min)
		{
			min = s; 
			index = i; 
		}

	}
	return index; 
}

int findLastOccurrence(const string array[], int n, string target)
{
	int index = -1; 
	for (int i = 0; i < n; i++)
	{
		string s = array[i];
		if (s == target)
		{
			index = i; 
		}

	}
	return index; 

}

int flipAround(string array[], int n)
{	
	int flips = n / 2; 
	if (n <= 0)
	{
		flips = -1;
	}
	for (int i = 0; i < (n+1)/2; i++)
	{
		int k = n - i - 1; 
		string back = array[k];
		string front = array[i];
		array[i] = back;
		array[k] = front;
	}
	return flips;
}

bool hasNoDuplicates(const string array[], int  n)
{
	bool result = true; 
	if (n < 0)
	{
		result = false;
	}
	for (int i = 0; i < n; i++)
	{
		string s = array[i];
		for (int j = i + 1; j < n; j++)
		{
			string k = array[j];
			if (s == k)
			{
				result = false;
				break;
			}


		}
	}
	return result;
}

void unionWithNoDuplicates(const string array1[], int n1, const string array2[], int n2, string resultingString[], int& resultingSize)
{
	resultingSize = 0;
	bool valid = true; 
	if (n1 <= 0 || n2 <= 0)
	{
		resultingSize = -1;
		valid = false; 
	}
	for (int i = 0; i < n1 && valid == true; i++)//this for loop adds the unique elements of the first array into the resulting array 
	{
		int count1 = 0;
		string s = array1[i];
		for (int j = i - 1; j >= 0; j--)
		{
			if (s != array1[j])
			{
				count1++;
			}
		}
		if (i == count1)
		{
			resultingString[resultingSize] = s;
			resultingSize++;
		}
	}
	for (int k = 0; k < n2 && valid == true; k++)
	{
		int count2 = 0;
		string a = array2[k];
		bool unique = true; 
		for (int y = 0; y < resultingSize; y++)
		{
			if (a == resultingString[y])
			{
				unique = false; 
				break; 
			}
		}
		for (int x = k - 1; x >= 0; x--)
		{
			if (a != array2[x])
			{
				count2++;
			}
		}
		if (k == count2 && unique)
		{
			resultingString[resultingSize] = a;
			resultingSize++;
		}


	}

}

int shiftRight(string array[], int n, int amount, string placeholderToFillEmpties)
{
	int replace = 0;
	int  original = n - amount;
	if (n < 0 || amount > n)
	{
		original = -1;
	}
	if (amount < 0)
	{
		original = 0; 
	}
	for (int i = n-1 ; i > 0; i--)
	{
		int j = i - amount;
		if (j < 0)
		{
			break;
			
		}
		else
		{
			replace++; 
		}
		array[i] = array[j]; 
		
	}
	for (int x = 0; x < (n-replace); x++)
	{
		array[x] = placeholderToFillEmpties;
	}
	return original; 
}

bool isInIncreasingOrder(const string array[], int  n)
{
	bool result = true; 
	if (n < 0)
	{
		result = false; 
	}
	for (int i = 0; i < n; i++)
	{	
		int k = i + 1; 
		if (k == n)
		{
			break; 
		}
		if (array[i] >= array[k])
		{
			result = false;
			break; 
		}
	}
	return result;
}
