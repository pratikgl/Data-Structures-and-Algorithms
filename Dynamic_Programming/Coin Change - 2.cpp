// https://leetcode.com/problems/coin-change-2/submissions/

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int dp[5000 + 5] = {0};
        dp[0] = 1;
        for (int u : coins) {
            for (int i = 0; i <= amount; i++) {
                if (i + u <= amount) {
                    dp[i + u] += dp[i];
                }
            }
        }
        return dp[amount];
    }
};