#include<bits/stdc++.h>
using namespace std;

class WordDictionary {
    struct Node {
        Node *links[26];
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
    
    bool solve(int idx, Node* node, string word) {
        if(idx==word.length()) return node->getEnd();
        char ch = word[idx];
        
        if(ch=='.') {
            bool ans = false;
            for(int i=0; i<26; i++) {
                if(node->links[i]!=NULL) {
                    ans = ans || solve(idx+1, node->links[i], word);
                }
            }
            
            return ans;
        }
        
        if(node->links[ch-'a']==NULL) return false;
        return solve(idx+1, node->links[ch-'a'], word);
    }
    
    Node* root;
public:
    WordDictionary() {
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
    
    bool search(string word) {
        Node* node = root;

        return solve(0, node, word);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */

int main()
{


    return 0;
}