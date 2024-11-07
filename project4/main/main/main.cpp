
#include <iostream>
#include <string>
#include <cassert>
#include <array>
#include "Header.h"

using namespace std;

int main()
{
    string h[7] = { "5", "1", "5", "2", "10", "11", "15" };
    string b[7] = { "ee", "dd", "cc", "bb", "aa", "BB", "AA" };
    int resultingSize = 0;
    string resultingString[2];
   
    assert(flipAround(h, 5) == 2);
    //assert(unionWithNoDuplicates(b, 7, b, 7, resultingString, resultingSize)  == 7 );
  
}
