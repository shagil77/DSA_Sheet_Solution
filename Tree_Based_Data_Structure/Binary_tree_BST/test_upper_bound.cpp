#include<bits/stdc++.h>
using namespace std;
#define REP(i,a,b) for(int i=a; i<b; i++)



int main()
{
    vector<int> v={13,3,1,2,4,12,10,5,8,7,6,9,11,14,18};

    auto upper = upper_bound(v.begin(), v.end(), 18);

    cout<<(upper-v.begin())<<endl;

    

    return 0;
}