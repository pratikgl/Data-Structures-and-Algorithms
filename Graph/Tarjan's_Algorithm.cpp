#include <bits/stdc++.h>
using namespace std;
// https://www.hackerearth.com/practice/algorithms/graphs/strongly-connected-components/practice-problems/algorithm/a-walk-to-remember-qualifier2/

/*
#pragma GCC optimize("Ofast,03")
#pragma comment(linker, "/stack:200000000")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")
*/
#define    boost        ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define    nl           "\n"
#define    ll           long long
#define    pb           push_back
#define    mpr          make_pair
#define    fr(i,a,n)    for(ll i=a;i<n;++i)
#define    fr0(i,n)     for(ll i=0;i<n;++i)
#define    pii          pair<ll, ll>
#define    mem(a)       memset(a,0,sizeof(a))
#define    F            first
#define    S            second
#define    sp           ' '
#define    vi           vector<ll>
#define    vii          vector<pair<ll, ll>>
#define    all(a)       a.begin(), a.end()

/*
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree <ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;
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
	double tt =  chrono::duration_cast<chrono::nanoseconds>(end - start).count();
	cout << "\nExecuted in: " << fixed << tt * 1e-9 << setprecision(9) << " sec";
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

#define int long long //change int main to int32_t main

///----------------------------- | FUNCTIONS | --------------------------------------///

bool sortbysec(const pii &a, const pii &b) {return a.S < b.S;}
bool compBySec(const pii &a, const pii &b) {return a.S == b.S ? a.F < b.F : a.S < b.S;}

///----------------------------- | START FROM HERE | --------------------------------------///

const int N = 1e5 + 5;

vector<int> adj[N];
vector<bool> onStack(N);
vector<int> tin(N), low(N); // clean tin
vector<vector<int>> SCC;
int timer = 0;
stack<int> st;

void dfs(int v)
{
	st.push(v);
	tin[v] = low[v] = ++timer;
	onStack[v] = true;
	for (int u : adj[v]) {
		if (tin[u] == 0) {
			dfs(u);
			low[v] = min(low[v], low[u]);
		}
		else if (onStack[u]) {
			low[v] = min(low[v], tin[u]);
		}
	}
	if (low[v] == tin[v]) {
		vector<int> scc_temp;
		while (1) {
			scc_temp.push_back(st.top());
			onStack[st.top()] = false;
			if (st.top() == v) {
				st.pop(); break;
			} st.pop();
		}
		SCC.push_back(scc_temp);
	}
}

void solve()
{
	int n, m; cin >> n >> m;
	fr0(i, m) {
		int u, v; cin >> u >> v;
		adj[u].pb(v);
	}
	fr(i, 1, n + 1) {
		if (tin[i] == 0) dfs(i);
	}
	vi ans(N);
	for (auto v : SCC) {
		if (v.size() != 1) {
			for (int i : v) ans[i] = 1;
		}
	}
	fr(i, 1, n + 1) cout << ans[i] << sp;
}


int32_t main()
{
	auto start = chrono::high_resolution_clock::now();
	boost;
	fio();
	int t = 1;
	//cin >> t;
	while (t--) solve();
	auto end = chrono::high_resolution_clock::now();
	TIME(start, end);
	return 0;
}