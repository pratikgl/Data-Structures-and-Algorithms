#include <bits/stdc++.h>
using namespace std;
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
/*
const int N = 2e5 + 5;

vector<int> adj[N];      // mem(adj);
vector<bool> visited(N); // fill(all(visited), 0)
//vector<int> val(N);    // val.assign(N, 1)
//vector<int> depth(N);
//vector<int> parent(N);
//vector<int> child(N);

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
            //child[v] += child[u] + 1;
        }
    }
}
*/

// left shift << multiply by 2
// right shift >> divide by 2

///----------------------------- | START FROM HERE | --------------------------------------///

const int mod = 1e9 + 7;
const int N = 1e5 + 5;
int dp[N][105];

void solve()
{
	int n, m; cin >> n >> m;
	vi x(n); fr0(i, n) cin >> x[i];
	if (x[0] == 0) {
		fr(i, 1, m + 1) dp[0][i] = 1;
	}
	else {
		dp[0][x[0]] = 1;
	}
	fr(i, 1, n) {
		if (x[i] == 0) {
			fr(j, 1, m + 1) (dp[i][j] = dp[i - 1][j] + dp[i - 1][j + 1] + dp[i - 1][j - 1]) %= mod;
		}
		else {
			(dp[i][x[i]] = dp[i - 1][x[i] - 1] + dp[i - 1][x[i]] + dp[i - 1][x[i] + 1]) %= mod;
		}
	}
	int ans = 0;
	fr(i, 1, m + 1) (ans += dp[n - 1][i]) %= mod;
	cout << ans;
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