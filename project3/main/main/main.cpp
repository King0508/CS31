#include <iostream>
#include <string>
#include <cassert>
#include <array>
#include "Header.h"

using namespace std;

int main()
{
    string a[7] = { "ee", "dd", "cc", "bb", "aa", "BB", "AA" };
    string b[7] = { "ee", "BB", "BB", "BB", "cc", "dd", "AA" };
    string people[5] = { "samwell", "jon", "margaery", "daenerys", "tyrion" };
    string folks[8] = { "samwell", "jon", "margaery", "daenerys", "tyrion", "sansa", "howard123", "jon" };
    string o[5] = { "1","2","3","3","4" };
    string four[5] = { "1","2","3","3","4" };
    string fourRe[5] = { "4","3","3","2","1" };
    string five[5] = { "1","2","3","4","5" };
    string fiveRe[5] = { "5","4","3","2","1" };
    string three[5] = { "1","2","1","3","1" };
    string threeRe[5] = { "1","3","1","2","1" };
    string two[5] = { "1","2","1","2","1" };
    string allOne[5] = { "1","1","1","1","1" };
    string nineFive[5] = { "5","6","7","8","9" };
    string nineFour[5] = { "5","4","7","8","9" };
    string eightFour[5] = { "5","4","7","4","8" };
    string example[7] = { "5", "1", "5", "2", "10", "11", "15" };
    string example1[8] = { "0", "1", "2", "3", "4", "5", "6", "7" };
    string bar[7] = { "5", "1", "5", "2", "10", "11", "15" };
    string blank[4] = { "", "", "", "" };
    //locateMinimum testing starts here 
    assert(locateMinimum(people, 5) == 3);
    assert(locateMinimum(people, 4) == 3);
    assert(locateMinimum(people, 3) == 1);
    assert(locateMinimum(people, 2) == 1);
    assert(locateMinimum(people, 1) == 0);
    assert(locateMinimum(example, 7) == 1);
    assert(locateMinimum(example, 1) == 0);
    assert(locateMinimum(a, 7) == 6);
    assert(locateMinimum(a, 6) == 5);
    assert(locateMinimum(a, 5) == 4);
    assert(locateMinimum(a, 4) == 3);
    assert(locateMinimum(a, 3) == 2);
    assert(locateMinimum(b, 7) == 6);
    assert(locateMinimum(b, 5) == 1);
    assert(locateMinimum(b, 3) == 1);
    assert(locateMinimum(fourRe, 5) == 4);
    assert(locateMinimum(fourRe, 4) == 3);
    assert(locateMinimum(fourRe, 3) == 1);
    assert(locateMinimum(fourRe, 1) == 0);
    assert(locateMinimum(fourRe, -5) == -1);
    assert(locateMinimum(four, 5) == 0);
    assert(locateMinimum(four, 4) == 0);
    assert(locateMinimum(four, 3) == 0);
    assert(locateMinimum(four, 1) == 0);
    assert(locateMinimum(five, 5) == 0);
    assert(locateMinimum(five, 3) == 0);
    assert(locateMinimum(fiveRe, 5) == 4);
    assert(locateMinimum(fiveRe, 4) == 3);
    assert(locateMinimum(fiveRe, 3) == 2);
    assert(locateMinimum(fiveRe, 2) == 1);
    assert(locateMinimum(three, 5) == 0);
    assert(locateMinimum(allOne, 5) == 0);
    assert(locateMinimum(allOne, 5) == 0);
    //findLastOccurrence testing begins here 
    assert(findLastOccurrence(b, 7, "BB") == 3);
    assert(findLastOccurrence(fourRe, 5, "3") == 2);
    assert(findLastOccurrence(three, 5, "1") == 4);
    assert(findLastOccurrence(allOne, 5, "1") == 4);
    assert(findLastOccurrence(eightFour, 4, "5") == 0);
    assert(findLastOccurrence(allOne, 5, "1") == 4);
    assert(findLastOccurrence(allOne, 5, "1") == 4);
    assert(findLastOccurrence(blank, 4, "") == 3);
    assert(findLastOccurrence(three, 3, "1") == 2);
    assert(findLastOccurrence(nineFive, 5, "1") == -1);
    assert(findLastOccurrence(example, 5, "") == -1);
    assert(findLastOccurrence(folks, 0, "1") == -1);
    assert(findLastOccurrence(allOne, -6, "1") == -1);
    assert(findLastOccurrence(two, 1, "1") == 0);
    //shiftRight testing begins here 
    assert(shiftRight(example, 7, 1, "empty") == 6);
    assert(example[0] == "empty");
    assert(example[1] == "5");
    assert(example[2] == "1");
    assert(example[3] == "5");
    assert(example[4] == "2");
    assert(example[5] == "10");
    assert(example[6] == "11");
    assert(shiftRight(eightFour, 3, 1, "empty") == 2);
    assert(eightFour[0] == "empty");
    assert(eightFour[1] == "5");
    assert(eightFour[2] == "4");
    assert(eightFour[3] == "4");
    assert(eightFour[4] == "8");
    assert(shiftRight(example1, 5, 2, "empty") == 3);
    assert(example1[0] == "empty");
    assert(example1[1] == "empty");
    assert(example1[2] == "0");
    assert(example1[3] == "1");
    assert(example1[4] == "2");
    assert(example1[5] == "5");
    assert(example1[6] == "6");
    assert(example1[7] == "7");
    assert(shiftRight(nineFour, 5, 2, "empty") == 3);
    assert(nineFour[0] == "empty");
    assert(nineFour[1] == "empty");
    assert(nineFour[2] == "5");
    assert(nineFour[3] == "4");
    assert(nineFour[4] == "7");
    assert(shiftRight(o, -7, 0, "empty") == -1);
    //flipAround testing begins here
    assert(flipAround(bar, 6) == 3);
    assert(bar[0] == "11");
    assert(bar[1] == "10");
    assert(bar[2] == "2");
    assert(bar[3] == "5");
    assert(bar[4] == "1");
    assert(bar[5] == "5");
    assert(bar[6] == "15");
    assert(flipAround(fourRe, 5) == 2);
    assert(fourRe[0] == "1");
    assert(fourRe[1] == "2");
    assert(fourRe[2] == "3");
    assert(fourRe[3] == "3");
    assert(fourRe[4] == "4");
    assert(flipAround(nineFive, 4) == 2);
    assert(nineFive[0] == "8");
    assert(nineFive[1] == "7");
    assert(nineFive[2] == "6");
    assert(nineFive[3] == "5");
    assert(nineFive[4] == "9");
    assert(flipAround(allOne, 0) == -1);
    assert(allOne[0] == "1");
    assert(allOne[1] == "1");
    assert(allOne[2] == "1");
    assert(allOne[3] == "1");
    assert(allOne[3] == "1");
    //unionWithNoDuplicates testing begins here
    string resultingString[100];
    int resultingSize = 0;
    unionWithNoDuplicates(two, 4, five, 5, resultingString, resultingSize);
    assert(resultingSize == 5);
    assert(resultingString[0] == "1"); 
    assert(resultingString[1] == "2");
    assert(resultingString[2] == "3");
    assert(resultingString[3] == "4");
    assert(resultingString[4] == "5");
    unionWithNoDuplicates(blank, 4, blank, 4, resultingString, resultingSize);
    assert(resultingSize == 1);
    assert(resultingString[0] == "");
    unionWithNoDuplicates(a, 5, people, 5, resultingString, resultingSize);
    assert(resultingSize == 10); 
    assert(resultingString[0] == "ee");
    assert(resultingString[1] == "dd");
    assert(resultingString[2] == "cc");
    assert(resultingString[3] == "bb");
    assert(resultingString[4] == "aa");
    assert(resultingString[5] == "samwell");
    assert(resultingString[6] == "jon");
    assert(resultingString[7] == "margaery");
    assert(resultingString[8] == "daenerys");
    assert(resultingString[9] == "tyrion");
    unionWithNoDuplicates(blank, 4, allOne, 5, resultingString, resultingSize);
    assert(resultingSize == 2);
    assert(resultingString[0] == "");
    assert(resultingString[1] == "1");
    //hasNoDuplicates testing begins here 
    assert(hasNoDuplicates(five, 5) == true); 
    assert(hasNoDuplicates(o, 5) == false);
    assert(hasNoDuplicates(four, 5) == false);
    assert(hasNoDuplicates(fiveRe, 5) == true);
    assert(hasNoDuplicates(three, 5) == false);
    assert(hasNoDuplicates(threeRe, 1) == true);
    assert(hasNoDuplicates(two, 5) == false);
    assert(hasNoDuplicates(two, -1) == false);
    assert(hasNoDuplicates(a, 5) == true);
    assert(hasNoDuplicates(a, 0) == true);
    //isInIncreasingOrder testing begins here 
    assert(isInIncreasingOrder(five, 5) == true);
    assert(isInIncreasingOrder(o, 5) == false);
    assert(isInIncreasingOrder(four, 5) == false);
    assert(isInIncreasingOrder(fiveRe, 5) == false);
    assert(isInIncreasingOrder(three, 5) == false);
    assert(isInIncreasingOrder(threeRe, 2) == true);
    assert(isInIncreasingOrder(two, 2) == true);
    assert(isInIncreasingOrder(a, 5) == false);
    assert(isInIncreasingOrder(five, 0) == true);
    assert(isInIncreasingOrder(o, -7) == false);
    for (int n = -2; n < 6; n++) //nested for loop to throughly test for shiftRight function  
    {
        string placeholderToFillEmpties = "hi";
        for (int a = 0; a < 8; a++)
        {
            string o[5] = { "1","2","3","3","4" };
            string four[5] = { "1","2","3","3","4" };
            string fourRe[5] = { "4","3","3","2","1" };
            string five[5] = { "1","2","3","4","5" };
            string fiveRe[5] = { "5","4","3","2","1" };
            string three[5] = { "1","2","1","3","1" };
            string threeRe[5] = { "1","3","1","2","1" };
            string two[5] = { "1","2","1","2","1" };
            string allOne[5] = { "1","1","1","1","1" };
            string nineFive[5] = { "5","6","7","8","9" };
            string nineFour[5] = { "5","4","7","8","9" };
            string eightFour[5] = { "5","4","7","4","8" };
            if (n < 0 || a > n)
            {
                assert(shiftRight(o, n, a, placeholderToFillEmpties) == -1);
                assert(shiftRight(four, n, a, placeholderToFillEmpties) == -1);
                assert(shiftRight(fourRe, n, a, placeholderToFillEmpties) == -1);
                assert(shiftRight(five, n, a, placeholderToFillEmpties) == -1);
                assert(shiftRight(fiveRe, n, a, placeholderToFillEmpties) == -1);
                assert(shiftRight(three, n, a, placeholderToFillEmpties) == -1);
                assert(shiftRight(two, n, a, placeholderToFillEmpties) == -1);
                assert(shiftRight(allOne, n, a, placeholderToFillEmpties) == -1);
                assert(shiftRight(nineFive, n, a, placeholderToFillEmpties) == -1);
                assert(shiftRight(nineFour, n, a, placeholderToFillEmpties) == -1);
                assert(shiftRight(eightFour, n, a, placeholderToFillEmpties) == -1);
            }
            else if (a == 0)
            {
                assert(shiftRight(o, n, a, placeholderToFillEmpties) == n);
                assert(shiftRight(four, n, a, placeholderToFillEmpties) == n);
                assert(shiftRight(fourRe, n, a, placeholderToFillEmpties) == n);
                assert(shiftRight(five, n, a, placeholderToFillEmpties) == n);
                assert(shiftRight(fiveRe, n, a, placeholderToFillEmpties) == n);
                assert(shiftRight(three, n, a, placeholderToFillEmpties) == n);
                assert(shiftRight(two, n, a, placeholderToFillEmpties) == n);
                assert(shiftRight(allOne, n, a, placeholderToFillEmpties) == n);
                assert(shiftRight(nineFive, n, a, placeholderToFillEmpties) == n);
                assert(shiftRight(nineFour, n, a, placeholderToFillEmpties) == n);
                assert(shiftRight(eightFour, n, a, placeholderToFillEmpties) == n);
            }
            else if (a < 0)
            {
                assert(shiftRight(o, n, a, placeholderToFillEmpties) == 0);
                assert(shiftRight(four, n, a, placeholderToFillEmpties) == 0);
                assert(shiftRight(fourRe, n, a, placeholderToFillEmpties) == 0);
                assert(shiftRight(five, n, a, placeholderToFillEmpties) == 0);
                assert(shiftRight(fiveRe, n, a, placeholderToFillEmpties) == 0);
                assert(shiftRight(three, n, a, placeholderToFillEmpties) == 0);
                assert(shiftRight(two, n, a, placeholderToFillEmpties) == 0);
                assert(shiftRight(allOne, n, a, placeholderToFillEmpties) == 0);
                assert(shiftRight(nineFive, n, a, placeholderToFillEmpties) == 0);
                assert(shiftRight(nineFour, n, a, placeholderToFillEmpties) == 0);
                assert(shiftRight(eightFour, n, a, placeholderToFillEmpties) == 0);
            }
            else
            {
                assert(shiftRight(o, n, a, placeholderToFillEmpties) == n - a);
                assert(shiftRight(four, n, a, placeholderToFillEmpties) == n - a);
                assert(shiftRight(fourRe, n, a, placeholderToFillEmpties) == n - a);
                assert(shiftRight(five, n, a, placeholderToFillEmpties) == n - a);
                assert(shiftRight(fiveRe, n, a, placeholderToFillEmpties) == n - a);
                assert(shiftRight(three, n, a, placeholderToFillEmpties) == n - a);
                assert(shiftRight(two, n, a, placeholderToFillEmpties) == n - a);
                assert(shiftRight(allOne, n, a, placeholderToFillEmpties) == n - a);
                assert(shiftRight(nineFive, n, a, placeholderToFillEmpties) == n - a);
                assert(shiftRight(nineFour, n, a, placeholderToFillEmpties) == n - a);
                assert(shiftRight(eightFour, n, a, placeholderToFillEmpties) == n - a);

            }



        }
    }
    for (int i = -1; i <= 5; i++)//fliparound function
    {
       
        string a[7] = { "ee", "dd", "cc", "bb", "aa", "BB", "AA" };
        string b[7] = { "ee", "BB", "BB", "BB", "cc", "dd", "AA" };
        string c[7] = { "5", "1", "5", "2", "10", "11", "15" };
        string people[5] = { "samwell", "jon", "margaery,", "daenerys", "tyrion" };
        string folks[8] = { "samwell", "jon", "margaery", "daenerys", "tyrion", "sansa", "howard123", "jon" };
        string fivet[5] = { "1","2","3","4","5" };
        string twot[5] = { "1","2","1","2","1" };
        string o[5] = { "1","2","3","3","4" };
        string four[5] = { "1","2","3","3","4" };
        string fourRe[5] = { "4","3","3","2","1" };
        string five[5] = { "1","2","3","4","5" };
        string fiveRe[5] = { "5","4","3","2","1" };
        string three[5] = { "1","2","1","3","1" };
        string threeRe[5] = { "1","3","1","2","1" };
        string two[5] = { "1","2","1","2","1" };
        string allOne[5] = { "1","1","1","1","1" };
        string nineFive[5] = { "5","6","7","8","9" };
        string nineFour[5] = { "5","4","7","8","9" };
        string eightFour[5] = { "5","4","7","4","8" };
        if (i <= 0)
        {
            assert(flipAround(fivet, i) == -1);
            assert(flipAround(twot, i) == -1);
            assert(flipAround(a, i) == -1);
            assert(flipAround(b, i) == -1);
            assert(flipAround(c, i) == -1);
            assert(flipAround(people, i) == -1);
            assert(flipAround(folks, i) == -1);
            assert(flipAround(o, i) == -1);
            assert(flipAround(four, i) == -1);
            assert(flipAround(fourRe, i) == -1);
            assert(flipAround(five, i) == -1);
            assert(flipAround(fiveRe, i) == -1);
            assert(flipAround(three, i) == -1);
            assert(flipAround(threeRe, i) == -1);
            assert(flipAround(two, i) == -1);
            assert(flipAround(allOne, i) == -1);
            assert(flipAround(nineFive, i) == -1);
            assert(flipAround(nineFour, i) == -1);
            assert(flipAround(eightFour, i) == -1);

        }
        else
        {
            assert(flipAround(fivet, i) == i / 2);
            assert(flipAround(twot, i) == i / 2);
            assert(flipAround(a, i) == i / 2);
            assert(flipAround(b, i) == i / 2);
            assert(flipAround(c, i) == i / 2);
            assert(flipAround(people, i) == i / 2); 
            assert(flipAround(folks, i) == i / 2); 
            assert(flipAround(o, i) == i / 2);
            assert(flipAround(four, i) == i / 2);
            assert(flipAround(fourRe, i) == i / 2);
            assert(flipAround(five, i) == i / 2);
            assert(flipAround(fiveRe, i) == i / 2);
            assert(flipAround(three, i) == i / 2);
            assert(flipAround(threeRe, i) == i / 2);
            assert(flipAround(two, i) == i / 2);
            assert(flipAround(allOne, i) == i / 2);
            assert(flipAround(nineFive, i) == i / 2);
            assert(flipAround(nineFour, i) == i / 2);
            assert(flipAround(eightFour, i) == i / 2);
            
            
        }
    }


    for (int n1 = -2; n1 < 6; n1++)//nested for loop to test the union function 
    {
        for (int n2 = -2; n2 < 6; n2++)
        {

            unionWithNoDuplicates(o, n1, fourRe, n2, resultingString, resultingSize);
            if (n1 <= 0 || n2 <= 0)
            {
                assert(resultingSize == -1);
            }
            else
            {
                assert(resultingSize == (n1 + n2 - dupNum(o, n1, fourRe, n2)));
            }
            unionWithNoDuplicates(o, n1, four, n2, resultingString, resultingSize);
            if (n1 <= 0 || n2 <= 0)
            {
                assert(resultingSize == -1);
            }
            else
            {
                assert(resultingSize == (n1 + n2 - dupNum(o, n1, four, n2)));
            }
            unionWithNoDuplicates(five, n1, two, n2, resultingString, resultingSize);
            if (n1 <= 0 || n2 <= 0)
            {
                assert(resultingSize == -1);
            }
            else
            {
                assert(resultingSize == (n1 + n2 - dupNum(five, n1, two, n2)));
            }
            unionWithNoDuplicates(allOne, n1, nineFive, n2, resultingString, resultingSize);
            if (n1 <= 0 || n2 <= 0)
            {
                assert(resultingSize == -1);
            }
            else
            {
                assert(resultingSize == (n1 + n2 - dupNum(allOne, n1, nineFive, n2)));
            }
            unionWithNoDuplicates(eightFour, n1, five, n2, resultingString, resultingSize);
            if (n1 <= 0 || n2 <= 0)
            {
                assert(resultingSize == -1);
            }
            else
            {
                assert(resultingSize == (n1 + n2 - dupNum(eightFour, n1, five, n2)));
            }


        }

    }
    return 0;
}
















