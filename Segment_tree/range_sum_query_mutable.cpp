#include<bits/stdc++.h>
using namespace std;

class NumArray {
    int N;
    vector<int> arr;
    vector<int> seg;
    
    void build(int index, int low, int high) {
        if(low==high) {
            seg[index]=arr[low];
            return;
        }
        
        int mid=(low+high)/2;
        build(2*index+1, low, mid);
        build(2*index+2, mid+1, high);
        
        seg[index] = seg[2*index+1] + seg[2*index+2];
    }
    
    void buildUpdate(int index, int low, int high, int updatedIdx) {
        if(low==high && updatedIdx==low) {
            seg[index] = arr[updatedIdx];
            return;
        } 
        
        int mid = (low+high)/2;
        if(updatedIdx>=low && updatedIdx<=mid) {
            buildUpdate(2*index+1, low, mid, updatedIdx);
        } else {
            buildUpdate(2*index+2, mid+1, high, updatedIdx);
        }
        
        seg[index]=seg[2*index+1] + seg[2*index+2];
    }
    
    int sumRangeUtil(int index, int low, int high, int l, int r) {
        if(low>=l && high<=r) return seg[index];
        if(high<l || low>r) return 0;
        
        int mid=(low+high)/2;
        int left = sumRangeUtil(2*index+1, low, mid, l, r);
        int right = sumRangeUtil(2*index+2, mid+1, high, l, r);
        
        return (left+right);
    }
    
public:
    
    NumArray(vector<int>& nums) {
        N=nums.size();
        seg.resize(4*N+4);
        
        for(auto it:nums) arr.push_back(it);
        
        build(0, 0, N-1);
    }
    
    void update(int index, int val) {
        arr[index] = val;
        
        buildUpdate(0, 0, N-1, index);
    }
    
    int sumRange(int left, int right) {
        return sumRangeUtil(0, 0, N-1, left, right);
    }
};

int main()
{


    return 0;
}