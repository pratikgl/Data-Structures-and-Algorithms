#include<bits/stdc++.h>
using namespace std;


// Author: Pratik Goyal
// goyal.9@iitj.ac.in

// LCA and path using upward crawling (Tree)
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

vector<int> path_a;   //path from a to lca
vector<int> path_b;   //path from b to lca
vector<int> path_a2b; //path from a to b
int LCA;

void find_path(int a, int b)
{
	path_a.push_back(a);
	path_b.push_back(b);
	LCA = a;
	while (a != b)
	{
		if (depth[a] > depth[b])
		{
			a = parent[a];
			LCA = a;
			path_a.push_back(a);
		}
		else if (depth[a] < depth[b])
		{
			b = parent[b];
			LCA = b;
			path_b.push_back(b);
		}
		else
		{
			a = parent[a];
			b = parent[b];
			LCA = a;
			path_a.push_back(a);
			path_b.push_back(b);
		}
	}
	reverse(path_b.begin(), path_b.end());
	path_b.erase(path_b.begin());
	path_a2b.insert(path_a2b.begin(), path_a.begin(), path_a.end());
	path_a2b.insert(path_a2b.end(), path_b.begin(), path_b.end());
}


void solve()
{
	int n; cin >> n; //number of nodes

	// adjacency list representation
	for (int i = 0; i < n - 1; ++i)
	{
		int u, v; cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	dfs(1, 0, 0);
	find_path(5, 4); //find_path(a, b)

	// print path_a2b
	for (int u : path_a2b)
		cout << u << endl;
	// LCA is:
	cout << LCA << endl;

	// clear garbage values
	for (int i = 0; i < n + 3; ++i)
		adj[i].clear();
	path_a.clear();
	path_b.clear();
	path_a2b.clear();
}

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	solve();
	return 0;
}