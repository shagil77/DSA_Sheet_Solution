#include <bits/stdc++.h>
using namespace std;
#define REP(i, a, b) for (int i = a; i < b; i++)

static bool sortByFreq(const pair<int, int> &a, const pair<int, int> &b)
{
    if (a.second == b.second)
        return (a.first > b.first);
    return (a.second > b.second);
}
vector<int> topK(vector<int> &nums, int k)
{
    // Code here
    vector<int> ans;
    vector<pair<int, int>> vi;
    unordered_map<int, int> mp;
    for (auto it : nums)
        mp[it]++;

    for (auto p : mp)
        vi.push_back(p);

    sort(vi.begin(), vi.end(), sortByFreq);

    for (auto elem : vi)
    {
        ans.push_back(elem.first);
        k--;
        if (k == 0)
            break;
    }

    return ans;
}

int main()
{

    return 0;
}