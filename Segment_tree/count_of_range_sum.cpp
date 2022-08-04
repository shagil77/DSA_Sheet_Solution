#include<bits/stdc++.h>
using namespace std;
#define vec vector
#define ll long long
#define all(x) x.begin(), x.end()

class Solution {

  void build(vec<ll> &seg, vec<pair<ll, ll>> &cnts, int tl, int tr, int n) {
    if (tl == tr)
      seg[n] = cnts[tl].second;
    else {
      int mid = (tl + tr) / 2;
      build(seg, cnts, tl, mid, 2 * n + 1);
      build(seg, cnts, mid + 1, tr, 2 * n + 2);
      seg[n] = seg[2 * n + 1] + seg[2 * n + 2];
    }
  }

  int query(vec<ll> &seg, int tl, int tr, int l, int r, int n) {
    if (tl == l && tr == r)
      return seg[n];
    else {
      int mid = (tl + tr) / 2;
      ll ans = 0;
      if (r <= mid)
        ans += query(seg, tl, mid, l, r, 2 * n + 1);
      else if (l > mid)
        ans += query(seg, mid + 1, tr, l, r, 2 * n + 2);
      else {
        ans += query(seg, tl, mid, l, min(mid, r), 2 * n + 1);
        ans += query(seg, mid + 1, tr, max(mid + 1, l), r, 2 * n + 2);
      }
      return ans;
    }
  }

  void update(vec<ll> &seg, int tl, int tr, int i, int n) {
    if (tl == tr)
      seg[n] = max(seg[n] - 1, 0LL);
    else {
      int mid = (tl + tr) / 2;
      if (i <= mid)
        update(seg, tl, mid, i, 2 * n + 1);
      else
        update(seg, mid + 1, tr, i, 2 * n + 2);
      seg[n] = seg[2 * n + 1] + seg[2 * n + 2];
    }
  }

public:
  int countRangeSum(vector<int> &nums, int lower, int upper) {
    int n = nums.size();
    map<ll, ll> cnt;
    ll pref = 0;
    for (int i = 0; i < n; i++) {
      cnt.try_emplace(pref + lower, 0);
      cnt.try_emplace(pref + upper, 0);
      cnt[pref + nums[i]] += 1;
      pref += nums[i];
    }
    vec<pair<ll, ll>> cnts;
    cnts.reserve(cnt.size());
    for (auto &p : cnt)
      cnts.push_back(p);
    int m = cnts.size();
    vec<ll> seg(4 * m);
    build(seg, cnts, 0, m - 1, 0);

    ll ans = 0;
    pref = 0;
    for (int i = 0; i < n; i++) {
      int l = lower_bound(all(cnts), pref + lower,
                          [](auto &a, auto b) { return a.first < b; }) -
              cnts.begin();
      int r = lower_bound(all(cnts), pref + upper,
                          [](auto &a, auto b) { return a.first < b; }) -
              cnts.begin();
      ll res = query(seg, 0, m - 1, l, r, 0);
      ans += res;
      pref += nums[i];
      int p = lower_bound(all(cnts), pref,
                          [](auto &a, auto b) { return a.first < b; }) -
              cnts.begin();
      update(seg, 0, m - 1, p, 0);
    }
    return ans;
  }
};