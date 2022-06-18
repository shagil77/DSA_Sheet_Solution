#include<bits/stdc++.h>
using namespace std;
#define REP(i,a,b) for(int i=a; i<b; i++)



int main()
{
    vector<int> a;
    a.push_back(1);
    a.push_back(1);
    a.push_back(1);
    a.push_back(1);

    vector<int> b;
    b.push_back(2);
    b.push_back(2);
    b.push_back(2);
    b.push_back(2);

    a.clear();
    a=b;

    cout<<a.size();

    return 0;
}
