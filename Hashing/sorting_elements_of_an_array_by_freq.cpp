#include<bits/stdc++.h>
using namespace std;
#define REP(i,a,b) for(int i=a; i<b; i++)

bool sortbysec(const pair<int,int> &a,const pair<int,int> &b)
{
    return (a.second > b.second);
}

vector<int> sortByFreq(int arr[],int n)
    {
        //Your code here
        vector<int> ans;
        vector<pair<int,int>> vi;
        unordered_map<int,int> mp1;

        for(int i=0; i<n; i++) { // mp1[element]=freq
            mp1[arr[i]]++;
        }
        for(auto elem:mp1) {
            for(int i=0; i<elem.second; i++) vi.push_back(elem);
        }

        sort(vi.begin(), vi.end(), sortbysec);

        for(auto it:vi) ans.push_back(it.first);
        return ans;
    }

int main()
{
    int arr[]={5,5,4,6,4};
    vector<int> a=sortByFreq(arr, 5);

    for(auto i:a) cout<<i<<" ";

    return 0;
}