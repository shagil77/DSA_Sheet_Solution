#include<bits/stdc++.h>
using namespace std;

class Solution {
    
    int calcMinMoves(int s, int n, map<int,pair<int,int>> mp, vector<vector<int>> &board, vector<vector<bool>> &vis){
        if(s==n*n) return 0;

        int i=mp[s].first, j=mp[s].second;
        // vis[i][j]=true;
        
        int minMove=INT_MAX;
        
        for(int move=1; move<=6; move++) {
            if(s+move>n*n) break;

            int next = min(s+move, n*n);
            
            int x=mp[next].first, y=mp[next].second;

            if(!vis[x][y]) {
                int nxtMove = (board[x][y]==-1)?next:board[x][y];
                cout<<nxtMove<<"\n";
                minMove=1+min(minMove, calcMinMoves(nxtMove, n, mp, board,vis));
            }            
        }
        
        return minMove;
    }
    
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n=board.size();
        vector<vector<bool>> vis(n, vector<bool>(n, false));
        
        map<int, pair<int,int>> mp;

        int rev=0, pos=0;
        for(int i=n-1; i>=0; i--) {
            if(rev==0) {
                for(int j=0; j<n; j++) {
                    pos++;
                    mp[pos]={i,j};
                }
                
                rev=1;
            } else {
                for(int j=n-1; j>=0; j--) {
                    pos++;
                    mp[pos]={i,j};
                }
                
                rev=0;
            }
        }

        for(auto it:mp) {
            cout<<it.first<<" "<<it.second.first<<" "<<it.second.second<<"\n";
        }
        
        return calcMinMoves(1,n,mp,board,vis);
    }
};

int main()
{
    Solution s;
    vector<vector<int>> matrix = {{-1,-1,-1,-1,-1,-1},{-1,-1,-1,-1,-1,-1},{-1,-1,-1,-1,-1,-1},{-1,35,-1,-1,13,-1},{-1,-1,-1,-1,-1,-1},{-1,15,-1,-1,-1,-1}};

    cout<<s.snakesAndLadders(matrix);

    return 0;
}