#include<bits/stdc++.h>
using namespace std;
#define REP(i,a,b) for(int i=a; i<b; i++)

int func(vector<string> &A) {
    return A.size();
}

int main()
{
    vector<string> A = {"shagil", "sruti", "trisha"};

    cout<<func(A);

    return 0;
}