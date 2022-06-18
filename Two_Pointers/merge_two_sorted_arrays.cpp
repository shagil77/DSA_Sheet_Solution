#include<bits/stdc++.h>
using namespace std;
#define REP(i,a,b) for(int i=a; i<b; i++)

void merge2sortedArrays(vector<int> &A, vector<int> &B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int n1=A.size(), n2=B.size();
    vector<int> ans;
    int i=0, j=0;
    while(i<n1 && j<n2) {
        if(A[i]<B[j]) {
            ans.push_back(A[i]);
            i++;
        }
        else {
            ans.push_back(B[j]);
            j++;
        }
    }
    while(i<n1) {
        ans.push_back(A[i]);
        i++;
    }
    while(j<n2) {
        ans.push_back(B[j]);
        j++;
    }
    A.clear();
    A=ans;
}


int main()
{


    return 0;
}