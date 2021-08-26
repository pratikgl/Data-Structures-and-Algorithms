// https://leetcode.com/problems/implement-strstr/

class Solution {
public:

	// Knuth–Morris–Pratt (KMP) algorithm for string matching

	int strStr(string haystack, string needle) {
		if (haystack.size() < needle.size()) return -1;
		if (needle.size() == 0) return 0;

		vector<int> prefix_arr = kmp_preprocess(needle);

		// searching in the haystack
		int i = 0, j = 0;
		while (i < haystack.length() && j < needle.length()) {
			if (haystack[i] == needle[j]) i++, j++;
			else if (j > 0) j = prefix_arr[j - 1];
			else i++;
		}

		return j == needle.size() ? i - j : -1;
	}

	// preprocessing of needle (pattern string)
	vector<int> kmp_preprocess(string pattern) {
		int i = 1, j = 0;
		vector<int> prefix_arr(pattern.size());
		while (i < pattern.size()) {
			if (pattern[i] == pattern[j]) {
				prefix_arr[i] = j + 1;
				i++, j++;
			}
			else if (j > 0) j = prefix_arr[j - 1];
			else prefix_arr[i] = 0, i++;
		}
		return prefix_arr;
	}
};