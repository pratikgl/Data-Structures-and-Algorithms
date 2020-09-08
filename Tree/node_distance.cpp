/*
https://cses.fi/problemset/task/1135/
*/

#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("Ofast,03")
#pragma comment(linker, "/stack:200000000")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")

#define    boost        ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define    nl           "\n"
#define    ll           long long
#define    pb           push_back
#define    mpr          make_pair
#define    fr(i,a,n)    for(ll i=a;i<n;++i)
#define    fr0(i,n)     for(ll i=0;i<n;++i)
#define    pii          pair<int, int>
#define    FO           find_by_order
#define    OK           order_of_key
#define    mem(a)       memset(a,0,sizeof(a))
#define    F            first
#define    S            second
#define    sp           " "
#define    vi           vector<int>
#define    vii          vector<pair<int, int>>
#define    all(a)       a.begin(), a.end()

/*
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree <
int,
null_type,
less<int>,
rb_tree_tag,
tree_order_statistics_node_update >
set_t;
*/

void fio()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}


template<typename T> void TIME(T start, T end)
{
#ifndef ONLINE_JUDGE
	double time_taken =  chrono::duration_cast<chrono::nanoseconds>(end - start).count();
	time_taken *= 1e-9;
	cout << "\nExecuted in: " << fixed
	     << time_taken << setprecision(9);
	cout << " sec";
#endif
}

///----------------------------- | Debugging Starts | --------------------------------------///

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i : x) cerr << (f++ ? ", " : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}

#ifndef ONLINE_JUDGE
#define debug(x...)  cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

///----------------------------- | Debugging Ends | --------------------------------------///


///----------------------------- | FUNCTIONS | --------------------------------------///

const int N = 2e5 + 5;
const int MAXLOG = 25;

vector<vi> adj(N);
int timer, log_value;
int tin[N], tout[N];
int up[N][MAXLOG];
int depth[N];

void dfs(int v, int p)
{
	tin[v] = ++timer;
	up[v][0] = p;
	for (int i = 1; i <= log_value; ++i)
		up[v][i] = up[up[v][i - 1]][i - 1];
	for (int u : adj[v])
	{
		if (u != p)
		{
			depth[u] = depth[v] + 1;
			dfs(u, v);
		}
	}

	tout[v] = ++timer;
}

// u is ancestor of v
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

int distance(int a, int x)
{
	return depth[a] - depth[x];
}


///----------------------------- | START FROM HERE | --------------------------------------///


void solve()
{
	int n, q; cin >> n >> q;
	log_value = ceil(log2(n));
	fr0(i, n - 1)
	{
		int u, v; cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	dfs(1, 1);
	while (q--)
	{
		int a, b; cin >> a >> b;
		int x = lca(a, b);
		cout << distance(a, x) + distance(b, x) << nl;
	}
}


int32_t main()
{
	auto start = chrono::high_resolution_clock::now();
	boost;
	fio();
	int t;
	t = 1;
	//cin >> t;
	while (t--) solve();
	auto end = chrono::high_resolution_clock::now();
	TIME(start, end);
	return 0;
}