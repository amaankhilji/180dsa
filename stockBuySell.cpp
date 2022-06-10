#include <bits/stdc++.h>
int maximumProfit(vector<int> &prices) {
  int ans = 0;
  int mx = prices[prices.size() - 1];
  for (int i = prices.size() - 1; i >= 0; i--) {
    mx = max(mx, prices[i]);
    ans = max(mx - prices[i], ans);

  }
  return ans;
}