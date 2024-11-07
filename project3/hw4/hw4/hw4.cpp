#include <iostream>
using namespace std;
int foo(const int& i, const double& d, const char& c)
{
    return i + d + c;
}

int main()
{
    int a = 1;
    double d = 2.0;
    char c = 'A';
    cout << foo(c, a, d);
    cout << "   " << a << "   " << d << "   " << c;
    return(0);
}