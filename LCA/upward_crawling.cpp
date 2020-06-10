#include<bits/stdc++.h>
using namespace std;


// Author: Pratik Goyal
// goyal.9@iitj.ac.in

// LCA and path using upward crawling
// Time complexity for preprocessing and query
// <O(n), O(n)>

const int N = 2e5 + 5;
vector<int> adj[N];
bool visited[N];
int depth[N];
int parent[N];

void dfs(int v)
{
	visited[v] = true;
	for (int u : adj[v])
	{
		if (!visited[u])
		{
			parent[u] = v;
			depth[u] = depth[v] + 1;
			dfs(u);
		}
	}
}

vector<int> path_a;   //path from a to lca
vector<int> path_b;   //path from b to lca
vector<int> path_a2b; //path from a to b
// Given that a is not equal to b

void find_path(int a, int b)
{
	path_a.push_back(a);
	path_b.push_back(b);

	if (depth[a] > depth[b])
	{
		while (depth[a] != depth[b])
		{
			a = parent[a];
			if (a == b) break;
			path_a.push_back(a);
		}
	}

	else if (depth[a] < depth[b])
	{
		while (depth[a] != depth[b])
		{
			b = parent[b];
			if (a == b) break;
			path_b.push_back(b);
		}

	}

	while (a != b)
	{
		a = parent[a];
		b = parent[b];
		if (a == b)
		{
			path_a.push_back(a);
			break;
		}
		else
		{
			path_a.push_back(a);
			path_b.push_back(b);
		}
	}
	for (auto u = path_a.begin(); u != path_a.end(); u++)
	{
		path_a2b.push_back(*u);
	}
	for (auto u = path_b.rbegin(); u != path_b.rend(); u++)
	{
		path_a2b.push_back(*u);
	}
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

	parent[1] = -1;
	depth[1] = 0;
	dfs(1);
	find_path(2, 3); //find_path(a, b)

	// print path_a2b
	for (int u : path_a2b) cout << u << endl;
}

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	solve();
	return 0;
}