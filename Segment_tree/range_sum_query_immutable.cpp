#include<bits/stdc++.h>
using namespace std;

class NumArray {
    int N;
    vector<int> seg;
    vector<int> arr;
    
public:
    NumArray(vector<int>& nums) {
        N=nums.size();
        seg.resize(4*N+4);

        for(auto it:nums) arr.push_back(it);
        build(0, N-1, 0);
    }
    
    void build(int low, int high, int index) {
        if(low==high) {
            seg[index]=arr[low];
            return;
        }
        
        int mid = (low+high)/2;
        build(low, mid, 2*index+1);
        build(mid+1, high, 2*index+2);
        
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
    
    int sumRange(int left, int right) {
        return sumRangeUtil(0, 0, N-1, left, right);
    }
    void printarr() {
        for(auto it:seg) cout<<it<<" ";
        cout<<'\n';
        for(auto it:arr) cout<<it<<" ";
    }
};


int main()
{
    vector<int> a={-2, 0, 3, -5, 2, -1};
    NumArray numarr(a);

    // numarr.printarr();
    cout<<numarr.sumRange(2,5);

    return 0;
}