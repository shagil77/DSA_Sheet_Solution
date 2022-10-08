#include<bits/stdc++.h>
using namespace std;

class Solution{
    int M, N;
    bool isSafe(bool graph[][101], vector<int>& colors, int node, int c) {
        for(int i=0; i<N; i++) {
            if(i!=node && graph[node][i] && colors[i]==c) {
                return false;
            }
        }
        return true;
    }
    
    bool solve(int node, bool graph[][101], vector<int>& colors) {
        if(node==N) return true;
        
        for(int color=0; color<M; color++) {
            if(isSafe(graph, colors, node, color)) {
                colors[node] = color;
                
                if(solve(node+1, graph, colors)) return true;
                
                colors[node] = -1;
            }
        }
        
        return false;
    }
public:
    // Function to determine if graph can be coloured with at most M colours such
    // that no two adjacent vertices of graph are coloured with same colour.
    bool graphColoring(bool graph[101][101], int m, int n) {
        // your code here
        M = m;
        N = n;
        vector<int> colors(n, -1);
        return solve(0, graph, colors);
    }
};

int main()
{


    return 0;
}