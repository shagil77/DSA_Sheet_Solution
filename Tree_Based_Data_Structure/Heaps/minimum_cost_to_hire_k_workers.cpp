#include<bits/stdc++.h>
using namespace std;

/* Solution I
class Solution {
    double correctToNDecimalPlaces(double num, int n) {
        return (ceil(num*pow(10,n))/pow(10,n));
    }
public:
   double mincostToHireWorkers(vector<int> q, vector<int> w, int K) {
        vector<vector<double>> workers;
        for (int i = 0; i < q.size(); ++i)
            workers.push_back({(double)(w[i]) / q[i], (double)q[i]});
        sort(workers.begin(), workers.end());
        double res = DBL_MAX, qsum = 0;
        priority_queue<int> pq;
        for (auto worker: workers) {
            qsum += worker[1], pq.push(worker[1]);
            if (pq.size() > K) qsum -= pq.top(), pq.pop();
            if (pq.size() == K) res = min(res, qsum * worker[0]);
        }
        return correctToNDecimalPlaces(res, 5);
    }
};*/

class Solution {
    double correctToNDecimalPlaces(double num, int n) {
        return (ceil(num*pow(10,n))/pow(10,n));
    }
public:
   double mincostToHireWorkers(vector<int> quality, vector<int> expectedWage, int k) {
       int n= quality.size();
       vector<pair<double, int>> worker(n);
       
       for(int i=0; i<n; i++) {
           double ratio = (double) expectedWage[i]/quality[i];
           worker[i] = {ratio, quality[i]};
       }
       sort(worker.begin(), worker.end());
       
       priority_queue<int> maxHeap;
       int sumHeap = 0;
       for(int i=0; i<k; i++) {
           maxHeap.push(worker[i].second);
           sumHeap += worker[i].second;
       }
       
       double captainRatio = worker[k-1].first;
       double minCost = captainRatio * sumHeap;
       
       for(int i=k; i<n; i++) {
           captainRatio = worker[i].first; 
           
           if(!maxHeap.empty() && worker[i].second < maxHeap.top()) {
               sumHeap -= maxHeap.top();
               maxHeap.pop();
               sumHeap += worker[i].second;
               maxHeap.push(worker[i].second);
           }
           
           double cost = captainRatio * sumHeap;
           minCost = min(minCost, cost);
       }
       return minCost;
    }
};

int main()
{


    return 0;
}