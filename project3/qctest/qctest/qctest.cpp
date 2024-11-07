// Online C++ compiler to run C++ program online
#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <cassert>
using namespace std;

bool isValidQC(string results);
int passQC(string results);
int defectQC(string results);
int totalQC(string results);
int batches(string results);
int order(int i, string results);
bool digit(int i, string results);
// function that checks to see if passQC + defect QC = totalQC./
bool equal(string results);

int main() {

    assert(isValidQC("Q1p1d1"));
    assert(isValidQC("Q1d1p1"));
    assert(isValidQC("Q1000p1000d10000"));



    return 0;
}

int order(int i, string results)
{   //this function returns 0 for Q is good, 1 when only p is good, 2 when only d is good, return 3 when both p and d is good. 
    int countQ = 0;
    int countP = 0;
    int countD = 0;
    int order = 0;
    int Qmp, Qmd;


    for (int k = 0; k < i; k++)
    {
        char q = results.at(k);
        if (q == 'Q')
        {
            countQ++;
        }
        if (q == 'p')
        {
            countP++;
        }
        if (q == 'd')
        {
            countD++;
        }

    }
    Qmp = countQ - countP;
    Qmd = countQ - countD;
    if (Qmp == 0 && Qmd == 0)//if order = 0, Q is allowed, qpd 
    {
        order = 0;
    }
    else if (Qmp == 1 && Qmd == 0)// qd, 1 means only p 
    {
        order = 1;
    }
    else if (Qmd == 1 && Qmp == 0)//qp, 2 means only d 
    {
        order = 2;
    }
    else //q , 3 means either d or p is okay 
    {
        order = 3;
    }
    return order;
}
bool digit(int i, string results)
{
    bool result = true;
    if (i + 1 < results.size() && !isdigit(results.at(i + 1)))
    {
        result = false;
    }
    if (i + 2 < results.size() && (results.at(i + 1) == '0' && isdigit(results.at(i + 2))))
    {
        result = false;
    }
    return result;

}
bool equal(string results)
{
    bool result = true;
    int Q = 0;
    int p = 0;
    int d = 0;
    int multi = 1;
    for (int i = 0; i < results.size() - 1; i++)
    {
        char k = results.at(i);

        switch (k)
        {
        case 'Q':
            while (isdigit(results.at(i + 1)))//increment the number of digits after Q, loopbackwards starting from k = i+j(number of digits); k>=i i--)
            {
                Q += (results.at(y) - 'O') * multi;
                multi *= 10;
                i++;
            }
        case 'p'://when order returns 1, qd, when order returns 3, q


        case 'd'://when order returns 2, qp, when order returns 3, q 
        }
    }


}
bool isValidQC(string results)
{
    bool result = true;
    if (results.size() < 6)
    {
        result = false;
    }
    if (results.at(0) != 'Q')
    {
        result = false;
    }
    for (int i = 0; i < results.size() && result == true; i++)
    {
        char c = results.at(i);
        switch (c)
        {
        case 'Q':
            if (order(i, results) != 0)
            {
                result = false;
            }
            else if (digit(i, results) == false)
            {
                result = false;
            }
            break;
        case 'p':
            if (order(i, results) != 1 && order(i, results) != 3)
            {
                result = false;
            }
            else if (digit(i, results) == false)
            {
                result = false;
            }
            break;
        case 'd':
            if (order(i, results) != 2 && order(i, results) != 3)
            {
                result = false;
            }
            else if (digit(i, results) == false)
            {
                result = false;
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
        case '0':
            break;

        default:
            result = false;
            break;
        }

    }
    if (!(equal(results)))
    {
        result = false;
    }
    return result;


}
int passQC(string results)
{
    return 100;
}
int defectQC(string results)
{
    return 1;
}
int totalQC(string results)
{
    return 1;
}
int batches(string results)
{
    return 1;
}