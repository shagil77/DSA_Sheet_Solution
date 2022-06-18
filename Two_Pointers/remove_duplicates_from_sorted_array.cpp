#include<bits/stdc++.h>
using namespace std;
#define REP(i,a,b) for(int i=a; i<b; i++)

int removeDuplicates(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int i=0, j=1;
    while(j<A.size()) {
        if(A[j]==A[i]) {
            j++;
        }
        else {
            int t=A[j];
            A[j]=A[i+1];
            A[i+1]=t;
            i++;
            j++;
        }
    }
    return i+1;
}


int main()
{


    return 0;
}