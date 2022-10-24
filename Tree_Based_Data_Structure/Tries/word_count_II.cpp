#include<bits/stdc++.h>
using namespace std;
#define REP(i,a,b) for(int i=a; i<b; i++)

class Solution {
    int m, n;
    vector<string> ans;
    vector<vector<int>> DIR = {{0,1}, {1,0}, {0,-1}, {-1,0}};
    struct Node {
        Node *links[26];
        int index = -1;
        
        bool containsKey(char ch) {
            int idx = ch-'a';
            if(idx<0 || idx>25) return false;
            return (links[ch-'a']!=NULL);
        }
        
        void put(char ch, Node *node) {links[ch-'a'] = node;}
        
        Node *getNext(char ch) {return links[ch-'a'];}
        
        int getIndex() {return index;}
        
        void setIndex(int idx) {index = idx;}
    };
    
    void addWord(string word, int index, Node* root) {
        Node *node = root;
        for(int i=0; i<word.length(); i++) {
            if(!node->containsKey(word[i])) node->put(word[i], new Node());
            
            node = node->getNext(word[i]);
        }
        node->setIndex(index);
    }
    
    void solve(int x, int y, Node *root, vector<vector<char>> &board, vector<string>& words) {
        if(x<0 || x==m || y<0 || y==n || board[x][y]=='#' || !root->containsKey(board[x][y])) return;
        
        char ch = board[x][y];
        root = root->getNext(ch);
        if(root->getIndex()!=-1) {
            ans.push_back(words[root->getIndex()]);
            root->setIndex(-1);
        }
        
        board[x][y] = '#';
        for (int i = 0; i < 4; i++) solve(x + DIR[i][0], y + DIR[i][1], root, board, words);
        board[x][y] = ch; // restore org state
    }
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        m = board.size();
        n = board[0].size();
        Node *root = new Node();
        for(int i=0; i<words.size(); i++) addWord(words[i], i, root);
        
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                solve(i, j, root, board, words);
            }
        }
        
        return ans;
    }
};


int main()
{
    Solution sol;
    vector<vector<char>> board = {{'a', 'a'}};
    // {{'a','b','c','e'},{'x','x','c','d'},{'x','x','b','a'}}
    
    vector<string> words = {"aa"};

    vector<string> ans = sol.findWords(board, words);

    for(auto it:ans) cout<<it<<" ";
    return 0;
}