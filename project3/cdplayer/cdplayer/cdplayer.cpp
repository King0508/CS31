// cdplayer.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string> 
#include <cassert>
#include <cstdlib>
#include <cmath>

using namespace std; 
bool isValidCDPlayerString(string cdstring);
bool isOpen(string cdstring);
bool hasCD(string cdstring);
int totalTracksPlayed(string cdstring);
int currentTrack(string cdstring);
int counter(size_t i, string cdstring);
int insert(size_t i, string cdstring);
bool play(size_t i, string cdstring);
bool sequence(size_t i, string cdstring);

int main()
{	

	assert(isValidCDPlayerString("I") == false);
	assert(isValidCDPlayerString("OICP123ORICP123") == true);
	assert(isValidCDPlayerString("OO") == false);
	assert(isValidCDPlayerString("COI") == false);
	assert(isValidCDPlayerString("OICPSPOIC") == false);
	assert(isValidCDPlayerString("abcdefghijklmnopqrstuvwxyz") == false);
	assert(isValidCDPlayerString("ORC") == false);
	assert(isValidCDPlayerString("OCP123SOICOR") == false);
	assert(isValidCDPlayerString("OICP123SORICS") == false);
	assert(isValidCDPlayerString("OICORCOICP1234OCP567SORICP12") == true);
	assert(isValidCDPlayerString("OCOCOICP1OCP2SORICP123") == true);
	assert(isValidCDPlayerString("OPC") == false);
	assert(isValidCDPlayerString("OIRICP123456789") == true);
	assert(isValidCDPlayerString("OIRC") == true);
	assert(isValidCDPlayerString("OI") == true);
	assert(isValidCDPlayerString("OICPS") == true);
	assert(hasCD("OICORCOICP1234OCP567SORICP12") == true);
	assert(hasCD("OCOCOICP1OCP2SORICP123") == true);
	assert(hasCD("OPC") == false);
	assert(hasCD("OIRICP123456789") == true);
	assert(hasCD("OIRC") == false);
	assert(hasCD("OI") == true);
	assert(hasCD("OICPS") == true);
	assert(isOpen("OICORCOICP1234OCP567SORICP12") == false);
	assert(isOpen("OCOCOICP1OCP2SORICP123") == false);
	assert(isOpen("OPC") == false);
	assert(isOpen("OIRICP123456789") == false);
	assert(isOpen("OIRC") == false);
	assert(isOpen("OI") == true);
	assert(isOpen("OICPS") == false);
	assert(isOpen("OICPO") == true);
	assert(currentTrack("OICORCOICP1234OCP567SORICP12") == 3);
	assert(currentTrack("OCOCOICP1OCP2SORICP123") == 4);
	assert(currentTrack("OPC") == -1);
	assert(currentTrack("OIRICP12345678") == 9);
	assert(currentTrack("OIRC") == -1);
	assert(currentTrack("OI") == 1);
	assert(currentTrack("OICPS") == 1);
	assert(totalTracksPlayed("O") == 0);
	assert(totalTracksPlayed("OICORCOICP1234OCP567SORICP12") == 9);
	assert(totalTracksPlayed("OCOCOICP1OCP2SORICP123") == 5);
	assert(totalTracksPlayed("OPC") == -1);
	assert(totalTracksPlayed("OIRICP123456789") == 9);
	assert(totalTracksPlayed("OIRC") == 0);
	assert(totalTracksPlayed("OI") == 0);
	assert(totalTracksPlayed("OICPS") == 0);
	assert(currentTrack("OICP1234SOR") == -1);
	assert(currentTrack("OICORCOICP1234OCP567SORICP12") == 3);
	assert(currentTrack("P123S") == -1);

	assert(isValidCDPlayerString("OICPP12345SOCPP6789"));
	assert(isValidCDPlayerString("OICPPP123456"));
	assert(isValidCDPlayerString("OICP123P456"));
	assert(isValidCDPlayerString("OICP123SO"));
	assert(isValidCDPlayerString("OICP123OS"));
	assert(isValidCDPlayerString("OICPS")); 
	assert(isValidCDPlayerString("OC"));
	assert(isValidCDPlayerString("OIRIC"));
	assert(isValidCDPlayerString("OICPP"));
	assert(isValidCDPlayerString("OICP123SOCP456S"));
	assert(isValidCDPlayerString("OICP123SP456SORICP123"));
	assert(isValidCDPlayerString("OICP123O"));
	assert(isValidCDPlayerString("OICPO"));
	assert(isValidCDPlayerString("OICP123ORICP123"));
	assert(isValidCDPlayerString("OICP123"));
	assert(isValidCDPlayerString("OICPP1234SOR"));
	assert(isValidCDPlayerString("OS") == false);
	assert(isValidCDPlayerString("OR") == false);
	assert(isValidCDPlayerString("O1") == false);
	assert(isValidCDPlayerString("") == false);
	assert(isValidCDPlayerString("abc") == false);
	assert(isValidCDPlayerString("123") == false);
	assert(isValidCDPlayerString("CP1") == false);
	assert(isValidCDPlayerString("P1C") == false);
	assert(isValidCDPlayerString("OP") == false);
	assert(isValidCDPlayerString("OIP") == false);
	assert(isValidCDPlayerString("OO") == false);
	assert(isValidCDPlayerString("OICPP1234SSOR") == false);
	assert(isValidCDPlayerString("OICP123SOCP123S") == false);
	assert(isValidCDPlayerString("OIC123") == false);
	assert(isValidCDPlayerString("OICOO") == false);
	assert(isValidCDPlayerString("OIICP") == false);
	assert(isValidCDPlayerString("OICPORR") == false);
	assert(isValidCDPlayerString("OICC") == false);
	assert(isValidCDPlayerString("OICPSS") == false);
	assert(isValidCDPlayerString("OCCCCCCO") == false);
	
	
	assert(isOpen("O"));
	assert(isOpen("OI"));
	assert(isOpen("OCO"));
	assert(isOpen("OC") == false);
	assert(isOpen("OICO"));
	assert(isOpen("OICP123SO"));
	assert(isOpen("OICP123OS"));
	assert(isOpen("OICP123O"));
	assert(isOpen("OICPP1234SOR"));
	assert(isOpen("OICP123O"));
	assert(isOpen("OICPO"));
	assert(isOpen("OICPP12345SOCPP6789") == false);
	assert(isOpen("OICPPP123456") == false);
	assert(isOpen("OICP123P456") == false);
	assert(isOpen("") == false); 
	assert(isOpen("I") == false);
	assert(isOpen("C") == false);
	assert(isOpen("OIO") == false);
	assert(isOpen("OCOC") == false);
	assert(isOpen("OICP123SOCP456S") == false);
	assert(isOpen("OICP123SP456SORICP123") == false);
	assert(isOpen("OICP123ORICP123") == false);
	assert(isOpen("OICP123") == false);
	assert(isOpen("OICPS") == false);
	assert(isOpen("OC") == false);
	assert(isOpen("OIRIC") == false);
	assert(isOpen("OICPP") == false);
	assert(isOpen("OICP123SOCP456S") == false);
	assert(isOpen("OCOICC") == false);
	assert(isOpen("P123S") == false);
	assert(isOpen("xyz") == false);

	assert(hasCD("OIR") == false);
	assert(hasCD("OIRI"));
	assert(hasCD("O") == false);
	assert(hasCD("OI"));
	assert(hasCD("OCO") == false);
	assert(hasCD("OC") == false);
	assert(hasCD("OICO"));
	assert(hasCD("OICP123SOCP456S"));
	assert(hasCD("OICPS"));
	assert(hasCD("OIRIC"));
	assert(hasCD("OICP123SOCP456S"));
	assert(hasCD("OICPP"));
	assert(hasCD("OICP123SOCP456S"));
	assert(hasCD("OICP123SP456SORICP123"));
	assert(hasCD("OICP123O"));
	assert(hasCD("OICPO"));
	assert(hasCD("OICP123ORICP123"));
	assert(hasCD("OICP123"));
	assert(hasCD("") == false);
	assert(hasCD("OICP123SOCP123S") == false);
	assert(hasCD("OICPP1234SSOR") == false);
	assert(hasCD("OC") == false);
	assert(hasCD("OICPP1234SOR") == false);
	assert(hasCD("OO") == false);
	assert(hasCD("OIC123") == false);
	assert(hasCD("OICOO") == false);
	assert(hasCD("OIICP") == false);
	assert(hasCD("OICPORR") == false);
	assert(hasCD("OICC") == false);
	assert(hasCD("OICPSS") == false);
	assert(hasCD("OCCCCCCO") == false);

	assert(totalTracksPlayed("OICPP12345SOCPP6789") == 9);
	assert(totalTracksPlayed("OICPPP123456") == 6);
	assert(totalTracksPlayed("OICP123P456") == 6);
	assert(totalTracksPlayed("OICP123SO") == 3);
	assert(totalTracksPlayed("OICP123OS") == 3);
	assert(totalTracksPlayed("OICPS") == 0);
	assert(totalTracksPlayed("OC") == 0);
	assert(totalTracksPlayed("OIRIC") == 0);
	assert(totalTracksPlayed("OICPP") == 0);
	assert(totalTracksPlayed("OICP123SOCP456S") == 6);
	assert(totalTracksPlayed("OICP123SP456SORICP123") == 9);
	assert(totalTracksPlayed("OICP123O") == 3);
	assert(totalTracksPlayed("") == -1);
	assert(totalTracksPlayed("abc") == -1);
	assert(totalTracksPlayed("123") == -1);
	assert(totalTracksPlayed("CP1") == -1);
	assert(totalTracksPlayed("P1C") == -1);
	assert(totalTracksPlayed("OP") == -1);
	assert(totalTracksPlayed("OO") == -1);
	assert(totalTracksPlayed("OICPP1234SSOR") == -1);
	assert(totalTracksPlayed("OICP") == 0);
	assert(totalTracksPlayed("OIC") == 0);
	assert(totalTracksPlayed("O") == 0);
	assert(totalTracksPlayed("OICPP") == 0);
	assert(totalTracksPlayed("OICP123SOCP456S") == 6);
	assert(totalTracksPlayed("OICP123SP456SORICP123") == 9);
	assert(totalTracksPlayed("OICP123O") == 3);
	assert(totalTracksPlayed("OICPO") == 0);
	assert(totalTracksPlayed("OICP123ORICP123") == 6);
	assert(totalTracksPlayed("OICP123") == 3);
	assert(totalTracksPlayed("OICPP1234SOR") == 4);

	
	assert(currentTrack("OICP123ORICP") == 1);
	assert(currentTrack("OICP123ORICP123") == 4);
	assert(currentTrack("OICPPP123456") == 7);
	assert(currentTrack("OICP123P456") == 7);
	assert(currentTrack("OICP123SO") == 4);
	assert(currentTrack("OICP123OS") == 4);
	assert(currentTrack("OICPS") == 1);
	assert(currentTrack("OC") == -1);
	assert(currentTrack("OIRIC") == 1);
	assert(currentTrack("xyz") == -1);
	assert(currentTrack("abc") == -1);
	assert(currentTrack("123") == -1);
	assert(currentTrack("CP1") == -1);
	assert(currentTrack("P1C") == -1);
	assert(currentTrack("OP") == -1);
	assert(currentTrack("OO") == -1);
	assert(currentTrack("O") == -1); 
	assert(currentTrack("OIR") == -1);
	assert(currentTrack("OIRI") == 1);
	assert(currentTrack("OI") == 1);
	assert(currentTrack("OIC") == 1);
	assert(currentTrack("OICP") == 1);
	assert(currentTrack("") == -1);   
	assert(currentTrack("OICP123O") == 4);
	assert(currentTrack("OICPP") == 1);
	assert(currentTrack("OICP123SOCP456S") == 7);
	assert(currentTrack("OICP123SP456SORICP123") == 4);
	assert(currentTrack("OICP123O") == 4);
	assert(currentTrack("OICPO") == 1);
	assert(currentTrack("OICP123ORICP123") == 4);
	assert(currentTrack("OICP123") == 4);
	assert(currentTrack("OICPP1234SOR") == -1);

	return(0);
}	
bool isValidCDPlayerString(string cdstring)
{
	bool result = true;
	int cd = 0;
	bool playing = false;
	int count = 0;
	if (cdstring.empty())
	{
		result = false; 
	}
	if (cdstring[0] != 'O')
	{
		result = false; 
	}
	for (size_t k = 0; k < cdstring.size() && result == true; k++)
	{
		char c = cdstring.at(k);
		
			switch (c)
			{
			case 'O':
				if (count != 0)
				{
					result = false;
					break;
				}
				
				break;
			case 'I':
				if (count == 0)
				{
					result = false;
					break;
				}
				if (cd != 0)
				{
					result = false; 
					break; 
				}
				break;
			case 'C':
				if (count == 0)
				{
					result = false; 
					break;
				}
				break;
			case 'P':
				if (count != 0)
				{
					result = false; 
					break; 
				}
				if (cd == 0)
				{
					result = false; 
					break; 
				}
				break;
			case 'R':
				if (count == 0)
				{
					result = false;
					break;
				}
				if (cd == 0)
				{
					result = false; 
					break;
				}
				break;
			case 'S':
				if (!(playing))
				{
					result = false; 
					break; 
				}
				break;
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':
				if (!(playing))
				{
					result = false; 
					break;
				}
				else if (!(sequence(k,cdstring)))
				{
					result = false; 
					break; 
				}
				break;
			default:
				result = false;
				

			}
		 count = counter(k, cdstring);//open(1) closed(0) 
		 cd = insert(k, cdstring);//has cd(1) no cd(0)
		 playing = play(k, cdstring);//playing true, not playing false 
		
	}
	return result; 
}

bool isOpen(string cdstring)
{
	bool result = true; 
	if (!(isValidCDPlayerString(cdstring)))
	{
		result = false; 
	}
	else if (counter(cdstring.size() - 1, cdstring) == 0)
	{
		result = false; 
	}

	return result;
}

bool hasCD(string cdstring)
{	
	bool result = true; 
	if (!(isValidCDPlayerString(cdstring)))
	{
		result = false;
	}
	else if (insert(cdstring.size() - 1, cdstring) == 0)
	{
		result = false;

	}
    return result;
}

int totalTracksPlayed(string cdstring)
{
	int tracks = 0;
	if (!(isValidCDPlayerString(cdstring)))
	{
		tracks = -1; 
	}
	else
	{
		for (int k = 0; k < cdstring.size(); k++)
		{
			char c = cdstring.at(k);
			if (c >= 49 && c <= 57)
			{
				tracks++; 
			}
		}
	}
    return tracks;
}

int currentTrack(string cdstring)
{
	int ctrack = 1;
	if (!(isValidCDPlayerString(cdstring)))
	{
		ctrack = -1;
	}
	else if (insert(cdstring.size() - 1, cdstring) == 0)
	{
		ctrack = -1; 
	}
	else
	{
		for (int k = 0; k < cdstring.size(); k++)
		{
			char c = cdstring.at(k);
			if (c == 'I')
			{
				ctrack = 1; 
			}
			if (c >= 49 && c <= 57) 
			{
				ctrack++;
			}
		
		}
	}
	return ctrack;
}
int counter(size_t i, string cdstring)//returns 0 when the cd is closed, and returns 1 when the cd is open.  
{	
	int counterO = 1; 
	int counterC = 0; 
	int counter = 0;
	
	while (i > 0)
	{ 

			char c = cdstring.at(i);
			if (c == 'O')
			{
				counterO++;
			}
			if (c == 'C')
			{
				counterC++;
			}
			i--;

	}
	counter = counterO - counterC;

	return counter; 
}
int insert(size_t i, string cdstring)//returns 0 when no cd, returns 1 when has cd. 
{
	int counterI = 0; 
	int counterR = 0;
	int insert = 0;
 
	while (i > 0)
	{
		char c = cdstring.at(i);
		if (c == 'I')
		{
			counterI++;
		}
		if (c == 'R')
		{
			counterR++;
		}
		i--;
	}
	insert = counterI - counterR;
	return insert; 
}
bool play(size_t i, string cdstring)//returns false when not playing, returns true when playing.
{	
	int counterP = 0; 
	int counterS = 0;
	bool playing = false;
	
	for(int z = 0; z <= i; z++)
	{
		char c = cdstring[z];
		if (c == 'P' && playing == false)
		{
			counterP++;
		}
		if (c == 'S')
		{
			counterS++;
		}
		if (counterP > counterS)
		{
			playing = true;
		}
		else
		{
			playing = false;
		}
	}
	return playing; 
}
bool sequence(size_t i, string cdstring)//returns ture if the numbers are in order, false otherwise. 
{	
	bool inOrder = true;
	string num = "";
	for(int x = 0; x <= i; x++)
	{
		char c = cdstring.at(x);
		if (c == 'I')
		{
			num = "";
		}
		if (c >= 49 && c <= 57)
		{
			num += c; 
			
			for (int j = 0; j < num.size(); j++)
			{
				if (j == num.size() - 1)
				{
					break;
				}
				if (num.at(0)!= 49)
				{
					inOrder = false;
					break;
				}
				if (num.at(j) >= num.at(j+1))
				{
					inOrder = false;
					break;
				}
			}
			if (!inOrder)
			{
				break;
			}
		}
		
		
	}	
	return inOrder; 
}