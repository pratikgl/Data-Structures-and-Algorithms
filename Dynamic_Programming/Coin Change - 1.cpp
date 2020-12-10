// https://codeforces.com/blog/entry/43256
// https://leetcode.com/problems/coin-change/

class Solution {
public:
	int coinChange(vector<int>& coins, int amount) {
		int dp[10005];
		dp[0] = 0;
		for (int i = 1; i <= amount; ++i) {
			dp[i] = INT_MAX - 5;
			for (int j : coins) {
				if (i - j >= 0) {
					dp[i] = min(dp[i], dp[i - j] + 1);
				}
			}
		}
		if (dp[amount] == INT_MAX - 5) return -1;
		return dp[amount];
	}
};