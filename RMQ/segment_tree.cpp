#include<bits/stdc++.h>
using namespace std;


// Author: Pratik Goyal
// goyal.9@iitj.ac.in

// RMQ using Segment tree
// Output would be the minimum value between two index

// Time complexity for preprocessing and query
// <O(n), O(log(n))>


const int N = 2e5 + 5;
int n;  // array size
int t[2 * N];

void build()
{	// build the tree
	for (int i = n - 1; i > 0; --i)
		t[i] = min(t[i << 1] , t[i << 1 | 1]);
	//  t[i] = function eg: t[i] = t[i<<1] + t[i<<1|1];
	//  If we want the minimum sum
}

void modify(int p, int value)
{	// set value at position p
	for (t[p += n] = value; p > 1; p >>= 1)
		t[p >> 1] = min(t[p], t[p ^ 1]);
	//  t[p >> 1] = function
}

int query(int l, int r)
{	// sum on interval [l, r)
	int res = INT_MAX; // initialize res as per the need
	for (l += n, r += n; l < r; l >>= 1, r >>= 1)
	{
		if (l & 1) res = min(res,  t[l++]);
		if (r & 1) res = min(res, t[--r]);
		// res = function
	}
	return res;
}

void solve()
{

	cin >> n; // n is globally declared
	for (int i = 0; i < n; ++i)
		cin >> t[i + n]; // taking input

	build();

	// Indexing starts from 0
	// L is less than or equal to R
	// Minimum of a range [L, R) would be
	int L, R;
	cin >> L >> R;

	cout << query(L, R);
}


int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	solve();
	return 0;
}