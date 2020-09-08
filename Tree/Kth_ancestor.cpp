/*
https://cses.fi/problemset/task/1687/
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
/*
vector<int> v;
bool binarySearch(int l, int r, int num)
{
	if (l > r) return -1;
	int m = (l + r + 1) / 2;
	if (v[m] == num) return m;
	if (v[m] > num) binarySearch(l, m - 1, num);
	if (v[m] < num) binarySearch(m + 1, r, num);
}
*/

/*
// dfs(root, root);
void My_dfs(int v, int p)
{
	for (int u : adj[v])
	{
		if (u != p)
		{
			My_dfs(u, v);
		}
	}
}
*/

/*
const int N = 2e5 + 5;

vector<int> adj[N];
vector<bool> visited(N);
//vector<int> val(N);
//vector<int> depth(N);
//vector<int> parent(N);

void dfs(int v)
{
	visited[v] = true;
	for (int u : adj[v])
	{
		if (!visited[u])
		{
			//parent[u] = v;
			//depth[u] = depth[v] + 1;
			dfs(u);
		}
	}
}
*/

const int N = 2e5 + 5;
const int MAXLOG = 25;

vector<int> adj[N];
int timer, log_value;
int tin[N], tout[N];
int up[N][MAXLOG];

//dfs(root, 0);
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

int find_ancestor(int k, int x)
{
	for (int i = MAXLOG; i >= 0; i--)
	{
		if (k >= (1 << i))
		{
			x = up[x][i];
			k -= (1 << i);
		}
		if (k == 0) return x;
	}
	return 0;
}


// left shift << multiply by 2
// right shift >> divide by 2

///----------------------------- | START FROM HERE | --------------------------------------///



#define int long long //change int main to int32_t main

const  int mod = 1e9 + 7;

void solve()
{
	int n, q; cin >> n >> q;
	log_value = ceil(log2(n));
	fr(i, 2, n + 1)
	{
		int x; cin >> x;
		adj[i].pb(x);
		adj[x].pb(i);
	}
	dfs(1, 0);
	while (q--)
	{
		int k, x; cin >> x >> k;
		int ans = find_ancestor(k, x);
		if (ans == 0) cout << -1 << sp;
		else cout << ans << sp;
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