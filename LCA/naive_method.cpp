#include<bits/stdc++.h>
using namespace std;


// Author: Pratik Goyal
// goyal.9@iitj.ac.in

// LCA using upward crawling (Naive method)
// Time complexity for preprocessing and query
// <O(n), O(n)>

const int N = 2e5 + 5;
vector<int> adj[N];
int depth[N];
int parent[N];

void dfs(int v, int p, int d)
{
	depth[v] = d;
	parent[v] = p;
	for (int u : adj[v])
		if (u != p)
			dfs(u, v, d + 1);
}


int lca(int a, int b)
{
	while (a != b)
	{
		if (depth[a] > depth[b])
			a = parent[a];
		else if (depth[a] < depth[b])
			b = parent[b];
		else
			a = parent[a], b = parent[b];
	}
	return a;
}


void solve()
{
	int n; cin >> n; //number of nodes
	for (int i = 0; i < n - 1; ++i)
	{
		int u, v; cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	dfs(1, 0, 0);
	cout << lca(2, 3);

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