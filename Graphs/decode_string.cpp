#include<bits/stdc++.h>
using namespace std;

string getDecodedString(int count, string encodedString) {
    int n=encodedString.length();
    string ans="";
    string temp="";
    int i=0;

    while(i<n) {
        if(48<=encodedString[i] && encodedString[i]<=57) {
            string cnt = encodedString.substr(i, encodedString.find('[', i)-i);
            i=encodedString.find('[', i)+1;

            string encStr = "";
            int open=1;
            while(open!=0) {
                if(encodedString[i]=='[') open++;
                else if(encodedString[i]==']') open--;
                if(open==0) break;
                encStr+=encodedString[i];
                i++;
            }
            i++;


            temp+=getDecodedString(stoi(cnt), encStr);
            
        } else {
            temp+=encodedString[i];
            i++;
        }
        
    }

    for(int i=0; i<count; i++) ans+=temp;
    return ans;
}



int main()
{
    string encodedString = "2[abc]3[cd]ef";
    int n=encodedString.length();
    cout<<getDecodedString(1, encodedString);

    return 0;
}