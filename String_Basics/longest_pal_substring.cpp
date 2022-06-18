#include<bits/stdc++.h>
using namespace std;
#define REP(i,a,b) for(int i=a; i<b; i++)

//DP Approach (not optimal in terms of space complexity: O(N^2))
// string longestPalindrome(string A) {
//     int n=A.length();
//     int dp[n][n];
//     memset(dp, 0, sizeof(dp));
//     int pos=0;
//     while(pos<n) {
//         dp[pos][pos]=1;
//         pos++;
//     }
//     pos=0;
//     while(pos<n-1) {
//         if(A[pos]==A[pos+1]) dp[pos][pos+1]=1;
//         else dp[pos][pos+1]=0;
//         pos++;
//     }
    
//     for(int j=2; j<n; j++) {
//         // for(int i=0; i<n-j; i++) {
//         //     if(A[i]==A[j] && dp[i+1][j-1]) dp[i][j]=1;
//         //     else dp[i][j]=0;
//         // }
//         int i=0;
//         while(i<n-j) {
//             if(A[i]==A[j+i] && dp[i+1][j+i-1]) dp[i][j+i]=1;
//             else dp[i][j+i]=0;
//             i++;
//         }
//     }

//     for(int i=0; i<n; i++) {
//         for(int j=0; j<n; j++) {
//             cout<<dp[i][j]<<" ";
//         }
//         cout<<"\n";
//     }
    
//     int l, r, size=INT_MIN;
//     for(int i=0; i<n; i++) {
//         for(int j=i; j<n; j++) {
//             if(dp[i][j]==1) {
//                 if(j-i+1>size) {
//                     size=j-i+1;
//                     l=i;
//                     r=j;
//                 }
//             }
//         }
//     }
//     return A.substr(l, r-l+1);
// }

string longestPalindrome(string A) {
    int n=A.length(),best_len=0;
    if(n==1) return A;
    string best_s="";
    for(int mid=0; mid<n; mid++) {
        for(int x=0; mid-x>=0 && mid+x<n; x++) {
            if(A[mid+x]!=A[mid-x]) {
                break;
            }
            int len=2*x+1;
            if(len>best_len) {
                best_len=len;
                best_s=A.substr(mid-x, len);
            }
        }
    }

    for(int mid=0; mid<n-1; mid++) {
        for(int x=0; mid-x+1>=0 && mid+x<n; x++) {
            if(A[mid+x]!=A[mid-x+1]) {
                break;
            }
            int len=2*x;
            if(len>best_len) {
                best_len=len;
                best_s=A.substr(mid-x+1, len);
            }
        }
    }

    return best_s;
}


int main()
{
    string A;
    cin>>A;
    cout<<longestPalindrome(A);
    return 0;
}