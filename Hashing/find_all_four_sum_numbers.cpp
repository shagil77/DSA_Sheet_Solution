#include <bits/stdc++.h>
using namespace std;
#define REP(i, a, b) for (int i = a; i < b; i++)

vector<vector<int>> fourSum(vector<int> &arr, int ksum)
{
    // Your code goes here
    int n=arr.size();
    vector<vector<int>> ans;
    unordered_map<int, int> ump;

    for(auto a:arr) ump[a]++;

    sort(arr.begin(), arr.end());

    for(int i=0; i<n-3; i++) {
        for(int j=i+1; j<n-2; j++) {
            for(int k=j+1; k<n-1; k++) {
                int s=arr[i]+arr[j]+arr[k];
                if(s<=ksum) {
                    ump[arr[i]]--;
                    ump[arr[j]]--;
                    ump[arr[k]]--;
                    if(ump[ksum-s]!=0) {
                        vector<int> v={arr[i], arr[j], arr[k], ksum-s};
                        sort(v.begin(), v.end());
                        if(count(ans.begin(), ans.end(), v)==0) {
                            
                            ans.push_back(v);
                        }
                    }
                    ump[arr[i]]++;
                    ump[arr[j]]++;
                    ump[arr[k]]++;
                }
            }
        }
    }
    return ans;
}

    vector<vector<int>> fourSum2(vector<int> &arr, int ksum)
{
    // Your code goes here
    int n=arr.size();
    vector<vector<int>> f_ans;
    set<vector<int>> ans;

    sort(arr.begin(), arr.end());

    
    for(int i=0; i<n-3; i++) {
        for(int j=i+1; j<n-2; j++) {
            int l=j+1, r=n-1;
            while(l<r) {
                int s=arr[i]+arr[j]+arr[l]+arr[r];
                if(s==ksum) {
                    vector<int> v={arr[i],arr[j],arr[l],arr[r]};
                    ans.insert(v);
                    l++;
                    r--;
                }
                else if(s>ksum) r--;
                else l++;
            }
        }
    }
    for(auto elem:ans) f_ans.push_back(elem);
    return f_ans;
}
int main()
{
    int N = 7, K = 23;
    vector<int> A = {10,2,3,4,5,7,8};

    vector<vector<int>> v=fourSum2(A, K);
    

    for(auto i:v) {
        for(auto j:i) cout<<j<<" ";
        cout<<"\n";
    }
    return 0;
}