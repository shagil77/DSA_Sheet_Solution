#include<bits/stdc++.h>
using namespace std;

struct Node {
    Node *links[26];
    bool flag=false;
    
    bool containsKey(char ch) {
        return (links[ch-'a'] != NULL);
    }
    void put(char ch, Node *node) {
        links[ch-'a']=node;
    }
    Node *get(char ch) {
        return links[ch-'a'];
    }
    void setEnd() {
        flag=true;
    }
    bool getEnd() {
        return flag;
    }
};

class Trie {
    private:
    Node *root;
    
    public:
    Trie() {
        root=new Node();
    }
    void insert(string word) {
        Node *node=root;
        for(int i=0; i<word.length(); i++) {
            if(!node->containsKey(word[i])) {
                node->put(word[i], new Node());
            }
            node=node->get(word[i]);
        }
        node->setEnd();
    }
    bool search(string word) {
        Node *node=root;
        for(int i=0; i<word.length(); i++) {
            if(!node->containsKey(word[i])) {
                return false;
            }
            node=node->get(word[i]);
        }
        return (node->getEnd());
    }
};

bool sortbysecdesc(const pair<int,int> &a, const pair<int,int> &b)
{
    if(a.second == b.second) return (a.first < b.first);
    return a.second>b.second;
}

vector<int> solve(string A, vector<string> &B) {
    int n=B.size();
    vector<pair<int,int>> ic; // index, count
    vector<int> ans;
    Trie *trie=new Trie();
    int pos=-1;
    for(int i=0; i<A.length(); i++) {
        if(A[i]=='_') {
            trie->insert(A.substr(pos+1, i-pos-1));
            pos=i;
        } else if(i==(A.length()-1)) {
            trie->insert(A.substr(pos+1, i-pos));
            pos=i;
        }
    }
    
    for(int j=0; j<n; j++) {
        string s=B[j];
        int p=-1, count=0;
        for(int i=0; i<s.length(); i++) {
            if(s[i]=='_') {
                if(trie->search(s.substr(p+1, i-p-1))) {
                    count++;
                }
                p=i;
            } else if(i==(s.length()-1)) {
                if(trie->search(s.substr(p+1, i-p))) {
                    count++;
                }
                p=i;
            }
        }
        ic.push_back(make_pair(j,count));
    }
    
    sort(ic.begin(), ic.end(), sortbysecdesc);
    
    for(auto pr:ic) {
        ans.push_back(pr.first);
    }
    
    return ans;
}
// "_"

int main()
{
    string a="cool_ice_wifi";
    vector<string> b={"water_is_cool", "cold_ice_drink", "cool_wifi_speed"};

    vector<int> ans=solve(a, b);

    for(auto it:ans) cout<<it<<" ";

    return 0;
}