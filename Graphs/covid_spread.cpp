//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    struct node
    {
        int i;
        int j;
        int t;
        node(int _i, int _j, int _t) {
            i=_i;
            j=_j;
            t=_t;
        }
    };
    
    int helpaterp(vector<vector<int>> hospital)
    {
        // code here
        int r = hospital.size(), c = hospital[0].size();
        int row[] = {1, -1, 0, 0};
        int col[] = {0, 0, 1, -1};
        vector<vector<int>> time(r, vector<int>(c, -1));
        queue<node> q;

        int ans = INT_MIN;
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                if (hospital[i][j]==2)
                {
                    q.push(node(i,j,0));
                }
            }
        }
        while(!q.empty()) {
            int i=q.front().i, j=q.front().j, t=q.front().t;
            q.pop();

            for (int k = 0; k < 4; k++)
            {
                int x1 = i + row[k], y1 = j + col[k];

                if ((x1 >= 0 && x1 < r) && (y1 >= 0 && y1 < c))
                {
                    if (hospital[x1][y1] == 1 && time[x1][y1]==-1)
                    {
                        
                        time[x1][y1]=1+t;
                        q.push(node(x1,y1,time[x1][y1]));
                    }
                }
            }
        }
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                if (hospital[i][j]==1 && time[i][j]==-1)
                {
                    return -1;
                }
                ans=max(ans, time[i][j]);
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int R;
        int C;

        cin >> R >> C;
        vector<vector<int>> hospital;
        int i, j;
        for (i = 0; i < R; i++)
        {
            vector<int> temp;
            for (j = 0; j < C; j++)
            {
                int k;
                cin >> k;
                temp.push_back(k);
            }
            hospital.push_back(temp);
        }

        Solution ob;
        int ans = ob.helpaterp(hospital);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends