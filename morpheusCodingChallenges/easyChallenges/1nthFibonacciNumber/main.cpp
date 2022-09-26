#include <iostream>
#include <math.h>

using namespace std;

int fib(int n);

int main()
{

    int n;
    cin >> n;

    cout << fib(n) << endl;
    return 0;
}

int fib(int n)
{
    long double ergebnis;
    long double a = ((1/2)*(1 + sqrt(5)));
    long double b = ((1/2)*(1 - sqrt(5)));
    long double x = pow(a, n);
    long double y = pow(b, n);
    ergebnis = ((x - y) / sqrt(5));
    return ergebnis;
}