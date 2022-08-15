#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int ladderLength(string beginWord, string endWord, vector<string> &wordList)
    {
        unordered_set dict(wordList.begin(), wordList.end()); // O(1) searching time
        queue<pair<string, int>> seq;
        seq.push({beginWord, 1});
        while (!seq.empty())
        {
            pair<string, int> p = seq.front();
            string word = p.first;
            int ladder = p.second;
            seq.pop();
            if (word == endWord)
            {
                return ladder;
            }
            dict.erase(word);
            for (int j = 0; j < word.size(); j++)
            {
                char c = word[j];
                for (int k = 0; k < 26; k++)
                {
                    word[j] = 'a' + k;
                    if (dict.find(word) != dict.end())
                    {
                        seq.push({word, ladder + 1});
                    }
                }
                word[j] = c;
            }
        }
        return 0;
    }
};


int main()
{
    return 0;
}