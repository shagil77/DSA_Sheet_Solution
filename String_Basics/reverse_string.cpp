#include<bits/stdc++.h>
using namespace std;
#define REP(i,a,b) for(int i=a; i<b; i++)

string trim(const string &s)
{
    auto start = s.begin();
    while (start != s.end() && std::isspace(*start)) {
        start++;
    }
 
    auto end = s.end();
    do {
        end--;
    } while (distance(start, end) > 0 && isspace(*end));
 
    return string(start, end + 1);
}

string solver(string A) {
    A=trim(A);
    string ans="";
    int i=A.length()-1, j=A.length()-1;
    while(j>=0) {
        while(A[j]!=' ') {
            j--;
            if(j==-1) break;
        }
        ans+=A.substr(j+1, i-j)+' ';
        
        if(j==-1) {
            break;
        }
        else {
            while(A[j]==' ') {
                j--;
            }
            i=j;
        }
        
    }
    return ans;
}

int main()
{
    cout<<solver("  the  sky is   blue   ");

    return 0;
}