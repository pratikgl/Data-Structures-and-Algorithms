#include<bits/stdc++.h>
using namespace std;


// Author: Pratik Goyal
// goyal.9@iitj.ac.in

// LCA using Binary lifting
// Time complexity
// <O(n*log(n)), O(log(n))>


const int N = 2e5 + 5;
const int MAXLOG = 25;

vector<int> adj[N];
int timer, log_value;
int tin[N], tout[N];
int up[N][MAXLOG];

void dfs(int v, int p)
{
	tin[v] = ++timer;
	up[v][0] = p;
	for (int i = 1; i <= log_value; ++i)
		up[v][i] = up[up[v][i - 1]][i - 1];
	for (int u : adj[v])
		if (u != p)
			dfs(u, v);

	tout[v] = ++timer;
}


bool is_ancestor(int u, int v)
{
	return tin[u] <= tin[v] && tout[u] >= tout[v];
}


int lca(int u, int v)
{
	if (is_ancestor(u, v))
		return u;
	if (is_ancestor(v, u))
		return v;
	for (int i = log_value; i >= 0; --i)
		if (!is_ancestor(up[u][i], v))
			u = up[u][i];

	return up[u][0];
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
	log_value = ceil(log2(n));
	timer = 0;
	dfs(1, 1);
	cout << lca(1, 2);

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