#include <bits/stdc++.h>
using namespace std;

double correctToNDecimalPlaces(double num, int n)
{
    return (ceil(num * pow(10, n)) / pow(10, n));
}

int main()
{
    cout << correctToNDecimalPlaces(13.0 / 6.0, 5);

    return 0;
}