#include <iostream>
#include <string>
#include <array>
#include "Header.h"
using namespace std;
int locateMinimum(const string array[], int n)//the function locates the lowest index of the smallest string
{
	int index = 0; 
	string min = "";//the zeroth index of the array will be set as the min, and the min will be compared and updated in the for loop
	if (n <= 0)
	{
		index = -1;
		
	}
	else
	{
		min = array[0];
	}
	for (int i = 0; i < n; i++)//for loop loops through the array with size n 
	{
		string s = array[i];
		if (s < min)//if string at current index is less than min, min and index is updated
		{
			min = s; 
			index = i; 
		}

	}
	return index;// returns index
}

int findLastOccurrence(const string array[], int n, string target)//the function locates the index of the last occurrence of a target string
{
	int index = -1; 
	for (int i = 0; i < n; i++)
	{
		string s = array[i];
		if (s == target)//this line checks if the string at the current index is the same as the target string 
		{
			index = i;//if so, the index is updated, the loop will continue to n-1 index to make sure the last occurrence of target is returned 
		}

	}
	return index;//returns index 

}

int flipAround(string array[], int n)//this function flips the string array 
{	
	int flips = n / 2; //odd n flips (n-1)/2 times, even n flips n/2 times, if n is odd, (n-1)/2 = n/2 given n is type int 
	if (n <= 0)
	{
		flips = -1;
	}
	for (int i = 0; i < (n+1)/2; i++)//since we need to reach either index (n-1)/2 or index n/2, we make i < (n+1)/2 
	{
		int k = n - i - 1;//k gives the index that needs to swap with index i 
		string back = array[k];
		string front = array[i];
		array[i] = back;//swap indices
		array[k] = front;//swap indices 
	}
	return flips;//returns flips
}

bool hasNoDuplicates(const string array[], int  n)//this function returns true if all contents within the array are unique, otherwise false 
{
	bool result = true;//declare resulting to true, as the function executes, results will be updated 
	if (n < 0)//invalid array size, so result = false; 
	{
		result = false;
	}
	for (int i = 0; i < n; i++)
	{
		string s = array[i];
		for (int j = i + 1; j < n; j++)//nested for loop to compare each element in the array with all elements after it 
		{
			string k = array[j];
			if (s == k)
			{
				result = false;
				break;//the for loop can stop once we duplicate is found 
			}


		}
	}
	return result;//returns result 
}

void unionWithNoDuplicates(const string array1[], int n1, const string array2[], int n2, string resultingString[], int& resultingSize)//this function combines all the unique elements of two arrays into one array, and returns the size of the new array 
{
	resultingSize = 0;//resultingSize is initially set to zero to function as the index of the resultingString where the function will fill in the string 
	bool valid = true;//check if the array sizes are valid 
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
			if (s != array1[j])//counts and adds how many elements before the current element is not equal to the current element
			{
				count1++;
			}
		}
		if (i == count1)
		{
			resultingString[resultingSize] = s;
			resultingSize++;//updates the resultingSize
		}
	}
	for (int k = 0; k < n2 && valid == true; k++)//this for loop adds the unique elements of the second array into the resulting array 
	{
		int count2 = 0;
		string a = array2[k];
		bool unique = true; 
		for (int y = 0; y < resultingSize; y++)//checks that the second array elements are unique compared to elements in the first array 
		{
			if (a == resultingString[y])
			{
				unique = false; 
				break; 
			}
		}
		for (int x = k - 1; x >= 0; x--)
		{
			if (a != array2[x])//counts and adds how many elements before the current element is not equal to the current element
			{
				count2++;
			}
		}
		if (k == count2 && unique)
		{
			resultingString[resultingSize] = a;
			resultingSize++;//updates the resultingSize
		}


	}

}
int shiftRight(string array[], int n, int amount, string placeholderToFillEmpties)//this function shifts the array to the right by an amount, and fill the empties indices with a filler string
{
	int replace = 0;
	int  original = n - amount;//items from orignial array is just size of array minus amount shifted, given n and amount are valid 
	if (amount < 0)//if amount is less than zero, function returns 0 
	{
		original = 0;
	}
	if (n < 0 || amount > n)//if n is less than zero or amount is greater than n, function returns -1 
	{
		original = -1;
	}
	for (int i = n-1 ; i > 0; i--)
	{
		int j = i - amount;
		if (j < 0)//makes sure that array index is not out of bounds 
		{
			break;
			
		}
		else
		{
			replace++;//counts how many strings are replaced 
		}
		array[i] = array[j]; 
		
	}
	for (int x = 0; x < (n-replace); x++)
	{
		array[x] = placeholderToFillEmpties;//fills in fill string 
	}
	return original;//returns original item amount
}

bool isInIncreasingOrder(const string array[], int  n)//this function returns true is all elements in the array are in increasing order, false otherwise 
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
		if (array[i] >= array[k])//compares the current element with the next element 
		{
			result = false;
			break;//if not in increasing order, for loop terminates 
		}
	}
	return result;//returns results 
}
int dupNum(const string array1[], int n1, const string array2[], int n2)//helper function used to test unionWithNoDuplicates function 
{
	int dupnumm = 0;
	for (int i = 1; i < n1; i++)
	{
		bool nodup = true;
		for (int j = 0; j < i; j++)
		{
			if (array1[i] == array1[j])
			{
				if (nodup == true)
				{
					dupnumm++;
				}
				nodup = false;
			}
		}

	}
	for (int i = 0; i < n2; i++)
	{
		bool nodup = true;
		for (int j = 0; j < n1; j++)
		{
			if (array2[i] == array1[j])
			{
				if (nodup == true)
				{
					dupnumm++;
				}
				nodup = false;
			}
		}
		for (int k = -1; k < i; k++)
		{
			if (k >= 0 && array2[i] == array2[k])
			{
				if (nodup == true)
				{
					dupnumm++;
				}
				nodup = false;
			}
		}
	}
	return (dupnumm);

}