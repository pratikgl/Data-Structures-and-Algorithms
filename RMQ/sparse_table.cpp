#include<bits/stdc++.h>
using namespace std;


// Author: Pratik Goyal
// goyal.9@iitj.ac.in

// RMQ using sparse table
// Output would be the minimum value between two index

// Time complexity
// <O(n*log(n)), O(1)>


const int N = 2e5 + 5;
const int MAXLOG = 25;

int table[N][MAXLOG];
int logs[N];

void solve()
{
	int n; cin >> n;  // Number of elements in the array
	int arr[n];
	for (int i = 0; i < n; ++i)
		cin >> arr[i];

	// Precomputing all the log values
	for (int i = 2; i < N; i++)
		logs[i] = logs[i / 2] + 1;

	// Initialising the 0th index
	for (int i = 0; i < n; i++)
		table[i][0] = arr[i];

	// Sparse table
	for (int j = 1; j < MAXLOG; j++)
		for (int i = 0; i + (1 << j) <= n; i++)
			table[i][j] = min(table[i][j - 1], table[i + (1 << (j - 1))][j - 1]);

	// Indexing starts from 0
	// L is less than or equal to R
	// Minimum of a range [L, R] would be
	int L, R;
	cin >> L >> R;
	int j = logs[R - L + 1];
	int minimum = min(table[L][j], table[R - (1 << j) + 1][j]);
	cout << minimum;
}

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	solve();
	return 0;
}