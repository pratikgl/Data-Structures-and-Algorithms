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

// Method: 1 --> using segment tree

const int mod = (1e9 + 7) * 2;
const int N = 2e5 + 5;

int t[2 * N];

void modify(int p, int value)
{	// set value at position p
	for (t[p += N] = value; p > 1; p >>= 1)
		t[p >> 1] = max(t[p], t[p ^ 1]);
}

int query(int l, int r)
{	// sum on interval [l, r)
	int res = 0; // initialize res as per the need
	for (l += N, r += N; l < r; l >>= 1, r >>= 1)
	{
		if (l & 1) res = max(res,  t[l++]);
		if (r & 1) res = max(res, t[--r]);
	}
	return res;
}


void solve()
{
	int n; cin >> n;
	vi a(n); fr0(i, n) cin >> a[i];

	map<int, int> mp;
	fr0(i, n) mp[a[i]];
	int count = 0;
	for (auto it : mp) mp[it.F] = count++;
	fr0(i, n) a[i] = mp[a[i]];

	for (int i = 0; i < n; ++i) {
		int q = query(0, a[i]);
		modify(a[i], max(q + 1, t[a[i] + N]));
	}
	cout << *max_element(t, t + n);
}

/*
// Method: 2 --> Binary Search

void solve()
{
	int n; cin >> n;
	vi a(n); fr0(i, n) cin >> a[i];
	vi ans; ans.pb(a[0]);
	fr(i, 1, n) {
		auto it = upper_bound(all(ans), a[i]);
		if (it == ans.begin()) ans[0] = a[i];
		else {
			auto it_prev = it - 1;
			if (*it_prev != a[i]) {
				if (it == ans.end()) ans.pb(a[i]);
				else ans[it - ans.begin()] = a[i];
			}
		}
	}
	cout << ans.size();
}
*/

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