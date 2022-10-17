#include<bits/stdc++.h>
using namespace std;

//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
    class Trie {
        struct Node {
            Node* links[26];
            bool flag = false;
            
            bool containsKey(char ch) {
                return (links[ch-'a']!=NULL);
            }
            
            void put(char ch, Node* node) {
                links[ch-'a'] = node;
            }
            
            Node* nextNode(char ch) {
                return links[ch-'a'];
            }
            
            void setEnd() {
                flag = true;
            }
            
            bool getEnd() {
                return flag;
            }
        };
        
        Node* root;
        public:
        Trie() {
            root = new Node();
        }
        
        void addWord(string word) {
            Node* node = root;
            for(int i=0; i<word.length(); i++) {
                if(!node->containsKey(word[i])) {
                    node->put(word[i], new Node());
                }
                node = node->nextNode(word[i]);
            }
            node->setEnd();
        }
        
        bool searchWord(string word) {
            Node* node = root;
            for(int i=0; i<word.length(); i++) {
                if(!node->containsKey(word[i])) {
                    return false;
                }
                node = node->nextNode(word[i]);
            }
            return (node->getEnd());
        }
    };
    
    bool solve(string s, Trie* trie) {
        int n = s.length();
        if(n==0) return true;
        
        
        for(int i=1; i<=n; i++) {
            if(trie->searchWord(s.substr(0,i)) && solve(s.substr(i, n), trie)) return true;
        }
        
        return false;
    }
    
    /* Map Solution (Correct)
    bool solve(string s) {
        int n=s.length();
        if(n==0) return true;
        
        for(int i=1; i<=n; i++) {
            if(mp[s.substr(0,i)] && solve(s.substr(i, n))) return true;
        }
        return false;
    }
    unordered_map<string, int> mp;*/
    public:
    // A : given string to search
    // B : vector of available strings
    
    int wordBreak(string A, vector<string> &B) {
        //code here
        int n = A.length();
        Trie* trie = new Trie();
        
        for(auto word:B) trie->addWord(word);
        /*for(auto word:B) mp[word]=1;*/
        
        return solve(A, trie);
        
        /*return solve(A, trie);*/
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> dict;
        for(int i=0;i<n;i++){
            string S;
            cin>>S;
            dict.push_back(S);
        }
        string line;
        cin>>line;
        Solution ob;
        cout<<ob.wordBreak(line, dict)<<"\n";
    }
}

// } Driver Code Ends