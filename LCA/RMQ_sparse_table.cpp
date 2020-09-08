#include<bits/stdc++.h>
using namespace std;


// Author: Pratik Goyal
// goyal.9@iitj.ac.in

// LCA using RMQ sparse table method
// Time complexity for preprocessing and query
// <O(n*log(n)), O(1)>


// Double of the upper bound
// otherwise Runtime error
const int N = 5e5 + 5;
const int MAXLOG = 25;

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


pair<int, int> table[N][MAXLOG];
int logs[N];

void preprocess()
{
	int n = level.size();

	for (int i = 2; i < N; i++)
		logs[i] = logs[i / 2] + 1;

	for (int i = 0; i < n; i++)
		table[i][0] = make_pair(level[i], i);

	for (int j = 1; j < MAXLOG; j++)
		for (int i = 0; i + (1 << j) <= n; i++)
			table[i][j] = min(table[i][j - 1], table[i + (1 << (j - 1))][j - 1]);
}


int query(int u, int v)
{
	int L = first_visit[u];
	int R = first_visit[v];
	if (L > R) swap(L, R);
	int j = logs[R - L + 1];
	pair<int, int> minimum;
	minimum = min(table[L][j], table[R - (1 << j) + 1][j]);
	return (euler[minimum.second]);
}


void solve()
{
	int n; cin >> n;
	for (int i = 0; i < n - 1; ++i)
	{
		int u, v; cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	dfs(1, 0);
	preprocess();
	int a, b; cin >> a >> b;
	cout << query(a, b);

	// clear garbage values
	for (int i = 0; i < n + 3; ++i)
		adj[i].clear();
	euler.clear();
	level.clear();
	memset(first_visit, 0, sizeof(first_visit));
}


int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	solve();
	return 0;
}