#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    //Function to find the smallest positive number missing from the array.
    int missingNumber(int arr[], int n) 
    { 
        // Your code here
        int smallestPosMissNum = 1;
        priority_queue<int, vector<int>, greater<int>> pq;
        
        for(int i=0; i<n; i++) {
            if(arr[i]>0) {
                pq.push(arr[i]);
            }
        }
        
        while(!pq.empty()) {
            int curr = pq.top();
            pq.pop();
            
            if(curr>smallestPosMissNum) break;
            
            if(curr==smallestPosMissNum) {
                smallestPosMissNum++;
            }
        }
        
        return smallestPosMissNum;
    } 
};

int main()
{


    return 0;
}