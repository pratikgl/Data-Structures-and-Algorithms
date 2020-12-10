//https://leetcode.com/problems/longest-increasing-subsequence/solution/


// for each i check for i+1 to j and use dp to find the max element

class Solution {
public:
	int lengthOfLIS(vector<int>& arr) {
		int n = arr.size();
		int dp[n];
		for (int i = 0; i < n; ++i) dp[i] = 1;
		for (int i = 0; i < n; ++i) {
			for (int j = i + 1; j < n; ++j) {
				if (arr[j] > arr[i]) {
					dp[j] = max(dp[i] + 1, dp[j]);
				}
			}
		}
		return *max_element(dp, dp + n);
	}
};