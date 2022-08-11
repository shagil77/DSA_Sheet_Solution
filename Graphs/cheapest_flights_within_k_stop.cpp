#include<bits/stdc++.h>
using namespace std;

class Solution {
    struct Node{
        int node;
        int price;
        int stops;
    };
    struct ComparePrice {
        bool operator()(Node const& n1, Node const& n2) {
            return (n1.price<n2.price);
        }
    };

public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>> adj[n];
        vector<int> vis(n, 0);
        vector<int> stop(n, 0);
        vector<int> price(n, INT_MAX);
        priority_queue<Node, vector<Node>, ComparePrice> pq;
        // dist, node
        
        for(auto it:flights) {
            adj[it[0]].push_back({it[1],it[2]});
        }
        
        price[src]=0;
        pq.push({src, price[src], 0});
        
        while(!pq.empty()) {
            int node=pq.top().node, nodePrice = pq.top().price, nodeStop=pq.top().stops;
            pq.pop();

            for(auto it:adj[node]) {
                int child=it.first, childPrice=it.second;

                if(nodeStop<=k) {
                    if(nodePrice+childPrice<price[child]) {
                        price[child] = nodePrice+childPrice;
                        pq.push({child, price[child], nodeStop+1});
                    }
                }
            }
        }


        return ((price[dst]==INT_MAX)?-1:price[dst]);
    }
};

int main()
{
    // n = 4, flights = [[0,1,100],[1,2,100],[2,0,100],[1,3,600],[2,3,200]], src = 0, dst = 3, k = 1
    int n=4, src=0, dst=3, k=1;
    vector<vector<int>> flights = {{0,1,100},{1,2,100},{2,0,100},{1,3,600},{2,3,200}};
    Solution s;
    cout<<s.findCheapestPrice(n, flights, src, dst, k);

    return 0;
}