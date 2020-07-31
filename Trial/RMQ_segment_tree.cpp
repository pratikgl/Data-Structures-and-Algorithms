#include<bits/stdc++.h>
using namespace std;

// Time complexity
// < O(n*log(n)), O(1) >
// RMQ sSegment tree

const int N = 2e3 + 5;

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
int nn;

void build()
{
	nn = level.size();
	for (int i = 0; i < nn; i++)
		t[i + nn] = make_pair(level[i], i);
	for (int i = nn - 1; i > 0; --i)
		t[i] = min(t[i << 1] , t[i << 1 | 1]);
}

int query(int u, int v)
{	// sum on interval [l, r)
	nn = level.size();
	int L = first_visit[u];
	int R = first_visit[v] + 1;
	if (L > R) swap(L, R);

	pair<int, int> res = {INT_MAX, INT_MAX}; // initialize res as per the need
	for (L += nn, R += nn; L < R; L >>= 1, R >>= 1)
	{
		if (L & 1) res = min(res, t[L++]);
		if (R & 1) res = min(res, t[--R]);
		// res = function
	}
	return (euler[res.second]);
}



void solve(int caseo)
{
	cout << "Case " << caseo << ":" << endl;
	int n; cin >> n;
	for (int i = 0; i < n; ++i)
	{
		int m; cin >> m;
		for (int j = 0; j < m; ++j)
		{
			int lola; cin >> lola;
			adj[i + 1].push_back(lola);
			adj[lola].push_back(i + 1);
		}
	}

	dfs(1, 0);	//for (auto u : level) cout << u << " "; cout << endl;


	build();
	int qq; cin >> qq;
	while (qq--)
	{
		int a, b; cin >> a >> b;
		cout << query(a, b) << "\n";
	}
	for (int i = 0; i < n + 5; i++) adj[i].clear();
	euler.clear();
	level.clear();
	memset(first_visit, 0, sizeof(first_visit));

}


int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n; cin >> n;
	int i = 0;
	while (n--)
	{
		i++;
		solve(i);
	}
	return 0;
}