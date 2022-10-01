#include<bits/stdc++.h>
using namespace std;

class Solution {
    struct Point {
        float dist;
        int x;
        int y;
        
        Point(float dist, int x, int y)
            :dist(dist), x(x), y(y)
            {}
    };
    
    
    struct ComparePoints {
        bool operator()(Point const& p1, Point const& p2) {
            return (p1.dist>p2.dist);
        }
    };
    

    
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        
        priority_queue<Point, vector<Point>, ComparePoints> pq;
        vector<vector<int>> ans(k, vector<int>(2));
        
        
        for(auto point:points) {
            int x = point[0], y = point[1];
            int x2 = x*x, y2 = y*y;
            pq.push(Point(sqrt(x2+y2), x, y));
            // cout<<sqrt(x2+y2)<<" "<<x<<" "<<y<<"\n";
        }
        
        for(int i=0; i<k; i++) {
            Point point = pq.top();
            pq.pop();
            ans[i] = {point.x, point.y};
        }
        
        return ans;
    }
};

int main()
{


    return 0;
}