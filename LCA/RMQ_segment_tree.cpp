#include<bits/stdc++.h>
using namespace std;


// Author: Pratik Goyal
// goyal.9@iitj.ac.in

// LCA using RMQ Segment tree
// Time complexity
// <O(n*log(n)), O(1)>

const int N = 2e5 + 5;

vector<int> adj[N];
vector<int> euler;
vector<int> level;
int depth[N], parent[N];
int first_visit[N];

void dfs(int v, int p)
{
	euler.push_back(v);
	level.push_back(depth[v]);
	if (!first_visit[v])
		first_visit[v] = euler.size() - 1;

	for (int u : adj[v])
		if (u != p)
		{
			depth[u] = depth[v] + 1;
			parent[u] = v;
			dfs(u, v);
		}

	euler.push_back(p);
	level.push_back(depth[p]);
}


pair<int, int> t[6 * N];

void build()
{
	int nn = level.size();
	for (int i = 0; i < nn; i++)
		t[i + nn] = make_pair(level[i], i);
	for (int i = nn - 1; i > 0; --i)
		t[i] = min(t[i << 1] , t[i << 1 | 1]);
}

int query(int u, int v)
{	// sum on interval [l, r)
	int nn = level.size();
	int L = first_visit[u];
	int R = first_visit[v];
	if (L > R) swap(L, R);
	R++;

	pair<int, int> res = {INT_MAX, INT_MAX}; // initialize res as per the need
	for (L += nn, R += nn; L < R; L >>= 1, R >>= 1)
	{
		if (L & 1) res = min(res, t[L++]);
		if (R & 1) res = min(res, t[--R]);
		// res = function
	}
	return (euler[res.second]);
}

void solve()
{
	int n; cin >> n;  // Number of nodes
	for (int i = 0; i < n - 1; ++i)
	{
		int u, v; cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(1, 0);
	build();

	cout << query(1, 2);

	// clear garbage values
	for (int i = 0; i < n + 3; ++i)
		adj[i].clear();
}


int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	solve();
	return 0;
}