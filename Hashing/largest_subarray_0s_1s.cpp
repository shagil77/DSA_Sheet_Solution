#include<bits/stdc++.h>
using namespace std;
#define REP(i,a,b) for(int i=a; i<b; i++)

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Solution{
  public:
    int maxLen(int arr[], int N)
    {
        // Your code here
        unordered_map<int, int> ump;
        int sum=0, maxSize=INT_MIN;
        
        for(int i=0; i<N; i++) {
            if(arr[i]==0) sum-=1;
            else sum+=1;
            
            if(sum==0) maxSize=max(maxSize, i+1);
            else {
                if(ump[sum]==0) {
                    ump[sum]=i+1;
                } else {
                    maxSize=max(maxSize, i+1-ump[sum]);
                }
                    
            }
        }
        if(maxSize==INT_MIN) return 0;
        return maxSize;
    }
};


// { Driver Code Starts.

int main()
{
    // your code goes here
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        Solution obj;
        cout << obj.maxLen(a, n) << endl;
    }
    return 0;
}
