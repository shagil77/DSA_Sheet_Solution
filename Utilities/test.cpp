#include<bits/stdc++.h>
using namespace std;
#define REP(i,a,b) for(int i=a; i<b; i++)



int main()
{
    string s = "shaaaaagil";
    string s1 = "aaaaagissh";
    multiset<char> ms(s.begin(), s.end());
    multiset<char> ms1(s1.begin(), s1.end());

    cout<<(ms==ms1);

    return 0;
}