#include<bits/stdc++.h>
using namespace std;
#define REP(i,a,b) for(int i=a; i<b; i++)

class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int n=letters.size();
        int start=0, end=n-1, m;
        
        while(start<end) {
            m=start+(end-start)/2;
            if(letters[m]<=target) {
                if(m+1<n) {
                    if(letters[m+1]>target) return letters[m+1];
                }
                start=m+1;
            }
            else {
                if(m-1>=0) {
                    if(letters[m-1]<=target) return letters[m];
                }
                end=m-1;
            }
            
        }
        return letters[0];
    }
};

int main()
{


    return 0;
}