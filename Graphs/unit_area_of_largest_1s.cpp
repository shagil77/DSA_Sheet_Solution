//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int bfs(int s, vector<int> adj[], vector<vector<bool>> &vis, int n, int m)
    {
        int i = s / m, j = s % m;
        vis[i][j] = true;
        queue<int> q;
        q.push(s);
        int c = 0;

        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            c++;

            for (auto it : adj[node])
            {
                int x = it / m, y = it % m;
                if (!vis[x][y])
                {
                    vis[x][y] = true;
                    q.push(it);
                }
            }
        }
        return c;
    }
    // Function to find unit area of the largest region of 1s.
    int findMaxArea(vector<vector<int>> &grid)
    {
        // Code here
        int row[] = {1,1,0,1};
        int col[] = {1,0,1,-1};
        int n = grid.size(), m = grid[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        vector<int> adj[n * m];
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 1)
                {
                    for (int k = 0; k < 4; k++)
                    {
                        int x = i + row[k], y = j + col[k];
                        if ((x >= 0 && x < n) && (y >= 0 && y < m))
                        {
                            if (grid[x][y] == 1)
                            {
                                adj[i * m + j].push_back(x * m + y);
                                adj[x * m + y].push_back(i * m + j);
                            }
                        }
                    }
                }
            }
        }
        
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {

                if (!vis[i][j] && grid[i][j] != 0)
                {
                    int source = i * m + j;
                    ans = max(ans, bfs(source, adj, vis, n, m));
                }
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m, -1));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.findMaxArea(grid);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends