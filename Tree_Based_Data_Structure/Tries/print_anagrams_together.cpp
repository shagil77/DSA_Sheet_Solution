//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    
  public:
    vector<vector<string> > Anagrams(vector<string>& string_list) {
        //code here
        int n = string_list.size();
        vector<vector<string>> ans;
        
        map<multiset<char>, int> mp;
        int idx=1;
        
        for(auto str:string_list) {
            multiset<char> ms(str.begin(), str.end());
            if(mp[ms]==0) {
                mp[ms] = idx;
                ans.push_back({str});
                idx++;
            } else {
                ans[mp[ms]-1].push_back(str);
            }
        }
        
        sort(ans.begin(), ans.end());
        
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<string> string_list(n);
        for (int i = 0; i < n; ++i)
            cin>>string_list[i]; 
        Solution ob;
        vector<vector<string> > result = ob.Anagrams(string_list);
        sort(result.begin(),result.end());
        for (int i = 0; i < result.size(); i++)
        {
            for(int j=0; j < result[i].size(); j++)
            {
                cout<<result[i][j]<<" ";
            }
            cout<<"\n";
        }
    }

    return 0;
}

// } Driver Code Ends