#include<bits/stdc++.h>
using namespace std;
#define REP(i,a,b) for(int i=a; i<b; i++)

int threeSumClosest(vector<int> &A, int B) {
    sort(A.begin(), A.end());
    int n1=A.size();
    int ans=INT_MIN;
    
    for(int i=0; i<n1-2; i++) {
        int one=i+1, two=n1-1;
        while(one<two) {
            if(A[one]+A[two]+A[i]<B) {
                
                if(B-(A[one]+A[two]+A[i])<B-ans) {
                    ans=(A[one]+A[two]+A[i]);
                }
                one++;
            }
            else if(A[one]+A[two]+A[i]==B) {
                return B;
            }
            else {
                two--;
            }
        }
    }
    return ans;
}


int main()
{


    return 0;
}