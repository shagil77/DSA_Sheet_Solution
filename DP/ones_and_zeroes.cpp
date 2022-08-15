#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int t[601][101][101];
	
    int solve(vector<string> &s, int m, int n, int index){
        int size= s.size();
        
        if(index>=size || m<0 || n<0) return 0;
        
        if( m==0 && n==0)return 0;
		
        if(t[index][m][n]!=-1)return t[index][m][n];
		
        int i= index;

        int zeros= count(s[i].begin(), s[i].end(),'0');

        int ones= s[i].size()-zeros;
		
        if(m-zeros >=0 && n-ones>=0){
            return t[index][m][n]= max(1+solve(s,m-zeros,n-ones, i+1) , solve( s,m,n,i+1));
        }
		
            return t[index][m][n]= solve( s,m,n,i+1);
    }
    
    int findMaxForm(vector<string>& strs, int m, int n) {
    memset(t,-1, sizeof(t));
        return solve(strs, m,n, 0);
    }
};

int main()
{
    vector<string> strs={"11111","100","1101","1101","11000"};
    int m=7, n=5;
    
    Solution s;
    cout<<s.findMaxForm(strs, m, n);
    // s.printDP();

    return 0;
}