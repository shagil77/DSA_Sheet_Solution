#include<bits/stdc++.h>
using namespace std;
#define REP(i,a,b) for(int i=a; i<b; i++)

struct Node {
    Node *links[26];
    int countEndsWith=0;
    int countPrefix=0;

    void put(char ch, Node *node) {
        links[ch-'a']=node;
    }
    Node *get(char ch) {
        return links[ch-'a'];
    }
    bool containsKey(char ch) {
        return (links[ch-'a']!=NULL);
    }
    void incrementCP() {
        countPrefix++;
    }
    void decreasePrefix() {
        countPrefix--;
    }
    void deleteWord() {
        countEndsWith--;
    }
    void incrementEndsWith() {
        countEndsWith++;
    }
    int getEnd() {
        return countEndsWith;
    }
    int getPrefix() {
        return countPrefix;
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
            node->incrementCP();
        }
        node->incrementEndsWith();
    }

    int countWordsEqualTo(string word) {
        Node *node=root;
        for(int i=0; i<word.length(); i++) {
            if(!node->containsKey(word[i])) {
                return 0;
            }
            node=node->get(word[i]);
        }
        return (node->getEnd());
    }

    int countWordsStartingWith(string word) {
        Node *node=root;
        for(int i=0; i<word.length(); i++) {
            if(!node->containsKey(word[i])) {
                return 0;
            }
            node=node->get(word[i]);
        }
        return (node->getPrefix());
    }
    void erase(string word) {
        Node *node=root;
        for(int i=0; i<word.length(); i++) {
            if(!node->containsKey(word[i])) {
                return;
            }
            node=node->get(word[i]);
            node->decreasePrefix();
        }
        node->deleteWord();
    }
};

int main()
{
    Trie *trie=new Trie();
    

    return 0;
}