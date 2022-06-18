#include<bits/stdc++.h>
using namespace std;
#define REP(i,a,b) for(int i=a; i<b; i++)

int countSmaller(vector<vector<int>>& matrix, int mid) { //no of elements <= mid
        int n=matrix[0].size(), ans;
        int i=n-1, j=0, c=0;
        while(i>=0 && j<n) {
            if(matrix[i][j]<=mid) {
                c+=i+1;
                j++;
            } else {
                i--;
            }
        }
        return c;
    }

int main()
{
    vector<vector<int>> matrix = {{1,5,9},{10,11,13},{12,13,15}};

    cout<<countSmaller(matrix, 13);

    return 0;
}